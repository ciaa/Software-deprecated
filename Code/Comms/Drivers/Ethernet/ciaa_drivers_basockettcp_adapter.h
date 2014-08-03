/*! \brief Do not include this file directly in external modules.
    \file ciaa_drivers_basockettcp_adapter.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Sun Apr 27 22:51:04 CDT 2014

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
    \brief This file become from: Comms/Drivers/Ethernet/ciaa_drivers_basockettcp_adapter.h

    [ACSE-URL]: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/ "Asociación Civil para la Investigación, Promoción y Desarrollo de los Sistemas Electrónicos Embebidos"
    [CADIEEL-URL]: http://www.cadieel.org.ar "Cámara de Industrias Electrónicas, Electromecánicas y Luminotécnicas"
    [proyecto-ciaa-URL]: http://proyecto-ciaa.com.ar "Proyecto CIAA(Computador Industrial Abierta Argentina)"
    [proyecto-ciaa-PCSoftware-URL]: http://proyecto-ciaa.com.ar/gggg "PCSoftware bla bla"
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

#include "Code/Comms/Drivers/ciaa_drivers_ioservice_adapter.h"

namespace ciaa {
namespace comms {
namespace drivers {
class ciaaBATCPSocketAdapter : public ciaaBAIOServiceAdapter {
 public:
  ciaaBATCPSocketAdapter(std::string host, std::uint16_t port);
  ~ciaaBATCPSocketAdapter() = default;

  ciaaBATCPSocketAdapter(
      const ciaaBATCPSocketAdapter&) = delete;
  ciaaBATCPSocketAdapter& operator=(
      const ciaaBATCPSocketAdapter&) = delete;

  ciaaBATCPSocketAdapter(
      const ciaaBATCPSocketAdapter&&) = delete;
  ciaaBATCPSocketAdapter& operator=(
      const ciaaBATCPSocketAdapter&&) = delete;

  ciaaDriversErrorCode connect(std::chrono::milliseconds timeout) override {
    CIAA_UNUSED_PARAM(timeout);
//    ba::io_service io_service;
    ba::ip::tcp::resolver resolver{io_service_};
    std::ostringstream stream;
    stream << port_;
    ba::ip::tcp::resolver::query query{ba::ip::tcp::v4(),
                                       host_.c_str(),
                                       stream.str().c_str()};
    ciaaDriversErrorCode ret{ciaaDriversErrorCode::OK};
    try {
      ba::connect(socket_, resolver.resolve(query));
    } catch (boost::system::system_error& err) {
      std::fprintf(stderr, "WHAT? %s", err.what());
      ret = ciaaDriversErrorCode::connection_error;
    }
    return ret;
  }

  ciaaDriversErrorCode disconnect(std::chrono::milliseconds timeout) override {
    CIAA_UNUSED_PARAM(timeout);
    ciaaDriversErrorCode ret{ciaaDriversErrorCode::OK};
    try {
      socket_.close();
    } catch (boost::system::system_error err) {
      std::printf("FULA: %s", err.what());
      ret = ciaaDriversErrorCode::disconnect_error;
    }
    return ret;
  }

  ciaaDriversErrorCode read(std::chrono::milliseconds timeout,
                           char *data,
                           ciaa_size_t *n_bytes) override {
    deadline_.expires_from_now(boost::posix_time::millisec{timeout.count()});
    boost::system::error_code ec = ba::error::would_block;
    ba::async_read(socket_, ba::buffer(data, *n_bytes),
                            [&data, &ec](
                              const boost::system::error_code& err,
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
    ba::async_read(socket_,
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
    // ba::async_write(socket_, ba::buffer(data), using
    // boost::lambda::var(ec) = boost::lambda::_1);
    // --> boost_1_55_0/doc/html/boost_asio/example/
    // cpp03/timeouts/blocking_tcp_client.cpp
    ba::async_write(socket_,
                    ba::buffer(data, *n_bytes),
                    [&ec](
                        const boost::system::error_code& err,
                        std::size_t) {
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
    ba::async_write(socket_,
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
  std::string host_;
  int port_;
  ba::io_service io_service_;
  ba::ip::tcp::socket socket_;
  ba::deadline_timer deadline_;

  void check_deadline() {
    if (deadline_.expires_at() <= ba::deadline_timer::traits_type::now()) {
      socket_.cancel();
      deadline_.expires_at(boost::posix_time::pos_infin);
    }
    // Put the actor back to sleep.
    // FIXME(denisacostaq\@gmail.com): c++11
    deadline_.async_wait(boost::lambda::bind(
                           &ciaaBATCPSocketAdapter::check_deadline,
                           this));
  }
};
}  // namespace drivers
}  // namespace comms
}  // namespace ciaa
#endif  // COMMS_DRIVERS_TCP_ASIO_ADAPTOR_H
