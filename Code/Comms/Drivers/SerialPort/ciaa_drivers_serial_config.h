/*! \brief Do not include this file directly in external modules.
    \file ciaa_drivers_serial_config.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Mon Apr 28 00:57:42 CDT 2014

    \attention <h1><center><strong>&copy;COPYRIGHT 2014 </strong>[<strong>ACSE</strong>]
               [ACSE-URL] & [<strong>CADIEEL</strong>][CADIEEL-URL]</center></h1>

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice,
     this list of conditions and the following disclaimer.

    2. Redistributions in binary form must reproduce the above copyright notice,
     this list of conditions and the following disclaimer in the documentation
     and/or other materials provided with the distribution.

    3. Neither the name of the copyright holder nor the names of its
     contributors may be used to endorse or promote products derived from this
     software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
    POSSIBILITY OF SUCH DAMAGE.

    \brief This are some enums for serial por configuration.
    \brief This file is part of [<strong>CIAA Project</strong>][proyecto-ciaa-URL]
    \brief , especifically in the [<strong>PC Software subproject</strong>]
    \brief [proyecto-ciaa-PCSoftware-URL], in the Comms/Drivers module.\n
    \brief This file become from: Code/Comms/Drivers/SerialPort/ciaa_drivers_serial_config.h

    [ACSE-URL]: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/ "Asociación Civil para la Investigación, Promoción y Desarrollo de los Sistemas Electrónicos Embebidos"
    [CADIEEL-URL]: http://www.cadieel.org.ar "Cámara de Industrias Electrónicas, Electromecánicas y Luminotécnicas"
    [proyecto-ciaa-URL]: http://proyecto-ciaa.com.ar "Proyecto CIAA(Computador Industrial Abierta Argentina)"
    [proyecto-ciaa-PCSoftware-URL]: http://proyecto-ciaa.com.ar/gggg "PCSoftware bla bla"
*/


#ifndef COMM_DRIVER_SERIALPORT_CONFIG_H
#define COMM_DRIVER_SERIALPORT_CONFIG_H

// enum Direction  {
//    Input = 1,
//    Output = 2,
//    AllDirections = Input | Output
// };

//  FIXME(denisacostaq@gmail.com): esto hay que quitarlo
struct SerialPortAdaptor {
 public:
  enum class BaudRate {
      Baud1200 = 1200,
      Baud2400 = 2400,
      Baud4800 = 4800,
      Baud9600 = 9600,
      Baud19200 = 19200,
      Baud38400 = 38400,
      Baud57600 = 57600,
      Baud115200 = 115200,
      UnknownBaud = -1  // TODO(denisacostaq\@gmail.com): remove this option
  };

  enum class DataBits {
      Data5 = 5,
      Data6 = 6,
      Data7 = 7,
      Data8 = 8,
      UnknownDataBits = -1  // TODO(denisacostaq\@gmail.com): remove this option
  };

  enum class Parity {
      NoParity = 0,
      EvenParity = 2,
      OddParity = 3,
      SpaceParity = 4,
      MarkParity = 5,
      UnknownParity = -1  // TODO(denisacostaq\@gmail.com): remove this option
  };

  enum class StopBits {
      OneStop = 1,
      OneAndHalfStop = 3,
      TwoStop = 2,
      UnknownStopBits = -1  // TODO(denisacostaq\@gmail.com): remove this option
  };

  enum class FlowControl {
      NoFlowControl,
      HardwareControl,
      SoftwareControl,
      UnknownFlowControl = -1  // TODO(denisacostaq\@gmail.com): remove this option  // NOLINT(whitespace/line_length)
  };
};

#endif  // COMM_DRIVER_SERIALPORT_CONFIG_H
