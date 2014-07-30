/*! \brief Do not include this file directly in external modules.
    \file ciaa_compiler_pou-def.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Tue Jul 29 04:14:03 UTC 2014

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
    \brief This file become from: Code/Compiler/IEC61131Standard/Textuals/Grammar/ciaa_compiler_pou-def.h

    [ACSE-URL]: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/ "Asociación Civil para la Investigación, Promoción y Desarrollo de los Sistemas Electrónicos Embebidos"
    [CADIEEL-URL]: http://www.cadieel.org.ar "Cámara de Industrias Electrónicas, Electromecánicas y Luminotécnicas"
    [proyecto-ciaa-URL]: http://proyecto-ciaa.com.ar "Proyecto CIAA(Computador Industrial Abierta Argentina)"
    [proyecto-ciaa-PCSoftware-URL]: http://proyecto-ciaa.com.ar/gggg "PCSoftware bla bla"
*/

#ifndef CIAA_COMPILER_IEC_POU_INL_H
#define CIAA_COMPILER_IEC_POU_INL_H

#include "Code/Compiler/IEC61131Standard/Textuals/Grammar/ciaa_compiler_pou.h"

#include "Code/Compiler/IEC61131Standard/Textuals/Grammar/ciaa_compiler_data_types.h"
#include "Code/Compiler/IEC61131Standard/Textuals/Grammar/ciaa_compiler_variable.h"
#include "Code/Compiler/IEC61131Standard/Textuals/Grammar/ciaa_compiler_sequential_function_chart_elements.h"
//#include "Code/Compiler/IEC61131Standard/Textuals/IL/ciaa_compiler_language_il.h"

#include "Code/Compiler/IEC61131Standard/Textuals/IL/ciaa_error_handler.h"

namespace ciaa {
namespace compiler {
namespace iec61131_3 {
template <typename Iterator>
template <typename TokenDef>
ciaaPOU<Iterator>::ciaaPOU(const TokenDef& token) : ciaaPOU::base_type(_function_declaration) {
  // Externals rules
  ciaaDataTypes<Iterator> _ext_data_types{token};
  ciaaVariables<Iterator> _ext_variables{token};
  ciaaSequentialFunctionChartElements<Iterator> _ext_sfce{token};
  // text::il::ciaaLanguageIL<Iterator> _ext_il{token};
  #ifndef BOOST_SPIRIT_QI_DEBUG
    bsqi::char_type char_;
  #else
    using boost::spirit::qi::char_;
  #endif
  // B.1.5.2 Function blocks
  _function_block_body
        =  _ext_sfce._sequential_function_chart
//      |  ladder_diagram
//      |  function_block_diagram
//      |  instruction_list
//      |  statement_list
//      |  <other languages>
      ;

  _non_retentive_var_decls
      =  "VAR" > "NON_RETAIN" > +(_ext_variables._var_init_decl > char_(";"))
      >  "END_VAR";
  _temp_var_decls
      =  "VAR_TEMP" > +(_temp_var_decls > char_(";")) > "END_VAR";
  _other_var_declarations
      =  _ext_variables._external_var_declarations
      |  _ext_variables._var_declarations
      |  _ext_variables._retentive_var_declarations
   // |   _non_retentive_var_declarations
      |  _temp_var_decls
      |  _ext_variables._incompl_located_var_declarations;
  _function_block_declaration
      =  "FUNCTION_BLOCK" > _derived_function_block_name
      >> *(_io_var_declarations | _other_var_declarations)
      >  _function_block_body > "END_FUNCTION_BLOCK";
  _derived_function_block_name
      =  token._identifier;
  //_standard_function_block_name ::= <as defined in 2.5.2.3>
  _function_block_type_name
      =  _standard_function_block_name | _derived_function_block_name;



  // B.1.5.1 Functions
  _var2_init_decl
      =  _ext_variables._var1_init_decl
      |  _ext_variables._array_var_init_decl
      |  _ext_variables._structured_var_init_decl
      |  _ext_variables._string_var_declaration;
//  _function_body
//      =  ladder_diagram
//      |  function_block_diagram
//      |  instruction_list
//      |  statement_list
//      |  <other languages>
  _function_var_decls
      =  "VAR" >> -("CONSTANT") > +(_var2_init_decl > char_(";")) > "END_VAR";
  _io_var_declarations
      =  _ext_variables._input_declarations
      |  _ext_variables._output_declarations
      |  _ext_variables._input_output_declarations;
  _function_declaration
      =  "FUNCTION" > _derived_function_name > char_(":")
      >  (_ext_data_types._elementary_type_name | _ext_data_types._derived_type_name)
      >> *(_io_var_declarations | _function_var_decls)
      >  _function_body > "END_FUNCTION";
  _derived_function_name
      =  token._identifier;
  // TODO(denisacostaq\@gmail.com): _standard_function_name ::= <as defined in 2.5.1.5>
  _function_name
      =  _standard_function_name | _derived_function_name;
}


}  // namespace iec61131_3
}  // namespace compiler
}  // namespcae ciaa

#endif  // CIAA_COMPILER_IEC_POU_INL_H
