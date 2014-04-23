/*! \file ciaaGlobalMacros.h
    \author Ezequiel Esposito <ejesposito\@debtech.com.ar>
    \date Thu Jan 9 14:28:58 CDT 2014

    \brief This file is TODO: see ciaaSerialPort
    \brief This file become from: CIAA_v1_0/Defines/ciaaGlobalMacros.h

    \attention <h1><center>&copy; COPYRIGHT
    GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007</center></h1>

    \copyright

    <h3>This file is part of CIAA project (Computadora Industrial Argentina Abierta).</h3>
    Copyright (C) 2014 Ezequiel Esposito <ejesposito\@debtech.com.ar>

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

#ifndef CIAAGLOBALMACROS_H
#define CIAAGLOBALMACROS_H

/*! \brief DISALLOW_COPY_AND_ASSIGN Desabilita contructor de copia y operador de asignacion.
  \brief Desavilitar por defecto la habilidad de las clases de ser copiadas por
  \brief copia y por asignacion. Se pone en el ambito privado de manera que un
  \brief error de copia o asignacion que no sea debidamente tratado se detecte
  \brief en tiempo de compilacion. En caso de querer usar estas facilidades concientemente
  \brief se debe eliminar la macro y reimplementar las funcionalidades debidamente.
  \param TypeName El tipo es la misma clase en que se utiliza.
*/
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
TypeName(const TypeName&); \
void operator=(const TypeName&)

#define CIAA_UNUSED_PARAM(unusedparam) (void)unusedparam

#endif // CIAAGLOBALMACROS_H
