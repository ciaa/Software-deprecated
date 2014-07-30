/*! \brief This file give the functionality to ciaaSequentialFunctionChartElements class.
    \file ciaa_compiler_sequential_function_chart_elements-def.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Sun Jul 27 22:37:18 UTC 2014

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
    \brief This file become from: Code/Compiler/IEC61131Standard/Textuals/Grammar/ciaa_compiler_sequential_function_chart_elements-def.h

    [ACSE-URL]: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/ "Asociación Civil para la Investigación, Promoción y Desarrollo de los Sistemas Electrónicos Embebidos"
    [CADIEEL-URL]: http://www.cadieel.org.ar "Cámara de Industrias Electrónicas, Electromecánicas y Luminotécnicas"
    [proyecto-ciaa-URL]: http://proyecto-ciaa.com.ar "Proyecto CIAA(Computador Industrial Abierta Argentina)"
    [proyecto-ciaa-PCSoftware-URL]: http://proyecto-ciaa.com.ar/gggg "PCSoftware bla bla"
*/

#ifndef CIAA_COMPILER_IEC_SEQUENTIAL_FUNCTION_CHART_ELEMENTS_DEF_H
#define CIAA_COMPILER_IEC_SEQUENTIAL_FUNCTION_CHART_ELEMENTS_DEF_H

#include "Code/Compiler/IEC61131Standard/Textuals/Grammar/ciaa_compiler_sequential_function_chart_elements.h"

#include "Code/Compiler/IEC61131Standard/Textuals/Grammar/ciaa_compiler_constants.h"
#include "Code/Compiler/IEC61131Standard/Textuals/Grammar/ciaa_compiler_variable.h"
#include "Code/Compiler/IEC61131Standard/Textuals/Grammar/ciaa_compiler_pou.h"

// TODO#include "Code/Compiler/IEC61131Standard/Textuals/Grammar/ciaa_compiler_instruction_list.h"

namespace ciaa {
namespace compiler {
namespace iec61131_3 {
template <typename Iterator>
template <typename TokenDef>
ciaaSequentialFunctionChartElements<Iterator>::ciaaSequentialFunctionChartElements(const TokenDef& token)
  : ciaaSequentialFunctionChartElements::base_type(_sequential_function_chart) {
  bsqi::char_type char_;
  //External rules
  ciaaVariables<Iterator> _ext_variables{token};
  ciaaConstants<Iterator> _ext_constants{token};
  ciaaPOU<Iterator> _ext_pou{token};
  // TODO ciaaConstants<Iterator> _ext_il{token};

  // B.1.6 Sequential function chart elements
  // FIXME(denisacostaq\@gmail.com): simple_instruction_list != instruction_list;
  _action
      =  "ACTION" > _action_name > char_(":")
      >  _ext_pou._function_block_body
      >  "END_ACTION";
  _transition_condition
      =  char_(":") //TODO(denisacostaq\@gmail.com): > _ext_il._instruction_list
      |  ":=" // TODO:(denisacostaq\@gmail.com): _ext_st._expression
      |  char_(";")
      |  char_(":") // FIXME(denisacostaq\@gmail.com): > (fbd_network | rung);
      ;
  _steps
      =  _step_name
      | char_('(') > _step_name > +(char_(",") > _step_name) > char_(")");
  _transition_name
      =  token._identifier;
  _transition
      =  "TRANSITION" >> -_transition_name
      >> -(char_('(') > "PRIORITY" > ":=" > _ext_constants._integer > char_(')'))
      >  "FROM" > _steps > "TO" > _steps
      >  _transition_condition
      >  "END_TRANSITION";
  _indicator_name
      =  _ext_variables._variable_name;
  _action_time
      =  _ext_constants._duration | _ext_variables._variable_name;
  _timed_qualifier
      =  char_('L') | char_('D') | "SD" | "DS" | "SL";
  _action_qualifier
      =  char_('N') | char_('R') | char_('S') | char_('P') | _timed_qualifier
      >  char_(",") > _action_name;
  _action_name
      =  token._identifier;
  _action_association
      =  _action_name > char_("(") >> -_action_qualifier
      >> *(char_(",") > _indicator_name) > char_(")");
  _step_name
      =  token._identifier;
  _step
      =  "STEP" > _step_name > char_(":")
      >> *(_action_association > char_(";"))
      >  "END_STEP";
  _initial_step
      =  "INITIAL_STEP" > _step_name > char_(':')
      >> *(_action_association > char_(";"))
      >  "END_STEP";
  _sfc_network
      =  _initial_step >> *(_step | _transition | _action);
  _sequential_function_chart
      =  _sfc_network >> *_sfc_network;
}

}  // namespace iec61131_3
}  // namespace compiler
}  // namespcae ciaa

#endif  // CIAA_COMPILER_IEC_SEQUENTIAL_FUNCTION_CHART_ELEMENTS_DEF_H
