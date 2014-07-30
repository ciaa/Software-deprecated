/*! \brief This file give the functionality to ciaaVariables class.
    \file ciaa_compiler_variable-def.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Wed Jul 30 15:17:39 UTC 2014

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
    \brief This file become from: Code/Compiler/IEC61131Standard/Textuals/Grammar/ciaa_compiler_variable-def.h

    [ACSE-URL]: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/ "Asociación Civil para la Investigación, Promoción y Desarrollo de los Sistemas Electrónicos Embebidos"
    [CADIEEL-URL]: http://www.cadieel.org.ar "Cámara de Industrias Electrónicas, Electromecánicas y Luminotécnicas"
    [proyecto-ciaa-URL]: http://proyecto-ciaa.com.ar "Proyecto CIAA(Computador Industrial Abierta Argentina)"
    [proyecto-ciaa-PCSoftware-URL]: http://proyecto-ciaa.com.ar/gggg "PCSoftware bla bla"
*/

#ifndef CIAA_COMPILER_IEC_VARIABLE_DEF_H
#define CIAA_COMPILER_IEC_VARIABLE_DEF_H

#include "Code/Compiler/IEC61131Standard/Textuals/Grammar/ciaa_compiler_variable.h"

#include "Code/Compiler/IEC61131Standard/Textuals/Grammar/ciaa_compiler_data_types.h"
#include "Code/Compiler/IEC61131Standard/Textuals/Grammar/ciaa_compiler_pou.h"
#include "Code/Compiler/IEC61131Standard/Textuals/Grammar/ciaa_compiler_constants.h"

namespace ciaa {
namespace compiler {
namespace iec61131_3 {
template <typename Iterator>
template <typename TokenDef>
ciaaVariables<Iterator>::ciaaVariables(const TokenDef& token) : ciaaVariables::base_type(_variable) {
  bsqi::char_type char_;
  // External rules
  ciaaDataTypes<Iterator> _ext_data_types{token};
  ciaaPOU<Iterator> _ext_pou{token};
  ciaaConstants<Iterator> _ext_constants{token};

  // B.1.4.3 Declaration and initialization
  _var_spec
      =  _ext_data_types._simple_specification
      |  _ext_data_types._subrange_specification
      |  _ext_data_types._enumerated_specification
      |  _ext_data_types._array_specification
      |  _ext_data_types._structure_type_name
      |  "STRING" >> -(char_("[") > _ext_constants._integer > char_("]"))
      |  "WSTRING" >> -(char_("[") > _ext_constants._integer > char_("]"));
  _incompl_location
      =  "AT" > char_("%") > (char_('I')|char_('Q')|char_('M')) > char_('*');
  _incompl_located_var_decl
      =  _variable_name > _incompl_location > char_(":") > _var_spec;
  _double_byte_string_spec
      =  "WSTRING"
      >> -(char_("[") > _ext_constants._integer > char_("]"))
      >> -(":=" > _ext_constants._double_byte_character_string);
  _double_byte_string_var_declaration
      =  _var1_list > char_(":") > _double_byte_string_spec;
  _single_byte_string_spec
      =  "STRING"
      >> -(char_("[") > _ext_constants._integer > char_("]"))
      >> -(":=" > _ext_constants._single_byte_character_string);
  _single_byte_string_var_declaration
      =  _var1_list > char_(":") > _single_byte_string_spec;
  _string_var_declaration
      =  _single_byte_string_var_declaration
      |  _double_byte_string_var_declaration;
  _global_var_list
      =  _global_var_name >> *(char_(",") > _global_var_name);
  _location
      =  "AT" > _direct_variable;
  _located_var_spec_init
      =  _ext_data_types._simple_spec_init
      |  _ext_data_types._subrange_spec_init
      |  _ext_data_types._enumerated_spec_init
      |  _ext_data_types._array_spec_init
      |  _ext_data_types._initialized_structure
      |  _single_byte_string_spec
      |  _double_byte_string_spec;
  _global_var_spec
      =  _global_var_list | -_global_var_name > _location;
  _global_var_decl
      =  _global_var_spec > char_(":")
      >> -(_located_var_spec_init | _ext_pou._function_block_type_name);
  bsqi::symbols<char> fdfd;
  fdfd.add("CONSTANT");
  fdfd.add("RETAIN");
  _global_var_declarations
      =  "VAR_GLOBAL" >> -fdfd
      >  _global_var_decl > char_(";")
      >> *(_global_var_decl > char_(";"))
      > "END_VAR";
  _global_var_name
      =  token._identifier;
  _external_declaration
      =  _global_var_name > char_(":")
      >  (
               _ext_data_types._simple_specification
            |  _ext_data_types._subrange_specification
            |  _ext_data_types._enumerated_specification
            |  _ext_data_types._array_specification
            |  _ext_data_types._structure_type_name
            |  _ext_pou._function_block_type_name
         );
  bsqi::symbols<char> tttt;
  tttt.add("CONSTANT");
  _external_var_declarations
      =  "VAR_EXTERNAL" >> -tttt
      >  _external_declaration > char_(";")
      >> *(_external_declaration > char_(";"))
      > "END_VAR";
  _located_var_decl
      =  -_variable_name > _location > char_(":") > _located_var_spec_init;
  bsqi::symbols<char> tyty;
  tyty.add("CONSTANT");
  tyty.add("RETAIN");
  tyty.add("NON_RETAIN");
  _located_var_declarations
      =  "VAR" >> -tyty
      >  _located_var_decl > char_(";")
      >> *(_located_var_decl > char_(";"))
      >> "END_VAR";
  bsqi::symbols<char> fgfg;
  fgfg.add("RETAIN");
  _retentive_var_declarations
      =  "VAR" >> -fgfg
      >  _var_init_decl > char_(";")
      >> *(_var_init_decl > char_(";"))
      >  "END_VAR";
  bsqi::symbols<char> fgfg2;
  fgfg2.add("CONSTANT");
  _var_declaration
      =  "VAR" > -fgfg2
      >  _var1_init_decl > char_(";")
      >> *(_var1_init_decl > char_(";"))
      >  "END__VAR";
  _structured_var_declaration
      =  _var1_list > char_(":") > _ext_data_types._structure_type_name;
  _array_var_declaration
      = _var1_list > char_(":") > _ext_data_types._array_specification;
  _var1_declaration
      =  _var1_list
      >  char_(':')
      >  (
              _ext_data_types._simple_specification
           |  _ext_data_types._subrange_specification
           |  _ext_data_types._enumerated_specification
         );
  _temp_var_decl
      =  _var1_declaration
      |  _array_var_declaration
      |  _structured_var_declaration
      |  _string_var_declaration;
  _var_declaration
      =  _temp_var_decl | _fb_name_decl;
  _input_output_declarations
      =  "VAR_IN_OUT"
      >  _var_declaration > char_(';')
      >> *(_var_declaration > char_(';'))
      >  "END_VAR";
  bsqi::symbols<char> rgrg;
  rgrg.add("RETAIN");
  rgrg.add("NON_RETAIN");
  _output_declarations
      =  "VAR_OUTPUT" >> -(rgrg)
      >  _var_init_decl > char_(';')
      >> *(_var_init_decl > char_(';'))
      >  "END_VAR";
  _fb_name
      =  token._identifier;
  _fb_name_list
      =  _fb_name >> *(char_(',') > _fb_name);
    _fb_name_decl
        =  _fb_name_list > char_(":") > _ext_pou._function_block_type_name
        >> -(":=" > _ext_data_types._structure_initialization);
  _structured_var_init_decl
      =  _var1_list > char_(":") > _ext_data_types._initialized_structure;
  _array_var_init_decl
      =  _var1_list > char_(":") > _ext_data_types._array_spec_init;
  _var1_list
      =  _variable_name >> *(char_(",") > _variable_name);
  _var1_init_decl
      =  _var1_list > char_(':')
      >  (
              _ext_data_types._simple_spec_init
           |  _ext_data_types._subrange_spec_init
           |  _ext_data_types._enumerated_spec_init
         );
  _var_init_decl
      =  _var1_init_decl | _array_var_init_decl | _structured_var_init_decl
      |  _fb_name_decl | _string_var_declaration;
  bsqi::symbols <char> jkjk;
  jkjk.add("R_EDGE");
  jkjk.add("F_EDGE");
  _edge_declaration
      =  _var1_list > char_(':') > "BOOL" > jkjk;
  _input_declaration
      =  _var1_init_decl | _edge_declaration;
  bsqi::symbols<char> truntran;
  truntran.add("RETAIN");
  truntran.add("NON_RETAIN");
  _input_declarations
      =  "VAR_INPUT" >> -(truntran)
      >  _input_declaration > char(';')
      >  *(_input_declaration > char(';'))
      >  "END_VAR";

  //    // B.1.4.2 Multi-element variables
  _field_selector
      = token._identifier;
  _record_variable
      =  _symbolic_variable.alias();
  _structured_variable
      =  _record_variable
      >  char_('.')
      > _field_selector;
  //        _subscript
  //            =  _expression; //FIXME(denisacostaq\@gmail.com): ST?
  _subscript_list
      =  char_('[')
      >  _subscript
      >> *(char_(',') > _subscript)
      >  char_(']');
  _subscripted_variable
      = _symbolic_variable.alias();
  _array_variable
      =  _subscripted_variable
      > _subscript_list;
  _multi_element_variable
      = _array_variable
      | _structured_variable;
  // B.1.4.1 Directly represented variables
  _location_prefix
      =  char_('I')
      |  char_('Q')
      |  char_('M');
  _size_prefix
      =  char_('N')  // FIXME(denisacostaq\@gmail.com): see NIL in the manual.
      |  char_('X')
      |  char_('B')
      |  char_('W')
      |  char_('D')
      |  char_('L');
  _direct_variable
      =  char_('%')
      >  _location_prefix
      >  _size_prefix
      >  token._integer
      > *(char_('.') > token._integer);
  // B.1.4 Variables
  _variable_name
      =  token._identifier;
  _symbolic_variable
      =  _variable_name
      |  _multi_element_variable;
  _variable
      =  _direct_variable
      |  _symbolic_variable;
}
}  // namespace iec61131_3
}  // namespace compiler
}  // namespcae ciaa

#endif  // CIAA_COMPILER_IEC_VARIABLE_DEF_H
