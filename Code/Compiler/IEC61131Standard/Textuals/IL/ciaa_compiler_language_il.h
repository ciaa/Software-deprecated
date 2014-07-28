/*! \brief Do not include this file directly in external modules.
    \file ciaa_compiler_language_il.h
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
    \brief This file become from: Code/Compiler/IEC61131Standard/Textuals/IL/ciaa_compiler_language_il.h

    [ACSE-URL]: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/ "Asociación Civil para la Investigación, Promoción y Desarrollo de los Sistemas Electrónicos Embebidos"
    [CADIEEL-URL]: http://www.cadieel.org.ar "Cámara de Industrias Electrónicas, Electromecánicas y Luminotécnicas"
    [proyecto-ciaa-URL]: http://proyecto-ciaa.com.ar "Proyecto CIAA(Computador Industrial Abierta Argentina)"
    [proyecto-ciaa-PCSoftware-URL]: http://proyecto-ciaa.com.ar/gggg "PCSoftware bla bla"
*/

#ifndef CIAA_COMPILER_IEC_LANGUAGE_IL_H
#define CIAA_COMPILER_IEC_LANGUAGE_IL_H

#define DEUGGGGGG
#ifdef DEUGGGGGG
#define BOOST_SPIRIT_QI_DEBUG
#endif

#include <boost/spirit/include/qi.hpp>

namespace ciaa {
namespace compiler {
namespace iec61131_3 {
namespace text {
namespace il {

namespace bsqi = boost::spirit::qi;


template <typename Iterator>
struct ciaaLanguageIL : bsqi::grammar<Iterator, std::string> {
  template <typename TokenDef>
  ciaaLanguageIL(const TokenDef& token);



//  qi::rule<Iterator, AST::AST_il_instruction_list()> _il_instruction_list2;
//  qi::rule<Iterator, AST::AST_il_instruction()> _il_instruction2;
//  qi::rule<Iterator, AST::AST_il_simple_operation::posible_variants()> _il_simple_operation2;
//  qi::rule<Iterator, AST::AST_il_expression()> _il_expression2;
//  qi::rule<Iterator, AST::AST_il_jump_operation()> _il_jump_operation2;
//  qi::rule<Iterator, AST::AST_il_fb_call()> _il_fb_call2;
//  qi::rule<Iterator, AST::AST_il_formal_funct_call()> _il_formal_funct_call2;
//  qi::rule<Iterator, AST::AST_il_return_operator()> _il_return_operator2;
//  qi::rule<Iterator, AST::AST_il_label()> _il_label2;
//  qi::rule<Iterator, std::string()> _il_label;
//  qi::rule<Iterator, std::string()> _il_simple_operator2;
//  qi::rule<Iterator, std::string()> _il_expr_operator2;
//  qi::rule<Iterator, std::list<AST::AST_il_operand>()> _il_operand_list2;
//  qi::rule<Iterator, AST::AST_il_operand()> _il_operand2;
//  qi::rule<Iterator, std::string> _il_call_operator,
//                                  _il_return_operator,
//                                  _il_jump_operator;
bsqi::rule<Iterator, std::string> _pepe;

bsqi::rule<Iterator, std::string()> _a;
bsqi::rule<Iterator, std::string> _b;

};
}  // namespace il
}  // namespace text
}  // namespace iec61131_3
}  // namespace compiler
}  // namespcae ciaa

#endif  // CIAA_COMPILER_IEC_LANGUAGE_IL_H
