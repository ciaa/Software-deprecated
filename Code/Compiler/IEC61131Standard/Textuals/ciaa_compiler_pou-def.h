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
    \brief This file become from: Code/Compiler/IEC61131Standard/Textuals/ciaa_compiler_pou-def.h

    [ACSE-URL]: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/ "Asociación Civil para la Investigación, Promoción y Desarrollo de los Sistemas Electrónicos Embebidos"
    [CADIEEL-URL]: http://www.cadieel.org.ar "Cámara de Industrias Electrónicas, Electromecánicas y Luminotécnicas"
    [proyecto-ciaa-URL]: http://proyecto-ciaa.com.ar "Proyecto CIAA(Computador Industrial Abierta Argentina)"
    [proyecto-ciaa-PCSoftware-URL]: http://proyecto-ciaa.com.ar/gggg "PCSoftware bla bla"
*/

#ifndef CIAA_COMPILER_IEC_POU_INL_H
#define CIAA_COMPILER_IEC_POU_INL_H

#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/lex.hpp>

#include "Code/Compiler/IEC61131Standard/Textuals/ciaa_compiler_data_types.h"
#include "Code/Compiler/IEC61131Standard/Textuals/IL/ciaa_compiler_language_il.h"
#include "Code/Compiler/IEC61131Standard/Textuals/IL/ciaa_error_handler.h"
#include "Code/Compiler/IEC61131Standard/Textuals/ciaa_compiler_pou.h"

namespace ciaa {
namespace compiler {
namespace iec61131_3 {
template <typename Iterator>
template <typename TokenDef>
ciaaPOU<Iterator>::ciaaPOU(const TokenDef& token) : ciaaPOU::base_type(_function_declaration) {
  #ifndef BOOST_SPIRIT_QI_DEBUG
    bsqi::char_type char_;
  #else
    using boost::spirit::qi::char_;
  #endif


  // Externals rules
  //  ciaaDataTypes<Iterator> _ext_data_types{token};
    //text::il::ciaaLanguageIL<Iterator> _instruction_list{token};

  ////  _var2_init_decl TODO(denisacostaq\@gmail.com): todo
  ////      =  var1_init_decl | array_var_init_decl
  ////      |  structured_var_init_decl | string_var_declaration
  //  _function_body  // TODO(denisacostaq\@gmail.com): some
  //      = // ladder_diagram | function_block_diagram |
  //         _instruction_list;// | statement_list | <other languages>
  //  _function_var_decls
  //      =  token._rw_var
  //      >> -token._rw_constant
  //      >  _var2_init_decl
  //      >  char_(';')
  //      >> *(
  //              _var2_init_decl
  //            > char_(';')
  //          )
  //      > token._rw_end_var;
  ////  _io_var_declarations ::= input_declarations | output_declarations |
  ////  input_output_declarations TODO(denisacostaq\@gmail.com): todo
  //  _derived_function_name
  //      = token._identifier;
  //  _standard_function_name
  //      = char_('A');  // FIXME(denisacostaq\@gmail.com): 2.5.1.5
  //  _function_name
  //      = _standard_function_name
  //      | _derived_function_name;
    _function_declaration
        =
        token._rw_function
//        >  _derived_function_name
//        >  char_(':')
//  //      >> (
//  //              _ext_data_types._elementary_type_name
//  //           |  _ext_data_types._derived_type_name
//  //         )
//        >> *(
//                _io_var_declarations
//             |  _function_var_decls
//           )
//        >>  _function_body
       > token._rw_function_end
        ;

}


}  // namespace iec61131_3
}  // namespace compiler
}  // namespcae ciaa

#endif  // CIAA_COMPILER_IEC_POU_INL_H
