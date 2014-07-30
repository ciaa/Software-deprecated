/*! \brief This file give the functionality to ciaaConfigurationElements class.
    \file ciaa_compiler_configuration_elements-def.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Wed Jul 30 19:37:13 UTC 2014

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
    \brief This file become from: Code/Compiler/IEC61131Standard/Textuals/Grammar/ciaa_compiler_configuration_elements-def.h

    [ACSE-URL]: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/ "Asociación Civil para la Investigación, Promoción y Desarrollo de los Sistemas Electrónicos Embebidos"
    [CADIEEL-URL]: http://www.cadieel.org.ar "Cámara de Industrias Electrónicas, Electromecánicas y Luminotécnicas"
    [proyecto-ciaa-URL]: http://proyecto-ciaa.com.ar "Proyecto CIAA(Computador Industrial Abierta Argentina)"
    [proyecto-ciaa-PCSoftware-URL]: http://proyecto-ciaa.com.ar/gggg "PCSoftware bla bla"
*/

#ifndef CIAA_COMPILER_CONFIGURATION_ELEMENTSDEF_H
#define CIAA_COMPILER_CONFIGURATION_ELEMENTSDEF_H

#include "Code/Compiler/IEC61131Standard/Textuals/Grammar/ciaa_compiler_configuration_elements.h"

#include "Code/Compiler/IEC61131Standard/Textuals/Grammar/ciaa_compiler_variable.h"
#include "Code/Compiler/IEC61131Standard/Textuals/Grammar/ciaa_compiler_data_types.h"
#include "Code/Compiler/IEC61131Standard/Textuals/Grammar/ciaa_compiler_constants.h"
#include "Code/Compiler/IEC61131Standard/Textuals/Grammar/ciaa_compiler_pou.h"

namespace ciaa {
namespace compiler {
namespace iec61131_3 {
template <typename Iterator>
template <typename TokenDef>
ciaaConfigurationElements<Iterator>::ciaaConfigurationElements(const TokenDef& token)
  : ciaaConfigurationElements::base_type(_configuration_name) {
  bsqi::char_type char_;
  // External rules
  ciaaVariables<Iterator> _ext_variables{token};
  ciaaDataTypes<Iterator> _ext_data_types{token};
  ciaaConstants<Iterator> _ext_contants{token};
  ciaaPOU<Iterator> _ext_pou{token};
  // B.1.7 Configuration elements
  _instance_specific_init
      =  _resource_name > char_('.') > _program_name > char_(".")
      >> *(_ext_variables._fb_name > char_("."))
      >  (
            (
                 _ext_variables._variable_name >> -_ext_variables._location
              >  char_(":") > _ext_variables._located_var_spec_init
            )
            |
            (
                _ext_variables._fb_name > char_(":")
             >  _ext_pou._function_block_type_name > ":="
             >  _ext_data_types._structure_initialization
            )
         )
     ;
  _instance_specific_initializations
      =  "VAR_CONFIG" > +(_instance_specific_init > char_(';')) > "END_VAR";
  _data_sink
      =  _global_var_reference | _ext_variables._direct_variable;
  _prog_data_source
      =  _ext_contants._constant
      |  _ext_data_types._enumerated_value
      |  _global_var_reference
      |  _ext_variables._direct_variable;
  _prog_cnxn
      =  _ext_variables._symbolic_variable > ":=" > _prog_data_source
      |  _ext_variables._symbolic_variable > "=>" > _data_sink;
  _fb_task
      =  _ext_variables._fb_name > "WITH" > _task_name;
  _prog_conf_element
      =  _fb_task | _prog_cnxn;
  _prog_conf_elements
      =  _prog_conf_element > -(char_(',') > _prog_conf_element);
  bsqi::symbols<char> fttf;
  fttf.add("RETAIN");
  fttf.add("NON_RETAIN");
  _program_configuration
      =  "PROGRAM"
      >> -fttf  // FIXME(denisacostaq\@gmail.com): see grammar in the pdf.
      >  _program_name >> -("WITH" > _task_name) > char_(':')
      >  _ext_pou._program_type_name
      >> -(char_('(') > _prog_conf_elements > char_(')'));
  _data_source
      =  _ext_contants._constant
      |  _global_var_reference
      |  _program_output_reference
      |  _ext_variables._direct_variable;
  _task_initialization
      =  char_('(')
      >> -("SINGLE" > ":=" > _data_source > char_(','))
      >> -("INTERVAL" > ":=" > _data_source > char_(','))
      >  "PRIORITY" > ":=" > _ext_contants._integer
      >  char_(')');
  _task_name
      =  token._identifier;
  _task_configuration
      =  "TASK" > _task_name > _task_initialization;
  bsqi::symbols<char> trrtr;
  trrtr.add("READ_WRITE");
  trrtr.add("READ_WRITE");
  _direction
      =  trrtr;
  _program_name
      =  token._identifier;
  _program_output_reference
      =  _program_name > char_('.') > _ext_variables._symbolic_variable;

  _access_name
      =  token._identifier;
  _global_var_reference
      =  -(_resource_name > char_('.'))
      >  _ext_variables._global_var_name
      >> -(char_('.') > _ext_data_types._structure_element_name);
  _access_path
      =  -(_resource_name > char_('.')) > _ext_variables._direct_variable
      |  -(_resource_name > char_('.')) >> -(_program_name > char_('.'))
      >> *(_ext_variables._fb_name > char_("."))
      >  _ext_variables._symbolic_variable;
  _access_declaration
      =  _access_name > char_(":") > _access_path > char_(":")
      >  _ext_data_types._non_generic_type_name >> -_direction;
  _access_declarations
      =  "VAR_ACCESS" > +(_access_declaration > char_(";")) > "END_VAR";
  _resource_name
      =  token._identifier;
  _single_resource_declaration
      =  *(_task_configuration > char_(";"))
      >  +(_program_configuration > char_(";"));
  _resource_declaration
      =  "RESOURCE" > _resource_name > "ON" > _resource_type_name
      >> -_ext_variables._global_var_declarations
      >  _single_resource_declaration
      >  "END_RESOURCE";
  _configuration_declaration
      =  "CONFIGURATION" > _configuration_name
      >> -_ext_variables._global_var_declarations
      >  (_single_resource_declaration | +_resource_declaration)
      >> -_access_declaration >> -_instance_specific_initializations
      >  "END_CONFIGURATION";
  _configuration_name
      =  token._identifier;
  _resource_type_name
      =  token._identifier;

}
}  // namespace iec61131_3
}  // namespace compiler
}  // namespcae ciaa
#endif // CIAA_COMPILER_CONFIGURATION_ELEMENTSDEF_H
