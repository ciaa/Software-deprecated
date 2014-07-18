/*! \brief Do not include this file directly in external modules.
    \file ciaa_compiler_il_lexer.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Thu Jul 17 21:44:46 UTC 2014

    \attention <h1><center>&copy; COPYRIGHT 2014,
    <a class="el" href="http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/">
      ACSE
      ====
    </a>
    &
    <a class="el" href="http://www.cadieel.org.ar">
      CADIEEL
      =======
    </a>
    </center></h1>
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


    \brief This file is part of
    <a class="el" href="http://proyecto-ciaa.com.ar">
    CIAA Project
    ============
    </a>
    \brief especifically in the PC Software subproject in the Compiler/IL module.\n
    \brief This file become from: Code/Compiler/IL/Lexer/ciaa_compiler_il_lexer.h
*/


#ifndef COMPILER_IL_LEXER_H
#define COMPILER_IL_LEXER_H

#include <boost/spirit/include/lex_lexertl.hpp>
namespace lex = boost::spirit::lex;

namespace ciaa {
namespace compiler {
namespace il {
/*! \brief The ciaaLexer class provide a tocken flow.
 * \brief The ciaaLexer class take a flow of characters and transorm
 * \brief it in a tocken flow.
 * \ingroup CompilerIL
 */
template <typename Lexer>
class ciaaLexer : lex::lexer<Lexer> {
 public:
  ciaaLexer() = default;
  ~ciaaLexer() = default;

  ciaaLexer(const ciaaLexer&) = delete;
  ciaaLexer& operator=(const ciaaLexer&) = delete;

  ciaaLexer(const ciaaLexer&&) = delete;
  ciaaLexer& operator=(const ciaaLexer&&) = delete;
};
}  // namespace il
}  // namespace compiler
}  // namespace ciaa
#endif  // COMPILER_IL_LEXER_H

