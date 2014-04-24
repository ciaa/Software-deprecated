// \brief Do not include this file directly in external modules.
// \brief This file gives a className(TODO: \author) functionality.
/*! \brief This is the only file you need to include external modules to use the ModuleName(TODO).
    \file TODO
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Sun Apr  6 16:20:20 CDT 2014

    \brief This file is part of TODO:ModuleName module.
    \brief This file become from: TODO:Code/Comms/Drivers/ciaa_comm_facade.h

    \attention <h1><center>&copy; COPYRIGHT
    GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007</center></h1>

    \copyright

    <h3>This file is part of CIAA project (Computadora Industrial Argentina Abierta).</h3>
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

#include <memory>

#include "Comms/Protocols/Modbus/ciaa_modbus_master_rtu.h"
int main()
{
  std::unique_ptr<ciaaModbusMasterOverCommsInterface> over_serial{
    new ciaaModbusMasterOverSerial("/dev/ttyS0")};
  ciaaModbusMasterRTU::build(over_serial);

  return 0;
}


