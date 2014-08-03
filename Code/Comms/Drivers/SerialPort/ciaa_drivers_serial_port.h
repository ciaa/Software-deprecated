/*! \brief Do not include this file directly in external modules.
    \file ciaa_drivers_serial_port.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Thu Jan 9 14:28:58 CDT 2014

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
    \brief This file become from: Comms/Drivers/SerialPort/ciaa_drivers_serial_port.h

    [ACSE-URL]: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/ "Asociación Civil para la Investigación, Promoción y Desarrollo de los Sistemas Electrónicos Embebidos"
    [CADIEEL-URL]: http://www.cadieel.org.ar "Cámara de Industrias Electrónicas, Electromecánicas y Luminotécnicas"
    [proyecto-ciaa-URL]: http://proyecto-ciaa.com.ar "Proyecto CIAA(Computador Industrial Abierta Argentina)"
    [proyecto-ciaa-PCSoftware-URL]: http://proyecto-ciaa.com.ar/gggg "PCSoftware bla bla"
*/

#ifndef COMMS_DRIVERS_SERIALPORT_H
#define COMMS_DRIVERS_SERIALPORT_H

#include "Code/Comms/Drivers/ciaa_drivers_interface.h"
#include "Code/Comms/Drivers/SerialPort/ciaa_drivers_serial_config.h"
#ifdef USE_BOOST_ASIO
#include "Code/Comms/Drivers/SerialPort/ciaa_drivers_baserialport_adapter.h"
#else
#include "Code/Comms/Drivers/SerialPort/ciaa_drivers_qserialport_adapter.h"
#endif

namespace ciaa {
namespace comms {
namespace drivers {
/*! \brief ciaaDriversSerialPort is a class for the Serial Port communication.
 *  \ingroup SerialPort
 *  \brief This class is for the Serial Port communication using RS-232
 *  \brief standard(ANSI/EIA­232) in the Comms module.
 * \ingroup SerialPort
 */
class ciaaDriversSerialPort : public ciaaDriversInterface {
 public:
  explicit ciaaDriversSerialPort(std::string device,
                                 SerialPortAdaptor::BaudRate baudrt,
                                 SerialPortAdaptor::DataBits databs,
                                 SerialPortAdaptor::FlowControl flowctl,
                                 SerialPortAdaptor::Parity prt,
                                 SerialPortAdaptor::StopBits stbs);
  ~ciaaDriversSerialPort();

  ciaaDriversSerialPort(const ciaaDriversSerialPort&) = delete;
  ciaaDriversSerialPort& operator=(const ciaaDriversSerialPort&) = delete;

  ciaaDriversSerialPort(const ciaaDriversSerialPort&&) = delete;
  ciaaDriversSerialPort& operator=(const ciaaDriversSerialPort&&) = delete;

  inline ciaaDriversErrorCode connect(std::chrono::milliseconds timeout) const override {  // NOLINT(whitespace/line_length)
    return serial_->connect(timeout) ;
  }

  inline ciaaDriversErrorCode disconnect(std::chrono::milliseconds timeout) const override {  // NOLINT(whitespace/line_length)
    return serial_->disconnect(timeout);
  }

  inline ciaaDriversErrorCode read(std::chrono::milliseconds timeout,
                                  char *data,
                                  ciaa_size_t *n_bytes) const override {
    return serial_->read(timeout, data, n_bytes);
  }

  inline void read(char *data,
                   ciaa_size_t *n_bytes,
                   std::function<void(ciaaDriversErrorCode, ciaa_size_t)> callback) {  // NOLINT(whitespace/line_length)
    serial_->read(data, n_bytes, callback);
  }

  inline ciaaDriversErrorCode write(std::chrono::milliseconds timeout,
                                   const char *data,
                                   ciaa_size_t *n_bytes) const override {
    return serial_->write(timeout, data, n_bytes) ;
  }

  inline void write(const char *data,
                    ciaa_size_t *n_bytes,
                    std::function<void(ciaaDriversErrorCode,
                                       ciaa_size_t)> callback) override {
    return serial_->write(data, n_bytes, callback);
  }


 private:
#ifdef USE_BOOST_ASIO
  ciaaBASerialPortAdapter *serial_;
#else
  ciaaDriversQSerialPortAdapter *serial_;
#endif

};
}  // namespace drivers
}  // namespace comms
}  // namespace ciaa

#endif  // COMMS_DRIVERS_SERIALPORT_H
