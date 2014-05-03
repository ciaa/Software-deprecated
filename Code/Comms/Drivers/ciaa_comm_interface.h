/*! \brief Do not include this file directly in external modules.
    \file ciaa_comm_interface.h
    \author Ezequiel Esposito <ejesposito\@debtech.com.ar>
    \date Thu Jan 9 14:28:58 CDT 2014

    \brief This file is part of Comms module.
    \brief This file become from: Code/Comms/Drivers/ciaa_comm_interface.h

    \attention <h1><center>&copy; COPYRIGHT
    GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007</center></h1>

    \copyright

    <a class="el" href="http://proyecto-ciaa.com.ar">
      This file is part of CIAA Project.
      ==================================
    </a>

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

#include <functional>

#include "Code/Comms/Drivers/ciaa_comm_drivers_config.h" // NOLINT
#include "Code/Comms/Drivers/ciaa_comm_driver_error_code.h"

namespace ciaa {
  namespace comms {
    namespace drivers {
      /*!
       * \brief The ciaaCommInterface class is a common innterface for the Drivers module
       * \ingroup Drivers
       */
      class ciaaCommInterface {
       public:
          ciaaCommInterface() = default;
          virtual ~ciaaCommInterface() = default;

          ciaaCommInterface(const ciaaCommInterface&) = delete;
          ciaaCommInterface& operator=(const ciaaCommInterface&) = delete;

          ciaaCommInterface(const ciaaCommInterface&&) = delete;
          ciaaCommInterface& operator=(const ciaaCommInterface&&) = delete;

          virtual ciaaErrorCode connect(std::int32_t timeout) const = 0;

          virtual ciaaErrorCode disconnect(std::int32_t timeout) const = 0;

          virtual ciaaErrorCode read(std::int32_t timeout,
                                           char *data,
                                           ciaa_size_t *n_bytes) const = 0;
          virtual void read(char *data,
                            ciaa_size_t *n_bytes,
                            std::function<void(ciaaErrorCode,
                                                ciaa_size_t)> callback) = 0;

          virtual ciaaErrorCode write(std::int32_t timeout,
                                            const char *data,
                                            ciaa_size_t *n_bytes) const = 0;

          virtual void write(const char *data,
                             ciaa_size_t *n_bytes,
                             std::function<void(ciaaErrorCode,
                                                ciaa_size_t)> callback) = 0;

      };
    }  // namespace ciaa
  }  // namespace comms
}  // namespace drivers

#endif  // CIAA_COMM_INTERFACE_H
