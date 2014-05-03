/*! \brief This file gives a CommsDriversMaster functionality.
    \file comms_drivers_master_test.cc
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Mon Apr 28 15:53:23 CDT 2014

    \brief This file is part of Tests Comms/Divers module.
    \brief This file become from: Tests/Comms/Drivers/comms_drivers_master_test.cc

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

#include "Tests/Comms/Drivers/comms_drivers_master_test.h"

CommsDriversMaster::CommsDriversMaster(std::string device)
  : dev_{nullptr}
  , host_{""}
  , port_{0}
  , serial_device_name_{device}
  , correct_{false} {
}

CommsDriversMaster::CommsDriversMaster(const std::string host, std::uint16_t port)  // NOLINT(whitespace/line_length)
  : dev_{nullptr}
  , host_{host}
  , port_{port}
  , serial_device_name_{""}
  , correct_{false} {
}

CommsDriversMaster::~CommsDriversMaster() {
  if (dev_ != nullptr) delete dev_;
}


void CommsDriversMaster::run() {
  //  WARNING(denisacostaq\@gmail.com): el dev_ se debe crear dentro del
  //  mismo hilo por eso esta dentro del run y no del constructor.
  if (port_ == 0) {
    dev_ = new ciaaCommFacade(serial_device_name_,
                              SerialPortAdaptor::BaudRate::Baud1200,
                              SerialPortAdaptor::DataBits::Data8,
                              SerialPortAdaptor::FlowControl::NoFlowControl,
                              SerialPortAdaptor::Parity::NoParity,
                              SerialPortAdaptor::StopBits::OneStop);
  } else {
    if (dev_ == nullptr) dev_ = new ciaaCommFacade (host_, port_);
  }

  ciaaErrorCode ret = dev_->connect(100);
  if (ret != ciaaErrorCode::OK) {
    dev_->get_msg_error(ret);
    return;
  }
  char data[100]{0};
  printf(data, "Client\n");
  std::int32_t iters{kIters};
  while (iters--) {
    char data[kDataBufferSize];
    memset(data, 0, sizeof(data));
    char msg_for_remot[]{"I am a client.\n"};
    std::int32_t client_msg_lenth{sizeof(msg_for_remot)};
    ciaa_size_t lenth{sizeof(std::int32_t)};
    memcpy(data, &client_msg_lenth, lenth);
    if ((ret = dev_->write(100, data, &lenth)) != ciaaErrorCode::OK) {
    std::fprintf(stderr, "%s\n", dev_->get_msg_error(ret).c_str());
#ifdef USE_BOOST_ASIO_WITH_CMAKE_BUG
    std::printf("checking transitioned... %d\n", lenth);
#else
    std::printf("checking transitioned... %lld\n", lenth);
#endif
    dev_->disconnect(100);
    return;
    }
    memset(data, 0, sizeof(data));
    memcpy(data, msg_for_remot, sizeof(msg_for_remot));
    lenth = sizeof(msg_for_remot);
    if ((ret = dev_->write(100, data, &lenth)) != ciaaErrorCode::OK) {
    std::fprintf(stderr, "%s\n", dev_->get_msg_error(ret).c_str());
#ifdef USE_BOOST_ASIO_WITH_CMAKE_BUG
    std::printf("checking transitioned... %d\n", lenth);
#else
    std::printf("checking transitioned... %lld\n", lenth);
#endif
    dev_->disconnect(100);
    return;
    }

    memset(data, 0, sizeof(data));
    lenth = sizeof(std::int32_t);
    if ((ret = dev_->read(100, data, &lenth)) != ciaaErrorCode::OK) {
    std::fprintf(stderr, "%s\n", dev_->get_msg_error(ret).c_str());
#ifdef USE_BOOST_ASIO_WITH_CMAKE_BUG
    std::printf("checking transitioned... %d\n", lenth);
#else
    std::printf("checking transitioned... %lld\n", lenth);
#endif
    dev_->disconnect(100);
    return;
    }
    memcpy(&lenth, data, sizeof(std::int32_t));
    memset(data, 0, sizeof(data));
    if ((ret = dev_->read(100, data, &lenth)) != ciaaErrorCode::OK) {
    std::fprintf(stderr, "%s\n", dev_->get_msg_error(ret).c_str());
#ifdef USE_BOOST_ASIO_WITH_CMAKE_BUG
    std::printf("checking transitioned... %d\n", lenth);
#else
    std::printf("checking transitioned... %lld\n", lenth);
#endif
    dev_->disconnect(100);
    return;
    }
    printf("%s", data);
  }
  correct_ = true;
  dev_->disconnect(100);
}
