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


/** \defgroup Comms Módulo de Comunicación
 *  \brief El software de la CIAA contará con un Módulo de Comunicación, cuya
 *  \brief funcionalidad será establecer comunicaciones con la CIAA.
 *  \{
 *  	\defgroup Protocols TODO: it is ....
 * 		\brief TODO: it is ....
 * 		\{
 * 			\defgroup Modbus TODO: it is ....
 * 			\brief TODO: it is ....
 * 			\{
 * 			\}
 *		\}
 *
 * 		\defgroup Drivers TODO: it is ....
 * 		\brief TODO: it is ....
 * 		\{
 * 			\defgroup Ethernet TODO: it is ....
 * 			\brief TODO: it is ....
 * 			\{
 * 			\}
 *
 * 			\defgroup SerialPort TODO: it is ....
 *	 		\brief TODO: it is ....
 * 			\{
 * 			\}
 * 		\}
 *  \}
 */
 
/** \defgroup Coder Módulo de Codificación
 *  \brief El software de la CIAA contará con un Módulo de Codificación, cuya
 *  \brief funcionalidad será permitir a los usuarios crear y editar los
 *  \brief programas que luego ejecutará la CIAA.
 *  \{
 * 		\defgroup IEC61131Standard TODO: it is ....
 *    \brief
 *  	\brief TODO: it is ....
 *  	\{
 *  	\}
 * 
 * 		\defgroup IL TODO: it is ....
 *  	\brief TODO: it is ....
 *  	\{
 *  	\}
 * 
 *  	\defgroup Ladder TODO: it is ....
 *  	\brief TODO: it is ....
 *  	\{
 *  	\}
 *  \}
 */

/** \defgroup Compiler Módulo  de  Compilación
 *  \brief El software de la CIAA contará con un Módulo de Compilación encargado
 *  \brief de  compilar  el  programa  escrito  mediante  el Módulo de
 *  \brief Codificación.
 *  \{
 *  \}
*/

/** \defgroup Debugger Módulo de Depuración
 *  \brief El software de la CIAA contará con un Módulo de Depuración, cuya
 *  \brief funcionalidad será obtener información del mapa de memoria de la
 *  \brief CIAA, para su visualización y/o edición.
 *  \{
 *  \}
*/

/** \defgroup GUI Interfaz Gráfica de Usuario
 * 	\brief El software de la CIAA contará con una Interfaz Gráfica de Usuario,
 *  \brief cuya funcionalidad será permitir a los usuarios de la plataforma CIAA
 * 	\brief realizar de manera gráfica las siguientes tareas:
 * 	\brief - Apertura y guardado de proyectos.
 *  \brief - Codificación.
 *  \brief - Compilación.
 *  \brief - Programación.
 *  \brief - Depuración.
 *  \{
 *  \}
*/

/** \defgroup Programmer Módulo de Programación
 *  \brief El software de la CIAA contará con un Módulo de Programación, cuya
 *  \brief funcionalidad será tomar el programa compilado, generado por el
 *  \brief Módulo de Compilación, y descargarlo al microcontrolador de la CIAA.
 *  \{
 *  \}
*/

/** \defgroup System TODO: it is ....
 *  \brief TODO: it is ....
 *  \{
 *  	\defgroup Base TODO: it is ....
 * 		\brief TODO: it is ....
 * 		\{
 *		\}
 * 
 * 		\defgroup ciaaFreescale TODO: it is ....
 * 		\brief TODO: it is ....
 * 		\{
 * 		\}
 *
 * 		\defgroup ciaaNXP TODO: it is ....
 * 		\brief TODO: it is ....
 * 		\{
 * 		\}
 * 
 *		\defgroup ciaaST TODO: it is ....
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
