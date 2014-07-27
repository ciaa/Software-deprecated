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





#define BOOST_SPIRIT_QI_DEBUG




#include <boost/spirit/include/phoenix_function.hpp>
#include <boost/spirit/include/qi.hpp>
namespace qi = boost::spirit::qi;

#include "Code/Compiler/IEC61131Standard/Textuals/IL/Scanner/ciaa_compiler_il_lexer.h"
#include "Code/Compiler/IEC61131Standard/Textuals/Common/Parser/ciaa_compiler_parcer.h"
#include "Code/Compiler/IEC61131Standard/Textuals/IL/ASTIL.h"

namespace ciaa {
namespace compiler {
namespace iec61131_3 {
namespace text {
namespace il {

/*! \brief pnp Parent namespace
 */
namespace pnp = ciaa::compiler::iec61131_3::text;
/*! \brief tnp This namespace
 */
namespace tnp = pnp::il;


template <typename Iterator, typename Lexer>
struct li_grammar_chield : public pnp::ciaaTextualParser<Iterator, Lexer, AST::AST_il_instruction_list> {
  template <typename TokenDef>
  li_grammar_chield(const TokenDef& token,
                    client::error_handler<typename Lexer::base_iterator_type, Iterator>& error_handler)
    : pnp::ciaaTextualParser<
      Iterator,
      Lexer,
      AST::AST_il_instruction_list>(token,
                                    error_handler,
                                    _il_instruction_list2) {
    using pc = pnp::ciaaTextualParser<Iterator, Lexer, AST::AST_il_instruction_list>;
    qi::char_type char_;
    boost::spirit::qi::eol_type eol_;
//    _il_jump_operator = token._jmp;
// // FIXME(denisacostaq\@gmail.com): reutilizar el lexer comun.

//    // _instruction_list = /*_label >> */qi::char_(":");
//    _instruction_list = token._jmp;

//    // il_jump_operator ::= 'JMP' | 'JMPC' | 'JMPCN'

//    //_il_simple_operation = il_simple_operator




//    _il_operand_list = _il_operand >> *(char_(',') >> _il_operand);

    _il_simple_operation.name("il_simple_operation");
    _il_simple_operation
        =
        //_il_simple_operator >> -_il_operand
        //|
        token._identifier;
//    //    | (pc::_function_name >> -_il_operand_list);



    _il_expr_operator2
        = token._and
        | token._and_symbol
        | token._or
        | token._xor
        | token._andn
        | token._and_symbol_n
        | token._orn
        | token._xorn
        | token._add
        | token._sub
        | token._mul
        | token._div
        | token._mod
        | token._gt
        | token._ge
        | token._eq
        | token._lt
        | token._le
        | token._ne;
    _il_simple_operator2
        = token._ld
        | token._ldn
        | token._st
        | token._stn
        | token._not
        | token._s
        | token._r
        | token._s1
        | token._r1
        | token._clk
        | token._cu
        | token._cd
        | token._pv
        | token._in
        | token._pt
        | _il_expr_operator2;

    _il_operand2
        = pc::_constant;
//        | variable
//        | enumerated_value;
    _il_operand_list2
        = _il_operand2
        >> *(char_(',') >> _il_operand2);
//        = +(_il_operand2 % char_(','));
    _il_simple_operation2
        =  (_il_simple_operator2 >> -_il_operand2)
        |  (pc::_function_name >> -_il_operand_list2);

    _il_instruction2
        = -_il_label2
        >> -(  _il_simple_operation2
               | _il_expression2
               | _il_jump_operation2
               | _il_fb_call2
               | _il_formal_funct_call2
               | _il_return_operator2
            )
        >> +eol_;
    _il_instruction_list2
        = +_il_instruction2;

  //BOOST_SPIRIT_DEBUG_NODES(
  //        (_il_expr_operator)
  //        (_str)
  //      );
    _il_expr_operator2.name("expr_operator");
    _il_simple_operator2.name("simple_operator");
    _il_label2.name("label");
    _il_simple_operation2.name("simple_operation");
    _il_expression2.name("expression");
    _il_jump_operation2.name("jump_operation");
    _il_fb_call2.name("fb_call");
    _il_formal_funct_call2.name("formal_funct_call");
    _il_return_operator2.name("return_operator");
    _il_instruction2.name("instruction");
    _il_instruction_list2.name("instruction_list");

    qi::_1_type _1;
    qi::_2_type _2;
    qi::_3_type _3;
    qi::_4_type _4;
    ///////////////////////////////////////////////////////////////////////
    typedef client::error_handler<typename Lexer::base_iterator_type, Iterator>
        error_handler_type;
    typedef boost::phoenix::function<error_handler_type> error_handler_function;


    qi::on_error<qi::fail>(_il_expr_operator2,
                           error_handler_function(error_handler)("Error! Expecting ", _4, _3));

  }


  qi::rule<Iterator, AST::AST_il_instruction_list()> _il_instruction_list2;
  qi::rule<Iterator, AST::AST_il_instruction()> _il_instruction2;
  qi::rule<Iterator, AST::AST_il_simple_operation::posible_variants()> _il_simple_operation2;
  qi::rule<Iterator, AST::AST_il_expression()> _il_expression2;
  qi::rule<Iterator, AST::AST_il_jump_operation()> _il_jump_operation2;
  qi::rule<Iterator, AST::AST_il_fb_call()> _il_fb_call2;
  qi::rule<Iterator, AST::AST_il_formal_funct_call()> _il_formal_funct_call2;
  qi::rule<Iterator, AST::AST_il_return_operator()> _il_return_operator2;
  qi::rule<Iterator, AST::AST_il_label()> _il_label2;
  qi::rule<Iterator, std::string()> _il_simple_operator2;
  qi::rule<Iterator, std::string()> _il_expr_operator2;
  qi::rule<Iterator, std::list<AST::AST_il_operand>()> _il_operand_list2;
  qi::rule<Iterator, AST::AST_il_operand()> _il_operand2;



//  qi::rule<Iterator, int> _il_jump_operation;
//  qi::rule<Iterator, int> _il_jump_operator;

  qi::rule<Iterator, std::string> _il_jump_operator;



  qi::rule<Iterator, instruction_list()> _instruction_list;
  qi::rule<Iterator, tnp::il_operand()> _il_instruction;

  qi::rule<Iterator, tnp::il_simple_operation::variant2()> _il_simple_operation;
  qi::rule<Iterator, tnp::il_expression()> _il_expression;
  qi::rule<Iterator, tnp::il_jump_operation()> _il_jump_operation;
  qi::rule<Iterator, tnp::il_fb_call()> _il_fb_call;
  qi::rule<Iterator, tnp::il_formal_funct_call()> _il_formal_funct_call;
  qi::rule<Iterator, tnp::il_return_operator()> _il_return_operator;

  qi::rule<Iterator, std::string()> _label;






//  qi::rule<Iterator, tnp::ast_label()> _pepe;
//  qi::rule<Iterator, tnp::ast_il_expression()> _tiene_pepe;
//  qi::rule<Iterator, tnp::ast_il_instruction()> _pepe22;
//  qi::rule<Iterator, std::list<tnp::ast_il_instruction>()> _tiene_pepesss22222222;
//  qi::rule<Iterator, std::list<tnp::ast_il_expression>()> _tiene_pepesss;
//  qi::rule<Iterator, std::list<tnp::ast_label>()> _pepe_list;


  void check(const ciaa::compiler::iec61131_3::text::il::il_expr_operator& ast) {
    typedef struct {
      bool operator()(tnp::il_instruction const& x) const {
        std::printf("DDDDDDDDDDDD\n");
        return true;
      }

      bool start(const tnp::il_expr_operator& ast) {
        std::printf("|%s|\n", ast._exp.c_str());
//        std::printf("size: %d\n", ast.il.size());
//        for (tnp::il_instruction instr : ast.il) {
//          std::printf("DDDDDDDDDDDD222222\n");
//          if (!(*this)(instr)) {
//            return false;
//          }
//        }
//        std::printf("DDDDDDDDDDDD33333333\n");
        return true;
      }
    } checker;
    checker ch;
    std::printf("DDDDDDDDDDDD4444444\n");
    if (!ch.start(ast)) std::exit(EXIT_FAILURE);

  }

};
}  // namespace il
}  // namespace text
}  // namespace iec61131_3
}  // namespace compiler
}  // namespcae ciaa

#endif // CIAA_COMPILER_IEC_IL_PARCER_H
