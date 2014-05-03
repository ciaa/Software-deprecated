/*! \brief Do not include this file directly in external modules.
    \file ciaa_comm_drivers_serial_config.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Mon Apr 28 00:57:42 CDT 2014

    \brief This are some enums for serial por configuration.
    \brief This file is part of Comms Drivers module.
    \brief This file become from: Code/Comms/Drivers/SerialPort/ciaa_comm_drivers_serial_config.h

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

#ifndef COMM_DRIVER_SERIALPORT_CONFIG_H
#define COMM_DRIVER_SERIALPORT_CONFIG_H

// enum Direction  {
//    Input = 1,
//    Output = 2,
//    AllDirections = Input | Output
// };

//  FIXME(denisacostaq@gmail.com): esto hay que quitarlo
struct SerialPortAdaptor {
 public:
  enum class BaudRate {
      Baud1200 = 1200,
      Baud2400 = 2400,
      Baud4800 = 4800,
      Baud9600 = 9600,
      Baud19200 = 19200,
      Baud38400 = 38400,
      Baud57600 = 57600,
      Baud115200 = 115200,
      UnknownBaud = -1  // TODO(denisacostaq\@gmail.com): remove this option
  };

  enum class DataBits {
      Data5 = 5,
      Data6 = 6,
      Data7 = 7,
      Data8 = 8,
      UnknownDataBits = -1  // TODO(denisacostaq\@gmail.com): remove this option
  };

  enum class Parity {
      NoParity = 0,
      EvenParity = 2,
      OddParity = 3,
      SpaceParity = 4,
      MarkParity = 5,
      UnknownParity = -1  // TODO(denisacostaq\@gmail.com): remove this option
  };

  enum class StopBits {
      OneStop = 1,
      OneAndHalfStop = 3,
      TwoStop = 2,
      UnknownStopBits = -1  // TODO(denisacostaq\@gmail.com): remove this option
  };

  enum class FlowControl {
      NoFlowControl,
      HardwareControl,
      SoftwareControl,
      UnknownFlowControl = -1  // TODO(denisacostaq\@gmail.com): remove this option
  };
};

#endif  // COMM_DRIVER_SERIALPORT_CONFIG_H
