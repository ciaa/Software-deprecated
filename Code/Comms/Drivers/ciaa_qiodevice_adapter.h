/*! \brief Do not include this file directly in external modules.
    \file ciaa_qiodevice_adapter.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Mon Apr 28 14:09:31 CDT 2014

    \brief This file is part of Comms module.
    \brief This file become from: Code/Comms/Drivers/ciaa_qiodevice_adapter.h

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

#ifndef COMMS_DRIVERS_CIAA_QIODEVICE_ADAPTER_H
#define COMMS_DRIVERS_CIAA_QIODEVICE_ADAPTER_H

#include <QtNetwork/QTcpSocket>

#include "Code/Comms/Drivers/ciaa_comm_adapter_interface.h"

class ciaaCommQIODeviceAdapter : public ciaaCommAdapterInterface {
 public:
  explicit ciaaCommQIODeviceAdapter(QIODevice *conexion);
  ~ciaaCommQIODeviceAdapter();

  ciaaCommQIODeviceAdapter(const ciaaCommQIODeviceAdapter&) = delete;
  ciaaCommQIODeviceAdapter& operator=(const ciaaCommQIODeviceAdapter&) = delete;

  ciaaCommQIODeviceAdapter(const ciaaCommQIODeviceAdapter&&) = delete;
  ciaaCommQIODeviceAdapter& operator=(const ciaaCommQIODeviceAdapter&&) =delete;

  /*! \brief read Read n_bytes and put it into data.
   * \param timeout
   * \param data
   * \param n_bytes
   * \warning Is very important fot itself implementation try read first
   *  beacause if tha data are available the readyRead() signal no are performed
   *  beafore.
   * \return
   */
  CommDriverErrorCode read(std::int32_t timeout,
                           char *data,
                           ciaa_size_t *n_bytes) override;
  void read(char *data,
            ciaa_size_t *n_bytes,
            std::function<void(CommDriverErrorCode, ciaa_size_t)> callback);


  CommDriverErrorCode write(std::int32_t timeout,
                            const char *data,
                            ciaa_size_t *n_bytes) override;

  void write(const char *data,
             ciaa_size_t *n_bytes,
             std::function<void(CommDriverErrorCode, ciaa_size_t)> callback);

 private:
  // WARNING(denisacostaq\@gmail.com): do not make this visible fot chields
    QIODevice *conexion_;
};

#endif  // COMMS_DRIVERS_CIAA_QIODEVICE_ADAPTER_H
