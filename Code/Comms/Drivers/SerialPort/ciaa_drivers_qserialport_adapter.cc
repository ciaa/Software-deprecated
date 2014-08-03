/*! \brief This file give the functionality to ciaaDriversQSerialPortAdapter class.
    \file ciaa_drivers_qserialport_adapter.cc
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Fri Mar 21 00:46:11 CDT 2014

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
    \brief This file become from: Code/Comms/Drivers/SerialPort/ciaa_drivers_qserialport_adapter.cc

    [ACSE-URL]: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/ "Asociación Civil para la Investigación, Promoción y Desarrollo de los Sistemas Electrónicos Embebidos"
    [CADIEEL-URL]: http://www.cadieel.org.ar "Cámara de Industrias Electrónicas, Electromecánicas y Luminotécnicas"
    [proyecto-ciaa-URL]: http://proyecto-ciaa.com.ar "Proyecto CIAA(Computador Industrial Abierta Argentina)"
    [proyecto-ciaa-PCSoftware-URL]: http://proyecto-ciaa.com.ar/gggg "PCSoftware bla bla"
*/


#include "Code/Comms/Drivers/SerialPort/ciaa_drivers_qserialport_adapter.h"

namespace ciaa {
namespace comms {
namespace drivers {
  // ciaaDriversQSerialPortAdapter::ciaaDriversQSerialPortAdapter(
  // std::string device) {
  //  CIAA_UNUSED_PARAM(device);
  // }

  ciaaDriversQSerialPortAdapter::ciaaDriversQSerialPortAdapter(
      std::string device,
      SerialPortAdaptor::BaudRate baudrt,
      SerialPortAdaptor::DataBits databs,
      SerialPortAdaptor::FlowControl flowctl,
      SerialPortAdaptor::Parity prt,
      SerialPortAdaptor::StopBits stbs)
    : ciaaDriversQIODeviceAdapter{&serial_} {
    serial_.setPortName(QString{device.c_str()});

    actived_baudrate_ = static_cast<QSerialPort::BaudRate>(baudrt);
    actived_databits_ = databits(databs);
    actived_flow_control_ = flow_control(flowctl);
    actived_parity_ = parity(prt);
    actived_stop_bits_ = stop_bits(stbs);
  }

  ciaaDriversErrorCode ciaaDriversQSerialPortAdapter::connect(
      std::chrono::milliseconds timeout) {
    // TODO<denisacostaq\@gmail.com>: todo
    CIAA_UNUSED_PARAM(timeout);
    if (serial_.open(QIODevice::ReadWrite)) {
      serial_.setBaudRate(static_cast<qint32>(actived_baudrate_));
      serial_.setDataBits(actived_databits_);
      serial_.setFlowControl(actived_flow_control_);
      serial_.setParity(actived_parity_);
      serial_.setStopBits(actived_stop_bits_);
      return ciaaDriversErrorCode::OK;
    } else {
      return ciaaDriversErrorCode::connection_error;
    }
  }

  ciaaDriversErrorCode ciaaDriversQSerialPortAdapter::disconnect(
      std::chrono::milliseconds timeout) {
    // TODO<denisacostaq\@gmail.com>: usar flush y wait
    CIAA_UNUSED_PARAM(timeout);

    serial_.close();
    return ciaaDriversErrorCode::OK;
  }
}  // namespace drivers
}  // namespace comms
}  // namespace ciaa
