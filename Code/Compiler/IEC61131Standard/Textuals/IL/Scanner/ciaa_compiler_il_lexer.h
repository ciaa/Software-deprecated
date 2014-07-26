/*! \brief Do not include this file directly in external modules.
    \file ciaa_compiler_il_lexer.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Mon Jul 21 22:54:58 UTC 2014

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
    \brief This file become from: Code/Compiler/IEC61131Standard/IL/Scanner/ciaa_compiler_il_lexer.h

    [ACSE-URL]: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/ "Asociación Civil para la Investigación, Promoción y Desarrollo de los Sistemas Electrónicos Embebidos"
    [CADIEEL-URL]: http://www.cadieel.org.ar "Cámara de Industrias Electrónicas, Electromecánicas y Luminotécnicas"
    [proyecto-ciaa-URL]: http://proyecto-ciaa.com.ar "Proyecto CIAA(Computador Industrial Abierta Argentina)"
    [proyecto-ciaa-PCSoftware-URL]: http://proyecto-ciaa.com.ar/gggg "PCSoftware bla bla"
*/

#ifndef COMPILER_IEC_IL_LEXER_H
#define COMPILER_IEC_IL_LEXER_H

#include "Code/Compiler/IEC61131Standard/Textuals/Common/Scanner/ciaa_compiler_lexer2.h"
#include "Code/Compiler/IEC61131Standard/Textuals/IL/ASTIL.h"

namespace ciaa {
namespace compiler {
namespace iec61131_3 {
namespace text {
namespace il {

namespace lex = boost::spirit::lex;

/*! \brief The ciaaLexer class provide a tocken flow.
 * \brief The ciaaLexer class take a flow of characters and transorm
 * \brief it in a tocken flow.
 * \ingroup CompilerIL
 */
template <typename BaseIterator>
struct ciaaILLexer : ciaa::compiler::iec61131_3::text::ciaaLexer<BaseIterator> {
  typedef std::string::const_iterator base_iterator_type;
  enum class tk_kind_chiekd {
    jmp = static_cast<int>(ciaaSymbolInfo::tk_kind::max_tk_id_val) + 1,  //TODO(denisacostaq/@gmail.com):
    jmpc = static_cast<int>(ciaaSymbolInfo::tk_kind::max_tk_id_val)  + 2,
    jmpcn = static_cast<int>(ciaaSymbolInfo::tk_kind::max_tk_id_val)  + 3,
    ld = static_cast<int>(ciaaSymbolInfo::tk_kind::max_tk_id_val)  + 4,
    ldn = static_cast<int>(ciaaSymbolInfo::tk_kind::max_tk_id_val)  + 5,
    st = static_cast<int>(ciaaSymbolInfo::tk_kind::max_tk_id_val)  + 6,
    stn = static_cast<int>(ciaaSymbolInfo::tk_kind::max_tk_id_val)  + 7,
    not_ = static_cast<int>(ciaaSymbolInfo::tk_kind::max_tk_id_val)  + 8,
    s = static_cast<int>(ciaaSymbolInfo::tk_kind::max_tk_id_val)  + 9,
    r = static_cast<int>(ciaaSymbolInfo::tk_kind::max_tk_id_val)  + 10,
    s1 = static_cast<int>(ciaaSymbolInfo::tk_kind::max_tk_id_val)  + 11,
    r1 = static_cast<int>(ciaaSymbolInfo::tk_kind::max_tk_id_val)  + 12,
    clk = static_cast<int>(ciaaSymbolInfo::tk_kind::max_tk_id_val)  + 13,
    cu = static_cast<int>(ciaaSymbolInfo::tk_kind::max_tk_id_val)  + 14,
    cd = static_cast<int>(ciaaSymbolInfo::tk_kind::max_tk_id_val)  + 15,
    pv = static_cast<int>(ciaaSymbolInfo::tk_kind::max_tk_id_val)  + 16,
    in = static_cast<int>(ciaaSymbolInfo::tk_kind::max_tk_id_val)  + 17,
    pt = static_cast<int>(ciaaSymbolInfo::tk_kind::max_tk_id_val)  + 18,
    and_ = static_cast<int>(ciaaSymbolInfo::tk_kind::max_tk_id_val)  + 19,
    and_symbol = static_cast<int>(ciaaSymbolInfo::tk_kind::max_tk_id_val)  + 20,
    or_ = static_cast<int>(ciaaSymbolInfo::tk_kind::max_tk_id_val)  + 21,
    xor_ = static_cast<int>(ciaaSymbolInfo::tk_kind::max_tk_id_val)  + 22,
    andn = static_cast<int>(ciaaSymbolInfo::tk_kind::max_tk_id_val)  + 23,
    and_symbol_n = static_cast<int>(ciaaSymbolInfo::tk_kind::max_tk_id_val)  + 24,
    orn = static_cast<int>(ciaaSymbolInfo::tk_kind::max_tk_id_val)  + 25,
    xorn = static_cast<int>(ciaaSymbolInfo::tk_kind::max_tk_id_val)  + 26,
    add = static_cast<int>(ciaaSymbolInfo::tk_kind::max_tk_id_val)  + 27,
    sub = static_cast<int>(ciaaSymbolInfo::tk_kind::max_tk_id_val)  + 28,
    mul = static_cast<int>(ciaaSymbolInfo::tk_kind::max_tk_id_val)  + 29,
    div = static_cast<int>(ciaaSymbolInfo::tk_kind::max_tk_id_val)  + 30,
    mod = static_cast<int>(ciaaSymbolInfo::tk_kind::max_tk_id_val)  + 31,
    gt = static_cast<int>(ciaaSymbolInfo::tk_kind::max_tk_id_val)  + 32,
    ge = static_cast<int>(ciaaSymbolInfo::tk_kind::max_tk_id_val)  + 33,
    eq = static_cast<int>(ciaaSymbolInfo::tk_kind::max_tk_id_val)  + 34,
    lt = static_cast<int>(ciaaSymbolInfo::tk_kind::max_tk_id_val)  + 35,
    le = static_cast<int>(ciaaSymbolInfo::tk_kind::max_tk_id_val)  + 36,
    ne = static_cast<int>(ciaaSymbolInfo::tk_kind::max_tk_id_val)  + 37
  };

  ciaaILLexer()
      : _jmp{R"***(JMP)***"}
      , _jmpc{R"***(JMPC)***"}
      , _jmpcn{R"***(JMPCN)***"}
      , _ld{R"***(LD)***"}
      , _ldn{R"***(LDN)***"}
      , _st{R"***(ST)***"}
      , _stn{R"***(STN)***"}
      , _not{R"***(NOT)***"}
      , _s{R"***(S)***"}
      , _r{R"***(R)***"}
      , _s1{R"***(S1)***"}
      , _r1{R"***(R1)***"}
      , _clk{R"***(CLK)***"}
      , _cu{R"***(CU)***"}
      , _cd{R"***(CD)***"}
      , _pv{R"***(PV)***"}
      , _in{R"***(IN)***"}
      , _pt{R"***(PT)***"}
      ,  _and{R"***(AND)***"}
      , _and_symbol{R"***(&)***"}
      , _or{R"***(OR)***"}
      , _xor{R"***(XOR)***"}
      , _andn{R"***(ANDN)***"}
      , _and_symbol_n{R"***(&N)***"}
      , _orn{R"***(ORN)***"}
      , _xorn{R"***(XORN)***"}
      , _add{R"***(ADD)***"}
      , _sub{R"***(SUB)***"}
      , _mul{R"***(MUL)***"}
      , _div{R"***(DIV)***"}
      , _mod{R"***(MOD)***"}
      , _gt{R"***(GT)***"}
      , _ge{R"***(GE)***"}
      , _eq{R"***(EQ)***"}
      , _lt{R"***(LT)***"}
      , _le{R"***(LE)***"}
      , _ne{R"***(NE)***"}
{
    this->self.add
      (_jmp, static_cast<std::size_t>(tk_kind_chiekd::jmp))
      (_jmpc, static_cast<std::size_t>(tk_kind_chiekd::jmpc))
      (_jmpcn, static_cast<std::size_t>(tk_kind_chiekd::jmpcn))
      (_ld, static_cast<std::size_t>(tk_kind_chiekd::ld))
      (_ldn, static_cast<std::size_t>(tk_kind_chiekd::ldn))
      (_st, static_cast<std::size_t>(tk_kind_chiekd::st))
      (_stn, static_cast<std::size_t>(tk_kind_chiekd::stn))
      (_not, static_cast<std::size_t>(tk_kind_chiekd::not_))
      (_s, static_cast<std::size_t>(tk_kind_chiekd::s))
      (_r, static_cast<std::size_t>(tk_kind_chiekd::r))
      (_s1, static_cast<std::size_t>(tk_kind_chiekd::s1))
      (_r1, static_cast<std::size_t>(tk_kind_chiekd::r1))
      (_clk, static_cast<std::size_t>(tk_kind_chiekd::clk))
      (_cu, static_cast<std::size_t>(tk_kind_chiekd::cu))
      (_cd, static_cast<std::size_t>(tk_kind_chiekd::cd))
      (_pv, static_cast<std::size_t>(tk_kind_chiekd::pv))
      (_in, static_cast<std::size_t>(tk_kind_chiekd::in))
      (_pt, static_cast<std::size_t>(tk_kind_chiekd::pt))
      (_and, static_cast<std::size_t>(tk_kind_chiekd::and_))
      (_and_symbol, static_cast<std::size_t>(tk_kind_chiekd::and_symbol))
      (_or, static_cast<std::size_t>(tk_kind_chiekd::or_))
      (_xor, static_cast<std::size_t>(tk_kind_chiekd::xor_))
      (_andn, static_cast<std::size_t>(tk_kind_chiekd::andn))
      (_and_symbol_n, static_cast<std::size_t>(tk_kind_chiekd::and_symbol_n))
      (_orn, static_cast<std::size_t>(tk_kind_chiekd::orn))
      (_xorn, static_cast<std::size_t>(tk_kind_chiekd::xorn))
      (_add, static_cast<std::size_t>(tk_kind_chiekd::add))
      (_sub, static_cast<std::size_t>(tk_kind_chiekd::sub))
      (_mul, static_cast<std::size_t>(tk_kind_chiekd::mul))
      (_div, static_cast<std::size_t>(tk_kind_chiekd::div))
      (_mod, static_cast<std::size_t>(tk_kind_chiekd::mod))
      (_gt, static_cast<std::size_t>(tk_kind_chiekd::gt))
      (_ge, static_cast<std::size_t>(tk_kind_chiekd::ge))
      (_eq, static_cast<std::size_t>(tk_kind_chiekd::eq))
      (_lt, static_cast<std::size_t>(tk_kind_chiekd::lt))
      (_le, static_cast<std::size_t>(tk_kind_chiekd::le))
      (_ne, static_cast<std::size_t>(tk_kind_chiekd::ne));
  }
  ~ciaaILLexer() = default;

  ciaaILLexer(const ciaaILLexer&) = delete;
  ciaaILLexer& operator=(const ciaaILLexer&) = delete;

  ciaaILLexer(const ciaaILLexer&&) = delete;
  ciaaILLexer& operator=(const ciaaILLexer&&) = delete;

  lex::token_def<std::string> _jmp;
  lex::token_def<std::string> _jmpc;
  lex::token_def<std::string> _jmpcn;

//  //il_simple_operator(il_expr_operator included)
  lex::token_def<std::string> _ld;
  lex::token_def<std::string> _ldn;
  lex::token_def<std::string> _st;
  lex::token_def<std::string> _stn;
  lex::token_def<std::string> _not;
  lex::token_def<std::string> _s;
  lex::token_def<std::string> _r;
  lex::token_def<std::string> _s1;
  lex::token_def<std::string> _r1;
  lex::token_def<std::string> _clk;
  lex::token_def<std::string> _cu;
  lex::token_def<std::string> _cd;
  lex::token_def<std::string> _pv;
  lex::token_def<std::string> _in;
  lex::token_def<std::string> _pt;
//  //il_expr_operator
  lex::token_def<std::string> _and;
  lex::token_def<std::string> _and_symbol;
  lex::token_def<std::string> _or;
  lex::token_def<std::string> _xor;
  lex::token_def<std::string> _andn;
  lex::token_def<std::string> _and_symbol_n;
  lex::token_def<std::string> _orn;
  lex::token_def<std::string> _xorn;
  lex::token_def<std::string> _add;
  lex::token_def<std::string> _sub;
  lex::token_def<std::string> _mul;
  lex::token_def<std::string> _div;
  lex::token_def<std::string> _mod;
  lex::token_def<std::string> _gt;
  lex::token_def<std::string> _ge;
  lex::token_def<std::string> _eq;
  lex::token_def<std::string> _lt;
  lex::token_def<std::string> _le;
  lex::token_def<std::string> _ne;
};
//typedef ciaaILLexer<lex::lexertl::actor_lexer<>> Scanner;
}  // namespace il
}  // namespace text
}  // namespace iec61131_3
}  // namespace compiler
}  // namespace ciaa
#endif  // COMPILER_IEC_IL_LEXER_H

