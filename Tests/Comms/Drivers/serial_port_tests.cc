/*! \brief Do not include this file in external modules.
    \file serial_port_tests.cc
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Thu Apr 24 18:44:27 CDT 2014

    \brief This file is part of Tests Comms/Divers module.
    \brief This file become from: Tests/Comms/Drivers/serial_port_tests.cc

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


#include <cstdio>

#include <QtCore/QThread>

#include <Code/Comms/Drivers/ciaa_comm_facade.h>

#include "Tests/Comms/Drivers/comms_drivers_master_test.h"

class Slave : public QThread {
 public:
  explicit  Slave(std::string device) :
    QThread{},
    device_{device} {
    }
  ~Slave() = default;

  Slave(const Slave&) = delete;
  Slave& operator=(const Slave&) = delete;

  Slave(const Slave&&) = delete;
  Slave& operator=(const Slave&&) = delete;

 protected:
  void run() override {
    ciaaCommFacade s_dev{device_,
                       SerialPortAdaptor::BaudRate::Baud1200,
                       SerialPortAdaptor::DataBits::Data8,
                       SerialPortAdaptor::FlowControl::NoFlowControl,
                       SerialPortAdaptor::Parity::SpaceParity,
                       SerialPortAdaptor::StopBits::TwoStop};

    CommDriverErrorCode ret = s_dev.connect(100);
    if (ret != CommDriverErrorCode::OK) {
      fprintf(stderr, "%s\n", s_dev.get_msg_error(ret).c_str())  ;
      return;
    }

    std::int32_t iters{kIters};
    while (iters--) {
      char data[100]{0};
      ciaa_size_t lenth{sizeof(std::int32_t)};
      if ((ret = s_dev.read(100, data, &lenth)) != CommDriverErrorCode::OK) {
        std::fprintf(stderr, "%s\n", s_dev.get_msg_error(ret).c_str());
        printf("checking transitioned... %lld\n", lenth);
        s_dev.disconnect(100);
        return;
      }
      memcpy(&lenth, data, sizeof(std::int32_t));
      memset(data, 0, sizeof(data));
      if ((ret = s_dev.read(100, data, &lenth)) != CommDriverErrorCode::OK) {
        std::fprintf(stderr, "%s\n", s_dev.get_msg_error(ret).c_str());
        printf("checking transitioned... %lld\n", lenth);
        s_dev.disconnect(100);
        return;
      }
      printf("%s", data);

      char msg_for_remot[]{"I am a server.\n"};
      std::int32_t client_msg_lenth{sizeof(msg_for_remot)};
      lenth = sizeof(std::int32_t);
      memset(data, 0, sizeof(data));
      memcpy(data, &client_msg_lenth, lenth);
      if ((ret = s_dev.write(100, data, &lenth)) != CommDriverErrorCode::OK) {
        std::fprintf(stderr, "%s\n", s_dev.get_msg_error(ret).c_str());
        printf("checking transitioned... %lld\n", lenth);
        s_dev.disconnect(100);
        return;
      }
      memset(data, 0, sizeof(data));
      memcpy(data, msg_for_remot, sizeof(msg_for_remot));
      lenth = sizeof(msg_for_remot);
      if ((ret = s_dev.write(100, data, &lenth)) != CommDriverErrorCode::OK) {
        std::fprintf(stderr, "%s\n", s_dev.get_msg_error(ret).c_str());
        printf("checking transitioned... %lld\n", lenth);
        s_dev.disconnect(100);
        return;
      }
    }
    s_dev.disconnect(100);
  }

 private:
  std::string device_;

};

int main (int argc, char *argv[]) {
  QCoreApplication app(argc, argv);
  if (argc != 3) {
    printf("usage: %s @com1@ @com1@\n",
           app.applicationFilePath().toStdString().c_str());
    return EXIT_FAILURE;
  }
  Slave server{std::string{argv[1]}};
  CommsDriversMaster client{std::string{argv[2]}};
  client.start();
  server.start();
  server.wait();
  client.wait();
  if (client.is_correct()) {
    return EXIT_SUCCESS;
  } else {
    return EXIT_FAILURE;
  }
}
