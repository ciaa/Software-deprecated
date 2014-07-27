/*! \brief Do not include this file directly in external modules.
    \file ciaa_compiler_pou.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Sun Jul 27 18:47:39 UTC 2014

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
    \brief This file become from: Code/Compiler/IEC61131Standard/Common/ciaa_compiler_pou.h

    [ACSE-URL]: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/ "Asociación Civil para la Investigación, Promoción y Desarrollo de los Sistemas Electrónicos Embebidos"
    [CADIEEL-URL]: http://www.cadieel.org.ar "Cámara de Industrias Electrónicas, Electromecánicas y Luminotécnicas"
    [proyecto-ciaa-URL]: http://proyecto-ciaa.com.ar "Proyecto CIAA(Computador Industrial Abierta Argentina)"
    [proyecto-ciaa-PCSoftware-URL]: http://proyecto-ciaa.com.ar/gggg "PCSoftware bla bla"
*/
#ifndef CIAA_COMPILER_IEC_POU_H
#define CIAA_COMPILER_IEC_POU_H

#define DEUGGGGGG
#ifdef DEUGGGGGG
#define BOOST_SPIRIT_QI_DEBUG
#endif

#include <boost/spirit/include/qi.hpp>
#include "Code/Compiler/IEC61131Standard/Common/ciaa_compiler_declaration_initialization.h"

namespace ciaa {
namespace compiler {
namespace iec61131_3 {
namespace bsqi = boost::spirit::qi;

/*! \brief struct ciaaProgrammingModel implemment B.0 Programming model.
 */
template <typename Iterator>
struct ciaaPOU : boost::spirit::qi::grammar<Iterator, std::string> {
  template <typename TokenDef>
  ciaaPOU(const TokenDef& token) : ciaaPOU::base_type(_function_declaration) {
    bsqi::char_type char_;

    _standard_function_name
        = char_('A');  // FIXME(denisacostaq\@gmail.com): 2.5.1.5
    _derived_function_name
        = token._identifier;
    _function_name
        = _standard_function_name
        | _derived_function_name;
//    _function_declaration
//        =  token._rw_function
//        >  _derived_function_name
//        >  char_(':')
//        >  (_el)

  }

  ~ciaaPOU() = default;

  ciaaPOU(const ciaaPOU&) = delete;
  ciaaPOU& operator=(const ciaaPOU&) = delete;

  ciaaPOU(const ciaaPOU&&) = delete;
  ciaaPOU& operator=(const ciaaPOU&&) = delete;

  // B.1.5.1 Functions
  bsqi::rule<Iterator, std::string> _function_name;
  bsqi::rule<Iterator, std::string> _standard_function_name;
  bsqi::rule<Iterator, std::string> _derived_function_name;
  bsqi::rule<Iterator, std::string> _function_declaration;
  bsqi::rule<Iterator, std::string> _io_var_declarations;
  bsqi::rule<Iterator, std::string> _function_var_decls;
  bsqi::rule<Iterator, std::string> _function_body;
  bsqi::rule<Iterator, std::string> _var2_init_decl;

  // B.1.5.2 Function blocks
  bsqi::rule<Iterator, std::string> _function_block_type_name;
  bsqi::rule<Iterator, std::string> _standard_function_block_name;
  bsqi::rule<Iterator, std::string> _derived_function_block_name;
  bsqi::rule<Iterator, std::string> _function_block_declaration;
  bsqi::rule<Iterator, std::string> _other_var_declarations;
  bsqi::rule<Iterator, std::string> _temp_var_decls;
  bsqi::rule<Iterator, std::string> _non_retentive_var_decls;
  bsqi::rule<Iterator, std::string> _function_block_body;

  // B.1.5.3 Programs
  bsqi::rule<Iterator, std::string> _program_type_name;
  bsqi::rule<Iterator, std::string> _program_declaration;
  bsqi::rule<Iterator, std::string> _program_access_decls;
  bsqi::rule<Iterator, std::string> _program_access_decl;
};
}  // namespace iec61131_3
}  // namespace compiler
}  // namespcae ciaa

#endif  // CIAA_COMPILER_IEC_POU_H