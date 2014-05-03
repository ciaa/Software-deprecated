/*! \brief Do not include this file directly in external modules.
    \file ciaa_boosttcp_adapter.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Sun Apr 27 22:51:04 CDT 2014

    \brief This file is part of Comms/Drivers module.
    \brief This file become from: Comms/Drivers/Ethernet/ciaa_boosttcp_adapter.h

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
#ifndef COMMS_DRIVERS_TCP_ASIO_ADAPTOR_H
#define COMMS_DRIVERS_TCP_ASIO_ADAPTOR_H
#include <stdint.h>
#include <string>
#include <cmath>

#include <boost/bind.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/read.hpp>
#include <boost/asio/write.hpp>
#include <boost/asio/streambuf.hpp>
#include <boost/asio/deadline_timer.hpp>
#include <boost/asio/placeholders.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/lambda/bind.hpp>

#include "Code/Comms/Drivers/ciaa_comm_adapter_interface.h"

namespace ciaa {
  namespace comms {
    namespace drivers {
      class ciaaBoostAsiotcpSocketAdapter : public ciaaCommAdapterInterface {
       public:
        ciaaBoostAsiotcpSocketAdapter(std::string host, std::uint16_t port);
        ~ciaaBoostAsiotcpSocketAdapter() = default;

        ciaaBoostAsiotcpSocketAdapter(
            const ciaaBoostAsiotcpSocketAdapter&) = delete;
        ciaaBoostAsiotcpSocketAdapter& operator=(
            const ciaaBoostAsiotcpSocketAdapter&) = delete;

        ciaaBoostAsiotcpSocketAdapter(
            const ciaaBoostAsiotcpSocketAdapter&&) = delete;
        ciaaBoostAsiotcpSocketAdapter& operator=(
            const ciaaBoostAsiotcpSocketAdapter&&) = delete;

        ciaaErrorCode connect(std::int32_t timeout) override {
          CIAA_UNUSED_PARAM(timeout);
      //    boost::asio::io_service io_service;
          boost::asio::ip::tcp::resolver resolver{io_service_};
          boost::asio::ip::tcp::resolver::query query{boost::asio::ip::tcp::v4(),
                                                     host_.c_str(),
                                                     "8881"};// TODO(denisacostaq\@gmail.com)

          ciaaErrorCode ret{ciaaErrorCode::OK};
          try {
            boost::asio::connect(socket_, resolver.resolve(query));
          } catch (boost::system::system_error& err) {
            std::printf("FULA: %s", err.what());
            ret = ciaaErrorCode::connection_error;
          }
          return ret;
        }

        ciaaErrorCode disconnect(std::int32_t timeout) override {
          CIAA_UNUSED_PARAM(timeout);
          ciaaErrorCode ret{ciaaErrorCode::OK};
          try {
            socket_.close();
          } catch (boost::system::system_error err) {
            std::printf("FULA: %s", err.what());
            ret = ciaaErrorCode::disconnect_error;
          }
          return ret;
        }

        ciaaErrorCode read(std::int32_t timeout,
                                 char *data,
                                 ciaa_size_t *n_bytes) override {
          deadline_.expires_from_now(boost::posix_time::millisec{timeout});
          boost::system::error_code ec = boost::asio::error::would_block;
          boost::asio::async_read(socket_, boost::asio::buffer(data, *n_bytes),
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
          boost::asio::async_read(socket_, boost::asio::buffer(data, *n_bytes),
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
          boost::asio::async_write(socket_, boost::asio::buffer(data, *n_bytes),
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
          boost::asio::async_write(socket_, boost::asio::buffer(data, *n_bytes),
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
        std::string host_;
        int port_;
        boost::asio::io_service io_service_;
        boost::asio::ip::tcp::socket socket_;
        boost::asio::deadline_timer deadline_;

        void check_deadline() {
          if (deadline_.expires_at() <= boost::asio::deadline_timer::traits_type::now()) {
            socket_.cancel();
            deadline_.expires_at(boost::posix_time::pos_infin);
          }
          // Put the actor back to sleep.
          //FIXME(denisacostaq\@gmail.com): c++11
          deadline_.async_wait(boost::lambda::bind(
                                 &ciaaBoostAsiotcpSocketAdapter::check_deadline,
                                 this));
        }
      };
    }  // namespace ciaa
  }  // namespace comms
}  // namespace drivers
#endif  // COMMS_DRIVERS_TCP_ASIO_ADAPTOR_H
