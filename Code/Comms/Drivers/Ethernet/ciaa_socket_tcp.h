/*! \brief Do not include this file directly in external modules.
    \file ciaa_socket_tcp.h
    \author Ezequiel Esposito <ejesposito\@debtech.com.ar>
    \date Thu Jan 9 14:28:58 CDT 2014

    \brief This file is part of Comms/Ethernet module.
    \brief This file become from: Comms/Drivers/Ethernet/ciaa_socket_tcp.h

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


#ifndef COMMS_DRIVERS_ETHERNET_SOCKETTCP_H
#define COMMS_DRIVERS_ETHERNET_SOCKETTCP_H

#include "Comms/Drivers/ciaa_comm_interface.h"
#include "Comms/Drivers/Ethernet/ciaa_qtcpsocket_adapter.h"

/*! \brief TODO <denisacostaq\@gmail.com>
 * \brief The ciaaSocket class
 * \ingroup Ethernet
 */
class ciaaSocketTCP : public ciaaCommInterface
{
public:
    ciaaSocketTCP(std::string host, std::uint16_t port);
    ~ciaaSocketTCP();

    ciaaSocketTCP(const ciaaSocketTCP&) = delete;
    ciaaSocketTCP& operator=(const ciaaSocketTCP&) = delete;

    ciaaSocketTCP(const ciaaSocketTCP&&) = delete;
    ciaaSocketTCP& operator=(const ciaaSocketTCP&&) = delete;

    inline CommDriverErrorCode connect(std::int32_t timeout) const override {
      return socket_->connect(timeout) ;
    }

    inline CommDriverErrorCode disconnect(std::int32_t timeout) const override {
      return socket_->disconnect(timeout);
    }

    inline CommDriverErrorCode read(std::int32_t timeout,
                                    char *data,
                                    std::int32_t *n_bytes) const override {
      return socket_->read(timeout, data, n_bytes);
    }

    inline CommDriverErrorCode write(std::int32_t timeout,
                                     const char *data,
                                     std::int32_t *n_bytes) const override {
      return socket_->write(timeout, data, n_bytes) ;
    }


  private:
    ciaaQtcpSocketAdapter *socket_;
};

#endif // COMMS_DRIVERS_ETHERNET_SOCKETTCP_H
