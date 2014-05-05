/*! \brief This file gives a ciaaBATCPSocketAdapter functionality.
    \file ciaa_drivers_basockettcp_adapter.cc
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Sun Apr 27 22:51:04 CDT 2014

    \brief This file is part of Comms/Drivers module.
    \brief This file become from: Comms/Drivers/Ethernet/ciaa_drivers_basockettcp_adapter.cc

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

#include <sstream>

#include "Code/Comms/Drivers/Ethernet/ciaa_drivers_basockettcp_adapter.h"

namespace ciaa {
namespace comms {
namespace drivers {
ciaaBATCPSocketAdapter::ciaaBATCPSocketAdapter(std::string host,
                                               std::uint16_t port)
  : host_{host}
  , port_{port}
  , io_service_{}
  , socket_{io_service_}
  , deadline_{io_service_} {
  // set the deadline to positive infinity so that the actor takes no action
  // until a specific deadline is set.
    deadline_.expires_at(boost::posix_time::pos_infin);

    // Start the persistent actor that checks for deadline expiry.
    this->check_deadline();
}
}  // namespace drivers
}  // namespace comms
}  // namespace ciaa
