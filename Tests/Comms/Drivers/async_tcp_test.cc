/*! \brief Do not include this file in external modules.
    \file async_tcp_test.cc
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Mon Apr 28 00:37:29 CDT 2014

    \brief This file is part of Tests Comms/Divers module.
    \brief This file become from: Tests/Comms/Drivers/async_tcp_test.cc

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

#include <QtNetwork/QTcpServer>

#include <Code/Comms/Drivers/ciaa_comm_facade.h>

const std::int32_t kTcpPort{8881};
const std::string kHost{"127.0.0.1"};
const std::int32_t kDataBufferSize{256};
const std::int32_t kIters{10};


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

    char data[1000]{0};
    qint64 lenth{100};
    if (cli_sock_->waitForReadyRead(1000) == true) {
      serverLog(u8"ready!\n");
    } else {
      fprintf(stderr, "%s\n", cli_sock_->errorString().toStdString().c_str());
      serverLog("no ready!\n");
    }
    cli_sock_->read(data, lenth);
    printf("SERVER: |%s|\n", data);


    printf("start\n");
    for (int i = 0; i < 100000; i++) {
      for (int j = 0; j < 100000; j++) {
      }
    }
    printf("end\n");

    lenth = 10;
    cli_sock_->write(data, lenth);
    if (cli_sock_->waitForBytesWritten(100) == -1) {
      serverLog(cli_sock_->errorString() + "in write");
    }
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

class Master : public QThread {
 public:
  Master() = default;
  ~Master() {
    delete connection;
  }

  Master(const Master&) = delete;
  Master& operator=(const Master&) = delete;

  Master(const Master&&) = delete;
  Master& operator=(const Master&&) = delete;

 protected:
  ciaaCommFacade *connection;

  void run() override {

    connection = {new ciaaCommFacade{kHost, kTcpPort}};

    CommDriverErrorCode err{connection->connect(100)};
    if (err != CommDriverErrorCode::OK) {
      printf("%s\n", connection->get_msg_error(err).c_str());
    }

    char write_data[]{"FROM CLIENT\n"};
    ciaa_size_t data_length{10};

    connection->write(write_data, &data_length, [this](
                     CommDriverErrorCode err,
                     ciaa_size_t n){
      std::printf("CLIENT: writed %lld bytes\n", n);
      if (err != CommDriverErrorCode::OK) {
        std::printf("%s\n", connection->get_msg_error(err).c_str());
      }
    });

    char read_data[100]{0};
    connection->read(read_data, &data_length, [this](
                    CommDriverErrorCode err,
                    ciaa_size_t n) {
      std::printf("CLIENT: readed %lld bytes\n", n);
      if (err != CommDriverErrorCode::OK) {
        std::printf("%s\n", connection->get_msg_error(err).c_str());
      }
    });
  }
 private:
};

int main(int argc, char *argv[]) {
  QCoreApplication app(argc, argv);

  Slave server;
  Master client;
  QTimer t;
  QObject::connect(&t, &QTimer::timeout, [&t, &server, &client]{
    t.stop();
    server.terminate();
    client.terminate();
    client.wait();
    exit(EXIT_FAILURE);
  });
  t.start(1000);
  server.start();
  client.start();
  return app.exec();
}
