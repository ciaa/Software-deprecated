/*! \brief This file gives a ciaaQtcpSocketAdapter functionality.
    \file ciaa_qtcpsocket_adapter.cc
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Fri Mar 21 00:44:09 CDT 2014

    \brief This file is part of Comms/Ethernet module.
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

#include "Comms/Drivers/Ethernet/ciaa_qtcpsocket_adapter.h"

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
  // TODO<denisacostaq\@gmail.com>: socket_.reset()
  return CommDriverErrorCode::disconnect_error;
}

  // FIXME<denisacostaq\@gmail.com>: arreglar esto, ver el .h \warning
CommDriverErrorCode ciaaQtcpSocketAdapter::read(std::int32_t timeout,
                                                char *data,
                                                ciaa_size_t *n_bytes) {
  std::int32_t lenth = socket_.read(data, *n_bytes);
  if (lenth == 0) {
    if (socket_.waitForReadyRead(timeout)) {
      std::int32_t lenth = socket_.read(data, *n_bytes);
      if (lenth == *n_bytes) {
        return CommDriverErrorCode::OK;
      } else {
        *n_bytes = lenth;
        return CommDriverErrorCode::read_error;
      }
    } else {
      *n_bytes = 0;
      if (socket_.state() != QAbstractSocket::SocketState::ConnectedState) {
        return CommDriverErrorCode::connection_error;
      } else {
        // En relidad pudiera ser error tambien.
        return CommDriverErrorCode::timeout_error;
      }
    }
  }
  return CommDriverErrorCode::OK;
}

CommDriverErrorCode ciaaQtcpSocketAdapter::write(std::int32_t timeout,
                                                 const char *data,
                                                 ciaa_size_t *n_bytes) {
  std::int32_t lenth = socket_.write(data, *n_bytes);
  if (socket_.waitForBytesWritten(timeout)) {
    if (*n_bytes == lenth) {
      return CommDriverErrorCode::OK;
    } else {
      *n_bytes = lenth;
      return CommDriverErrorCode::write_error;
    }
  } else {
    *n_bytes = 0;
    if (socket_.state() != QAbstractSocket::SocketState::ConnectedState) {
      return CommDriverErrorCode::connection_error;
    } else {
      // En relidad pudiera ser error tambien.
      return CommDriverErrorCode::timeout_error;
    }
  }
}
