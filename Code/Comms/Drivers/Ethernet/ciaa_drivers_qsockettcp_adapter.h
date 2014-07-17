/*! \brief Do not include this file directly in external modules.
    \file ciaa_drivers_qsockettcp_adapter.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Sun Apr 27 22:20:34 CDT 2014

    \brief This file is part of Comms/Driversrnet module.
    \brief This file become from: Code/Comms/Drivers/Ethernet/ciaa_drivers_qsockettcp_adapter.h

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

#ifndef COMMS_DRIVERS_ETHERNET_QTCPSOCKET_ADAPTER_H
#define COMMS_DRIVERS_ETHERNET_QTCPSOCKET_ADAPTER_H

#include <iostream>  // FIXME(denisacostaq\@gmail.com):
#include <functional>

#include <QtNetwork/QTcpSocket>

#include "Code/Comms/Drivers/ciaa_drivers_qiodevice_adapter.h"
#include "Code/config.h"  // NOLINT

namespace ciaa {
namespace comms {
namespace drivers {
/*! \brief TODO<denisacostaq\@gmail.com>
 * \brief The ciaaDriversQSocketTCPAdapater class
 * \ingroup Ethernet
 */
class ciaaDriversQSocketTCPAdapater : public ciaaDriversQIODeviceAdapter {
  // TODO(denisacostaq@gmail.com): ciaaDriversQSerialPortAdapter ->
  // ciaaDriversQSocketTCPAdapater !ciaaDriversQSocketTCPAdapater == udp
 public:
  ciaaDriversQSocketTCPAdapater(std::string host, std::uint16_t port);
  ~ciaaDriversQSocketTCPAdapater() = default;

  ciaaDriversQSocketTCPAdapater(const ciaaDriversQSocketTCPAdapater&) = delete;
  ciaaDriversQSocketTCPAdapater& operator=(
      const ciaaDriversQSocketTCPAdapater&) = delete;

  ciaaDriversQSocketTCPAdapater(const ciaaDriversQSocketTCPAdapater&&) = delete;
  ciaaDriversQSocketTCPAdapater& operator=(
      const ciaaDriversQSocketTCPAdapater&&) = delete;

  ciaaDriversErrorCode connect(std::chrono::milliseconds timeout) override;
  ciaaDriversErrorCode disconnect(std::chrono::milliseconds timeout) override;

 private:
  QString host_;
  quint16 port_;
  QTcpSocket socket_;
};
}  // namespace drivers
}  // namespace comms
}  // namespace ciaa
#endif  // COMMS_DRIVERS_ETHERNET_QTCPSOCKET_ADAPTER_H
