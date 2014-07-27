/*! \brief Do not include this file directly in external modules.
    \file ciaa_compiler_variable.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Sun Jul 27 20:02:46 UTC 2014

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
    \brief This file become from: Code/Compiler/IEC61131Standard/Common/ciaa_compiler_variable.h

    [ACSE-URL]: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/ "Asociación Civil para la Investigación, Promoción y Desarrollo de los Sistemas Electrónicos Embebidos"
    [CADIEEL-URL]: http://www.cadieel.org.ar "Cámara de Industrias Electrónicas, Electromecánicas y Luminotécnicas"
    [proyecto-ciaa-URL]: http://proyecto-ciaa.com.ar "Proyecto CIAA(Computador Industrial Abierta Argentina)"
    [proyecto-ciaa-PCSoftware-URL]: http://proyecto-ciaa.com.ar/gggg "PCSoftware bla bla"
*/

#ifndef CIAA_COMPILER_IEC_VARIABLE_H
#define CIAA_COMPILER_IEC_VARIABLE_H

#define DEUGGGGGG
#ifdef DEUGGGGGG
#define BOOST_SPIRIT_QI_DEBUG
#endif

#include <boost/spirit/include/qi.hpp>

namespace ciaa {
namespace compiler {
namespace iec61131_3 {
namespace bsqi = boost::spirit::qi;

/*! \brief struct ciaaVariable implemment B.1.4 Variables.
 */
template <typename Iterator>
struct ciaaVariable : boost::spirit::qi::grammar<Iterator, std::string> {
  template <typename TokenDef>
  ciaaVariable(const TokenDef& token) : ciaaVariable::base_type(_variable) {
    bsqi::char_type char_;

    //    // B.1.4.2 Multi-element variables
        _field_selector
            = token._identifier;
        _record_variable
            =  _symbolic_variable.alias();
        _structured_variable
            =  _record_variable
            >  char_('.')
            > _field_selector;
        _subscript
            =  _expression;
        _subscript_list
            =  char_('[')
            >  _subscript
            >> *(char_(',') > _subscript)
            >  char_(']');
        _subscripted_variable
            = _symbolic_variable.alias();
        _array_variable
            =  _subscripted_variable
            > _subscript_list;
        _multi_element_variable
            = _array_variable
            | _structured_variable;
        // B.1.4.1 Directly represented variables
        _location_prefix
            =  char_('I')
            |  char_('Q')
            |  char_('M');
        _size_prefix
            =  char_('N')  // FIXME(denisacostaq\@gmail.com): see NIL in the manual.
            |  char_('X')
            |  char_('B')
            |  char_('W')
            |  char_('D')
            |  char_('L');
        _direct_variable
            =  char_('%')
            >  _location_prefix
            >  _size_prefix
            >  token._integer
            > *(char_('.') > token._integer);
        // B.1.4 Variables
        _variable_name
            =  token._identifier;
        _symbolic_variable
            =  _variable_name
            |  _multi_element_variable;
        _variable
            =  _direct_variable
            |  _symbolic_variable;
  }

  ~ciaaVariable() = default;

  ciaaVariable(const ciaaVariable&) = delete;
  ciaaVariable& operator=(const ciaaVariable&) = delete;

  ciaaVariable(const ciaaVariable&&) = delete;
  ciaaVariable& operator=(const ciaaVariable&&) = delete;

  bsqi::rule<Iterator, std::string> _variable;
  bsqi::rule<Iterator, std::string> _direct_variable;
  bsqi::rule<Iterator, std::string> _location_prefix;
  bsqi::rule<Iterator, std::string> _size_prefix;
  bsqi::rule<Iterator, std::string> _multi_element_variable;
  bsqi::rule<Iterator, std::string> _array_variable;
  bsqi::rule<Iterator, std::string> _subscripted_variable;
  bsqi::rule<Iterator, std::string> _subscript_list;
  bsqi::rule<Iterator, std::string> _subscript;
  bsqi::rule<Iterator, std::string> _structured_variable;
  bsqi::rule<Iterator, std::string> _record_variable;
  bsqi::rule<Iterator, std::string> _field_selector;
  bsqi::rule<Iterator, std::string> _variable_name;
  bsqi::rule<Iterator, std::string> _symbolic_variable;
  bsqi::rule<Iterator, std::string> _expression;
};
}  // namespace iec61131_3
}  // namespace compiler
}  // namespcae ciaa




class ciaaVariable
{
public:
  ciaaVariable();
};

#endif  // CIAA_COMPILER_IEC_VARIABLE_H
