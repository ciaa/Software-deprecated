/*! \brief This is the only file you need to include external modules to use the Communication Drivers.
    \file ciaa_drivers_facade.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Fri Mar 21 00:20:15 CDT 2014

    \brief This file is part of Comms module.
    \brief This file become from: Code/Comms/Drivers/ciaa_drivers_facade.h

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


#ifndef COMMS_DRIVERS_FACADE_H
#define COMMS_DRIVERS_FACADE_H

#include <map>

#include "Code/Comms/Drivers/Ethernet/ciaa_drivers_socket_tcp.h"
#include "Code/Comms/Drivers/SerialPort/ciaa_drivers_serial_port.h"


namespace ciaa {
namespace comms {
namespace drivers {
/*! \brief The ciaaCommFacade class use a facade pattern.
 * \brief ciaaCommFacade is a common facade for \"all\" transport protocols.
 * \ingroup Drivers
 */
class ciaaDriversFacade {
 public:

   /*! \brief ciaaDriversFacade. This constructor create a tcp object.
   * \brief If you use a port lees than 1024 need edit the iptable in an *nix
   * \brief environment
   * \param host is the ipv4 address of the remot host as string but in four
   * points numeric format eg: \"127.0.0.1\"
   * \param port is the port of the remot tcp server.
   * \note For example usage see the Tests/Comms/Drivers directory.
   */
  ciaaDriversFacade(std::string host, std::uint16_t port);

  /*! \brief ciaaDriversFacade. This constructor create a serial port object.
   * \param device The name of the virtual device, for example \"\\dev\\ttyS0\".
   * \param baudrt The baudrate for the transfer.
   * \param databs The number of data bits.
   * \param flowctl The flow control.
   * \param prt The parity.
   * \param stbs The stop bits.
   * \warning Do not use custon values in params, for example never pass a
   * custom value such as 9600 for baudrate, insted use
   * SerialPortAdaptor::BaudRate::Baud9600, if you ned custom values contact
   * the privider or send a pull request.
   */
  ciaaDriversFacade(std::string device,
                    SerialPortAdaptor::BaudRate baudrt,
                    SerialPortAdaptor::DataBits databs,
                    SerialPortAdaptor::FlowControl flowctl,
                    SerialPortAdaptor::Parity prt,
                    SerialPortAdaptor::StopBits stbs);
  ~ciaaDriversFacade();

  /*! \brief ciaaDriversFacade coppy constructor are disabled.
   */
  ciaaDriversFacade(const ciaaDriversFacade&) = delete;
  /*! \brief operator= asignation operator are disabled.
   */
  ciaaDriversFacade& operator=(const ciaaDriversFacade&) = delete;

  /*! \brief ciaaDriversFacade coppy constructor using move are disabled.
   */
  ciaaDriversFacade(const ciaaDriversFacade&&) = delete;
  /*! \brief operator= asignation operator using move are disabled.
   */
  ciaaDriversFacade& operator=(const ciaaDriversFacade&&) = delete;

  /*! \brief connect This create the connection using the timeout for reintent.
   * \param timeout The timeout for wait if error or latency.
   * \return ciaaDriversErrorCode::OK If no error found.
   * \sa get_msg_error(), disconnect()
   */
  inline ciaaDriversErrorCode connect(std::int32_t timeout) {
    return transporter_->connect(timeout);
  }

  /*! \brief disconnect This release the connection using the timeout for
   *  reintent.
   * \param timeout The timeout for wait if error or latency.
   * \return ciaaDriversErrorCode::OK If no error found.
   * \sa get_msg_error(), connect()
   * \warning Call this function for resource release, the destructor do not
   * perform this action by default.
   */
  inline ciaaDriversErrorCode disconnect(std::int32_t timeout) {
    return transporter_->disconnect(timeout);
  }

  /*! \brief read is a syncronous function for read.
   * \param timeout is the timeout for wait for the data is arrived.
   * \param data put the readed data here.
   * \param n_bytes is the number of bytes to read.
   * \return ciaaDriversErrorCode::OK If no error found. If you have an error
   * check n_bytes, this is an in//out parameter that contain the real nuber
   * of bytes readed.
   * \sa write(), get_msg_error(), connect()
   */
  inline ciaaDriversErrorCode read(std::int32_t timeout,
                                  char *data,
                                  ciaa_size_t *n_bytes) {
    return transporter_->read(timeout, data, n_bytes);
  }

  /*! \brief read is an asyncronous function for read.
   * \param data put the readed data here.
   * \param n_bytes is the number of bytes to read.
   * \param callback is the function for return the ciaaDriversErrorCode and the
   * the real nuber of bytes readed.
   * \sa connect()
   */
  inline void read(char *data,
  // FIXME(denisacostaq\@gmail.com): ciaa_size_t *n_bytes -->
  // const ciaa_size_t n_bytes
                   ciaa_size_t *n_bytes,
                   std::function<void(ciaaDriversErrorCode, ciaa_size_t)> callback) {  // NOLINT(whitespace/line_length)
    transporter_->read(data, n_bytes, callback);
  }

  /*! \brief write is a syncronous function for write.
   * \param timeout is the timeout for wait for the data is sended.
   * \param data put here the data to send.
   * \param n_bytes is the number of bytes to write.
   * \return ciaaDriversErrorCode::OK If no error found. If you have an error
   * check n_bytes, this is an in//out parameter that contain the real nuber
   * of bytes writed.
   * \sa write(), get_msg_error(), connect()
   */
  inline ciaaDriversErrorCode write(std::int32_t timeout,
                                   const char *data,
                                   ciaa_size_t *n_bytes) {
    return transporter_->write(timeout, data, n_bytes);
  }

  /*! \brief write is an asyncronous function for read.
   * \param data put here the data to send.
   * \param n_bytes is the number of bytes to write.
   * \param callback is the function for return the ciaaDriversErrorCode and the
   * the real nuber of bytes writed.
   * \sa connect()
   */
  inline void write(char *data,
  // FIXME(denisacostaq\@gmail.com): ciaa_size_t *n_bytes -->
  // const ciaa_size_t n_bytes
                    ciaa_size_t *n_bytes,
                    std::function<void(ciaaDriversErrorCode, ciaa_size_t)> callback) {  // NOLINT(whitespace/line_length)
    transporter_->write(data, n_bytes, callback);
  }

  /*! \brief get_msg_error return a human readable msg for error codes.
   * \param err_code is the ciaaDriversErrorCode about tou need information.
   * \return the message error in utf-8 string format.
   */
  inline const std::string get_msg_error(ciaaDriversErrorCode err_code) const {
    return msg_error_.find(err_code)->second;
  }

 protected:
  ciaaDriversInterface *transporter_{nullptr};


 private:

  const std::map<ciaaDriversErrorCode, std::string> msg_error_ {
    std::pair<ciaaDriversErrorCode, std::string> {
      ciaaDriversErrorCode::OK, u8"General operation without errors."
    },
    std::pair<ciaaDriversErrorCode, std::string> {
      ciaaDriversErrorCode::access_error,
      u8"Application lacked the required privileges."
    },
    std::pair<ciaaDriversErrorCode, std::string> {
      ciaaDriversErrorCode::resource_error,
      u8"The local system ran out of resources (e.g., too many fd)."
    },
    std::pair<ciaaDriversErrorCode, std::string> {
      ciaaDriversErrorCode::connection_error,
      u8"The connect operation fail or the current connection has been broken."  // NOLINT(whitespace/line_length)
    },
    std::pair<ciaaDriversErrorCode, std::string> {
      ciaaDriversErrorCode::inuse_error,
      u8"TODO<denisacostaq@gmail.com>               /**< The device is busy."
    },
    std::pair<ciaaDriversErrorCode, std::string> {
      ciaaDriversErrorCode::unsupported_operation_error,
      u8"TODO<denisacostaq@gmail.com>: ej escribir un dispositivo de solo lectura"  // NOLINT(whitespace/line_length)
    },
    std::pair<ciaaDriversErrorCode, std::string> {
      ciaaDriversErrorCode::unfinished_operation_error,
      u8"The last operation attempted has not finished yet (still in progress in the background)."  // NOLINT(whitespace/line_length)
    },
    std::pair<ciaaDriversErrorCode, std::string> {
      ciaaDriversErrorCode::temporary_error,
      u8"You can retry the operation later."
    },
    std::pair<ciaaDriversErrorCode, std::string> {
      ciaaDriversErrorCode::disconnect_error,
      u8"Could not disconnect the device."
    },
    std::pair<ciaaDriversErrorCode, std::string> {
      ciaaDriversErrorCode::read_error,
      u8"The read operation has been fail."
    },
    std::pair<ciaaDriversErrorCode, std::string> {
      ciaaDriversErrorCode::write_error,
      u8"The write operation has been fail."
    },
    std::pair<ciaaDriversErrorCode, std::string> {
      ciaaDriversErrorCode::timeout_error,
      u8"The operation fail by timeout."
    },
    std::pair<ciaaDriversErrorCode, std::string> {
      ciaaDriversErrorCode::unknown_error,
      u8"An unidentified error occurred."
    }
  };
};
}  // namespace drivers
}  // namespace comms
}  // namespace ciaa

#endif  // COMMS_DRIVERS_FACADE_H
