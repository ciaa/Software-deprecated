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

#include <boost/spirit/include/lex_lexertl.hpp>
namespace lex = boost::spirit::lex;

#include "Code/Compiler/IEC61131Standard/Textuals/IL/ASTIL.h"
#include "Code/Compiler/IEC61131Standard/Textuals/Common/Scanner/ciaa_compiler_lexer.h"

namespace ciaa {
namespace compiler {
namespace iec61131_3 {
namespace text {
namespace il {

enum class tk_id_ {
  jmp,
  jmpc,
  jmpcn
};

/*! \brief The ciaaLexer class provide a tocken flow.
 * \brief The ciaaLexer class take a flow of characters and transorm
 * \brief it in a tocken flow.
 * \ingroup CompilerIL
 */
template <typename Lexer>
struct ciaaILLexer : ciaa::compiler::iec61131_3::text::ciaaLexer<Lexer> {
  ciaaILLexer()
      : _space{R"***( )***"}
      , _comment{R"***(coment)***"}
      , _jmp   {R"***(JMP)***"}
      , _jmpc  {R"***(JMPC)***"}
      , _jmpcn {R"***(JMPCN)***"} {
    this->self.add
      (_jmp  , static_cast<std::size_t>(tk_id_::jmp))
      (_jmpc , static_cast<std::size_t>(tk_id_::jmpc))
      (_jmpcn, static_cast<std::size_t>(tk_id_::jmpcn));

      this->self += _space [lex::_pass = lex::pass_flags::pass_ignore];
      this->self += _comment [lex::_pass = lex::pass_flags::pass_ignore];
  }
  ~ciaaILLexer() = default;

  ciaaILLexer(const ciaaILLexer&) = delete;
  ciaaILLexer& operator=(const ciaaILLexer&) = delete;

  ciaaILLexer(const ciaaILLexer&&) = delete;
  ciaaILLexer& operator=(const ciaaILLexer&&) = delete;

  lex::token_def<std::string> _space;
  lex::token_def<std::string> _comment;

  lex::token_def<std::string> _jmp;
  lex::token_def<std::string> _jmpc;
  lex::token_def<std::string> _jmpcn;
};
typedef ciaaILLexer<lex::lexertl::actor_lexer<>> Scanner;
}  // namespace il
}  // namespace text
}  // namespace iec61131_3
}  // namespace compiler
}  // namespace ciaa
#endif  // COMPILER_IEC_IL_LEXER_H

