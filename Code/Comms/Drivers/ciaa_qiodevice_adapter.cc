/*! \brief Do not include this file directly in external modules.
    \file ciaa_qiodevice_adapter.cc
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Mon Apr 28 14:09:31 CDT 2014

    \brief This file is part of Comms module.
    \brief This file become from: Code/Comms/Drivers/ciaa_qiodevice_adapter.cc

    \attention <h1><center>&copy; COPYRIGHT
    GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007</center></h1>

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

#include "Code/Comms/Drivers/ciaa_qiodevice_adapter.h"

ciaaCommQIODeviceAdapter::ciaaCommQIODeviceAdapter(QIODevice *conexion)
  : conexion_{conexion} {
}

ciaaCommQIODeviceAdapter::~ciaaCommQIODeviceAdapter() {
  // WARNING(denisacostaq\@gmail.com): do not delete this(conexion_), this is a
  // reference of an automatic variable in the chields class;
}

// FIXME(denisacostaq\@gmail.com): arreglar esto, ver el .h \warning
CommDriverErrorCode ciaaCommQIODeviceAdapter::read(std::int32_t timeout,
                                                   char *data,
                                                   ciaa_size_t *n_bytes) {
  ciaa_size_t total_readed = conexion_->read(data, *n_bytes);
  if (total_readed != *n_bytes &&  // IF NOT, all ok!
      total_readed >= 0) {  // IF NOT, is an error!
    if (conexion_->waitForReadyRead(timeout)) {
      do {
        ciaa_size_t readed_in_transition =
            conexion_->read(data + total_readed, *n_bytes - total_readed);

        if (readed_in_transition >= 0) {  // IF NOT, is an error!
          total_readed += readed_in_transition;
          if (total_readed == *n_bytes) break;
        } else {
          break;
        }
      } while (conexion_->waitForReadyRead(timeout));
    }
  }

  if (total_readed == *n_bytes) {
    // std::cout << *n_bytes << " OKKKKK" << std::endl;
    return CommDriverErrorCode::OK;
  } else {
    // std::cout << *n_bytes << " FAIL" << std::endl;
    *n_bytes = total_readed;
    // TODO(<denisacostaq\@gmail.com>):
    return CommDriverErrorCode::read_error;
  }
}

void ciaaCommQIODeviceAdapter::read(char *data,
                               ciaa_size_t *n_bytes,
                               std::function<void(CommDriverErrorCode,
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
      callback(CommDriverErrorCode::OK, readed);
    }
    callback(CommDriverErrorCode::read_error, readed);
  });
  // FIXME(denisacostaq\@gmail.com): Debo poner esto hasta concretar una prueba
  // unitaria que no lo becesite.
  conexion_->waitForReadyRead(-1);
}

CommDriverErrorCode ciaaCommQIODeviceAdapter::write(std::int32_t timeout,
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
    conexion_->waitForBytesWritten(timeout);
    return CommDriverErrorCode::OK;
  } else {
    *n_bytes = total_writed;
    // TODO(<denisacostaq\@gmail.com>):
    return CommDriverErrorCode::write_error;
  }
}

void ciaaCommQIODeviceAdapter::write(const char *data,
                                ciaa_size_t *n_bytes,
                                std::function<void(CommDriverErrorCode,
                                                   ciaa_size_t)> callback) {
  QObject::disconnect(conexion_, &QTcpSocket::readyRead, nullptr, nullptr);
  QObject::connect(conexion_,
                   &QIODevice::bytesWritten,
                   [this, callback](qint64 bytes){
    QObject::disconnect(conexion_, &QTcpSocket::readyRead, nullptr, nullptr);
    callback(CommDriverErrorCode::OK, bytes);
  });
  conexion_->write(data, *n_bytes);
  // FIXME(denisacostaq\@gmail.com): Debo poner esto hasta concretar una prueba
  // unitaria que no lo becesite.
  conexion_->waitForBytesWritten(-1);
}
