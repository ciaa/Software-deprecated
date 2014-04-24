/*! \brief Do not include this file directly in external modules.
    \file ciaa_qtcpsocket_adapter.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Fri Mar 21 00:44:09 CDT 2014

    \brief This file is part of Comms/Ethernet module.
    \brief This file become from: Code/Comms/Drivers/Ethernet/ciaa_qtcpsocket_adapter.h

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

#include <iostream>  // FIXME<denisacostaq\@gmail.com>:

#include <QtNetwork/QTcpSocket>

#include "Comms/Drivers/ciaa_comm_adapter_interface.h"

/*! \brief TODO<denisacostaq\@gmail.com>
 * \brief The ciaaQtcpSocketAdapter class
 * \ingroup Ethernet
 */
class ciaaQtcpSocketAdapter : public ciaaCommAdapterInterface {
  // TODO<denisacostaq@gmail.com>: ciaaQSerialPortAdapter ->
  // ciaaQTCPSocketAdapter !ciaaQtcpSocketAdapter == udp
 public:
  ciaaQtcpSocketAdapter(std::string host, std::uint16_t port);
  ~ciaaQtcpSocketAdapter() = default;

  ciaaQtcpSocketAdapter(const ciaaQtcpSocketAdapter&) = delete;
  ciaaQtcpSocketAdapter& operator=(const ciaaQtcpSocketAdapter&) = delete;

  ciaaQtcpSocketAdapter(const ciaaQtcpSocketAdapter&&) = delete;
  ciaaQtcpSocketAdapter& operator=(const ciaaQtcpSocketAdapter&&) = delete;

  CommDriverErrorCode connect(std::int32_t timeout) override;
  CommDriverErrorCode disconnect(std::int32_t timeout) override;
  CommDriverErrorCode read(std::int32_t timeout,
                           char *data,
                           std::int32_t *n_bytes) override;
  CommDriverErrorCode write(std::int32_t timeout,
                            const char *data,
                            std::int32_t *n_bytes) override;

 private:
  QTcpSocket socket_;
  QString host_;
  quint16 port_;
};

#endif  // COMMS_DRIVERS_ETHERNET_QTCPSOCKET_ADAPTER_H
