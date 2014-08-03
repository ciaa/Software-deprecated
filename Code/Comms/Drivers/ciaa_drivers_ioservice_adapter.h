/*! \brief Do not include this file directly in external modules.
    \file ciaa_drivers_ioservice_adapter.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Sat May  3 15:05:41 CDT 2014

    \attention <h1><center><strong>&copy;COPYRIGHT 2014 </strong>[<strong>ACSE</strong>]
               [ACSE-URL] & [<strong>CADIEEL</strong>][CADIEEL-URL]</center></h1>

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice,
     this list of conditions and the following disclaimer.

    2. Redistributions in binary form must reproduce the above copyright notice,
     this list of conditions and the following disclaimer in the documentation
     and/or other materials provided with the distribution.

    3. Neither the name of the copyright holder nor the names of its
     contributors may be used to endorse or promote products derived from this
     software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
    POSSIBILITY OF SUCH DAMAGE.

    \brief This file is part of [<strong>CIAA Project</strong>][proyecto-ciaa-URL]
    \brief , especifically in the [<strong>PC Software subproject</strong>]
    \brief [proyecto-ciaa-PCSoftware-URL], in the Comms/Drivers module.\n
    \brief This file become from: Code/Comms/Drivers/ciaa_drivers_ioservice_adapter.h

    [ACSE-URL]: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/ "Asociación Civil para la Investigación, Promoción y Desarrollo de los Sistemas Electrónicos Embebidos"
    [CADIEEL-URL]: http://www.cadieel.org.ar "Cámara de Industrias Electrónicas, Electromecánicas y Luminotécnicas"
    [proyecto-ciaa-URL]: http://proyecto-ciaa.com.ar "Proyecto CIAA(Computador Industrial Abierta Argentina)"
    [proyecto-ciaa-PCSoftware-URL]: http://proyecto-ciaa.com.ar/gggg "PCSoftware bla bla"
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
