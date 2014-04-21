/*! \brief This file gives a ciaaQtcpSocketAdapter functionality.
    \file ciaa_qtcpsocket_adapter.cc
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Fri Mar 21 00:44:09 CDT 2014

    \brief This file is part of Comms/Ethernet module.
    \brief This file become from: Code/Comms/Drivers/Ethernet/ciaa_qtcpsocket_adapter.cc

    \attention <h1><center>&copy; COPYRIGHT
    GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007</center></h1>

    \copyright

    <h3>
      This file is part of
      <a class="el" href="http://proyecto-ciaa.com.ar">
        <h3>
          CIAA project (Computadora Industrial Argentina Abierta).
        </h3>
      </a>
    </h3>
    Copyright (C) 2014 Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>

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

ciaaQtcpSocketAdapter::ciaaQtcpSocketAdapter(std::string host, u_int16_t port)
  : host_{host.c_str()}
  , port_(port)
{
}

CommDriverErrorCode ciaaQtcpSocketAdapter::connect(int32_t timeout)
{
  //TODO<denisacostaq\@gmail.com>: some
  socket_.connectToHost(host_, port_);
  socket_.waitForConnected(timeout);
  if (socket_.state() == QAbstractSocket::SocketState::ConnectedState)
  {
    return CommDriverErrorCode::Ok;
  }
  {
    qDebug() << "yop: " << socket_.errorString();
    return CommDriverErrorCode::connection_error;
  }
}

CommDriverErrorCode ciaaQtcpSocketAdapter::disconnect(int32_t timeout)
{
  //TODO<denisacostaq\@gmail.com>: todo
  return CommDriverErrorCode::Ok;
}

CommDriverErrorCode ciaaQtcpSocketAdapter::read(int32_t timeout,
                                                char *data,
                                                int *n_bytes)
{
  //TODO<denisacostaq\@gmail.com>: todo
  return CommDriverErrorCode::Ok;
}

CommDriverErrorCode ciaaQtcpSocketAdapter::write(int32_t timeout,
                                                 const char *data,
                                                 int *n_bytes)
{
  //TODO<denisacostaq\@gmail.com>: todo
  return CommDriverErrorCode::Ok;
}
