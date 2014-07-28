/*! \brief This file give the functionality to ciaaLanguageIL class.
    \file ciaa_compiler_language_il.cc
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Mon Jul 21 22:23:25 UTC 2014

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
    \brief [proyecto-ciaa-PCSoftware-URL] for tests in the Compiler/IL module.\n
    \brief This file become from: Code/Compiler/IEC61131Standard/Textuals/IL/ciaa_compiler_language_il.cc

    [ACSE-URL]: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/ "Asociación Civil para la Investigación, Promoción y Desarrollo de los Sistemas Electrónicos Embebidos"
    [CADIEEL-URL]: http://www.cadieel.org.ar "Cámara de Industrias Electrónicas, Electromecánicas y Luminotécnicas"
    [proyecto-ciaa-URL]: http://proyecto-ciaa.com.ar "Proyecto CIAA(Computador Industrial Abierta Argentina)"
    [proyecto-ciaa-PCSoftware-URL]: http://proyecto-ciaa.com.ar/gggg "PCSoftware bla bla"
*/

#include "Code/Compiler/IEC61131Standard/Textuals/IL/ciaa_compiler_language_il.h"

namespace ciaa {
namespace compiler {
namespace iec61131_3 {
namespace text {
namespace il {
template <typename Iterator>
template <typename TokenDef>
ciaaLanguageIL<Iterator>::ciaaLanguageIL(const TokenDef& token) : ciaaLanguageIL::base_type(_pepe) {
//                   client::error_handler<typename Lexer::base_iterator_type, Iterator>& error_handler)
//    : pnp::ciaaTextualParser<
//      Iterator,
//      Lexer,
//      AST::AST_il_instruction_list>(token,
//                                    error_handler,
//                                    _il_instruction_list2) {
//  using pc = pnp::ciaaTextualParser<Iterator, Lexer, AST::AST_il_instruction_list>;
//  qi::char_type char_;

////    il_assign_operator ::= variable_name':='
////    il_assign_out_operator ::= ['NOT'] variable_name'=>'

//  _il_call_operator
//      = token._cal
//      | token._calc
//      | token._calcn;
//  _il_return_operator
//      = token._ret
//      | token._retc
//      | token._retcn;
//  _il_jump_operator
//      = token._jmp
//      | token._jmpc
//      | token._jmpcn;

//  _il_label
//      = token._identifier;
//  _il_label2
//      = _il_label;
//  _il_expr_operator2
//      = token._and
//      | token._and_symbol
//      | token._or
//      | token._xor
//      | token._andn
//      | token._and_symbol_n
//      | token._orn
//      | token._xorn
//      | token._add
//      | token._sub
//      | token._mul
//      | token._div
//      | token._mod
//      | token._gt
//      | token._ge
//      | token._eq
//      | token._lt
//      | token._le
//      | token._ne;
//  _il_simple_operator2
//      = token._ld
//      | token._ldn
//      | token._st
//      | token._stn
//      | token._not
//      | token._s
//      | token._r
//      | token._s1
//      | token._r1
//      | token._clk
//      | token._cu
//      | token._cd
//      | token._pv
//      | token._in
//      | token._pt
//      | _il_expr_operator2;
//  _il_operand2
//      = pc::_constant;
////        | variable
////        | enumerated_value;
//  _il_operand_list2
//      = _il_operand2
//      >> *(char_(',') >> _il_operand2);
////        = +(_il_operand2 % char_(','));
//  _il_simple_operation2
//      =  (_il_simple_operator2 >> -_il_operand2)
//      |  (pc::_function_name >> -_il_operand_list2);
//  _il_instruction2
//      =  -_il_label2
//      >> -(  _il_simple_operation2
//             | _il_expression2
//             | _il_jump_operation2
//             | _il_fb_call2
//             | _il_formal_funct_call2
//             | _il_return_operator2
//          )
//      >> token._eol;//+qi::eol_parser::;
//  _il_instruction_list2
//      = +_il_instruction2;

//  BOOST_SPIRIT_DEBUG_NODES(
////      (_il_instruction_list2)
////      (_il_instruction2)
//    (_il_simple_operation2)
////      (_il_expression2)
////      (_il_jump_operation2)
////      (_il_fb_call2)
////      (_il_formal_funct_call2)
////      (_il_return_operator2)
//    (_il_label)
//    (_il_label2)
//    (_il_simple_operator2)
//    (_il_expr_operator2)
//    (_il_operand_list2)
//    (_il_operand2)
//  );


//  _il_expr_operator2.name("expr_operator");
//  _il_simple_operator2.name("simple_operator");
//  _il_label2.name("label");
//  _il_simple_operation2.name("simple_operation");
//  _il_expression2.name("expression");
//  _il_jump_operation2.name("jump_operation");
//  _il_fb_call2.name("fb_call");
//  _il_formal_funct_call2.name("formal_funct_call");
//  _il_return_operator2.name("return_operator");
//  _il_instruction2.name("instruction");
//  _il_instruction_list2.name("instruction_list");

//  qi::_1_type _1;
//  qi::_2_type _2;
//  qi::_3_type _3;
//  qi::_4_type _4;
//  ///////////////////////////////////////////////////////////////////////
//  typedef client::error_handler<typename Lexer::base_iterator_type, Iterator>
//      error_handler_type;
//  typedef boost::phoenix::function<error_handler_type> error_handler_function;


//  qi::on_error<qi::fail>(_il_expr_operator2,
//                         error_handler_function(error_handler)("Error! Expecting ", _4, _3));


  _a = _b;
  _b = _a;
}
}  // namespace il
}  // namespace text
}  // namespace iec61131_3
}  // namespace compiler
}  // namespcae ciaa
