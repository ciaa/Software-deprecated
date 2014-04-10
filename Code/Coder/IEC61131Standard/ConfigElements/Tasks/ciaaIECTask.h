/*! \file ciaaIECTask.h
    \author Ezequiel Esposito <ejesposito\@debtech.com.ar>
    \date Mon Jan 27 12:08:11 CDT 2014

    \brief This file is TODO: see ciaaSerialPort
    \brief This file become from: CIAA_v1_0/Coder/IEC61131Standard/ConfigElements/Tasks/ciaaIECTask.h

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

#ifndef CIAAIECTASK_H
#define CIAAIECTASK_H

#include <vector>

#include "Defines/ciaaGlobalMacros.h"

#include "Coder/IEC61131Standard/ciaaIECBaseElement.h"

/*! \brief ciaIECTask has the program in terms of structs.
 *  \brief Those structs are saved in a vector of ciaaIECBaseElement.
 *  \brief The structs's data change from element to element.
 *  \ingroup Tasks
 */
class ciaaIECTask
{
    public:
        ciaaIECTask();

    private:
        DISALLOW_COPY_AND_ASSIGN(ciaaIECTask);

        /*! \brief Vector of pointers to IEC Base Elements used by the program to generate the code */
        std::vector<ciaaIECBaseElement*> vBaseElements;
};

#endif // CIAAIECTASK_H
