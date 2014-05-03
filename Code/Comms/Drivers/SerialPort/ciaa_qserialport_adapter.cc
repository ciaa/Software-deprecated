/*! \brief This file gives a ciaaQSerialPortAdapter functionality.
    \file ciaa_qserialport_adapter.cc
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Fri Mar 21 00:46:11 CDT 2014

    \brief This file is part of Comms/Driversrnet module.
    \brief This file become from: Code/Comms/Drivers/SerialPort/ciaa_qserialport_adapter.cc

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

#include "Code/Comms/Drivers/SerialPort/ciaa_qserialport_adapter.h"

namespace ciaa {
  namespace comms {
    namespace drivers {
      // ciaaQSerialPortAdapter::ciaaQSerialPortAdapter(std::string device) {
      //  CIAA_UNUSED_PARAM(device);
      // }

      ciaaQSerialPortAdapter::ciaaQSerialPortAdapter(
          std::string device,
          SerialPortAdaptor::BaudRate baudrt,
          SerialPortAdaptor::DataBits databs,
          SerialPortAdaptor::FlowControl flowctl,
          SerialPortAdaptor::Parity prt,
          SerialPortAdaptor::StopBits stbs)
        : ciaaCommQIODeviceAdapter{&serial_} {
        serial_.setPortName(QString{device.c_str()});

        actived_baudrate_ = static_cast<QSerialPort::BaudRate>(baudrt);
        actived_databits_ = databits(databs);
        actived_flow_control_ = flow_control(flowctl);
        actived_parity_ = parity(prt);
        actived_stop_bits_ = stop_bits(stbs);
      }

      ciaaErrorCode ciaaQSerialPortAdapter::connect(std::int32_t timeout) {
        // TODO<denisacostaq\@gmail.com>: todo
        CIAA_UNUSED_PARAM(timeout);
        if (serial_.open(QIODevice::ReadWrite)) {
          serial_.setBaudRate(static_cast<qint32>(actived_baudrate_));
          serial_.setDataBits(actived_databits_);
          serial_.setFlowControl(actived_flow_control_);
          serial_.setParity(actived_parity_);
          serial_.setStopBits(actived_stop_bits_);
          return ciaaErrorCode::OK;
        } else {
          return ciaaErrorCode::connection_error;
        }
      }

      ciaaErrorCode ciaaQSerialPortAdapter::disconnect(std::int32_t timeout) {
        // TODO<denisacostaq\@gmail.com>: usar flush y wait
        CIAA_UNUSED_PARAM(timeout);

        serial_.close();
        return ciaaErrorCode::OK;
      }
    }  // namespace ciaa
  }  // namespace comms
}  // namespace drivers
