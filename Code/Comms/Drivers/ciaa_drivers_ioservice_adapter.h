/*! \brief Do not include this file directly in external modules.
    \file ciaa_drivers_ioservice_adapter.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Sat May  3 15:05:41 CDT 2014

    \brief This file is part of Comms module.
    \brief This file become from: Code/Comms/Drivers/ciaa_drivers_ioservice_adapter.h

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

#include <map>

#include <boost/system/error_code.hpp>

#include <boost/asio/ip/tcp.hpp>
// NOTE(denisacostaq\@gmail.com): This is for enable namespace ba = boost::asio;

// #include <boost/asio/basic_io_object.hpp>

#include "Code/Comms/Drivers/ciaa_drivers_adapter_interface.h"

namespace ciaa {
namespace comms {
namespace drivers {
  namespace ba = boost::asio;
  // TODO(denisacostaq\@gmail.com): todo
class ciaaBAIOServiceAdapter : public ciaaDriversAdapterInterface {
 public:
  ciaaBAIOServiceAdapter(/*ba::basic_io_object *io_object*/) {
    // : io_object_{io_object} {
  }

  ~ciaaBAIOServiceAdapter() = default;

  ciaaBAIOServiceAdapter(const ciaaBAIOServiceAdapter&) = delete;
  ciaaBAIOServiceAdapter& operator=(const ciaaBAIOServiceAdapter&) = delete;

  ciaaBAIOServiceAdapter(const ciaaBAIOServiceAdapter&&) = delete;
  ciaaBAIOServiceAdapter& operator=(const ciaaBAIOServiceAdapter&&) = delete;

 protected:

  inline ciaaDriversErrorCode asociated_error(boost::system::error_code ec) {
    ciaaDriversErrorCode ret{ciaaDriversErrorCode::unknown_error};
    auto finded = asociated_error_.find(
          static_cast<boost::system::errc::errc_t>(ec.value()));
    if (finded != asociated_error_.end()) {
      ret = finded->second;
    }
    return ret;
  }


 private:

  std::map<boost::system::errc::errc_t, ciaaDriversErrorCode> asociated_error_ {
    std::pair<boost::system::errc::errc_t, ciaaDriversErrorCode> {
      boost::system::errc::errc_t::permission_denied,
      ciaaDriversErrorCode::access_error
    },
    std::pair<boost::system::errc::errc_t, ciaaDriversErrorCode> {
      boost::system::errc::owner_dead,
      ciaaDriversErrorCode::access_error
    },
    std::pair<boost::system::errc::errc_t, ciaaDriversErrorCode> {
      boost::system::errc::operation_not_permitted,
      ciaaDriversErrorCode::access_error
    },
    std::pair<boost::system::errc::errc_t, ciaaDriversErrorCode> {
      boost::system::errc::read_only_file_system,
      ciaaDriversErrorCode::access_error
    },

//         TODO(denisacostaq\@gmail.com): agregar los errores de asio
//         #include <boost/asio/error.hpp> tambien, ej:
//      std::pair<boost::system::errc::errc_t, ciaaDriversErrorCode> {
//        ba::error::misc_errors::already_connected,
//        ciaaDriversErrorCode::access_error
//      },
//      std::pair<boost::system::errc::errc_t, ciaaDriversErrorCode> {
//        ba::error::misc_errors::already_open,
//        ciaaDriversErrorCode::access_error
//      },

    std::pair<boost::system::errc::errc_t, ciaaDriversErrorCode> {
      boost::system::errc::address_in_use,
      ciaaDriversErrorCode::inuse_error
    },

    std::pair<boost::system::errc::errc_t, ciaaDriversErrorCode> {
      boost::system::errc::too_many_files_open,
      ciaaDriversErrorCode::resource_error
    },
    std::pair<boost::system::errc::errc_t, ciaaDriversErrorCode> {
      boost::system::errc::too_many_files_open_in_system,
      ciaaDriversErrorCode::resource_error
    },
    std::pair<boost::system::errc::errc_t, ciaaDriversErrorCode> {
      boost::system::errc::too_many_links,
      ciaaDriversErrorCode::resource_error
    },
    std::pair<boost::system::errc::errc_t, ciaaDriversErrorCode> {
      boost::system::errc::too_many_symbolic_link_levels,
      ciaaDriversErrorCode::resource_error
    },

    std::pair<boost::system::errc::errc_t, ciaaDriversErrorCode> {
      boost::system::errc::connection_refused,
      ciaaDriversErrorCode::connection_error
    },
    std::pair<boost::system::errc::errc_t, ciaaDriversErrorCode> {
      boost::system::errc::connection_reset,
      ciaaDriversErrorCode::connection_error
    },
    std::pair<boost::system::errc::errc_t, ciaaDriversErrorCode> {
      boost::system::errc::connection_aborted,
      ciaaDriversErrorCode::connection_error
    },

    std::pair<boost::system::errc::errc_t, ciaaDriversErrorCode> {
      boost::system::errc::connection_already_in_progress,
      ciaaDriversErrorCode::unfinished_operation_error
    },

    std::pair<boost::system::errc::errc_t, ciaaDriversErrorCode> {
      boost::system::errc::device_or_resource_busy,
      ciaaDriversErrorCode::inuse_error
    },

    std::pair<boost::system::errc::errc_t, ciaaDriversErrorCode> {
      boost::system::errc::operation_not_supported,
      ciaaDriversErrorCode::unsupported_operation_error
    },

    std::pair<boost::system::errc::errc_t, ciaaDriversErrorCode> {
      boost::system::errc::operation_in_progress,
      ciaaDriversErrorCode::temporary_error
    },

    std::pair<boost::system::errc::errc_t, ciaaDriversErrorCode> {
      boost::system::errc::not_connected,
      ciaaDriversErrorCode::disconnect_error
    },

    std::pair<boost::system::errc::errc_t, ciaaDriversErrorCode> {
      boost::system::errc::timed_out,
      ciaaDriversErrorCode::timeout_error
    }
  };
  // TODO(denisacostaq\@gmail.com): ba::basic_io_object *io_object_;

};
}  // namespace drivers
}  // namespace comms
}  // namespace ciaa
#endif  // COMMS_DRIVERS_IOSERVICE_ADAPTER_H
