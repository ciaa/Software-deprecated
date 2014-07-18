/*! \file main.cpp
    \author Ezequiel Esposito <ejesposito\@debtech.com.ar>
    \date Thu Jan 9 14:28:58 CDT 2014

    \brief This file is TODO: .
    \brief This file become from: CIAA_v1_0/main.cpp
 
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


/** \defgroup Comms
 *  \brief The communication module
 *  \{
 *  	\defgroup Protocols
 * 		\brief TODO: it is ....
 * 		\{
 * 			\defgroup Modbus
 * 			\brief TODO: it is ....
 * 			\{
 * 			\}
 *		\}
 *
 * 		\defgroup Drivers
 * 		\brief TODO: it is ....
 * 		\{
 * 			\defgroup Ethernet
 * 			\brief TODO: it is ....
 * 			\{
 * 			\}
 *
 * 			\defgroup SerialPort
 *	 		\brief TODO: it is ....
 * 			\{
 * 			\}
 * 		\}
 *  \}
 */
 
/** \defgroup Coder
 *  \brief TODO: it is ....
 *  \{
 * 		\defgroup IEC61131Standard
 *  	\brief TODO: it is ....
 *  	\{
 *  	\}
 * 
 * 		\defgroup IL
 *  	\brief TODO: it is ....
 *  	\{
 *  	\}
 * 
 *  	\defgroup Ladder
 *  	\brief TODO: it is ....
 *  	\{
 *  	\}
 *  \}
 */

/** \defgroup Compiler
 * 	\brief TODO: it is ....
 *  \{
 *    \defgroup CompilerIL
 *  	\brief TODO: it is ....
 *  	\{
 *  	\}
 *  \}
*/

/** \defgroup Debugger
 * 	\brief TODO: it is ....
 *  \{
 *  \}
*/

/** \defgroup GUI
 * 	\brief TODO: it is ....
 *  \{
 *  \}
*/

/** \defgroup Programmer
 * 	\brief TODO: it is ....
 *  \{
 *  \}
*/

/** \defgroup System
 *  \brief TODO: it is ....
 *  \{
 *  	\defgroup Base
 * 		\brief TODO: it is ....
 * 		\{
 *		\}
 * 
 * 		\defgroup ciaaFreescale
 * 		\brief TODO: it is ....
 * 		\{
 * 		\}
 *
 * 		\defgroup ciaaNXP
 * 		\brief TODO: it is ....
 * 		\{
 * 		\}
 * 
 *		\defgroup ciaaST
 * 		\brief TODO: it is ....
 * 		\{
 * 		\}
 *  \}
*/

 
#include <QApplication>

#include "GUI/MainWindow/ciaaMainWindow_Controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ciaaMainWindow_Controller w;
    w.show();
    
    return a.exec();
}
