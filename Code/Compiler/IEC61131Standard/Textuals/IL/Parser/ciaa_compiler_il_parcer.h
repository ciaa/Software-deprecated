/*! \brief Do not include this file directly in external modules.
    \file ciaa_compiler_il_parcer.h
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
    \brief This file become from: Code/Compiler/IEC61131Standard/IL/Parser/ciaa_compiler_il_parcer.h

    [ACSE-URL]: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/ "Asociación Civil para la Investigación, Promoción y Desarrollo de los Sistemas Electrónicos Embebidos"
    [CADIEEL-URL]: http://www.cadieel.org.ar "Cámara de Industrias Electrónicas, Electromecánicas y Luminotécnicas"
    [proyecto-ciaa-URL]: http://proyecto-ciaa.com.ar "Proyecto CIAA(Computador Industrial Abierta Argentina)"
    [proyecto-ciaa-PCSoftware-URL]: http://proyecto-ciaa.com.ar/gggg "PCSoftware bla bla"
*/

#ifndef CIAA_COMPILER_IEC_IL_PARCER_H
#define CIAA_COMPILER_IEC_IL_PARCER_H

///*! \brief The ciaaParcer class provide an AST and a SymbolTable.
// * \brief The ciaaParcer class take a flow of tockens and transorm
// * \brief it in an AST strcut and fill a the SymbolTable.
// * \ingroup CompilerIL
// */
//class ciaaParcer {
// public:
//  ciaaParcer() = default;
//  ~ciaaParcer() = default;

//  ciaaParcer(const ciaaParcer&) = delete;
//  ciaaParcer& operator=(const ciaaParcer&) = delete;

//  ciaaParcer(const ciaaParcer&&) = delete;
//  ciaaParcer& operator=(const ciaaParcer&&) = delete;
//};











#include <boost/spirit/include/qi.hpp>
namespace qi = boost::spirit::qi;

#include "Code/Compiler/IEC61131Standard/Textuals/IL/Scanner/ciaa_compiler_il_lexer.h"
#include "Code/Compiler/IEC61131Standard/Textuals/Common/Parser/ciaa_compiler_parcer.h"


namespace ciaa {
namespace compiler {
namespace iec61131_3 {
namespace text {
namespace il {
template <typename Iterator>
struct li_grammar_chield : ciaa::compiler::iec61131_3::text::ciaaTextualParser<
    Iterator,
    ciaa::compiler::iec61131_3::text::il::instruction_list> {
  template <typename TokenDef>
  li_grammar_chield(const TokenDef& token)
    : ciaa::compiler::iec61131_3::text::ciaaTextualParser<
      Iterator,
      ciaa::compiler::iec61131_3::text::il::instruction_list>(token, _instruction_list) {
//    _il_jump_operator = token._jmp;
// // FIXME(denisacostaq\@gmail.com): reutilizar el lexer comun.

//    // _instruction_list = /*_label >> */qi::char_(":");
//    _instruction_list = token._jmp;

//    // il_jump_operator ::= 'JMP' | 'JMPC' | 'JMPCN'

//    //_il_simple_operation = il_simple_operator

//    _label = token._identifier;

//    _il_instruction = _il_simple_operation  |
//                      _il_expression        |
//                      _il_jump_operation    |
//                      _il_fb_call           |
//                      _il_formal_funct_call |
//                      _il_return_operator;
//    _instruction_list = _il_instruction     >>
//                        *_il_instruction;


  }



//  qi::rule<Iterator, int> _il_jump_operation;
//  qi::rule<Iterator, int> _il_jump_operator;

  qi::rule<Iterator, std::string> _il_jump_operator;



  qi::rule<Iterator, ciaa::compiler::iec61131_3::text::il::instruction_list> _instruction_list;
  qi::rule<Iterator, ciaa::compiler::iec61131_3::text::il::il_instruction> _il_instruction;

  qi::rule<Iterator, ciaa::compiler::iec61131_3::text::il::il_simple_operation> _il_simple_operation;
  qi::rule<Iterator, ciaa::compiler::iec61131_3::text::il::il_expression> _il_expression;
  qi::rule<Iterator, ciaa::compiler::iec61131_3::text::il::il_jump_operation> _il_jump_operation;
  qi::rule<Iterator, ciaa::compiler::iec61131_3::text::il::il_fb_call> _il_fb_call;
  qi::rule<Iterator, ciaa::compiler::iec61131_3::text::il::il_formal_funct_call> _il_formal_funct_call;
  qi::rule<Iterator, ciaa::compiler::iec61131_3::text::il::il_return_operator> _il_return_operator;

  qi::rule<Iterator, ciaa::compiler::iec61131_3::text::il::label> _label;

};
}  // namespace il
}  // namespace text
}  // namespace iec61131_3
}  // namespace compiler
}  // namespcae ciaa

#endif // CIAA_COMPILER_IEC_IL_PARCER_H
