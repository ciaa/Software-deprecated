/*! \brief Do not include this file directly in external modules.
    \file ciaa_serial_port.h
    \author Ezequiel Esposito <ejesposito\@debtech.com.ar>
    \date Thu Jan 9 14:28:58 CDT 2014

    \brief This file is for the ethernet communication in the Comms module.
    \brief This file become from: Comms/Drivers/SerialPort/ciaa_serial_port.h

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


#ifndef COMMS_DRIVERS_SERIALPORT_H
#define COMMS_DRIVERS_SERIALPORT_H

#include "Code/Comms/Drivers/ciaa_comm_interface.h"
#include "Code/Comms/Drivers/SerialPort/ciaa_qserialport_adapter.h"
//#include "Code/Comms/Drivers/SerialPort/ciaa_boostserialport_adapter.h"

/*! \brief ciaaSerialPort is a class for the Serial Port communication.
 *  \ingroup SerialPort
 *  \brief This class is for the Serial Port communication using RS-232
 *  \brief standard(ANSI/EIA­232) in the Comms module.
 * \ingroup SerialPort
 */
class ciaaSerialPort : public ciaaCommInterface {
 public:
  explicit ciaaSerialPort(std::string device,
                          SerialPortAdaptor::BaudRate baudrt,
                          SerialPortAdaptor::DataBits databs,
                          SerialPortAdaptor::FlowControl flowctl,
                          SerialPortAdaptor::Parity prt,
                          SerialPortAdaptor::StopBits stbs);
  ~ciaaSerialPort();

  ciaaSerialPort(const ciaaSerialPort&) = delete;
  ciaaSerialPort& operator=(const ciaaSerialPort&) = delete;

  ciaaSerialPort(const ciaaSerialPort&&) = delete;
  ciaaSerialPort& operator=(const ciaaSerialPort&&) = delete;

  inline CommDriverErrorCode connect(std::int32_t timeout) const override {
    return serial_->connect(timeout) ;
  }

  inline CommDriverErrorCode disconnect(std::int32_t timeout) const override {
    return serial_->disconnect(timeout);
  }

  inline CommDriverErrorCode read(std::int32_t timeout,
                                  char *data,
                                  ciaa_size_t *n_bytes) const override {
    return serial_->read(timeout, data, n_bytes);
  }

  inline CommDriverErrorCode write(std::int32_t timeout,
                                   const char *data,
                                   ciaa_size_t *n_bytes) const override {
    return serial_->write(timeout, data, n_bytes) ;
  }


 private:
  ciaaQSerialPortAdapter *serial_;
  //ciaaBoostSerialPortAdapter *serial_;
};

#endif  // COMMS_DRIVERS_SERIALPORT_H
