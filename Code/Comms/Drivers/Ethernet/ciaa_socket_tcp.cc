/*! \brief This file gives a ciaaSocketTCP functionality.
    \file ciaa_socket_tcp.cc
    \author Ezequiel Esposito <ejesposito\@debtech.com.ar>
    \date Thu Jan 9 14:28:58 CDT 2014

    \brief This file is part of Comms/Driversrnet module.
    \brief This file become from: Comms/Drivers/Ethernet/ciaa_socket_tcp.cc

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


#include "Code/Comms/Drivers/Ethernet/ciaa_socket_tcp.h"

namespace ciaa {
  namespace comms {
    namespace drivers {
      ciaaSocketTCP::ciaaSocketTCP(std::string host, std::uint16_t port)
        : socket_{
      #ifdef USE_BOOST_ASIO
            new ciaaBoostAsiotcpSocketAdapter(host, port)
      #else
            new ciaaQtcpSocketAdapter{host, port}
      #endif
            } {
      }

      // ciaaSocketTCP::ciaaSocketTCP(std::string host, std::uint16_t port)
      //  : socket_{new ciaaBoostAsiotcpSocketAdapter{host, port}} {
      // }

      ciaaSocketTCP::~ciaaSocketTCP() {
        delete socket_;
      }
    }  // namespace ciaa
  }  // namespace comms
}  // namespace drivers
