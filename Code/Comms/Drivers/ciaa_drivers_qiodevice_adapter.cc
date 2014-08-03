/*! \brief This file give the functionality to ciaaDriversQIODeviceAdapter class.
    \file ciaa_drivers_qiodevice_adapter.cc
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Mon Apr 28 14:09:31 CDT 2014

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
    \brief This file become from: Code/Comms/Drivers/ciaa_drivers_qiodevice_adapter.cc

    [ACSE-URL]: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/ "Asociación Civil para la Investigación, Promoción y Desarrollo de los Sistemas Electrónicos Embebidos"
    [CADIEEL-URL]: http://www.cadieel.org.ar "Cámara de Industrias Electrónicas, Electromecánicas y Luminotécnicas"
    [proyecto-ciaa-URL]: http://proyecto-ciaa.com.ar "Proyecto CIAA(Computador Industrial Abierta Argentina)"
    [proyecto-ciaa-PCSoftware-URL]: http://proyecto-ciaa.com.ar/gggg "PCSoftware bla bla"
*/


#include "Code/Comms/Drivers/ciaa_drivers_qiodevice_adapter.h"

namespace ciaa {
namespace comms {
namespace drivers {
  ciaaDriversQIODeviceAdapter::ciaaDriversQIODeviceAdapter(QIODevice *conexion)
    : conexion_{conexion} {
  }

  ciaaDriversQIODeviceAdapter::~ciaaDriversQIODeviceAdapter() {
    // WARNING(denisacostaq\@gmail.com): do not delete this(conexion_), this is
    // a reference of an automatic variable in the chields class;
  }

  // FIXME(denisacostaq\@gmail.com): arreglar esto, ver el .h \warning
  ciaaDriversErrorCode ciaaDriversQIODeviceAdapter::read(
      std::chrono::milliseconds timeout,
      char *data,
      ciaa_size_t *n_bytes) {
    ciaa_size_t total_readed = conexion_->read(data, *n_bytes);
    if (total_readed != *n_bytes &&  // IF NOT, all ok!
        total_readed >= 0) {  // IF NOT, is an error!
      if (conexion_->waitForReadyRead(timeout.count())) {
        do {
          ciaa_size_t readed_in_transition =
              conexion_->read(data + total_readed, *n_bytes - total_readed);

          if (readed_in_transition >= 0) {  // IF NOT, is an error!
            total_readed += readed_in_transition;
            if (total_readed == *n_bytes) break;
          } else {
            break;
          }
        } while (conexion_->waitForReadyRead(timeout.count()));
      }
    }

    if (total_readed == *n_bytes) {
      // std::cout << *n_bytes << " OKKKKK" << std::endl;
      return ciaaDriversErrorCode::OK;
    } else {
      // std::cout << *n_bytes << " FAIL" << std::endl;
      *n_bytes = total_readed;
      // TODO(<denisacostaq\@gmail.com>):
      return ciaaDriversErrorCode::read_error;
    }
  }

  void ciaaDriversQIODeviceAdapter::read(char *data,
                                 ciaa_size_t *n_bytes,
                                 std::function<void(ciaaDriversErrorCode,
                                                    ciaa_size_t)> callback) {
    // FIXME(denisacostaq\@gmail.com):provar primero si hay datos disponibles:
    // qint64 readed = conexion_->read(data, *n_bytes);
    QObject::disconnect(conexion_, &QTcpSocket::readyRead, nullptr, nullptr);
    conexion_->connect(conexion_,
                     &QTcpSocket::readyRead,
                     [this, data, callback, n_bytes]{
      QObject::disconnect(conexion_, &QTcpSocket::readyRead, nullptr, nullptr);
      qint64 readed = conexion_->read(data, *n_bytes);
      if (*n_bytes == readed) {
        callback(ciaaDriversErrorCode::OK, readed);
      } else {
        callback(ciaaDriversErrorCode::read_error, readed);
      }
    });
    // FIXME(denisacostaq\@gmail.com): Debo poner esto hasta concretar unaprueba
    // unitaria que no lo necesite.
    conexion_->waitForReadyRead(-1);
  }

  ciaaDriversErrorCode ciaaDriversQIODeviceAdapter::write(
      std::chrono::milliseconds timeout,
      const char *data,
      ciaa_size_t *n_bytes) {
    ciaa_size_t total_writed = conexion_->write(data, *n_bytes);
    // FIXME(denisacostaq@gmail.com): deberia ser esto en lugar de el
    // socket_waitForBytesWritten(timeout); que hay en siguiente bloque ya que
    // si total_writed == *n_bytes es porque ya escribio todo.
    //  if (total_writed != *n_bytes &&  // IF NOT, all ok!
    //      total_writed >= 0) {  // IF NOT, is an error!
    //       if (!socket_waitForBytesWritten(timeout)) {
    //        *n_bytes = total_writed;
    //       }
    //  }

    if (total_writed == *n_bytes) {
      conexion_->waitForBytesWritten(timeout.count());
      return ciaaDriversErrorCode::OK;
    } else {
      *n_bytes = total_writed;
      // TODO(<denisacostaq\@gmail.com>):
      return ciaaDriversErrorCode::write_error;
    }
  }

  void ciaaDriversQIODeviceAdapter::write(const char *data,
                                  ciaa_size_t *n_bytes,
                                  std::function<void(ciaaDriversErrorCode,
                                                     ciaa_size_t)> callback) {
    QObject::disconnect(conexion_, &QTcpSocket::readyRead, nullptr, nullptr);
    QObject::connect(conexion_,
                     &QIODevice::bytesWritten,
                     [this, callback](qint64 bytes){
      QObject::disconnect(conexion_, &QTcpSocket::readyRead, nullptr, nullptr);
      callback(ciaaDriversErrorCode::OK, bytes);
    });
    conexion_->write(data, *n_bytes);
    // FIXME(denisacostaq\@gmail.com): Debo poner esto hasta concretar unaprueba
    // unitaria que no lo necesite.
     conexion_->waitForBytesWritten(-1);
  }
}  // namespace drivers
}  // namespace comms
}  // namespace ciaa
