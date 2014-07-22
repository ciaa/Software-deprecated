/*! \brief Do not include this file directly in external modules.
    \file ciaa_compiler_lexer.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Thu Jul 17 21:44:46 UTC 2014

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
    \brief This file become from: Code/Compiler/IEC61131Standard/Scanner/ciaa_compiler_lexer.h

    [ACSE-URL]: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/ "Asociación Civil para la Investigación, Promoción y Desarrollo de los Sistemas Electrónicos Embebidos"
    [CADIEEL-URL]: http://www.cadieel.org.ar "Cámara de Industrias Electrónicas, Electromecánicas y Luminotécnicas"
    [proyecto-ciaa-URL]: http://proyecto-ciaa.com.ar "Proyecto CIAA(Computador Industrial Abierta Argentina)"
    [proyecto-ciaa-PCSoftware-URL]: http://proyecto-ciaa.com.ar/gggg "PCSoftware bla bla"
*/

#ifndef COMPILER_IEC_LEXER_H
#define COMPILER_IEC_LEXER_H

#include <boost/spirit/include/lex_lexertl.hpp>
namespace lex = boost::spirit::lex;

#include "Code/Compiler/IEC61131Standard/Textuals/Common/AST.h"

namespace ciaa {
namespace compiler {

enum tk_id_ {
  LETTER,
  IDENTIFIER,
  LINE_JUMP,
  TYPE,
  BINARY_INTEGER,
  OCTAL_INTEGER,
  HEX_INTEGER,
  REAL_LITERAL,
  REAL_RW,
  LREAL_RW,
  COMMON_TYPE_LIT,
  COMMON_TYPE_END_LIT,
  COMMON_COLON,
  COMMON_DOCOLON
};

/*! \brief The ciaaLexer class provide a tocken flow.
 * \brief The ciaaLexer class take a flow of characters and transorm
 * \brief it in a tocken flow.
 * \ingroup CompilerIL
 */
template <typename Lexer>
struct ciaaLexer : lex::lexer<Lexer> {
  ciaaLexer()
      : _space{R"***( )***"}
      , _comment{R"***(coment)***"}
      //, _identifier{R"***((([A-Za-z])|(_([A-Za-z]|[0-9])))(_?([A-Za-z]|[0-9]))*)***"} //FIXME(denisacostaq\@gmail.com)
      , _identifier{R"***(_(([A-Za-z])|(_([A-Za-z]|[0-9])))(_?([A-Za-z]|[0-9]))*)***"} //FIXME(denisacostaq\@gmail.com) ponerle precedencia a los tokens para que las palabras reservadas no choquen con los identificacadores
      , _line_jump{R"***(\n)***"}
      , _binary_integer{R"***(2#[01](_?[01])*)***"}
      , _octal_integer{R"***(8#[1-8](_?[1-8])*)***"}
      , _hex_integer{R"***(16#[0-9A-Fa-f](_?[0-9A-Fa-f])*)***"}
      , _real_literal{R"***((("REAL"|"LREAL")#)?([\+\-])?[0-9](_?[0-9])*\.([0-9])(_?[0-9])*([eE]([\+\-])?[0-9](_?[0-9])*)?)***"}
      , _real_rw{R"***(REAL)***"}
      , _lreal_rw{R"***(LREAL)***"}
      , _common_type_lit {R"***(TYPE)***"}
      , _common_type_end_lit {R"***(TYPE_END)***"}
      , _common_colon_lit{R"***(;)***"}
      , _common_docolon_lit{R"***(:)***"} {
    this->self.add
      (_identifier, static_cast<std::size_t>(tk_id_::IDENTIFIER))
      (_line_jump, static_cast<std::size_t>(tk_id_::LINE_JUMP))
      (_binary_integer, static_cast<std::size_t>(tk_id_::BINARY_INTEGER))
      (_octal_integer, static_cast<std::size_t>(tk_id_::OCTAL_INTEGER))
      (_hex_integer, static_cast<std::size_t>(tk_id_::HEX_INTEGER))
      (_real_literal, static_cast<std::size_t>(tk_id_::REAL_LITERAL))
      (_real_rw, static_cast<std::size_t>(tk_id_::REAL_RW))
      (_lreal_rw, static_cast<std::size_t>(tk_id_::LREAL_RW))
      (_common_type_lit, static_cast<std::size_t>(tk_id_::COMMON_TYPE_LIT))
      (_common_type_end_lit, static_cast<std::size_t>(tk_id_::COMMON_TYPE_END_LIT))
      (_common_colon_lit, static_cast<std::size_t>(tk_id_::COMMON_COLON))
      (_common_docolon_lit, static_cast<std::size_t>(tk_id_::COMMON_DOCOLON));

      this->self += _space [lex::_pass = lex::pass_flags::pass_ignore];
      this->self += _comment [lex::_pass = lex::pass_flags::pass_ignore];
  }
  ~ciaaLexer() = default;

  ciaaLexer(const ciaaLexer&) = delete;
  ciaaLexer& operator=(const ciaaLexer&) = delete;

  ciaaLexer(const ciaaLexer&&) = delete;
  ciaaLexer& operator=(const ciaaLexer&&) = delete;

  lex::token_def<char> _space;
  lex::token_def<char> _comment;
  lex::token_def<std::string> _identifier;
  lex::token_def<char> _line_jump;
  lex::token_def<std::string> _binary_integer;
  lex::token_def<std::string> _octal_integer;
  lex::token_def<std::string> _hex_integer;
  lex::token_def<double> _real_literal;
  lex::token_def<std::string> _real_rw;
  lex::token_def<std::string> _lreal_rw;
  lex::token_def<std::string> _common_type_lit;
  lex::token_def<std::string> _common_type_end_lit;
  lex::token_def<char> _common_colon_lit;
  lex::token_def<char> _common_docolon_lit;
};
typedef ciaaLexer<lex::lexertl::actor_lexer<>> Scanner;
}  // namespace compiler
}  // namespace ciaa
#endif   // COMPILER_IEC_LEXER_H

