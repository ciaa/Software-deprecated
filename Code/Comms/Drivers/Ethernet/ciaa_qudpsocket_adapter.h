/*! \brief Do not include this file directly in external modules.
    \file ciaa_qudpsocket_adapter.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Sun Apr  6 16:42:12 CDT 2014

    \brief This file is part of Comms/Ethernet module.
    \brief This file become from: Code/Comms/Drivers/Ethernet/ciaa_qudpsocket_adapter.h

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

#ifndef COMMS_DRIVERS_ETHERNET_QUDPSOCKET_ADAPTER_H
#define COMMS_DRIVERS_ETHERNET_QUDPSOCKET_ADAPTER_H

#include "Comms/Drivers/ciaa_comm_adapter_interface.h"

class ciaaQudpSocketAdapater : public ciaaCommAdapterInterface
{
  public:
    ciaaQudpSocketAdapater() = delete;
    ~ciaaQudpSocketAdapater() = default;

    ciaaQudpSocketAdapater(const ciaaQudpSocketAdapater&) = delete;
    ciaaQudpSocketAdapater& operator =(const ciaaQudpSocketAdapater&) = delete;

    ciaaQudpSocketAdapater(const ciaaQudpSocketAdapater&&) = delete;
    ciaaQudpSocketAdapater& operator =(const ciaaQudpSocketAdapater&&) = delete;
};

#endif // COMMS_DRIVERS_ETHERNET_QUDPSOCKET_ADAPTER_H
