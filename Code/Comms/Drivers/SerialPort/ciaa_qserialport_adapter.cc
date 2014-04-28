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

// ciaaQSerialPortAdapter::ciaaQSerialPortAdapter(std::string device) {
//  CIAA_UNUSED_PARAM(device);
// }

ciaaQSerialPortAdapter::ciaaQSerialPortAdapter(
    std::string device,
    SerialPortAdaptor::BaudRate baudrt,
    SerialPortAdaptor::DataBits databs,
    SerialPortAdaptor::FlowControl flowctl,
    SerialPortAdaptor::Parity prt,
    SerialPortAdaptor::StopBits stbs) {
  serial_.setPortName(QString{device.c_str()});

  actived_baudrate_ = static_cast<QSerialPort::BaudRate>(baudrt);
  actived_databits_ = databits(databs);
  actived_flow_control_ = flow_control(flowctl);
  actived_parity_ = parity(prt);
  actived_stop_bits_ = stop_bits(stbs);
}

CommDriverErrorCode ciaaQSerialPortAdapter::connect(std::int32_t timeout) {
  // TODO<denisacostaq\@gmail.com>: todo
  CIAA_UNUSED_PARAM(timeout);
  if (serial_.open(QIODevice::ReadWrite)) {
    serial_.setBaudRate(static_cast<qint32>(actived_baudrate_));
    serial_.setDataBits(actived_databits_);
    serial_.setFlowControl(actived_flow_control_);
    serial_.setParity(actived_parity_);
    serial_.setStopBits(actived_stop_bits_);
    return CommDriverErrorCode::OK;
  } else {
    return CommDriverErrorCode::connection_error;
  }
}

CommDriverErrorCode ciaaQSerialPortAdapter::disconnect(std::int32_t timeout) {
  // TODO<denisacostaq\@gmail.com>: usar flush y wait
  CIAA_UNUSED_PARAM(timeout);

  serial_.close();
  return CommDriverErrorCode::OK;
}

CommDriverErrorCode ciaaQSerialPortAdapter::read(std::int32_t timeout,
                                                 char *data,
                                                 ciaa_size_t *n_bytes) {
  ciaa_size_t total_readed = serial_.read(data, *n_bytes);
  if (total_readed != *n_bytes &&  // IF NOT, all ok!
      total_readed >= 0) {  // IF NOT, is an error!
    if (serial_.waitForReadyRead(timeout)) {
      do {
        ciaa_size_t readed_in_transition =
            serial_.read(data + total_readed, *n_bytes - total_readed);

        if (readed_in_transition >= 0) {  // IF NOT, is an error!
          total_readed += readed_in_transition;
          if (total_readed == *n_bytes) break;
        } else {
          break;
        }
      } while (serial_.waitForReadyRead(timeout));
    }
  }

  if (total_readed == *n_bytes) {
    // std::cout << *n_bytes << " OKKKKK" << std::endl;
    return CommDriverErrorCode::OK;
  } else {
    // std::cout << *n_bytes << " FAIL" << std::endl;
    *n_bytes = total_readed;
    // TODO(<denisacostaq\@gmail.com>):
    return CommDriverErrorCode::read_error;
  }
}

CommDriverErrorCode ciaaQSerialPortAdapter::write(std::int32_t timeout,
                                                  const char *data,
                                                  ciaa_size_t *n_bytes) {
  ciaa_size_t total_writed = serial_.write(data, *n_bytes);
  // FIXME(denisacostaq@gmail.com): deberia ser esto en lugar de el
  // socket_.waitForBytesWritten(timeout); que hay en siguiente bloque ya que
  // si total_writed == *n_bytes es porque ya escribio todo.
//  if (total_writed != *n_bytes &&  // IF NOT, all ok!
//      total_writed >= 0) {  // IF NOT, is an error!
//       if (!socket_.waitForBytesWritten(timeout)) {
//        *n_bytes = total_writed;
//       }
//  }

  if (total_writed == *n_bytes) {
    serial_.waitForBytesWritten(timeout);
    return CommDriverErrorCode::OK;
  } else {
    *n_bytes = total_writed;
    // TODO(<denisacostaq\@gmail.com>):
    return CommDriverErrorCode::write_error;
  }
}
