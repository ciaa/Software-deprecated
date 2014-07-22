/*! \brief Do not include this file directly in external modules.
    \file ciaa_compiler_parcer.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Fri Jul 18 19:03:14 UTC 2014

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
    \brief This file become from: Code/Compiler/IEC61131Standard/Parser/ciaa_compiler_parcer.h

    [ACSE-URL]: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/ "Asociación Civil para la Investigación, Promoción y Desarrollo de los Sistemas Electrónicos Embebidos"
    [CADIEEL-URL]: http://www.cadieel.org.ar "Cámara de Industrias Electrónicas, Electromecánicas y Luminotécnicas"
    [proyecto-ciaa-URL]: http://proyecto-ciaa.com.ar "Proyecto CIAA(Computador Industrial Abierta Argentina)"
    [proyecto-ciaa-PCSoftware-URL]: http://proyecto-ciaa.com.ar/gggg "PCSoftware bla bla"
*/

#ifndef CIAA_COMPILER_IEC_PARCER_H
#define CIAA_COMPILER_IEC_PARCER_H

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













#include <functional>

#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/support_utree.hpp>
#include <boost/spirit/include/phoenix.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/phoenix_stl.hpp>
//#include <boost/phoenix/stl/container.hpp>

#include <boost/spirit/home/lex/argument.hpp>

#include <boost/spirit/include/lex.hpp>
#include "Code/Compiler/IEC61131Standard/Textuals/Common/Scanner/ciaa_compiler_lexer.h"
#include "AST.h"


namespace qi  = boost::spirit::qi;

namespace ciaa {
namespace compiler {

struct declaration
{
    template <typename T1, typename T2 = void>
    struct result { typedef void type; };

    void operator()(boost::spirit::utree& expr, boost::spirit::utree const& rhs) const
    {
      //boost::spirit::utree ut;
      //ut.push_back(rhs);
      expr.push_back(rhs);
    }
};
boost::phoenix::function<declaration> dcl;


struct ids
{
    template <typename T1, typename T2 = void>
    struct result { typedef void type; };

    void operator()(boost::spirit::lex::_tokenid_type td) const
    {
//      if (td == tk_id_::REAL_LITERAL) {
//      }
    }
};
boost::phoenix::function<ids> iddd;


template <typename Iterator>
struct li_grammar : qi::grammar<Iterator, boost::spirit::utree()> {
  template <typename TokenDef>
  li_grammar(const TokenDef& token/*,
             boost::spirit::utree *ut*/)
    : li_grammar::base_type(data_type_declaration) {

    real_type_name
        = token._real_rw
              // [boost::phoenix::push_back(boost::phoenix::ref(*ut), boost::spirit::_1)]
          | token._lreal_rw
        ;
    //    non_generic_type_name = real_type_name;
    //    data_type_name = non_generic_type_name;
    simple_type_name
        = token._identifier
        ;

    numeric_type_name
        = real_type_name
        ;

    elementary_type_name
        = numeric_type_name
        ;
    simple_specification
        = elementary_type_name
        ;
    simple_spec_init
        = simple_specification
        ;
    simple_type_declaration
        =  simple_type_name
        >> token._common_docolon_lit
        >> simple_spec_init
        ;
    single_element_type_declaration
        = simple_type_declaration
        ;
    type_declaration
        = single_element_type_declaration
        ;

    data_type_declaration =
        token._common_type_lit
        >> type_declaration
        >> token._common_colon_lit
        >> *(type_declaration
             >> token._common_colon_lit
            )
        >> token._common_type_end_lit
        ;
  }


  qi::rule<Iterator, boost::spirit::utree()> data_type_declaration;
  qi::rule<Iterator, boost::spirit::utree()> type_declaration;
  qi::rule<Iterator, boost::spirit::utree()> single_element_type_declaration;
  qi::rule<Iterator, boost::spirit::utree()> simple_type_declaration;
  qi::rule<Iterator, boost::spirit::utree()> simple_type_name;
  qi::rule<Iterator, boost::spirit::utree()> numeric_type_name;
  qi::rule<Iterator, boost::spirit::utree()> simple_spec_init;

  qi::rule<Iterator, boost::spirit::utree()> simple_specification;
  qi::rule<Iterator, boost::spirit::utree()> elementary_type_name;

  qi::rule<Iterator, boost::spirit::utree()> real_type_name;
  qi::rule<Iterator, boost::spirit::utree()> non_generic_type_name;
  qi::rule<Iterator, boost::spirit::utree()> data_type_name;
};
}  // namespace compiler
}  // namespace ciaa

#endif  // CIAA_COMPILER_IEC_PARCER_H