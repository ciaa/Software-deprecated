/*! \brief This file gives a ciaaCommFacade functionality.
    \file ciaa_comm_facade.cc
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Thu Jan 9 14:28:58 CDT 2014

    \brief This file is part of Comms module.
    \brief This file become from: Code/Comms/Drivers/ciaa_comm_facade.cc

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

#include "Code/Comms/Drivers/ciaa_comm_facade.h"

ciaaCommFacade::ciaaCommFacade(std::string host, std::uint16_t port)
  : transporter_{new ciaaSocketTCP{host, port}} {
}

ciaaCommFacade::ciaaCommFacade(std::string device,
                               SerialPortAdaptor::BaudRate baudrt,
                               SerialPortAdaptor::DataBits databs,
                               SerialPortAdaptor::FlowControl flowctl,
                               SerialPortAdaptor::Parity prt,
                               SerialPortAdaptor::StopBits stbs)
  : transporter_{new ciaaSerialPort{device, baudrt, databs, flowctl, prt, stbs}} {  // NOLINT(whitespace/line_length)
}

ciaaCommFacade::~ciaaCommFacade() {
  delete transporter_;
}
