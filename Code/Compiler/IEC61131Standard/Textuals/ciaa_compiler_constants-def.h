/*! \brief This file give the functionality to ciaaConstants class.
    \file ciaa_compiler_constants-def.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Tue Jul 29 22:52:34 UTC 2014

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
    \brief This file become from: Code/Compiler/IEC61131Standard/Textuals/ciaa_compiler_constants-def.h

    [ACSE-URL]: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/ "Asociación Civil para la Investigación, Promoción y Desarrollo de los Sistemas Electrónicos Embebidos"
    [CADIEEL-URL]: http://www.cadieel.org.ar "Cámara de Industrias Electrónicas, Electromecánicas y Luminotécnicas"
    [proyecto-ciaa-URL]: http://proyecto-ciaa.com.ar "Proyecto CIAA(Computador Industrial Abierta Argentina)"
    [proyecto-ciaa-PCSoftware-URL]: http://proyecto-ciaa.com.ar/gggg "PCSoftware bla bla"
*/
#ifndef CIAA_COMPILER_IEC_CONSTANTS_DEF_H
#define CIAA_COMPILER_IEC_CONSTANTS_DEF_H

#include "Code/Compiler/IEC61131Standard/Textuals/ciaa_compiler_constants.h"

namespace ciaa {
namespace compiler {
namespace iec61131_3 {
template <typename Iterator>
template<typename TokenDef>
ciaaConstants<Iterator>::ciaaConstants(const TokenDef& token)
  : ciaaConstants::base_type(_constant)
//  , _ext_data_types{}
{
  bsqi::char_type char_;
  // External rules
  ciaaDataTypes<Iterator> _ext_data_types{token};
  ciaaCommonElements<Iterator> _ext_common_elements{token};

  // B.1.2.1 Numeric literals
  bsqi::symbols<char> bool_char, true_false;
  bool_char.add("BOOL#");
  true_false.add("TRUE");
  true_false.add("FALSE");
  _boolean_literal
      =  (-bool_char > char_('0') | char_('1')) |  true_false;
  bsqi::symbols<char> bwdl;
  bwdl.add("BYTE");
  bwdl.add("WORD");
  bwdl.add("DWORD");
  bwdl.add("LWORD");
  _bit_string_literal  // FIXME(denisacostaq/@gmail.com): unsigned_integer
      =  -(bwdl > char_('#'))
      >  (_binary_integer | _octal_integer | _hex_integer);
  _exponent
      =  (char_('E') | char_('e')) >> -(char_('-') | char_('+')) > _integer;
  _real_literal
      =  -(_ext_data_types._real_type_name > char_('#'))
      >  _signed_integer >  char_('.') >  _integer >> -(_exponent);

  _numeric_literal
      =  _integer_literal
      |  _real_literal;
  _hex_integer
      =  "16#" >  _ext_common_elements._hex_digit
      >> *(char_('_') > _ext_common_elements._hex_digit);
  _octal_integer
      =  "8#" > _ext_common_elements._octal_digit
      >> *(char_('_') > _ext_common_elements._octal_digit);
  _bit
      = char_('0') | char_('1');
  _binary_integer
      =  "2#" > _bit >> *(char_('_') > _bit);
  _integer
      =  _ext_common_elements._digit >> *(char_('_') > _ext_common_elements._digit);

  _signed_integer
      =  -(char_('+') | char_('-')) > _integer;
  _integer_literal
      =  -(_ext_data_types._integer_type_name > char_('#'))
      >> (_signed_integer | _binary_integer | _octal_integer | _hex_integer);
  _numeric_literal
      =  _integer_literal | _real_literal;

  // B.1.2.2 Character strings
  bsqi::symbols<char> pracapraca;
  pracapraca.add(R"*($$)*");
  pracapraca.add(R"*($L)*");
  pracapraca.add(R"*($N)*");
  pracapraca.add(R"*($P)*");
  pracapraca.add(R"*($R)*");
  pracapraca.add(R"*($T)*");
  pracapraca.add(R"*($l)*");
  pracapraca.add(R"*($n)*");
  pracapraca.add(R"*($r)*");
  pracapraca.add(R"*($r)*");
  pracapraca.add(R"*($t)*");
  _common_character_representation
      =  //<any printable character except '$', '"' or "'"> |
         pracapraca;
  _double_byte_character_representation
      =  _common_character_representation
      |  R"*($')*"
      |  R"*(")*"
      |  "$"
      >  _ext_common_elements._hex_digit
      >  _ext_common_elements._hex_digit
      >  _ext_common_elements._hex_digit
      >  _ext_common_elements._hex_digit;
  _single_byte_character_representation
      =  _common_character_representation
      |  R"*($')*"
      |  R"*(")*"
      |  "$"
      >  _ext_common_elements._hex_digit
      >  _ext_common_elements._hex_digit;
  _double_byte_character_string
      =  char_('"')
      >> *(_double_byte_character_representation)
      >  char_('"');
  _single_byte_character_string
      =  char_('\'')
      >> *(_single_byte_character_representation)
      >  char_('\'');
  _character_string
      =  _single_byte_character_string | _double_byte_character_string;

  // B.1.2.3 Time literals
  _time_literal
      =  _duration  |  _time_of_day  |  _date  |  _date_and_time;
  // B.1.2.3.1 Duration
  _fixed_point
      =  _integer >> -(_integer);
  _milliseconds
      =  _fixed_point > ("ms");
  _seconds
      =  (_fixed_point > char_('s'))
      |  _integer > char_('s') >> -(char_('_')) > _milliseconds;
  _minutes
      =  _fixed_point > char_('m')
      | _integer > char_('m') >> -(char_('_')) > _milliseconds;
  _hours
      =  _fixed_point > char_('h')
      |  _integer > char_('h') >> -(char_('_')) > _minutes;
  _days
      =  _fixed_point > char_('d')
      |  _integer > char_('d') >> -(char_('_')) > _hours;
  _interval
      =  _days | _hours | _minutes | _seconds | _milliseconds;
  _duration
      =  (char_('T') | "TIME") > char_('#') >> -(char_('-')) > _interval;
  // B.1.2.3.2 Time of day and date
  _day_hour
      =  _integer;
  _day_minute
      =  _integer;
  _day_second
      =  _fixed_point;
  _daytime
      =  _day_hour > char_(':') > _day_minute > char_(':') > _day_second;
  bsqi::symbols<char> brubru;
  brubru.add("TIME_OF_DAY");
  brubru.add("TOD");
  _time_of_day
      =  brubru > char_('#') > _daytime;
  _year
      =  _integer;
  _month
      =  _integer;
  _day
      =  _integer;
  _date_literal
      =  _year > char_('-') > _month > char_('-') > _day;
  _date
      =  ("DATE" | char_('D')) > char_('#') > _date_literal;
  bsqi::symbols<char> brubru2;
  brubru2.add("DATE_AND_TIME");
  brubru2.add("DT");
  _date_and_time
      =  brubru2 >  char_('#') > _date_literal > char_('-') > _daytime;

  // B.1.2 Constants
  _constant
      =  _numeric_literal
      |  _character_string
      |  _time_literal
      |  _bit_string_literal
      |  _boolean_literal;
}
}  // namespace iec61131_3
}  // namespace compiler
}  // namespcae ciaa
#endif  // CIAA_COMPILER_IEC_CONSTANTS_DEF_H
