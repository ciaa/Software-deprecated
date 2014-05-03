/*! \brief Do not include this file directly in external modules.
    \file ciaa_boostserialport_adapter.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Sun Apr 27 23:20:13 CDT 2014

    \brief This file is part of Comms/SerialPort module.
    \brief This file become from: Code/Comms/Drivers/SerialPort/ciaa_boostserialport_adapter.h

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

#ifndef COMMS_DRIVERS_SERIAL_PORT_ASIO_ADAPTOR_H
#define COMMS_DRIVERS_SERIAL_PORT_ASIO_ADAPTOR_H
#include <map>

#include <boost/asio/error.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/read.hpp>
#include <boost/asio/write.hpp>
#include <boost/asio/serial_port.hpp>
#include <boost/asio/deadline_timer.hpp>
#include <boost/lambda/bind.hpp>

#include "Code/Comms/Drivers/ciaa_comm_adapter_interface.h"
#include "Code/Comms/Drivers/SerialPort/ciaa_comm_drivers_serial_config.h"

namespace ciaa {
  namespace comms {
    namespace drivers {
      class ciaaBoostSerialPortAdapter : public ciaaCommAdapterInterface {
       public:
        ciaaBoostSerialPortAdapter(std::string device,
                                   SerialPortAdaptor::BaudRate baudrt,
                                   SerialPortAdaptor::DataBits databs,
                                   SerialPortAdaptor::FlowControl flowctl,
                                   SerialPortAdaptor::Parity prt,
                                   SerialPortAdaptor::StopBits stbs);
        ~ciaaBoostSerialPortAdapter() = default;

        ciaaBoostSerialPortAdapter(const ciaaBoostSerialPortAdapter&) = delete;
        ciaaBoostSerialPortAdapter& operator=(const ciaaBoostSerialPortAdapter&) = delete;  // NOLINT(whitespace/line_length)

        ciaaBoostSerialPortAdapter(const ciaaBoostSerialPortAdapter&&) = delete;
        ciaaBoostSerialPortAdapter& operator=(
            const ciaaBoostSerialPortAdapter&&) = delete;

        ciaaErrorCode connect(std::int32_t timeout) override {
          CIAA_UNUSED_PARAM(timeout);
          boost::system::error_code ec;
          serial_.open(device_, ec);

          ciaaErrorCode ret{ciaaErrorCode::OK};
          if (!ec) {
            serial_.set_option(boost::asio::serial_port_base::baud_rate(actived_baudrate_));
            serial_.set_option(boost::asio::serial_port_base::character_size(actived_databits_));
            serial_.set_option(boost::asio::serial_port_base::flow_control(actived_flow_control_));
            serial_.set_option(boost::asio::serial_port_base::parity(actived_parity_));
            serial_.set_option(boost::asio::serial_port_base::stop_bits(actived_stop_bits_));

            // 	boost::thread t(boost::bind(&boost::asio::io_service::run, &io_service_));

          } else {
            ret = ciaaErrorCode::connection_error;
          }

//          if(ec == boost::asio::error::misc_errors::already_open) {
//TODO
//          }
          return ret;
        }

        ciaaErrorCode disconnect(std::int32_t timeout) override {
          CIAA_UNUSED_PARAM(timeout);
          return ciaaErrorCode::OK;
        }

        ciaaErrorCode read(std::int32_t timeout,
                                 char *data,
                                 ciaa_size_t *n_bytes) override {
          deadline_.expires_from_now(boost::posix_time::millisec{timeout});
          boost::system::error_code ec = boost::asio::error::would_block;
          boost::asio::async_read(serial_, boost::asio::buffer(data, *n_bytes),
                                  [&data, &ec](const boost::system::error_code& err,
                                  std::size_t bytes_transferred){
            ec = err;
          });
          // Block until the asynchronous operation has completed.
          do io_service_.run_one(); while (ec == boost::asio::error::would_block);

          if (ec) {
            return ciaaErrorCode::read_error;
          } else {
            return ciaaErrorCode::OK;
          }
        }

        void read(char *data,
                  ciaa_size_t *n_bytes,
                  std::function<void(ciaaErrorCode, ciaa_size_t)> callback) {
          boost::asio::async_read(serial_, boost::asio::buffer(data, *n_bytes),
                                  [&callback, &n_bytes](const boost::system::error_code& err,
                                     std::size_t bytes_transferred){
            if (bytes_transferred == *n_bytes) {
              callback(ciaaErrorCode::OK, bytes_transferred);
            } else {
              callback(ciaaErrorCode::read_error, bytes_transferred);
            }
          });
          io_service_.run_one();
        }

        ciaaErrorCode write(std::int32_t timeout,
                                  const char *data,
                                  ciaa_size_t *n_bytes) override {
          deadline_.expires_from_now(boost::posix_time::millisec{timeout});
          boost::system::error_code ec = boost::asio::error::would_block;

          // FIXME(denisacostaq\@gmail.com): boost::asio::async_write(socket_, boost::asio::buffer(data), using boost::lambda::var(ec) = boost::lambda::_1); --> boost_1_55_0/doc/html/boost_asio/example/cpp03/timeouts/blocking_tcp_client.cpp
          boost::asio::async_write(serial_, boost::asio::buffer(data, *n_bytes),
                                  [&ec](const boost::system::error_code& err,
                                  std::size_t bytes_transferred){
            ec = err;
          });
          // Block until the asynchronous operation has completed.
          do io_service_.run_one(); while (ec == boost::asio::error::would_block);

          if (ec) {
            return ciaaErrorCode::write_error;
          } else {
            return ciaaErrorCode::OK;
          }
        }

        void write(const char *data,
                   ciaa_size_t *n_bytes,
                   std::function<void(ciaaErrorCode, ciaa_size_t)> callback) {
          boost::asio::async_write(serial_, boost::asio::buffer(data, *n_bytes),
                                  [&callback, &n_bytes](const boost::system::error_code& err,
                                  std::size_t bytes_transferred){
            if (bytes_transferred == *n_bytes) {
              callback(ciaaErrorCode::OK, bytes_transferred);
            } else {
              callback(ciaaErrorCode::write_error, bytes_transferred);
            }
          });
          io_service_.run_one();
        }

       private:
        std::string device_;
        boost::asio::io_service io_service_;
        boost::asio::serial_port serial_;
        boost::asio::deadline_timer deadline_;

        const std::map<SerialPortAdaptor::DataBits, boost::asio::serial_port::character_size> databits_ {
            std::pair<SerialPortAdaptor::DataBits, boost::asio::serial_port::character_size> {
              SerialPortAdaptor::DataBits::Data5,
              boost::asio::serial_port::character_size{5}
            },
            std::pair<SerialPortAdaptor::DataBits, boost::asio::serial_port::character_size> {
              SerialPortAdaptor::DataBits::Data6,
              boost::asio::serial_port::character_size{6}
            },
            std::pair<SerialPortAdaptor::DataBits, boost::asio::serial_port::character_size> {
              SerialPortAdaptor::DataBits::Data7,
              boost::asio::serial_port::character_size{7}
            },
            std::pair<SerialPortAdaptor::DataBits, boost::asio::serial_port::character_size> {
              SerialPortAdaptor::DataBits::Data8,
              boost::asio::serial_port::character_size{8}
            }
          };

          const std::map<SerialPortAdaptor::FlowControl, boost::asio::serial_port::flow_control::type> flow_control_ {  // NOLINT(whitespace/line_length)
            std::pair<SerialPortAdaptor::FlowControl, boost::asio::serial_port::flow_control::type> {
              SerialPortAdaptor::FlowControl::HardwareControl,
              boost::asio::serial_port::flow_control::type::hardware
            },
            std::pair<SerialPortAdaptor::FlowControl, boost::asio::serial_port::flow_control::type> {
              SerialPortAdaptor::FlowControl::NoFlowControl,
              boost::asio::serial_port::flow_control::type::none
            },
            std::pair<SerialPortAdaptor::FlowControl, boost::asio::serial_port::flow_control::type> {
              SerialPortAdaptor::FlowControl::SoftwareControl,
              boost::asio::serial_port::flow_control::type::software
            }
          };

          const std::map<SerialPortAdaptor::Parity, boost::asio::serial_port::parity::type> parity_ {
            std::pair<SerialPortAdaptor::Parity, boost::asio::serial_port::parity::type> {
              SerialPortAdaptor::Parity::NoParity,
              boost::asio::serial_port::parity::type::none
            },
            std::pair<SerialPortAdaptor::Parity, boost::asio::serial_port::parity::type> {
              SerialPortAdaptor::Parity::EvenParity,
              boost::asio::serial_port::parity::type::even
            },
            std::pair<SerialPortAdaptor::Parity, boost::asio::serial_port::parity::type> {
              SerialPortAdaptor::Parity::OddParity,
              boost::asio::serial_port::parity::type::odd
            }
            // FIXME(denisacostaq\@gmail.com): poner una condicional de preprocesado
            // para cuando se use boost, en el contructor
            /*std::pair<SerialPortAdaptor::Parity, boost::asio::serial_port::parity> {
              SerialPortAdaptor::Parity::SpaceParity,
              boost::asio::serial_port::parity::type::space
            },
            std::pair<SerialPortAdaptor::Parity, boost::asio::serial_port::parity> {
              SerialPortAdaptor::Parity::MarkParity,
              boost::asio::serial_port::parity::type
            }*/

          };

          const std::map<SerialPortAdaptor::StopBits, boost::asio::serial_port::stop_bits::type> stop_bits_{
            std::pair<SerialPortAdaptor::StopBits, boost::asio::serial_port::stop_bits::type> {
              SerialPortAdaptor::StopBits::OneStop,
              boost::asio::serial_port::stop_bits::type::one  //FIXME(denisacostaq@gmail.com): arreglar contra el de abajo
            },
            std::pair<SerialPortAdaptor::StopBits, boost::asio::serial_port::stop_bits::type> {
              SerialPortAdaptor::StopBits::OneAndHalfStop,
              boost::asio::serial_port::stop_bits::type::onepointfive  //FIXME(denisacostaq@gmail.com): arreglar contra el de abajo
            },
            std::pair<SerialPortAdaptor::StopBits, boost::asio::serial_port::stop_bits::type> {
              SerialPortAdaptor::StopBits::TwoStop,
              boost::asio::serial_port::stop_bits::type::two
            }
          };

          // TODO(denisacostaq@gmail.com): hacer const
          inline boost::asio::serial_port::character_size databits(SerialPortAdaptor::DataBits databit) {
            return databits_.find(databit)->second;
          }

          // TODO(denisacostaq@gmail.com): hacer const
          inline boost::asio::serial_port::flow_control::type flow_control(SerialPortAdaptor::FlowControl flowcontrol) {  // NOLINT(whitespace/line_length)
            return flow_control_.find(flowcontrol)->second;
          }

          // TODO(denisacostaq@gmail.com): hacer const
          inline boost::asio::serial_port::parity::type parity(SerialPortAdaptor::Parity pari) {
            return parity_.find(pari)->second;
          }

          // TODO(denisacostaq@gmail.com): hacer const
          inline boost::asio::serial_port::stop_bits::type stop_bits(SerialPortAdaptor::StopBits stopbits) {
            return stop_bits_.find(stopbits)->second;
          }

        boost::asio::serial_port::baud_rate actived_baudrate_;
        boost::asio::serial_port::character_size actived_databits_;
        boost::asio::serial_port::flow_control::type actived_flow_control_;
        boost::asio::serial_port::parity::type actived_parity_;
        boost::asio::serial_port::stop_bits::type actived_stop_bits_;

        void check_deadline() {
          if (deadline_.expires_at() <= boost::asio::deadline_timer::traits_type::now()) {
            serial_.cancel();
            deadline_.expires_at(boost::posix_time::pos_infin);
          }
          // Put the actor back to sleep.
          //FIXME(denisacostaq\@gmail.com): c++11
          deadline_.async_wait(boost::lambda::bind(
                                 &ciaaBoostSerialPortAdapter::check_deadline,
                                 this));
        }
      };
    }  // namespace ciaa
  }  // namespace comms
}  // namespace drivers
#endif  // COMMS_DRIVERS_SERIAL_PORT_ASIO_ADAPTOR_H
