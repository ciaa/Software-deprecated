/*! \brief Do not include this file in external modules.
    \file serial_port_tests.cc
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Thu Apr 24 18:44:27 CDT 2014

    \brief A enum class for errors in Comms.
    \brief This file is part of Comms module.
    \brief This file become from: Tests/Comms/Drivers/serial_port_tests.cc

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

#include <cstdio>

#include "Comms/Drivers/ciaa_comm_facade.h"
#include "config.h"  // NOLINT

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::fprintf(stderr, "Debe especificar el dispositivo virtual.\n");
    exit(EXIT_FAILURE);
  }
  ciaaCommFacade s(argv[1]);

  CommDriverErrorCode ret = s.connect(100);
  if (ret == CommDriverErrorCode::OK) {
      std::cout << "All OK!!!" << std::endl;
  } else {
      std::cout << s.get_msg_error(s.connect(100)) << std::endl;
  }
  qDebug() << "clientaaaaa";
  if (ret == CommDriverErrorCode::OK) {
    return 0;
  } else {
    return 0;
  }
}
