/*! \brief Do not include this file directly in external modules.
    \file ciaa_qserialport_adapter.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Fri Mar 21 00:46:11 CDT 2014

    \brief This file is part of Comms/SerialPort module.
    \brief This file become from: Code/Comms/Drivers/SerialPort/ciaa_qserialport_adapter.h

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

#ifndef COMMS_DRIVERS_QSERIALPORT_ADAPTER_H
#define COMMS_DRIVERS_QSERIALPORT_ADAPTER_H

#include <QtSerialPort/QtSerialPort>

#include "Comms/Drivers/ciaa_comm_adapter_interface.h"

/*! \brief TODO<denisacostaq\@gmail.com>
 * \brief The ciaaQSerialPortAdapter class
 * \ingroup SerialPort
 */
class ciaaQSerialPortAdapter : public ciaaCommAdapterInterface
{
  public:
    ciaaQSerialPortAdapter(std::string device);
    ~ciaaQSerialPortAdapter() = default;

    ciaaQSerialPortAdapter(const ciaaQSerialPortAdapter&) = delete;
    ciaaQSerialPortAdapter& operator=(const ciaaQSerialPortAdapter&) = delete;

    ciaaQSerialPortAdapter(const ciaaQSerialPortAdapter&&) = delete;
    ciaaQSerialPortAdapter& operator=(const ciaaQSerialPortAdapter&&) = delete;

    CommDriverErrorCode connect(std::int32_t timeout) override;
    CommDriverErrorCode disconnect(std::int32_t timeout) override;
    CommDriverErrorCode read(std::int32_t timeout,
                             char *data,
                             std::int32_t *n_bytes) override;
    CommDriverErrorCode write(std::int32_t timeout,
                              const char *data,
                              std::int32_t *n_bytes) override;

    QSerialPort serial_;
};

#endif // COMMS_DRIVERS_QSERIALPORT_ADAPTER_H
