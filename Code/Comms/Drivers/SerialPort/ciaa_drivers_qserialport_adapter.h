/*! \brief Do not include this file directly in external modules.
    \file ciaa_drivers_qserialport_adapter.h
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
    \brief This file become from: Code/Comms/Drivers/SerialPort/ciaa_drivers_qserialport_adapter.h

    [ACSE-URL]: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/ "Asociación Civil para la Investigación, Promoción y Desarrollo de los Sistemas Electrónicos Embebidos"
    [CADIEEL-URL]: http://www.cadieel.org.ar "Cámara de Industrias Electrónicas, Electromecánicas y Luminotécnicas"
    [proyecto-ciaa-URL]: http://proyecto-ciaa.com.ar "Proyecto CIAA(Computador Industrial Abierta Argentina)"
    [proyecto-ciaa-PCSoftware-URL]: http://proyecto-ciaa.com.ar/gggg "PCSoftware bla bla"
*/


#ifndef COMMS_DRIVERS_QSERIALPORT_ADAPTER_H
#define COMMS_DRIVERS_QSERIALPORT_ADAPTER_H

#include <map>

#include <QtSerialPort/QtSerialPort>

#include "Code/Comms/Drivers/ciaa_drivers_qiodevice_adapter.h"
#include "Code/Comms/Drivers/SerialPort/ciaa_drivers_serial_config.h"

namespace ciaa {
namespace comms {
namespace drivers {
  /*! \brief TODO<denisacostaq\@gmail.com>
  * \brief The ciaaDriversQSerialPortAdapter class
  * \ingroup SerialPort
  */
class ciaaDriversQSerialPortAdapter : public ciaaDriversQIODeviceAdapter {
 public:
  ciaaDriversQSerialPortAdapter(std::string device,
                                SerialPortAdaptor::BaudRate baudrt,
                                SerialPortAdaptor::DataBits databs,
                                SerialPortAdaptor::FlowControl flowctl,
                                SerialPortAdaptor::Parity prt,
                                SerialPortAdaptor::StopBits stbs);
  ~ciaaDriversQSerialPortAdapter() = default;

  ciaaDriversQSerialPortAdapter(const ciaaDriversQSerialPortAdapter&) = delete;
  ciaaDriversQSerialPortAdapter& operator=(
      const ciaaDriversQSerialPortAdapter&) = delete;

  ciaaDriversQSerialPortAdapter(const ciaaDriversQSerialPortAdapter&&) = delete;
  ciaaDriversQSerialPortAdapter& operator=(
      const ciaaDriversQSerialPortAdapter&&) = delete;

  ciaaDriversErrorCode connect(std::chrono::milliseconds timeout) override;
  ciaaDriversErrorCode disconnect(std::chrono::milliseconds timeout) override;

 private:

  QSerialPort serial_;

  const std::map<SerialPortAdaptor::DataBits, QSerialPort::DataBits> databits_ {
    std::pair<SerialPortAdaptor::DataBits, QSerialPort::DataBits> {
      SerialPortAdaptor::DataBits::Data5,
      QSerialPort::Data5
    },
    std::pair<SerialPortAdaptor::DataBits, QSerialPort::DataBits> {
      SerialPortAdaptor::DataBits::Data6,
      QSerialPort::Data6
    },
    std::pair<SerialPortAdaptor::DataBits, QSerialPort::DataBits> {
      SerialPortAdaptor::DataBits::Data7,
      QSerialPort::Data7
    },
    std::pair<SerialPortAdaptor::DataBits, QSerialPort::DataBits> {
      SerialPortAdaptor::DataBits::Data8,
      QSerialPort::Data8
    }
  };

  const std::map<SerialPortAdaptor::FlowControl, QSerialPort::FlowControl> flow_control_ {  // NOLINT(whitespace/line_length)
    std::pair<SerialPortAdaptor::FlowControl, QSerialPort::FlowControl> {
      SerialPortAdaptor::FlowControl::HardwareControl,
      QSerialPort::FlowControl::HardwareControl
    },
    std::pair<SerialPortAdaptor::FlowControl, QSerialPort::FlowControl> {
      SerialPortAdaptor::FlowControl::NoFlowControl,
      QSerialPort::FlowControl::NoFlowControl
    },
    std::pair<SerialPortAdaptor::FlowControl, QSerialPort::FlowControl> {
      SerialPortAdaptor::FlowControl::SoftwareControl,
      QSerialPort::FlowControl::SoftwareControl
    },
    std::pair<SerialPortAdaptor::FlowControl, QSerialPort::FlowControl> {
      SerialPortAdaptor::FlowControl::UnknownFlowControl,
      QSerialPort::FlowControl::UnknownFlowControl
    }
  };

  const std::map<SerialPortAdaptor::Parity, QSerialPort::Parity> parity_ {
    std::pair<SerialPortAdaptor::Parity, QSerialPort::Parity> {
      SerialPortAdaptor::Parity::NoParity,
      QSerialPort::Parity::NoParity
    },
    std::pair<SerialPortAdaptor::Parity, QSerialPort::Parity> {
      SerialPortAdaptor::Parity::EvenParity,
      QSerialPort::Parity::EvenParity
    },
    std::pair<SerialPortAdaptor::Parity, QSerialPort::Parity> {
      SerialPortAdaptor::Parity::OddParity,
      QSerialPort::Parity::OddParity
    },
    std::pair<SerialPortAdaptor::Parity, QSerialPort::Parity> {
      SerialPortAdaptor::Parity::SpaceParity, QSerialPort::Parity::SpaceParity
    },
    std::pair<SerialPortAdaptor::Parity, QSerialPort::Parity> {
      SerialPortAdaptor::Parity::MarkParity,
      QSerialPort::Parity::MarkParity
    },
    std::pair<SerialPortAdaptor::Parity, QSerialPort::Parity> {
      SerialPortAdaptor::Parity::UnknownParity,
      QSerialPort::Parity::UnknownParity
    }
  };

  const std::map<SerialPortAdaptor::StopBits, QSerialPort::StopBits> stop_bits_{
    std::pair<SerialPortAdaptor::StopBits, QSerialPort::StopBits> {
      SerialPortAdaptor::StopBits::OneAndHalfStop,
      QSerialPort::StopBits::OneAndHalfStop
    },
    std::pair<SerialPortAdaptor::StopBits, QSerialPort::StopBits> {
      SerialPortAdaptor::StopBits::OneStop,
      QSerialPort::StopBits::OneStop
    },
    std::pair<SerialPortAdaptor::StopBits, QSerialPort::StopBits> {
      SerialPortAdaptor::StopBits::TwoStop,
      QSerialPort::StopBits::TwoStop
    },
    std::pair<SerialPortAdaptor::StopBits, QSerialPort::StopBits> {
      SerialPortAdaptor::StopBits::UnknownStopBits,
      QSerialPort::StopBits::UnknownStopBits
    }
  };

  // TODO(denisacostaq@gmail.com): hacer const
  inline QSerialPort::DataBits databits(SerialPortAdaptor::DataBits databit) {
    return databits_.find(databit)->second;
  }

  // TODO(denisacostaq@gmail.com): hacer const
  inline QSerialPort::FlowControl flow_control(
      SerialPortAdaptor::FlowControl flowcontrol) {
    return flow_control_.find(flowcontrol)->second;
  }

  // TODO(denisacostaq@gmail.com): hacer const
  inline QSerialPort::Parity parity(SerialPortAdaptor::Parity pari) {
    return parity_.find(pari)->second;
  }

  // TODO(denisacostaq@gmail.com): hacer const
  inline QSerialPort::StopBits stop_bits(SerialPortAdaptor::StopBits stopbits) {
    return stop_bits_.find(stopbits)->second;
  }

  QSerialPort::BaudRate actived_baudrate_;
  QSerialPort::DataBits actived_databits_;
  QSerialPort::FlowControl actived_flow_control_;
  QSerialPort::Parity actived_parity_;
  QSerialPort::StopBits actived_stop_bits_;

// inline const std::string get_msg_error(CommDriverErrorCode err_code) const {
//   return msg_error_.find(err_code)->second;
// }
};
}  // namespace drivers
}  // namespace comms
}  // namespace ciaa
#endif  // COMMS_DRIVERS_QSERIALPORT_ADAPTER_H
