/*! \brief Do not include this file directly in external modules.
    \file ciaa_comm_adapter_interface.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Fri Mar 21 00:32:43 CDT 2014

    \brief This file is part of Comms module.
    \brief This file become from: Code/Comms/Drivers/ciaa_comm_adapter_interface.h

    \attention <h1><center>&copy; COPYRIGHT
    GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007</center></h1>

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

#ifndef COMMS_DRIVERS_ADAPTER_INTERFACE_H
#define COMMS_DRIVERS_ADAPTER_INTERFACE_H

#include <cstdint>

#include "Defines/ciaaGlobalMacros.h"
#include "Comms/Drivers/ciaa_comm_drivers_config.h" //NOLINT
#include "Comms/Drivers/ciaa_comm_driver_error_code.h"

/*!
 * \brief The ciaaCommAdapterInterface class is a common innterface for the
 * adaptor pattern.
 * \ingroup Drivers
 */
class ciaaCommAdapterInterface {
 public:
  ciaaCommAdapterInterface() = default;
  virtual ~ciaaCommAdapterInterface() = default;

  ciaaCommAdapterInterface(const ciaaCommAdapterInterface&) = delete;
  ciaaCommAdapterInterface& operator=(const ciaaCommAdapterInterface&) = delete;

  ciaaCommAdapterInterface(const ciaaCommAdapterInterface&&) = delete;
  ciaaCommAdapterInterface& operator=(const ciaaCommAdapterInterface&&) =delete;

  virtual CommDriverErrorCode connect(std::int32_t timeout) = 0;
  virtual CommDriverErrorCode disconnect(std::int32_t timeout) = 0;
  virtual CommDriverErrorCode read(std::int32_t timeout,
                                   char *data,
                                   ciaa_size_t *n_bytes) = 0;
  virtual CommDriverErrorCode write(std::int32_t timeout,
                                    const char *data,
                                    ciaa_size_t *n_bytes) = 0;
};

#endif  // COMMS_DRIVERS_ADAPTER_INTERFACE_H
