/*! \brief This file give the functionality to ciaaSymbolTable class.
    \file ciaa_compiler_symbol_table.cc
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Tue Jul 22 02:19:55 UTC 2014

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

    \brief This file is part of [<strong>CIAA Project</strong>][proyecto-ciaa-URL]
    \brief , especifically in the [<strong>PC Software subproject</strong>]
    \brief [proyecto-ciaa-PCSoftware-URL] for tests in the Compiler module.\n
    \brief This file become from: Code/Compiler/IEC61131Standard/Textuals/Textuals/IL/Scanner/ciaa_compiler_symbol_table.cc

    [ACSE-URL]: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/ "Asociación Civil para la Investigación, Promoción y Desarrollo de los Sistemas Electrónicos Embebidos"
    [CADIEEL-URL]: http://www.cadieel.org.ar "Cámara de Industrias Electrónicas, Electromecánicas y Luminotécnicas"
    [proyecto-ciaa-URL]: http://proyecto-ciaa.com.ar "Proyecto CIAA(Computador Industrial Abierta Argentina)"
    [proyecto-ciaa-PCSoftware-URL]: http://proyecto-ciaa.com.ar/gggg "PCSoftware bla bla"
*/

#include "Code/Compiler/IEC61131Standard/Textuals/Textuals/IL/Scanner/ciaa_compiler_symbol_table.h"

namespace ciaa {
namespace compiler {
namespace iec61131_3 {
namespace text {
namespace il {

ciaaSymbolTable::~ciaaSymbolTable() {
  for (ciaaSymbolInfo* item : _items) {
    delete item;
  }
}

std::vector<ciaaSymbolInfo*>::iterator ciaaSymbolTable::entry_of(
    std::string lexeme) {
  return std::find_if(
        _items.begin(),
        _items.end(),
        [&lexeme](ciaaSymbolInfo* a) {
          return a->lexeme() == lexeme;
        });
}

std::vector<ciaaSymbolInfo*>::iterator ciaaSymbolTable::add(
    std::string lexeme,
    ciaaSymbolInfo::tk_kind kind) {
  std::vector<ciaaSymbolInfo*>::iterator index{this->entry_of(lexeme)};
  if (index == _items.end()) {
      _items.push_back(new ciaaSymbolInfo(lexeme, kind));
      return _items.end() - 1;
  }
  return index;
}

}  // namespace il
}  // namespace text
}  // namespace iec61131_3
}  // namespace compiler
}  // namespace ciaa
