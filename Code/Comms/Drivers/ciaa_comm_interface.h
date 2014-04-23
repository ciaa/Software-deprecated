/*! \brief Do not include this file directly in external modules.
    \file ciaa_comm_interface.h
    \author Ezequiel Esposito <ejesposito\@debtech.com.ar>
    \date Thu Jan 9 14:28:58 CDT 2014

    \brief This file is part of Comms module.
    \brief This file become from: Code/Comms/Drivers/ciaa_comm_interface.h

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

#ifndef CIAA_COMM_INTERFACE_H
#define CIAA_COMM_INTERFACE_H

#include <cstdint>

#include "Comms/Drivers/ciaa_comm_driver_error_code.h"
/*!
 * \brief The ciaaCommInterface class is a common innterface for the Drivers module
 * \ingroup Drivers
 */
class ciaaCommInterface
{
  public:
    ciaaCommInterface() = default;
    virtual ~ciaaCommInterface() = default;

    ciaaCommInterface(const ciaaCommInterface&) = delete;
    ciaaCommInterface& operator=(const ciaaCommInterface&) = delete;

    ciaaCommInterface(const ciaaCommInterface&&) = delete;
    ciaaCommInterface& operator=(const ciaaCommInterface&&) = delete;

    virtual CommDriverErrorCode connect(std::int32_t timeout) const = 0;

    virtual CommDriverErrorCode disconnect(std::int32_t timeout) const = 0;

    virtual CommDriverErrorCode read(std::int32_t timeout,
                                     char *data,
                                     std::int32_t *n_bytes) const = 0;

    virtual CommDriverErrorCode write(std::int32_t timeout,
                                      const char *data,
                                      std::int32_t *n_bytes) const = 0;

};

#endif // CIAA_COMM_INTERFACE_H
