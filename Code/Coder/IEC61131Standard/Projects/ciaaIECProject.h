/*! \file ciaaIECProject.h
    \author Ezequiel Esposito <ejesposito\@debtech.com.ar>
    \date Mon Jan 27 12:08:11 CDT 2014

    \brief This file is TODO: see ciaaDriversSerialPort
    \brief This file become from: CIAA_v1_0/Coder/IEC61131Standard/Projects/ciaaIECProject.h

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

#ifndef CIAAIECPROJECT_H
#define CIAAIECPROJECT_H

#include <vector>

#include "Code/Coder/IEC61131Standard/ConfigElements/Configurations/ciaaIECConfig.h"
#include "Code/Coder/IEC61131Standard/ConfigElements/Resources/ciaaIECResource.h"
#include "Code/Coder/IEC61131Standard/ConfigElements/Tasks/ciaaIECTask.h"

#include "Code/Coder/IEC61131Standard/Blocks/ciaaIECBaseBlock.h"

/*! \brief ciaaIECProject has the project in terms of IEC61132 standard
 *  \ingroup Projects
 */
class ciaaIECProject
{
    public:
        ciaaIECProject();

    private:
        DISALLOW_COPY_AND_ASSIGN (ciaaIECProject);

        /*! \brief used by the standard. */
        ciaaIECConfig* pConfigElement;

        /*! \brief used by the standard. */
        ciaaIECResource* pResourceElement;

        /*! \brief used by the standard.
            \brief has the program in terms of structs.
        */
        ciaaIECTask* pTaskElement;
};

#endif // CIAAIECPROJECT_H
