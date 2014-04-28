/*! \brief Do not include this file in external modules.
    \file tcp_test.cc
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Thu Apr 24 18:44:27 CDT 2014

    \brief This file is part of Tests Comms/Divers module.
    \brief This file become from: Tests/Comms/Drivers/tcp_test.cc

    \attention <h1><center>&copy; COPYRIGHT
    GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007</center></h1>

    \copyright

    <a class="el" href="http://proyecto-ciaa.com.ar">
      This file is part of CIAA Project.
      ==================================
    </a>

    Copyright (C) 2014 $(Entidad que patenta)

  This software is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License along
  with this program; if not, write to the Free Software Foundation, Inc.,
  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <cinttypes>
#include <cstdio>
#include <stddef.h>

#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>
#include <QDebug>

#include <Code/Comms/Drivers/ciaa_comm_facade.h>

#include "Tests/Comms/Drivers/comms_drivers_master_test.h"

const std::int32_t kTcpPort{8881};
const std::string kHost{"127.0.0.1"};

class Slave {
 public:
  Slave() = default;
  ~Slave() = default;

  Slave(const Slave&) = delete;
  Slave& operator=(const Slave&) = delete;

  Slave(const Slave&&) = delete;
  Slave& operator=(const Slave&&) = delete;

  void terminate() {
    while (server_.hasPendingConnections()) {
      server_.nextPendingConnection()->close();
    }
    server_.close();
  }

  void start() {
    this->run();
  }

 protected:
  void run() {
      serverLog(u8"Starting server...");
      QObject::connect(&server_, &QTcpServer::newConnection, [this]{
      cli_sock_ = server_.nextPendingConnection();
      serverLog(QString(u8"Acepted conection from %1").arg(cli_sock_->peerAddress().toString()));  // NOLINT(whitespace/line_length)

      int iters{kIters};
      while (iters--) {
        char data[kDataBufferSize]{0};
        qint64 lenth{sizeof(std::int32_t)};
        cli_sock_->waitForReadyRead(100);
        qint64 transitioned_data{cli_sock_->read(data, lenth)};
        if (transitioned_data != lenth) {
          return;
        }
        std::int32_t clieent_msg_lenth{0};
        memcpy(&clieent_msg_lenth, data, lenth);
        memset(data, 0, sizeof(data));
        lenth = clieent_msg_lenth;
        cli_sock_->waitForReadyRead(100);
        transitioned_data = cli_sock_->read(data, lenth);
        if (transitioned_data != lenth) {
          return;
        }
        printf("%s", data);
        memset(data, 0, sizeof(data));
        char server_msg[]{"I am a server.\n"};
        std::int32_t server2_msg_lenth{sizeof(server_msg)};
        memcpy(data, &server2_msg_lenth, sizeof(std::int32_t));
        lenth = sizeof(std::int32_t);
        transitioned_data = cli_sock_->write(data, lenth);
        cli_sock_->waitForBytesWritten(100);
        if (transitioned_data != lenth) {
          return;
        }
        lenth = sizeof(server_msg);
        memset(data, 0, sizeof(data));
        memcpy(data, server_msg, lenth);
        transitioned_data = cli_sock_->write(data, lenth);
        cli_sock_->waitForBytesWritten(100);
        if (transitioned_data != lenth) {
          return;
        }
      }
//      cli_sock_->disconnectFromHost();
//      cli_sock_->close();
//      server_.close();
    });

    if (server_.listen(QHostAddress::Any, kTcpPort)) {
      serverLog(u8"Server listening...");
    } else {
      serverLog(QString(u8"Error starting server: %1").arg(server_.errorString()));  // NOLINT(whitespace/line_length)
    }
  }

 private:
  QTcpServer server_;
  QTcpSocket *cli_sock_{nullptr};

  void serverLog(const QString &msg) {
    qDebug() << "-- [SERVIDOR] -- " << msg;
  }
};

int main(int argc, char *argv[]) {
  QCoreApplication app(argc, argv);
  Slave server;
  CommsDriversMaster client(kHost, kTcpPort);
  QTimer t;
  QObject::connect(&t, &QTimer::timeout, [&t, &server, &client]{
    t.stop();
    server.terminate();
    client.terminate();
    client.wait();
    if (client.is_correct()) {
      exit(EXIT_SUCCESS);
    } else {
      exit(EXIT_FAILURE);
    }
  });
  t.start(1000);
  server.start();
  client.start();
  return app.exec();
}
