/*! \brief Do not include this file directly in external modules.
    \file ciaa_comm_driver_error_code.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Fri Mar 21 00:44:09 CDT 2014

    \brief A enum class for errors in Comms.
    \brief This file is part of Comms module.
    \brief This file become from: Code/Comms/Drivers/ciaa_comm_driver_error_code.h

    \attention <h1><center>&copy; COPYRIGHT
    GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007</center></h1>

    \copyright

    <h3>
      This file is part of
      <a class="el" href="http://proyecto-ciaa.com.ar">
        <h3>
          CIAA project (Computadora Industrial Argentina Abierta).
        </h3>
      </a>
    </h3>
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

#ifndef COMM_DRIVER_ERROR_CODE_H
#define COMM_DRIVER_ERROR_CODE_H

/*!
 * \brief The CommDriverErrorCode enum
 * \ingroup Drivers
 */
enum class CommDriverErrorCode
{
  Ok,                          /**< General operation without errors. */
  access_error,                /**< Application lacked the required privileges. */
  resource_error,              /**< The local system ran out of resources (e.g., too many fd). */
  connection_error,            /**< The connect operation fail or the current connection has been broken. */
  inuse_error,                 //TODO<denisacostaq\@gmail.com>               /**< The device is busy. */
  unsupported_operation_error, //TODO<denisacostaq\@gmail.com>: ej escribir un dispositivo de solo lectura
  unfinished_operation_error,  /**< The last operation attempted has not finished yet (still in progress in the background). */
  temporary_error,             /**< You can retry the operation later. */
  disconnect_error,            /**< Could not disconnect the device. */
  read_error,                   /**< The read operation has been fail. */
  write_error,                  /**< The write operation has been fail. */
  timeout_error,                /**< The operation fail by timeout. */
  unknown_error                /**< An unidentified error occurred. */
};
#endif // COMM_DRIVER_ERROR_CODE_H
