/*! \brief This file gives a ciaaQtcpSocketAdapter functionality.
    \file ciaa_qtcpsocket_adapter.cc
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Fri Mar 21 00:44:09 CDT 2014

    \brief This file is part of Comms/Driversrnet module.
    \brief This file become from: Code/Comms/Drivers/Ethernet/ciaa_qtcpsocket_adapter.cc

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

#include "Code/Comms/Drivers/Ethernet/ciaa_qtcpsocket_adapter.h"

ciaaQtcpSocketAdapter::ciaaQtcpSocketAdapter(std::string host,
                                             std::uint16_t port)
  : host_{host.c_str()}
  , port_(port) {
}

CommDriverErrorCode ciaaQtcpSocketAdapter::connect(std::int32_t timeout) {
  // TODO<denisacostaq\@gmail.com>: socket_.reset() || others
  socket_.connectToHost(host_, port_);
  socket_.waitForConnected(timeout);
  if (socket_.state() == QAbstractSocket::SocketState::ConnectedState) {
    return CommDriverErrorCode::OK;
  }
  return CommDriverErrorCode::connection_error;
}

CommDriverErrorCode ciaaQtcpSocketAdapter::disconnect(std::int32_t timeout) {
  socket_.disconnectFromHost();
  if (socket_.state() == QAbstractSocket::ConnectedState) {
    socket_.waitForDisconnected(timeout);
  }
  if (socket_.state() == QAbstractSocket::UnconnectedState) {
    return CommDriverErrorCode::OK;
  }
  // TODO(denisacostaq\@gmail.com): socket_.reset()
  return CommDriverErrorCode::disconnect_error;
}

  // FIXME(denisacostaq\@gmail.com): arreglar esto, ver el .h \warning
CommDriverErrorCode ciaaQtcpSocketAdapter::read(std::int32_t timeout,
                                                char *data,
                                                ciaa_size_t *n_bytes) {
    ciaa_size_t total_readed = socket_.read(data, *n_bytes);
    if (total_readed != *n_bytes &&  // IF NOT, all ok!
        total_readed >= 0) {  // IF NOT, is an error!
      if (socket_.waitForReadyRead(timeout)) {
        do {
          ciaa_size_t readed_in_transition =
              socket_.read(data + total_readed, *n_bytes - total_readed);

          if (readed_in_transition >= 0) {  // IF NOT, is an error!
            total_readed += readed_in_transition;
            if (total_readed == *n_bytes) break;
          } else {
            break;
          }
        } while (socket_.waitForReadyRead(timeout));
      }
    }

    if (total_readed == *n_bytes) {
      //std::cout << *n_bytes << " OKKKKK" << std::endl;
      return CommDriverErrorCode::OK;
    } else {
      //std::cout << *n_bytes << " FAIL" << std::endl;
      *n_bytes = total_readed;
      //TODO(<denisacostaq\@gmail.com>):
      return CommDriverErrorCode::read_error;
    }
}

CommDriverErrorCode ciaaQtcpSocketAdapter::write(std::int32_t timeout,
                                                 const char *data,
                                                 ciaa_size_t *n_bytes) {
  ciaa_size_t total_writed = socket_.write(data, *n_bytes);
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
    socket_.waitForBytesWritten(timeout);
    return CommDriverErrorCode::OK;
  } else {
    *n_bytes = total_writed;
    //TODO(<denisacostaq\@gmail.com>):
    return CommDriverErrorCode::write_error;
  }
}
