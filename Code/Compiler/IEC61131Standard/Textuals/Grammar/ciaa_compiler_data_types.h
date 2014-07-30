/*! \brief Do not include this file directly in external modules.
    \file ciaa_compiler_data_types.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Mon Jul 28 01:25:32 UTC 2014

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
    \brief This file become from: Code/Compiler/IEC61131Standard/Textuals/Grammar/ciaa_compiler_data_types.h

    [ACSE-URL]: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/ "Asociación Civil para la Investigación, Promoción y Desarrollo de los Sistemas Electrónicos Embebidos"
    [CADIEEL-URL]: http://www.cadieel.org.ar "Cámara de Industrias Electrónicas, Electromecánicas y Luminotécnicas"
    [proyecto-ciaa-URL]: http://proyecto-ciaa.com.ar "Proyecto CIAA(Computador Industrial Abierta Argentina)"
    [proyecto-ciaa-PCSoftware-URL]: http://proyecto-ciaa.com.ar/gggg "PCSoftware bla bla"
*/

#ifndef CIAA_COMPILER_IEC_DATA_TYPES_H
#define CIAA_COMPILER_IEC_DATA_TYPES_H

#define DEUGGGGGG
#ifdef DEUGGGGGG
#define BOOST_SPIRIT_QI_DEBUG
#endif

// #include <string>

#include <boost/spirit/include/qi.hpp>

#include "Code/Compiler/IEC61131Standard/Textuals/Grammar/ciaa_compiler_constants.h"
#include "Code/Compiler/IEC61131Standard/Textuals/AST/ciaa_compiler_ast_data_types.h"

namespace ciaa {
namespace compiler {
namespace iec61131_3 {
namespace bsqi = boost::spirit::qi;

/*! \brief struct ciaaCommonElements implemment B.1.3 Data types.
*/
template <typename Iterator>
struct ciaaDataTypes : boost::spirit::qi::grammar<Iterator, std::string> {
  template<typename TokenDef>
  ciaaDataTypes(const TokenDef& token);
  ~ciaaDataTypes() = default;

  ciaaDataTypes(const ciaaDataTypes&) = delete;
  ciaaDataTypes& operator=(const ciaaDataTypes&) = delete;

  ciaaDataTypes(const ciaaDataTypes&&) = delete;
  ciaaDataTypes& operator=(const ciaaDataTypes&&) = delete;

  bsqi::rule<Iterator, std::string> _data_type_name;
  bsqi::rule<Iterator, std::string> _non_generic_type_name;

  // B.1.3.1 Elementary data types
  bsqi::rule<Iterator, std::string> _elementary_type_name;
  bsqi::rule<Iterator, std::string> _numeric_type_name;
  bsqi::rule<Iterator, std::string> _integer_type_name;
  bsqi::symbols<char> _signed_integer_type_name;
  bsqi::symbols<char> _unsigned_integer_type_name;
  bsqi::symbols<char> _real_type_name;
  bsqi::symbols<char> _date_type_name;
  bsqi::symbols<char> _bit_string_type_name;

  // B.1.3.2 Generic data types
  bsqi::rule<Iterator, std::string> _generic_type_name;

  // B.1.3.3 Derived data types
  bsqi::rule<Iterator, std::string> _derived_type_name;
  bsqi::rule<Iterator, std::string> _single_element_type_name;
  bsqi::rule<Iterator, std::string> _simple_type_name;
  bsqi::rule<Iterator, std::string> _subrange_type_name;
  bsqi::rule<Iterator, std::string> _enumerated_type_name;
  bsqi::rule<Iterator, std::string> _array_type_name;
  bsqi::rule<Iterator, std::string> _structure_type_name;
  bsqi::rule<Iterator, std::string> _data_type_declaration;
  bsqi::rule<Iterator, std::string> _type_declaration;
  bsqi::rule<Iterator, std::string> _single_element_type_declaration;
  bsqi::rule<Iterator, std::string> _simple_type_declaration;
  bsqi::rule<Iterator, std::string> _simple_spec_init;
  bsqi::rule<Iterator, std::string> _simple_specification;
  bsqi::rule<Iterator, std::string> _subrange_type_declaration;
  bsqi::rule<Iterator, std::string> _subrange_spec_init;
  bsqi::rule<Iterator, std::string> _subrange_specification;
  bsqi::rule<Iterator, std::string> _subrange;
  bsqi::rule<Iterator, std::string> _enumerated_type_declaration;
  bsqi::rule<Iterator, std::string> _enumerated_spec_init;
  bsqi::rule<Iterator, std::string> _enumerated_specification;
  bsqi::rule<Iterator, std::string> _enumerated_value;
  bsqi::rule<Iterator, std::string> _array_type_declaration;
  bsqi::rule<Iterator, std::string> _array_spec_init;
  bsqi::rule<Iterator, std::string> _array_specification;
  bsqi::rule<Iterator, std::string> _array_initialization;
  bsqi::rule<Iterator, std::string> _array_initial_elements;
  bsqi::rule<Iterator, std::string> _array_initial_element;
  bsqi::rule<Iterator, std::string> _structure_type_declaration;
  bsqi::rule<Iterator, std::string> _structure_specification;
  bsqi::rule<Iterator, std::string> _initialized_structure;
  bsqi::rule<Iterator, std::string> _structure_declaration;
  bsqi::rule<Iterator, std::string> _structure_element_declaration;
  bsqi::rule<Iterator, std::string> _structure_element_name;
  bsqi::rule<Iterator, std::string> _structure_initialization;
  bsqi::rule<Iterator, std::string> _structure_element_initialization;
  bsqi::rule<Iterator, std::string> _string_type_name;
  bsqi::rule<Iterator, std::string> _string_type_declaration;
};
}  // namespace iec61131_3
}  // namespace compiler
}  // namespcae ciaa
#endif  // CIAA_COMPILER_IEC_DATA_TYPES_H
