/*! \brief Do not include this file directly in external modules.
    \file ciaa_boosttcp_adapter.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Sun Apr 27 22:20:34 CDT 2014

    \brief This file is part of Comms/Driversrnet module.
    \brief This file become from: Code/Comms/Drivers/Ethernet/ciaa_boosttcp_adapter.h

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

#include "Code/Comms/Drivers/ciaa_comm_adapter_interface.h"
#include "Code/config.h"  // NOLINT

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

  /*! \brief read Read n_bytes and put it into data.
   * \param timeout
   * \param data
   * \param n_bytes
   * \warning Is very important fot itself implementation try read first
   *  beacause if tha data are available the readyRead() signal no are performed
   *  beafore.
   * \return
   */
  CommDriverErrorCode read(std::int32_t timeout,
                           char *data,
                           ciaa_size_t *n_bytes) override;
  void read(std::int32_t timeout,
            const char *data,
            std::function<CommDriverErrorCode()> callback) {
        CIAA_UNUSED_PARAM(timeout);
        CIAA_UNUSED_PARAM(data);
        CIAA_UNUSED_PARAM(callback);
  }

  CommDriverErrorCode write(std::int32_t timeout,
                            const char *data,
                            ciaa_size_t *n_bytes) override;
  void write(std::int32_t timeout,
             const char *data,
             std::function<CommDriverErrorCode()> callback) {
        CIAA_UNUSED_PARAM(timeout);
        CIAA_UNUSED_PARAM(data);
        CIAA_UNUSED_PARAM(callback);
  }

 private:
  QTcpSocket socket_;
  QString host_;
  quint16 port_;
};

#endif  // COMMS_DRIVERS_ETHERNET_QTCPSOCKET_ADAPTER_H
