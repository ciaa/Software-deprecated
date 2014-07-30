/*! \brief Do not include this file directly in external modules.
    \file ciaa_compiler_constants.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Mon Jul 28 00:56:18 UTC 2014

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
    \brief This file become from: Code/Compiler/IEC61131Standard/Textuals/Grammar/ciaa_compiler_constants.h

    [ACSE-URL]: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/ "Asociación Civil para la Investigación, Promoción y Desarrollo de los Sistemas Electrónicos Embebidos"
    [CADIEEL-URL]: http://www.cadieel.org.ar "Cámara de Industrias Electrónicas, Electromecánicas y Luminotécnicas"
    [proyecto-ciaa-URL]: http://proyecto-ciaa.com.ar "Proyecto CIAA(Computador Industrial Abierta Argentina)"
    [proyecto-ciaa-PCSoftware-URL]: http://proyecto-ciaa.com.ar/gggg "PCSoftware bla bla"
*/

#ifndef CIAA_COMPILER_IEC_CONSTANTS_H
#define CIAA_COMPILER_IEC_CONSTANTS_H

#define DEUGGGGGG
#ifdef DEUGGGGGG
#define BOOST_SPIRIT_QI_DEBUG
#endif

#include <boost/spirit/include/qi.hpp>
#include "Code/Compiler/IEC61131Standard/Textuals/Grammar/ciaa_compiler_data_types.h"
#include "Code/Compiler/IEC61131Standard/Textuals/Grammar/ciaa_compiler_common_elements.h"

namespace ciaa {
namespace compiler {
namespace iec61131_3 {
namespace bsqi = boost::spirit::qi;

/*! \brief struct ciaaCommonElements implemment B.1.2 Constants.
 */
template <typename Iterator>
struct ciaaConstants : boost::spirit::qi::grammar<Iterator, std::string> {
  template<typename TokenDef>
  ciaaConstants(const TokenDef& token);
  ~ciaaConstants() = default;

  ciaaConstants(const ciaaConstants&) = delete;
  ciaaConstants& operator=(const ciaaConstants&) = delete;

  ciaaConstants(const ciaaConstants&&) = delete;
  ciaaConstants& operator=(const ciaaConstants&&) = delete;

  bsqi::rule<Iterator, std::string> _constant;

  // B.1.2.1 Numeric literals
  bsqi::rule<Iterator, std::string> _numeric_literal;
  bsqi::rule<Iterator, std::string> _integer_literal;
  bsqi::rule<Iterator, std::string> _signed_integer;
  bsqi::rule<Iterator, std::string> _integer;
  bsqi::rule<Iterator, std::string> _binary_integer;
  bsqi::rule<Iterator, std::string> _bit;
  bsqi::rule<Iterator, std::string> _octal_integer;
  bsqi::rule<Iterator, std::string> _hex_integer;
  bsqi::rule<Iterator, std::string> _real_literal;
  bsqi::rule<Iterator, std::string> _exponent;
  bsqi::rule<Iterator, std::string> _bit_string_literal;
  bsqi::rule<Iterator, std::string> _boolean_literal;

  // B.1.2.2 Character strings
  bsqi::rule<Iterator, std::string> _character_string;
  bsqi::rule<Iterator, std::string> _single_byte_character_string;
  bsqi::rule<Iterator, std::string> _double_byte_character_string;
  bsqi::rule<Iterator, std::string> _single_byte_character_representation;
  bsqi::rule<Iterator, std::string> _double_byte_character_representation;
  bsqi::rule<Iterator, std::string> _common_character_representation;

  // B.1.2.3 Time literals
  bsqi::rule<Iterator, std::string> _time_literal;
  // B.1.2.3.1 Duration
  bsqi::rule<Iterator, std::string> _duration;
  bsqi::rule<Iterator, std::string> _interval;
  bsqi::rule<Iterator, std::string> _days;
  bsqi::rule<Iterator, std::string> _fixed_point;
  bsqi::rule<Iterator, std::string> _hours;
  bsqi::rule<Iterator, std::string> _minutes;
  bsqi::rule<Iterator, std::string> _seconds;
  bsqi::rule<Iterator, std::string> _milliseconds;
  // B.1.2.3.2 Time of day and date
  bsqi::rule<Iterator, std::string> _time_of_day;
  bsqi::rule<Iterator, std::string> _daytime;
  bsqi::rule<Iterator, std::string> _day_hour;
  bsqi::rule<Iterator, std::string> _day_minute;
  bsqi::rule<Iterator, std::string> _day_second;
  bsqi::rule<Iterator, std::string> _date;
  bsqi::rule<Iterator, std::string> _date_literal;
  bsqi::rule<Iterator, std::string> _year;
  bsqi::rule<Iterator, std::string> _month;
  bsqi::rule<Iterator, std::string> _day;
  bsqi::rule<Iterator, std::string> _date_and_time;


};
}  // namespace iec61131_3
}  // namespace compiler
}  // namespcae ciaa

#endif  // CIAA_COMPILER_IEC_CONSTANTS_H
