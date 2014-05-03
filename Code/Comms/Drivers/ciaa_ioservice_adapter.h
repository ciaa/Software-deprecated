/*! \brief Do not include this file directly in external modules.
    \file ciaa_ioservice_adapter.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Sat May  3 15:05:41 CDT 2014

    \brief This file is part of Comms module.
    \brief This file become from: Code/Comms/Drivers/ciaa_ioservice_adapter.h

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

#ifndef COMMS_DRIVERS_IOSERVICE_ADAPTER_H
#define COMMS_DRIVERS_IOSERVICE_ADAPTER_H
// #include <boost/asio/basic_io_object.hpp>

#include "Code/Comms/Drivers/ciaa_comm_adapter_interface.h"

namespace ciaa {
  namespace comms {
    namespace drivers {
      // TODO(denisacostaq\@gmail.com): todo
      class ciaaIOServiceAdapter : public ciaaCommAdapterInterface {
       public:
        ciaaIOServiceAdapter(/*boost::asio::basic_io_object *io_object*/)
         // : io_object_{io_object} {
        {
        }

        ~ciaaIOServiceAdapter() = default;

        ciaaIOServiceAdapter(const ciaaIOServiceAdapter&) = delete;
        ciaaIOServiceAdapter& operator=(const ciaaIOServiceAdapter&) = delete;

        ciaaIOServiceAdapter(const ciaaIOServiceAdapter&&) = delete;
        ciaaIOServiceAdapter& operator=(const ciaaIOServiceAdapter&&) = delete;
       protected:

       private:
        // TODO(denisacostaq\@gmail.com): boost::asio::basic_io_object *io_object_;
      };
    }  // namespace ciaa
  }  // namespace comms
}  // namespace drivers
#endif  // COMMS_DRIVERS_IOSERVICE_ADAPTER_H
