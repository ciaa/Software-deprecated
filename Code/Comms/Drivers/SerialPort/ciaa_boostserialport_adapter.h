/*! \brief Do not include this file directly in external modules.
    \file ciaa_qserialport_adapter.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Sun Apr 27 23:20:13 CDT 2014

    \brief This file is part of Comms/SerialPort module.
    \brief This file become from: Code/Comms/Drivers/SerialPort/ciaa_qserialport_adapter.h

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

#include "Code/Comms/Drivers/ciaa_comm_adapter_interface.h"

class ciaaBoostSerialPortAdapter : public ciaaCommAdapterInterface {
 public:
  explicit ciaaBoostSerialPortAdapter(std::string device);
  ~ciaaBoostSerialPortAdapter() = default;

  ciaaBoostSerialPortAdapter(const ciaaBoostSerialPortAdapter&) = delete;
  ciaaBoostSerialPortAdapter& operator=(const ciaaBoostSerialPortAdapter&) = delete;  // NOLINT(whitespace/line_length)

  ciaaBoostSerialPortAdapter(const ciaaBoostSerialPortAdapter&&) = delete;
  ciaaBoostSerialPortAdapter& operator=(
      const ciaaBoostSerialPortAdapter&&) = delete;

  CommDriverErrorCode connect(std::int32_t timeout) override {
    CIAA_UNUSED_PARAM(timeout);
    return CommDriverErrorCode::OK;
  }

  CommDriverErrorCode disconnect(std::int32_t timeout) override {
    CIAA_UNUSED_PARAM(timeout);
    return CommDriverErrorCode::OK;
  }
  CommDriverErrorCode read(std::int32_t timeout,
                           char *data,
                           ciaa_size_t *n_bytes) override {
    CIAA_UNUSED_PARAM(timeout);
    CIAA_UNUSED_PARAM(n_bytes);
    CIAA_UNUSED_PARAM(data);
    return CommDriverErrorCode::OK;
  }

  CommDriverErrorCode write(std::int32_t timeout,
                            const char *data,
                            ciaa_size_t *n_bytes) override {
    CIAA_UNUSED_PARAM(timeout);
    CIAA_UNUSED_PARAM(n_bytes);
    CIAA_UNUSED_PARAM(data);
    return CommDriverErrorCode::OK;
  }

// boost::asio::io_service serial_;
};
