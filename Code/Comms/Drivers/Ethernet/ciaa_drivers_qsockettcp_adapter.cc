/*! \brief This file gives a ciaaDriversQSocketTCPAdapater functionality.
    \file ciaa_drivers_qsockettcp_adapter.cc
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Fri Mar 21 00:44:09 CDT 2014

    \brief This file is part of Comms/Driversrnet module.
    \brief This file become from: Code/Comms/Drivers/Ethernet/ciaa_drivers_qsockettcp_adapter.cc

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

#include "Code/Comms/Drivers/Ethernet/ciaa_drivers_qsockettcp_adapter.h"

namespace ciaa {
namespace comms {
namespace drivers {
ciaaDriversQSocketTCPAdapater::ciaaDriversQSocketTCPAdapater(std::string host,
                                             std::uint16_t port)
  : ciaaDriversQIODeviceAdapter{&socket_},
    host_{host.c_str()},
    port_(port) {
}

ciaaDriversErrorCode ciaaDriversQSocketTCPAdapater::connect(
    std::int32_t timeout) {
  // TODO<denisacostaq\@gmail.com>: socket_reset() || others
  socket_.connectToHost(host_, port_);
  socket_.waitForConnected(timeout);
  if (socket_.state() == QAbstractSocket::SocketState::ConnectedState) {
    return ciaaDriversErrorCode::OK;
  }
  return ciaaDriversErrorCode::connection_error;
}

ciaaDriversErrorCode ciaaDriversQSocketTCPAdapater::disconnect(
    std::int32_t timeout) {
  socket_.disconnectFromHost();
  if (socket_.state() == QAbstractSocket::ConnectedState) {
    socket_.waitForDisconnected(timeout);
  }
  if (socket_.state() == QAbstractSocket::UnconnectedState) {
    return ciaaDriversErrorCode::OK;
  }
  // TODO(denisacostaq\@gmail.com): socket_reset()
  return ciaaDriversErrorCode::disconnect_error;
}
}  // namespace drivers
}  // namespace comms
}  // namespace ciaa
