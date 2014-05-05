/*! \file ciaaIECBaseElement.h
    \author Ezequiel Esposito <ejesposito\@debtech.com.ar>
    \date Thu Jan 9 14:28:58 CDT 2014

    \brief This file is TODO: see ciaaDriversSerialPort
    \brief This file become from: CIAA_v1_0/Coder/IEC61131Standard/ciaaIECBaseElement.h

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

#ifndef CIAAIECBASEELEMENT_H
#define CIAAIECBASEELEMENT_H

#include <cstdint>

#include "Code/Defines/ciaaGlobalMacros.h"

/*! \brief ciaaIECBaseElement is the base class for all IEC 61131 standard's elements
 *  \brief ciaaIECBaseElement has the private struct ciaaIECBaseElement_TSerializable.
 *  \brief This struct has the all the information of the element.
 *  \brief The variable type in the struct is an unique identifier for the element type.
 *  \brief The variable data in the struct is a generic pointer for the particular element data.
 *  \brief When the program is sended to the CIAA's firmware, the ciaaIECBaseElement_TSerializable is serialized to bytes. The firmware then reconstructs the struct.
 *  \ingroup IEC61131Standard
 */
class ciaaIECBaseElement
{
    public:
        ciaaIECBaseElement();

    private:
        DISALLOW_COPY_AND_ASSIGN(ciaaIECBaseElement);

        struct ciaaIECBaseElement_TSerializable
        {
            uint32_t type;
            void* data;
        };

        /*! \brief Serialize is a virtual method for transform data to bytes
         *  \param pBuffer is the bytes buffer where the data will be added
         *  \return the buffer modified
         */
        virtual uint8_t* Serialize (uint8_t pBuffer)
        {
          //FIXME(Ezequiel): esto lo puso alvaro para que compilara.
        }
};

#endif // CIAAIECBASEELEMENT_H
