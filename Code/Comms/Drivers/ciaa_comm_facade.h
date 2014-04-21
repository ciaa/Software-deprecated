/*! \brief This is the only file you need to include external modules to use the Communication Drivers.
    \file ciaa_comm_facade.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Fri Mar 21 00:20:15 CDT 2014

    \brief This file is part of Comms module.
    \brief This file become from: Code/Comms/Drivers/ciaa_comm_facade.h
 
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


#ifndef COMMS_DRIVERS_FACADE_H
#define COMMS_DRIVERS_FACADE_H

#include <map>

#include "Comms/Drivers/Ethernet/ciaa_socket_tcp.h"
#include "Comms/Drivers/SerialPort/ciaa_serial_port.h"

/*! \brief The ciaaCommFacade class use a facade pattern.
 * \brief ciaaCommFacade is a common facade for \"all\" transport protocols.
 * \ingroup Drivers
 */
class ciaaCommFacade
{
  public:
    ciaaCommFacade(std::string host, u_int16_t port);
    ciaaCommFacade(std::string device);
    ~ciaaCommFacade();

    ciaaCommFacade(const ciaaCommFacade&) = delete;
    ciaaCommFacade& operator=(const ciaaCommFacade&) = delete;

    ciaaCommFacade(const ciaaCommFacade&&) = delete;
    ciaaCommFacade& operator=(const ciaaCommFacade&&) = delete;

    inline CommDriverErrorCode connect(int32_t timeout) {
      return transporter_->connect(timeout);
    }

    inline CommDriverErrorCode disconnect(int32_t timeout) {
      return transporter_->disconnect(timeout);
    }

    inline CommDriverErrorCode read(int32_t timeout, char *data, int *n_bytes) {
      return transporter_->read(timeout, data, n_bytes);
    }

    inline CommDriverErrorCode write(int32_t timeout, const char *data, int *n_bytes) {
      return transporter_->write(timeout, data, n_bytes);
    }

    inline const std::string get_msg_error(CommDriverErrorCode err_code) const {
      return msg_error_.find(err_code)->second;
    }

  protected:
    ciaaCommInterface *transporter_{nullptr};


  private:

    std::map<CommDriverErrorCode, std::string> msg_error_
    {
      std::pair<CommDriverErrorCode, std::string>
      {
        CommDriverErrorCode::Ok, u8"General operation without errors."
      },
      std::pair<CommDriverErrorCode, std::string>
      {
        CommDriverErrorCode::access_error, u8"Application lacked the required privileges."
      },
      std::pair<CommDriverErrorCode, std::string>
      {
        CommDriverErrorCode::resource_error, u8"The local system ran out of resources (e.g., too many fd)."
      },
      std::pair<CommDriverErrorCode, std::string>
      {
        CommDriverErrorCode::timeout_error, u8"General operation timed out."
      },
      std::pair<CommDriverErrorCode, std::string>
      {
        CommDriverErrorCode::connection_error, u8"The connect operation fail or the current connection has been broken."
      },
      std::pair<CommDriverErrorCode, std::string>
      {
        CommDriverErrorCode::inuse_error, u8"***//TODO<denisacostaq@gmail.com>. The device is busy***"
      },
      std::pair<CommDriverErrorCode, std::string>
      {
        CommDriverErrorCode::unsupported_operation_error, u8"***//TODO<denisacostaq@gmail.com>: ej escribir un dispositivo de solo lectura.***"
      },
      std::pair<CommDriverErrorCode, std::string>
      {
        CommDriverErrorCode::unfinished_operation_error, u8"The last operation attempted has not finished yet (still in progress in the background)."
      },
      std::pair<CommDriverErrorCode, std::string>
      {
        CommDriverErrorCode::temporary_error, u8"You can retry the operation later."
      },
      std::pair<CommDriverErrorCode, std::string>
      {
        CommDriverErrorCode::disconnect_error, u8"Could not disconnect the device."
      },
      std::pair<CommDriverErrorCode, std::string>
      {
        CommDriverErrorCode::read_error, u8"The read operation has been fail."
      },
      std::pair<CommDriverErrorCode, std::string>
      {
        CommDriverErrorCode::write_error, u8"The write operation has been fail."
      },
      std::pair<CommDriverErrorCode, std::string>
      {
        CommDriverErrorCode::timeout_error, u8"The operation fail by timeout."
      },
      std::pair<CommDriverErrorCode, std::string>
      {
        CommDriverErrorCode::unknown_error, u8"An unidentified error occurred."
      }
    };
};

#endif // COMMS_DRIVERS_FACADE_H
