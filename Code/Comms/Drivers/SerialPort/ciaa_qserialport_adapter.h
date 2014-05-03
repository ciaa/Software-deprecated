/*! \brief Do not include this file directly in external modules.
    \file ciaa_qserialport_adapter.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Fri Mar 21 00:46:11 CDT 2014

    \brief This file is part of Comms/SerialPort module.
    \brief This file become from: Code/Comms/Drivers/SerialPort/ciaa_qserialport_adapter.h

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

#ifndef COMMS_DRIVERS_QSERIALPORT_ADAPTER_H
#define COMMS_DRIVERS_QSERIALPORT_ADAPTER_H

#include <map>

#include <QtSerialPort/QtSerialPort>

#include "Code/Comms/Drivers/ciaa_qiodevice_adapter.h"
#include "Code/Comms/Drivers/SerialPort/ciaa_comm_drivers_serial_config.h"

namespace ciaa {
  namespace comms {
    namespace drivers {
/*! \brief TODO<denisacostaq\@gmail.com>
 * \brief The ciaaQSerialPortAdapter class
 * \ingroup SerialPort
 */
class ciaaQSerialPortAdapter : public ciaaCommQIODeviceAdapter {
 public:
  // explicit ciaaQSerialPortAdapter(std::string device);
  ciaaQSerialPortAdapter(std::string device,
                         SerialPortAdaptor::BaudRate baudrt,
                         SerialPortAdaptor::DataBits databs,
                         SerialPortAdaptor::FlowControl flowctl,
                         SerialPortAdaptor::Parity prt,
                         SerialPortAdaptor::StopBits stbs);
  ~ciaaQSerialPortAdapter() = default;

  ciaaQSerialPortAdapter(const ciaaQSerialPortAdapter&) = delete;
  ciaaQSerialPortAdapter& operator=(const ciaaQSerialPortAdapter&) = delete;

  ciaaQSerialPortAdapter(const ciaaQSerialPortAdapter&&) = delete;
  ciaaQSerialPortAdapter& operator=(const ciaaQSerialPortAdapter&&) = delete;

  ciaaErrorCode connect(std::int32_t timeout) override;
  ciaaErrorCode disconnect(std::int32_t timeout) override;

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
      SerialPortAdaptor::Parity::SpaceParity,
      QSerialPort::Parity::SpaceParity
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
  inline QSerialPort::FlowControl flow_control(SerialPortAdaptor::FlowControl flowcontrol) {  // NOLINT(whitespace/line_length)
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
    }  // namespace ciaa
  }  // namespace comms
}  // namespace drivers
#endif  // COMMS_DRIVERS_QSERIALPORT_ADAPTER_H
