/*! \brief Do not include this file directly in external modules.
    \file ciaa_qtcpsocket_adapter.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Fri Mar 21 00:44:09 CDT 2014

    \brief This file is part of Comms/Ethernet module.
    \brief This file become from: Code/Comms/Drivers/Ethernet/ciaa_qtcpsocket_adapter.h

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

#include <cstdlib>
#include <iostream>//FIXME<denisacostaq\@gmail.com>:

#include <QtNetwork/QTcpSocket>

#include "Comms/Drivers/ciaa_comm_adapter_interface.h"

/*! \brief TODO<denisacostaq\@gmail.com>
 * \brief The ciaaQtcpSocketAdapter class
 * \ingroup Ethernet
 */
class ciaaQtcpSocketAdapter : public ciaaCommAdapterInterface
{
  public:
    ciaaQtcpSocketAdapter(std::string host, u_int16_t port);
    ~ciaaQtcpSocketAdapter() = default;

    ciaaQtcpSocketAdapter(const ciaaQtcpSocketAdapter&) = delete;
    ciaaQtcpSocketAdapter& operator=(const ciaaQtcpSocketAdapter&) = delete;

    ciaaQtcpSocketAdapter(const ciaaQtcpSocketAdapter&&) = delete;
    ciaaQtcpSocketAdapter& operator=(const ciaaQtcpSocketAdapter&&) = delete;

    CommDriverErrorCode connect(int32_t timeout) override;
    CommDriverErrorCode disconnect(int32_t timeout) override;
    CommDriverErrorCode read(int32_t timeout, char *data, int *n_bytes) override;
    CommDriverErrorCode write(int32_t timeout, const char *data, int *n_bytes) override;

  private:
    QTcpSocket socket_;
    QString host_;
    quint16 port_;
};

#endif // COMMS_DRIVERS_ETHERNET_QTCPSOCKET_ADAPTER_H
