/*! \brief This file gives a ciaaBASerialPortAdapter functionality.
    \file ciaa_drivers_baserialport_adapter.cc
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Sun Apr 27 23:20:13 CDT 2014

    \brief This file is part of Comms/Driversrnet module.
    \brief This file become from: Code/Comms/Drivers/SerialPort/ciaa_drivers_baserialport_adapter.cc

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

#include "Code/Comms/Drivers/SerialPort/ciaa_drivers_baserialport_adapter.h"

namespace ciaa {
namespace comms {
namespace drivers {
ciaaBASerialPortAdapter::ciaaBASerialPortAdapter(
    std::string device,
    SerialPortAdaptor::BaudRate baudrt,
    SerialPortAdaptor::DataBits databs,
    SerialPortAdaptor::FlowControl flowctl,
    SerialPortAdaptor::Parity prt,
    SerialPortAdaptor::StopBits stbs)
  : device_{device}
  , io_service_{}
  , serial_{io_service_}
  , deadline_{io_service_} {
    actived_baudrate_ = static_cast<ba::serial_port::baud_rate>(
          static_cast<unsigned int>(baudrt));
    actived_databits_ = databits(databs);
    actived_flow_control_ = flow_control(flowctl);
    actived_parity_ = parity(prt);
    actived_stop_bits_ = stop_bits(stbs);

    deadline_.expires_at(boost::posix_time::pos_infin);
    this->check_deadline();
}
}  // namespace drivers
}  // namespace comms
}  // namespace ciaa
