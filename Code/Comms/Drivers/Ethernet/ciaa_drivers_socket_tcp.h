/*! \brief Do not include this file directly in external modules.
    \file ciaa_drivers_socket_tcp.h
    \author Ezequiel Esposito <ejesposito\@debtech.com.ar>
    \date Thu Jan 9 14:28:58 CDT 2014

    \brief This file is part of Comms/Driversrnet module.
    \brief This file become from: Comms/Drivers/Ethernet/ciaa_drivers_socket_tcp.h

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


#ifndef COMMS_DRIVERS_ETHERNET_SOCKETTCP_H
#define COMMS_DRIVERS_ETHERNET_SOCKETTCP_H

#include "Code/Comms/Drivers/ciaa_drivers_interface.h"
#ifdef USE_BOOST_ASIO
  #include "Code/Comms/Drivers/Ethernet/ciaa_drivers_basockettcp_adapter.h"
#else
  #include "Code/Comms/Drivers/Ethernet/ciaa_drivers_qsockettcp_adapter.h"
#endif



namespace ciaa {
namespace comms {
namespace drivers {
/*! \brief TODO <denisacostaq\@gmail.com>
 * \brief The ciaaSocket class
 * \ingroup Ethernet
 */
class ciaaDriversSocketTCP : public ciaaDriversInterface {
 public:
  ciaaDriversSocketTCP(std::string host, std::uint16_t port);
  ~ciaaDriversSocketTCP();

  ciaaDriversSocketTCP(const ciaaDriversSocketTCP&) = delete;
  ciaaDriversSocketTCP& operator=(const ciaaDriversSocketTCP&) = delete;

  ciaaDriversSocketTCP(const ciaaDriversSocketTCP&&) = delete;
  ciaaDriversSocketTCP& operator=(const ciaaDriversSocketTCP&&) = delete;

  inline ciaaDriversErrorCode connect(std::int32_t timeout) const override {
    return socket_->connect(timeout) ;
  }

  inline ciaaDriversErrorCode disconnect(std::int32_t timeout) const override {
    return socket_->disconnect(timeout);
  }

  inline ciaaDriversErrorCode read(std::int32_t timeout,
                                  char *data,
                                  ciaa_size_t *n_bytes) const override {
    return socket_->read(timeout, data, n_bytes);
  }

  inline void read(char *data,
                   ciaa_size_t *n_bytes,
                   std::function<void(ciaaDriversErrorCode, ciaa_size_t)> callback) {  // NOLINT(whitespace/line_length)
    socket_->read(data, n_bytes, callback);
  }

  inline ciaaDriversErrorCode write(std::int32_t timeout,
                                   const char *data,
                                   ciaa_size_t *n_bytes) const override {
    return socket_->write(timeout, data, n_bytes) ;
  }

  inline void write(const char *data,
                    ciaa_size_t *n_bytes,
                    std::function<void(ciaaDriversErrorCode,
                                       ciaa_size_t)> callback) override {
    return socket_->write(data, n_bytes, callback);
  }


 private:
#ifdef USE_BOOST_ASIO
  ciaaBATCPSocketAdapter *socket_;
#else
  ciaaDriversQSocketTCPAdapater *socket_;
#endif

};
}  // namespace drivers
}  // namespace comms
}  // namespace ciaa
#endif  // COMMS_DRIVERS_ETHERNET_SOCKETTCP_H
