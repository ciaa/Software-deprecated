/*! \brief Do not include this file directly in external modules.
    \file ciaa_drivers_baserialport_adapter.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Sun Apr 27 23:20:13 CDT 2014

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
    \brief This file become from: Code/Comms/Drivers/SerialPort/ciaa_drivers_baserialport_adapter.h

    [ACSE-URL]: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/ "Asociación Civil para la Investigación, Promoción y Desarrollo de los Sistemas Electrónicos Embebidos"
    [CADIEEL-URL]: http://www.cadieel.org.ar "Cámara de Industrias Electrónicas, Electromecánicas y Luminotécnicas"
    [proyecto-ciaa-URL]: http://proyecto-ciaa.com.ar "Proyecto CIAA(Computador Industrial Abierta Argentina)"
    [proyecto-ciaa-PCSoftware-URL]: http://proyecto-ciaa.com.ar/gggg "PCSoftware bla bla"
*/


#ifndef COMMS_DRIVERS_SERIAL_PORT_ASIO_ADAPTOR_H
#define COMMS_DRIVERS_SERIAL_PORT_ASIO_ADAPTOR_H
#include <map>
#include <exception>

#include <boost/asio/error.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/read.hpp>
#include <boost/asio/write.hpp>
#include <boost/asio/serial_port.hpp>
#include <boost/asio/deadline_timer.hpp>
#include <boost/lambda/bind.hpp>

#include "Code/Comms/Drivers/ciaa_drivers_ioservice_adapter.h"
#include "Code/Comms/Drivers/SerialPort/ciaa_drivers_serial_config.h"

namespace ciaa {
namespace comms {
namespace drivers {
class ciaaBASerialPortAdapter : public ciaaBAIOServiceAdapter {
 public:
  ciaaBASerialPortAdapter(std::string device,
                             SerialPortAdaptor::BaudRate baudrt,
                             SerialPortAdaptor::DataBits databs,
                             SerialPortAdaptor::FlowControl flowctl,
                             SerialPortAdaptor::Parity prt,
                             SerialPortAdaptor::StopBits stbs);
  ~ciaaBASerialPortAdapter() = default;

  ciaaBASerialPortAdapter(const ciaaBASerialPortAdapter&) = delete;
  ciaaBASerialPortAdapter& operator=(
      const ciaaBASerialPortAdapter&) = delete;

  ciaaBASerialPortAdapter(const ciaaBASerialPortAdapter&&) = delete;
  ciaaBASerialPortAdapter& operator=(
      const ciaaBASerialPortAdapter&&) = delete;

  ciaaDriversErrorCode connect(std::chrono::milliseconds timeout) override {
    // TODO(denisacostaq\@gmail.com): use the timeout for retry.
    CIAA_UNUSED_PARAM(timeout);
    boost::system::error_code ec;
    serial_.open(device_, ec);
    if (!ec)
      serial_.set_option(
          ba::serial_port_base::baud_rate(actived_baudrate_));
    if (!ec)
      serial_.set_option(
            ba::serial_port_base::character_size(actived_databits_));
    if (!ec)
      serial_.set_option(
            ba::serial_port_base::flow_control(actived_flow_control_));
    if (!ec)
      serial_.set_option(
            ba::serial_port_base::parity(actived_parity_));
    if (!ec)
      serial_.set_option(
            ba::serial_port_base::stop_bits(actived_stop_bits_));

    // TDOD(denisacostaq\@gmail.com):	boost::thread
    // t(boost::bind(&ba::io_service::run, &io_service_));

    ciaaDriversErrorCode ret{ciaaDriversErrorCode::OK};
    if (ec) {
      ret = asociated_error(ec);
      if (ret == ciaaDriversErrorCode::unknown_error) {
        ret = ciaaDriversErrorCode::connection_error;
      }
    }
    return ret;
  }

  ciaaDriversErrorCode disconnect(std::chrono::milliseconds timeout) override {
    // TODO(denisacostaq\@gmail.com): use the timeout for retry.
    CIAA_UNUSED_PARAM(timeout);

    ciaaDriversErrorCode ret{ciaaDriversErrorCode::OK};
    // TODO(denisacostaq\@gmail.com): replace this implementation by using
    // boost::system::error_code close(boost::system::error_code& ec)
    // same as ciaaDriversErrorCode connect(std::chrono::milliseconds timeout)
    // override.
    try {
     serial_.close();
    } catch (std::exception ex) {
      CIAA_UNUSED_PARAM(ex);
      // std::fprintf(stderr, "%s\n", ex.what());
      ret = ciaaDriversErrorCode::disconnect_error;
    }
    return ret;
  }

  ciaaDriversErrorCode read(std::chrono::milliseconds timeout,
                           char *data,
                           ciaa_size_t *n_bytes) override {
    deadline_.expires_from_now(boost::posix_time::millisec{timeout.count()});
    boost::system::error_code ec = ba::error::would_block;
    ba::async_read(serial_, ba::buffer(data, *n_bytes),
                            [&data, &ec](const boost::system::error_code& err,
                            std::size_t){
      ec = err;
    });
    // Block until the asynchronous operation has completed.
    do {
      io_service_.run_one();
    } while (ec == ba::error::would_block);

    ciaaDriversErrorCode ret{ciaaDriversErrorCode::OK};
    if (ec) {
      ret = asociated_error(ec);
      if (ret == ciaaDriversErrorCode::unknown_error) {
        ret = ciaaDriversErrorCode::read_error;
      }
    }
    return ret;
  }

  void read(char *data,
            ciaa_size_t *n_bytes,
            std::function<void(ciaaDriversErrorCode, ciaa_size_t)> callback) {
    ba::async_read(serial_,
                   ba::buffer(data, *n_bytes),
                   [this, &callback, &n_bytes](
                     const boost::system::error_code& ec,
                     std::size_t bytes_transferred) {
      if (bytes_transferred == *n_bytes) {
        callback(ciaaDriversErrorCode::OK, bytes_transferred);
      } else {
        ciaaDriversErrorCode ret{ciaaDriversErrorCode::OK};
        if (ec) {
          ret = asociated_error(ec);
          if (ret == ciaaDriversErrorCode::unknown_error) {
            ret = ciaaDriversErrorCode::read_error;
          }
        }
        callback(ret, bytes_transferred);
      }
    });
    io_service_.run_one();
  }

  ciaaDriversErrorCode write(std::chrono::milliseconds timeout,
                            const char *data,
                            ciaa_size_t *n_bytes) override {
    deadline_.expires_from_now(boost::posix_time::millisec{timeout.count()});
    boost::system::error_code ec = ba::error::would_block;

    // FIXME(denisacostaq\@gmail.com):
    // ba::async_write(socket_, ba::buffer(data), using boost::lambda::var(ec)
    // = boost::lambda::_1);
    // --> boost_1_55_0/doc/html/boost_asio/example/cpp03/
    // timeouts/blocking_tcp_client.cpp
    ba::async_write(serial_, ba::buffer(data, *n_bytes),
                            [&ec](const boost::system::error_code& err,
                            std::size_t){
      ec = err;
    });
    // Block until the asynchronous operation has completed.
    do {
      io_service_.run_one();
    } while (ec == ba::error::would_block);

    ciaaDriversErrorCode ret{ciaaDriversErrorCode::OK};
    if (ec) {
      ret = asociated_error(ec);
      if (ret == ciaaDriversErrorCode::unknown_error) {
        ret = ciaaDriversErrorCode::write_error;
      }
    }
    return ret;
  }

  void write(const char *data,
             ciaa_size_t *n_bytes,
             std::function<void(ciaaDriversErrorCode, ciaa_size_t)> callback) {
    ba::async_write(serial_,
                             ba::buffer(data, *n_bytes),
                             [this, &callback, &n_bytes](
                               const boost::system::error_code& ec,
                               std::size_t bytes_transferred) {
      if (bytes_transferred == *n_bytes) {
        callback(ciaaDriversErrorCode::OK, bytes_transferred);
      } else {
        ciaaDriversErrorCode ret{ciaaDriversErrorCode::OK};
        if (ec) {
          ret = asociated_error(ec);
          if (ret == ciaaDriversErrorCode::unknown_error) {
            ret = ciaaDriversErrorCode::write_error;
          }
        }
        callback(ret, bytes_transferred);
      }
    });
    io_service_.run_one();
  }

 private:
  std::string device_;
  ba::io_service io_service_;
  ba::serial_port serial_;
  ba::deadline_timer deadline_;

  const std::map<SerialPortAdaptor::DataBits,
                 ba::serial_port::character_size> databits_ {
    std::pair<SerialPortAdaptor::DataBits, ba::serial_port::character_size> {
      SerialPortAdaptor::DataBits::Data5,
      ba::serial_port::character_size{5}
    },
    std::pair<SerialPortAdaptor::DataBits, ba::serial_port::character_size> {
      SerialPortAdaptor::DataBits::Data6,
      ba::serial_port::character_size{6}
    },
    std::pair<SerialPortAdaptor::DataBits, ba::serial_port::character_size> {
      SerialPortAdaptor::DataBits::Data7,
      ba::serial_port::character_size{7}
    },
    std::pair<SerialPortAdaptor::DataBits, ba::serial_port::character_size> {
      SerialPortAdaptor::DataBits::Data8,
      ba::serial_port::character_size{8}
    }
  };

  const std::map<SerialPortAdaptor::FlowControl,
                 ba::serial_port::flow_control::type> flow_control_ {
    std::pair<SerialPortAdaptor::FlowControl,
              ba::serial_port::flow_control::type> {
      SerialPortAdaptor::FlowControl::HardwareControl,
      ba::serial_port::flow_control::type::hardware
    },
    std::pair<SerialPortAdaptor::FlowControl,
              ba::serial_port::flow_control::type> {
      SerialPortAdaptor::FlowControl::NoFlowControl,
      ba::serial_port::flow_control::type::none
    },
    std::pair<SerialPortAdaptor::FlowControl,
              ba::serial_port::flow_control::type> {
      SerialPortAdaptor::FlowControl::SoftwareControl,
      ba::serial_port::flow_control::type::software
    }
  };

  const std::map<SerialPortAdaptor::Parity,
                 ba::serial_port::parity::type> parity_ {
    std::pair<SerialPortAdaptor::Parity,
              ba::serial_port::parity::type> {
      SerialPortAdaptor::Parity::NoParity,
      ba::serial_port::parity::type::none
    },
    std::pair<SerialPortAdaptor::Parity,
              ba::serial_port::parity::type> {
      SerialPortAdaptor::Parity::EvenParity,
      ba::serial_port::parity::type::even
    },
    std::pair<SerialPortAdaptor::Parity,
              ba::serial_port::parity::type> {
      SerialPortAdaptor::Parity::OddParity,
      ba::serial_port::parity::type::odd
    }
    // FIXME(denisacostaq\@gmail.com): poner una condicional de preprocesado
    // para cuando se use boost, en el contructor
    /*std::pair<SerialPortAdaptor::Parity, ba::serial_port::parity> {
      SerialPortAdaptor::Parity::SpaceParity,
      ba::serial_port::parity::type::space
    },
    std::pair<SerialPortAdaptor::Parity, ba::serial_port::parity> {
      SerialPortAdaptor::Parity::MarkParity,
      ba::serial_port::parity::type
    }*/

  };

  const std::map<SerialPortAdaptor::StopBits,
                 ba::serial_port::stop_bits::type> stop_bits_ {
    std::pair<SerialPortAdaptor::StopBits,
              ba::serial_port::stop_bits::type> {
      SerialPortAdaptor::StopBits::OneStop,
      ba::serial_port::stop_bits::type::one  // FIXME(denisacostaq@gmail.com): arreglar contra el de abajo  // NOLINT(whitespace/line_length)
    },
    std::pair<SerialPortAdaptor::StopBits,
              ba::serial_port::stop_bits::type> {
      SerialPortAdaptor::StopBits::OneAndHalfStop,
      ba::serial_port::stop_bits::type::onepointfive  // FIXME(denisacostaq@gmail.com): arreglar contra el de abajo  // NOLINT(whitespace/line_length)
    },
    std::pair<SerialPortAdaptor::StopBits,
              ba::serial_port::stop_bits::type> {
      SerialPortAdaptor::StopBits::TwoStop,
      ba::serial_port::stop_bits::type::two
    }
  };

  // TODO(denisacostaq@gmail.com): hacer const
  inline ba::serial_port::character_size databits(
      SerialPortAdaptor::DataBits databit) {
    return databits_.find(databit)->second;
  }

  // TODO(denisacostaq@gmail.com): hacer const
  inline ba::serial_port::flow_control::type flow_control(
      SerialPortAdaptor::FlowControl flowcontrol) {
    return flow_control_.find(flowcontrol)->second;
  }

  // TODO(denisacostaq@gmail.com): hacer const
  inline ba::serial_port::parity::type parity(
      SerialPortAdaptor::Parity pari) {
    return parity_.find(pari)->second;
  }

  // TODO(denisacostaq@gmail.com): hacer const
  inline ba::serial_port::stop_bits::type stop_bits(
      SerialPortAdaptor::StopBits stopbits) {
    return stop_bits_.find(stopbits)->second;
  }

  ba::serial_port::baud_rate actived_baudrate_;
  ba::serial_port::character_size actived_databits_;
  ba::serial_port::flow_control::type actived_flow_control_;
  ba::serial_port::parity::type actived_parity_;
  ba::serial_port::stop_bits::type actived_stop_bits_;

  void check_deadline() {
    if (deadline_.expires_at() <= ba::deadline_timer::traits_type::now()) {
      serial_.cancel();
      deadline_.expires_at(boost::posix_time::pos_infin);
    }
    // Put the actor back to sleep.
    // FIXME(denisacostaq\@gmail.com): c++11
    deadline_.async_wait(boost::lambda::bind(
                           &ciaaBASerialPortAdapter::check_deadline,
                           this));
  }
};
}  // namespace drivers
}  // namespace comms
}  // namespace ciaa
#endif  // COMMS_DRIVERS_SERIAL_PORT_ASIO_ADAPTOR_H
