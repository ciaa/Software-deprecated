/*! \brief This file give the functionality to grammar header files.
    \file ciaa_compiler_grammar_definition.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Thu Jul 31 02:58:50 UTC 2014

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
    \brief This file become from: Code/Compiler/IEC61131Standard/Textuals/Grammar/ciaa_compiler_grammar_definition.h

    [ACSE-URL]: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/ "Asociación Civil para la Investigación, Promoción y Desarrollo de los Sistemas Electrónicos Embebidos"
    [CADIEEL-URL]: http://www.cadieel.org.ar "Cámara de Industrias Electrónicas, Electromecánicas y Luminotécnicas"
    [proyecto-ciaa-URL]: http://proyecto-ciaa.com.ar "Proyecto CIAA(Computador Industrial Abierta Argentina)"
    [proyecto-ciaa-PCSoftware-URL]: http://proyecto-ciaa.com.ar/gggg "PCSoftware bla bla"
*/

#ifndef CIAA_COMPILER_IEC_GRAMMAR_DEFINITION_H
#define CIAA_COMPILER_IEC_GRAMMAR_DEFINITION_H

#include "Code/Compiler/IEC61131Standard/Textuals/Grammar/ciaa_compiler_programming_model.h"

namespace ciaa {
namespace compiler {
namespace iec61131_3 {

template <typename Iterator>
template <typename TokenDef>
ciaaProgrammingModel<Iterator>::ciaaProgrammingModel(const TokenDef& token)
  : ciaaProgrammingModel::base_type(_library_element_declaration) {

#ifdef BOOST_SPIRIT_NO_PREDEFINED_TERMINALS
#endif
  bsqi::char_type char_;





//}






  /****************************************************************************/
  /*                               B.1.2 Constants.                           */
  /****************************************************************************/
  // B.1.2.1 Numeric literals
//  bsqi::symbols<char> bool_char, true_false;
//  bool_char.add("BOOL#");
//  true_false.add("TRUE");
//  true_false.add("FALSE");
//  _boolean_literal
//      =  (-bool_char > char_('0') | char_('1')) |  true_false;
//  bsqi::symbols<char> bwdl;
//  bwdl.add("BYTE");
//  bwdl.add("WORD");
//  bwdl.add("DWORD");
//  bwdl.add("LWORD");
//  _bit_string_literal  // FIXME(denisacostaq/@gmail.com): unsigned_integer
//      =  -(bwdl > char_('#'))
//      >  (_binary_integer.alias() | _octal_integer.alias() | _hex_integer.alias());
//  _exponent
//      =  (char_('E') | char_('e')) >> -(char_('-') | char_('+')) > _integer.alias();
//  _real_literal
//      =  -(_real_type_name > char_('#'))
//      >  _signed_integer.alias() >  char_('.') >  _integer.alias() >> -(_exponent.alias());

//  _numeric_literal
//      =  _integer_literal.alias()
//      |  _real_literal.alias();
//  _hex_integer
//      =  "16#" >  _hex_digit.alias()
//      >> *(char_('_') > _hex_digit.alias());
//  _octal_integer
//      =  "8#" > _octal_digit.alias()
//      >> *(char_('_') > _octal_digit.alias());
//  _bit
//      = char_('0') | char_('1');
//  _binary_integer
//      =  "2#" > _bit >> *(char_('_') > _bit);
//  _integer
//      =  _digit.alias() >> *(char_('_') > _digit.alias());

//  _signed_integer
//      =  -(char_('+') | char_('-')) > _integer.alias();
//  _integer_literal
//      =  -(_integer_type_name.alias() > char_('#'))
//      >> (_signed_integer.alias() | _binary_integer.alias() | _octal_integer.alias() | _hex_integer.alias());
//  _numeric_literal
//      =  _integer_literal.alias() | _real_literal.alias();

//  // B.1.2.2 Character strings
//  bsqi::symbols<char> pracapraca;
//  pracapraca.add(R"*($$)*");
//  pracapraca.add(R"*($L)*");
//  pracapraca.add(R"*($N)*");
//  pracapraca.add(R"*($P)*");
//  pracapraca.add(R"*($R)*");
//  pracapraca.add(R"*($T)*");
//  pracapraca.add(R"*($l)*");
//  pracapraca.add(R"*($n)*");
//  pracapraca.add(R"*($r)*");
//  pracapraca.add(R"*($r)*");
//  pracapraca.add(R"*($t)*");
//  _common_character_representation
//      =  //<any printable character except '$', '"' or "'"> |
//         pracapraca;
//  _double_byte_character_representation
//      =  _common_character_representation.alias()
//      |  R"*($')*"
//      |  R"*(")*"
//      |  "$"
//      >  _hex_digit
//      >  _hex_digit
//      >  _hex_digit
//      >  _hex_digit;
//  _single_byte_character_representation
//      =  _common_character_representation.alias()
//      |  R"*($')*"
//      |  R"*(")*"
//      |  "$"
//      >  _hex_digit
//      >  _hex_digit;
//  _double_byte_character_string
//      =  char_('"')
//      >> *(_double_byte_character_representation)
//      >  char_('"');
//  _single_byte_character_string
//      =  char_('\'')
//      >> *(_single_byte_character_representation)
//      >  char_('\'');
//  _character_string
//      =  _single_byte_character_string | _double_byte_character_string;

//  // B.1.2.3 Time literals
//  _time_literal
//      =  _duration  |  _time_of_day  |  _date  |  _date_and_time;
//  // B.1.2.3.1 Duration
//  _fixed_point
//      =  _integer >> -(_integer);
//  _milliseconds
//      =  _fixed_point > ("ms");
//  _seconds
//      =  (_fixed_point > char_('s'))
//      |  _integer > char_('s') >> -(char_('_')) > _milliseconds;
//  _minutes
//      =  _fixed_point > char_('m')
//      | _integer > char_('m') >> -(char_('_')) > _milliseconds;
//  _hours
//      =  _fixed_point > char_('h')
//      |  _integer > char_('h') >> -(char_('_')) > _minutes;
//  _days
//      =  _fixed_point > char_('d')
//      |  _integer > char_('d') >> -(char_('_')) > _hours;
//  _interval
//      =  _days | _hours | _minutes | _seconds | _milliseconds;
//  _duration
//      =  (char_('T') | "TIME") > char_('#') >> -(char_('-')) > _interval;
//  // B.1.2.3.2 Time of day and date
//  _day_hour
//      =  _integer;
//  _day_minute
//      =  _integer;
//  _day_second
//      =  _fixed_point;
//  _daytime
//      =  _day_hour > char_(':') > _day_minute > char_(':') > _day_second;
//  bsqi::symbols<char> brubru;
//  brubru.add("TIME_OF_DAY");
//  brubru.add("TOD");
//  _time_of_day
//      =  brubru > char_('#') > _daytime;
//  _year
//      =  _integer;
//  _month
//      =  _integer;
//  _day
//      =  _integer;
//  _date_literal
//      =  _year > char_('-') > _month > char_('-') > _day;
//  _date
//      =  ("DATE" | char_('D')) > char_('#') > _date_literal;
//  bsqi::symbols<char> brubru2;
//  brubru2.add("DATE_AND_TIME");
//  brubru2.add("DT");
//  _date_and_time
//      =  brubru2 >  char_('#') > _date_literal > char_('-') > _daytime;

//  // B.1.2 Constants
//  _constant
//      =  _numeric_literal
//      |  _character_string
//      |  _time_literal
//      |  _bit_string_literal
//      |  _boolean_literal;
////}


  /****************************************************************************/
  /*                               B.1.3 Data types.                          */
  /****************************************************************************/
//  // B.1.3.1 Elementary data types
//  bsqi::symbols<char> elementary_type_name_others;
//  _bit_string_type_name.add("BOOL");
//  _bit_string_type_name.add("BYTE");
//  _bit_string_type_name.add("WORD");
//  _bit_string_type_name.add("DWORD");
//  _bit_string_type_name.add("LWORD");
//  _date_type_name.add("DATE");
//  _date_type_name.add("TIME_OF_DAY");
//  _date_type_name.add("TOD");
//  _date_type_name.add("DATE_AND_TIME");
//  _date_type_name.add("DT");
//  _real_type_name.add("REAL");
//  _real_type_name.add("LREAL");
//  _unsigned_integer_type_name.add("USINT");
//  _unsigned_integer_type_name.add("UINT");
//  _unsigned_integer_type_name.add("UDINT");
//  _unsigned_integer_type_name.add("ULINT");
//  _signed_integer_type_name.add("SINT");
//  _signed_integer_type_name.add("INT");
//  _signed_integer_type_name.add("DINT");
//  _signed_integer_type_name.add("LINT");
//  elementary_type_name_others.add("STRING");
//  elementary_type_name_others.add("WSTRING");
//  elementary_type_name_others.add("TIME");
//  _integer_type_name
//      =   _signed_integer_type_name
//      |   _unsigned_integer_type_name;
//  _numeric_type_name
//      =  _integer_type_name
//      |  _real_type_name;
//  _elementary_type_name
//      =  _numeric_type_name
//      |  _date_type_name
//      |  _bit_string_type_name
//      |  elementary_type_name_others;

//  // B.1.3.2 Generic data types
//  bsqi::symbols<char> generic_type_name;
//  generic_type_name.add("ANY");
//  generic_type_name.add("ANY_DERIVED");
//  generic_type_name.add("ANY_ELEMENTARY");
//  generic_type_name.add("ANY_MAGNITUDE");
//  generic_type_name.add("ANY_NUM");
//  generic_type_name.add("ANY_REAL");
//  generic_type_name.add("ANY_INT");
//  generic_type_name.add("ANY_BIT");
//  generic_type_name.add("ANY_STRING");
//  generic_type_name.add("ANY_DATE");
//  _generic_type_name
//      = generic_type_name;
//  _derived_type_name
//      =  _single_element_type_name
//      |  _array_type_name
//      |  _structure_type_name
//      |  _string_type_name;
//  _single_element_type_name
//      =  _simple_type_name
//      |  _subrange_type_name
//      |  _enumerated_type_name;
//  _simple_type_name
//      =  token._identifier;
//  _subrange_type_name
//      =  token._identifier;
//  _enumerated_type_name
//      =  token._identifier;
//  _array_type_name
//      =  token._identifier;
//  _structure_type_name
//      =  token._identifier;
//  _data_type_declaration
//      =  "TYPE"
//      >  _type_declaration
//      >  char_(";")
//      >> *(
//             _type_declaration
//             >  char_(";")
//          )
//      >  "END_TYPE";
//  _type_declaration
//      =  _single_element_type_declaration
//      |  _array_type_declaration
//      |  _structure_type_declaration
//      |  _string_type_declaration;
//  _single_element_type_declaration
//      =  _simple_type_declaration
//      |  _subrange_type_declaration
//      |  _enumerated_type_declaration;
//  _simple_type_declaration
//      =  _simple_type_name
//      >  char_(":")
//      >  _simple_spec_init;
//  _simple_spec_init
//      =  _simple_specification
//      >> -(
//                 ":="
//             >>  _constant
//          );
//  _simple_specification
//      =  _elementary_type_name
//      |  _simple_type_name;
//  _subrange_type_declaration
//      =  _subrange_type_name
//      >  char_(":")
//      >  _subrange_spec_init;
//  _subrange_spec_init
//      =  _subrange_specification
//      >> -(
//                ":="
//             >  _signed_integer
//          );
//  _subrange_specification // FIXME(denisacostaq\@gmail.com): ver la precedencia del |.
//      =  _integer_type_name
//      >  char_('(')
//      >  _subrange
//      >  char_(')')
//      |  _subrange_type_name;
//  _subrange
//      =  _signed_integer
//      >  ".."
//      >  _signed_integer;
//  _enumerated_type_declaration
//      =  _enumerated_type_name
//      >  char_(':')
//      >  _enumerated_spec_init;
//  _enumerated_spec_init
//      =  _enumerated_specification
//      >> -(
//                ":="
//            >>  _enumerated_value
//          );
//  _enumerated_specification
//      =  (
//              char_("(")
//           >  _enumerated_value
//           >> *(
//                  char_(",")
//                > _enumerated_value
//               )
//           >  char_(")")
//         )
//      |  _enumerated_type_name ;
//  _enumerated_value
//      =  -(
//               _enumerated_type_name
//            >  char_("#")
//          )
//      >  token._identifier;

//  _array_type_declaration
//      =  _array_type_name
//      >  char_(":")
//      >  _array_spec_init;
//  _array_spec_init
//      =  _array_specification
//      >> -(
//               ":="
//             >  _array_initialization
//          );
//  _array_specification
//      =  _array_type_name
//      |  "ARRAY"
//      >  char_("[")
//      >  _subrange
//      >> *(
//                char_(",")
//            >>  _subrange
//          )
//      >  char_("]")
//      >  "OF"
//      >  _non_generic_type_name;
//  _array_initialization
//      =  char_("[")
//      >  _array_initial_elements
//      >> *(
//               char_(",")
//            >  _array_initial_elements
//          )
//      >  char_("]");
//  _array_initial_elements
//      =  _array_initial_element
//      |  _integer
//      >  "("
//      >> -_array_initial_element
//      >  ")";
//  _structure_type_declaration
//      =  _string_type_name
//      >  char_(":")
//      >  _structure_specification;
//  _structure_specification
//      =  _structure_declaration
//      |  _initialized_structure;
//  _initialized_structure
//      =   _string_type_name
//      >>  -(
//                ":="
//             >  _structure_initialization
//           );
//  _structure_declaration
//      =  "STRUCT"
//      > +(
//               _structure_element_declaration
//            >  char_(";")
//          )
//      >  "END_STRUCT";
//  _structure_element_declaration
//      =  _structure_element_name
//      >  char_(":")
//      >> (
//              _simple_spec_init
//           |  _subrange_spec_init
//           |  _enumerated_spec_init
//           |  _array_spec_init
//           |  _initialized_structure
//         );
//  _structure_initialization
//      =  char_("(")
//      >  _structure_element_initialization
//      >> *(
//               char_(",")
//            >  _structure_element_initialization
//          )
//      >  char_(")");
//  _structure_element_initialization
//      =  _structure_element_name
//      >  ":="
//      >> (
//              _constant
//           |  _enumerated_value
//           |  _array_initialization
//           |  _structure_initialization
//         );
//  _string_type_name
//      =  token._identifier;
//  bsqi::symbols<char> two_string;
//  two_string.add("STRING");
//  two_string.add("WSTRING");
//  _string_type_declaration
//      =  _string_type_name
//      >  char_(":")
//      >  two_string
//      >> -(
//               char_("[")
//            >  _integer
//            >  char_("]")
//          )
//      >> -(
//               ":="
//            >  _character_string
//          );
////}


  /****************************************************************************/
  /*                               B.1.4 Variables.                           */
  /****************************************************************************/
//  // B.1.4.3 Declaration and initialization
//  _var_spec
//      =  _simple_specification
//      |  _subrange_specification
//      |  _enumerated_specification
//      |  _array_specification
//      |  _structure_type_name
//      |  "STRING" >> -(char_("[") > _integer > char_("]"))
//      |  "WSTRING" >> -(char_("[") > _integer > char_("]"));
//  _incompl_location
//      =  "AT" > char_("%") > (char_('I')|char_('Q')|char_('M')) > char_('*');
//  _incompl_located_var_decl
//      =  _variable_name > _incompl_location > char_(":") > _var_spec;
//  _double_byte_string_spec
//      =  "WSTRING"
//      >> -(char_("[") > _integer > char_("]"))
//      >> -(":=" > _double_byte_character_string);
//  _double_byte_string_var_declaration
//      =  _var1_list > char_(":") > _double_byte_string_spec;
//  _single_byte_string_spec
//      =  "STRING"
//      >> -(char_("[") > _integer > char_("]"))
//      >> -(":=" > _single_byte_character_string);
//  _single_byte_string_var_declaration
//      =  _var1_list > char_(":") > _single_byte_string_spec;
//  _string_var_declaration
//      =  _single_byte_string_var_declaration
//      |  _double_byte_string_var_declaration;
//  _global_var_list
//      =  _global_var_name >> *(char_(",") > _global_var_name);
//  _location
//      =  "AT" > _direct_variable;
//  _located_var_spec_init
//      =  _simple_spec_init
//      |  _subrange_spec_init
//      |  _enumerated_spec_init
//      |  _array_spec_init
//      |  _initialized_structure
//      |  _single_byte_string_spec
//      |  _double_byte_string_spec;
//  _global_var_spec
//      =  _global_var_list | -_global_var_name > _location;
//  _global_var_decl
//      =  _global_var_spec > char_(":")
//      >> -(_located_var_spec_init | _function_block_type_name);
//  bsqi::symbols<char> fdfd;
//  fdfd.add("CONSTANT");
//  fdfd.add("RETAIN");
//  _global_var_declarations
//      =  "VAR_GLOBAL" >> -fdfd
//      >  _global_var_decl > char_(";")
//      >> *(_global_var_decl > char_(";"))
//      > "END_VAR";
//  _global_var_name
//      =  token._identifier;
//  _external_declaration
//      =  _global_var_name > char_(":")
//      >  (
//               _simple_specification
//            |  _subrange_specification
//            |  _enumerated_specification
//            |  _array_specification
//            |  _structure_type_name
//            |  _function_block_type_name
//         );
//  bsqi::symbols<char> tttt;
//  tttt.add("CONSTANT");
//  _external_var_declarations
//      =  "VAR_EXTERNAL" >> -tttt
//      >  _external_declaration > char_(";")
//      >> *(_external_declaration > char_(";"))
//      > "END_VAR";
//  _located_var_decl
//      =  -_variable_name > _location > char_(":") > _located_var_spec_init;
//  bsqi::symbols<char> tyty;
//  tyty.add("CONSTANT");
//  tyty.add("RETAIN");
//  tyty.add("NON_RETAIN");
//  _located_var_declarations
//      =  "VAR" >> -tyty
//      >  _located_var_decl > char_(";")
//      >> *(_located_var_decl > char_(";"))
//      >> "END_VAR";
//  bsqi::symbols<char> fgfg;
//  fgfg.add("RETAIN");
//  _retentive_var_declarations
//      =  "VAR" >> -fgfg
//      >  _var_init_decl > char_(";")
//      >> *(_var_init_decl > char_(";"))
//      >  "END_VAR";
//  bsqi::symbols<char> fgfg2;
//  fgfg2.add("CONSTANT");
//  _var_declaration
//      =  "VAR" > -fgfg2
//      >  _var1_init_decl > char_(";")
//      >> *(_var1_init_decl > char_(";"))
//      >  "END__VAR";
//  _structured_var_declaration
//      =  _var1_list > char_(":") > _structure_type_name;
//  _array_var_declaration
//      = _var1_list > char_(":") > _array_specification;
//  _var1_declaration
//      =  _var1_list
//      >  char_(':')
//      >  (
//              _simple_specification
//           |  _subrange_specification
//           |  _enumerated_specification
//         );
//  _temp_var_decl
//      =  _var1_declaration
//      |  _array_var_declaration
//      |  _structured_var_declaration
//      |  _string_var_declaration;
//  _var_declaration
//      =  _temp_var_decl | _fb_name_decl;
//  _input_output_declarations
//      =  "VAR_IN_OUT"
//      >  _var_declaration > char_(';')
//      >> *(_var_declaration > char_(';'))
//      >  "END_VAR";
//  bsqi::symbols<char> rgrg;
//  rgrg.add("RETAIN");
//  rgrg.add("NON_RETAIN");
//  _output_declarations
//      =  "VAR_OUTPUT" >> -(rgrg)
//      >  _var_init_decl > char_(';')
//      >> *(_var_init_decl > char_(';'))
//      >  "END_VAR";
//  _fb_name
//      =  token._identifier;
//  _fb_name_list
//      =  _fb_name >> *(char_(',') > _fb_name);
//    _fb_name_decl
//        =  _fb_name_list > char_(":") > _function_block_type_name
//        >> -(":=" > _structure_initialization);
//  _structured_var_init_decl
//      =  _var1_list > char_(":") > _initialized_structure;
//  _array_var_init_decl
//      =  _var1_list > char_(":") > _array_spec_init;
//  _var1_list
//      =  _variable_name >> *(char_(",") > _variable_name);
//  _var1_init_decl
//      =  _var1_list > char_(':')
//      >  (
//              _simple_spec_init
//           |  _subrange_spec_init
//           |  _enumerated_spec_init
//         );
//  _var_init_decl
//      =  _var1_init_decl | _array_var_init_decl | _structured_var_init_decl
//      |  _fb_name_decl | _string_var_declaration;
//  bsqi::symbols <char> jkjk;
//  jkjk.add("R_EDGE");
//  jkjk.add("F_EDGE");
//  _edge_declaration
//      =  _var1_list > char_(':') > "BOOL" > jkjk;
//  _input_declaration
//      =  _var1_init_decl | _edge_declaration;
//  bsqi::symbols<char> truntran;
//  truntran.add("RETAIN");
//  truntran.add("NON_RETAIN");
//  _input_declarations
//      =  "VAR_INPUT" >> -(truntran)
//      >  _input_declaration > char(';')
//      >  *(_input_declaration > char(';'))
//      >  "END_VAR";

//  //    // B.1.4.2 Multi-element variables
//  _field_selector
//      = token._identifier;
//  _record_variable
//      =  _symbolic_variable.alias();
//  _structured_variable
//      =  _record_variable
//      >  char_('.')
//      > _field_selector;
//  //        _subscript
//  //            =  _expression; //FIXME(denisacostaq\@gmail.com): ST?
//  _subscript_list
//      =  char_('[')
//      >  _subscript
//      >> *(char_(',') > _subscript)
//      >  char_(']');
//  _subscripted_variable
//      = _symbolic_variable.alias();
//  _array_variable
//      =  _subscripted_variable
//      > _subscript_list;
//  _multi_element_variable
//      = _array_variable
//      | _structured_variable;
//  // B.1.4.1 Directly represented variables
//  _location_prefix
//      =  char_('I')
//      |  char_('Q')
//      |  char_('M');
//  _size_prefix
//      =  char_('N')  // FIXME(denisacostaq\@gmail.com): see NIL in the manual.
//      |  char_('X')
//      |  char_('B')
//      |  char_('W')
//      |  char_('D')
//      |  char_('L');
//  _direct_variable
//      =  char_('%')
//      >  _location_prefix
//      >  _size_prefix
//      >  token._integer
//      > *(char_('.') > token._integer);
//  // B.1.4 Variables
//  _variable_name
//      =  token._identifier;
//  _symbolic_variable
//      =  _variable_name
//      |  _multi_element_variable;
//  _variable
//      =  _direct_variable
//      |  _symbolic_variable;
////}


  /****************************************************************************/
  /*                       B.1.5 Program organization units.                  */
  /****************************************************************************/
//  // B.1.5.2 Function blocks
//  _function_block_body
//        =  _sequential_function_chart
////      |  ladder_diagram
////      |  function_block_diagram
////      |  instruction_list
////      |  statement_list
////      |  <other languages>
//      ;

//  bsqi::symbols<char> tyty2;
//  tyty2.add("NON_RETAIN");
//  _non_retentive_var_decls
//      =  "VAR" > tyty2 > +(_var_init_decl > char_(";"))
//      >  "END_VAR";
//  _temp_var_decls
//      =  "VAR_TEMP" > +(_temp_var_decls > char_(";")) > "END_VAR";
//  _other_var_declarations
//      =  _external_var_declarations
//      |  _var_declarations
//      |  _retentive_var_declarations
//   // |   _non_retentive_var_declarations
//      |  _temp_var_decls
//      |  _incompl_located_var_declarations;
//  _function_block_declaration
//      =  "FUNCTION_BLOCK" > _derived_function_block_name
//      >> *(_io_var_declarations | _other_var_declarations)
//      >  _function_block_body > "END_FUNCTION_BLOCK";
//  _derived_function_block_name
//      =  token._identifier;
//  //_standard_function_block_name ::= <as defined in 2.5.2.3>
//  _function_block_type_name
//      =  _standard_function_block_name | _derived_function_block_name;



//  // B.1.5.1 Functions
//  _var2_init_decl
//      =  _var1_init_decl
//      |  _array_var_init_decl
//      |  _structured_var_init_decl
//      |  _string_var_declaration;
////  _function_body
////      =  ladder_diagram
////      |  function_block_diagram
////      |  instruction_list
////      |  statement_list
////      |  <other languages>
//  bsqi::symbols<char> hjh;
//  hjh.add("CONSTANT");
//  _function_var_decls
//      =  "VAR" >> -hjh > +(_var2_init_decl > char_(";")) > "END_VAR";
//  _io_var_declarations
//      =  _input_declarations
//      |  _output_declarations
//      |  _input_output_declarations;
//  _function_declaration = "kaka";
////      =  "FUNCTION" > _derived_function_name > char_(":")
////      >  (_ext_data_types._elementary_type_name | _ext_data_types._derived_type_name)
////      >> *(_io_var_declarations | _function_var_decls)
////      >  _function_body > "END_FUNCTION";
//  _derived_function_name
//      =  token._identifier;
//  // TODO(denisacostaq\@gmail.com): _standard_function_name ::= <as defined in 2.5.1.5>
//  _function_name
//      =  _standard_function_name | _derived_function_name;
////}




  /****************************************************************************/
  /*                  B.1.6 Sequential function chart elements.               */
  /****************************************************************************/
//  // B.1.6 Sequential function chart elements
//  // FIXME(denisacostaq\@gmail.com): simple_instruction_list != instruction_list;
//  _action
//      =  "ACTION" > _action_name > char_(":")
//      >  _function_block_body
//      >  "END_ACTION";
//  _transition_condition
//      =  char_(":") //TODO(denisacostaq\@gmail.com): > _ext_il._instruction_list
//      |  ":=" // TODO:(denisacostaq\@gmail.com): _ext_st._expression
//      |  char_(";")
//      |  char_(":") // FIXME(denisacostaq\@gmail.com): > (fbd_network | rung);
//      ;
//  _steps
//      =  _step_name
//      | char_('(') > _step_name > +(char_(",") > _step_name) > char_(")");
//  _transition_name
//      =  token._identifier;
//  _transition
//      =  "TRANSITION" >> -_transition_name
//      >> -(char_('(') > "PRIORITY" > ":=" > _integer > char_(')'))
//      >  "FROM" > _steps > "TO" > _steps
//      >  _transition_condition
//      >  "END_TRANSITION";
//  _indicator_name
//      =  _variable_name;
//  _action_time
//      =  _duration | _variable_name;
//  _timed_qualifier
//      =  char_('L') | char_('D') | "SD" | "DS" | "SL";
//  _action_qualifier
//      =  char_('N') | char_('R') | char_('S') | char_('P') | _timed_qualifier
//      >  char_(",") > _action_name;
//  _action_name
//      =  token._identifier;
//  _action_association
//      =  _action_name > char_("(") >> -_action_qualifier
//      >> *(char_(",") > _indicator_name) > char_(")");
//  _step_name
//      =  token._identifier;
//  _step
//      =  "STEP" > _step_name > char_(":")
//      >> *(_action_association > char_(";"))
//      >  "END_STEP";
//  _initial_step
//      =  "INITIAL_STEP" > _step_name > char_(':')
//      >> *(_action_association > char_(";"))
//      >  "END_STEP";
//  _sfc_network
//      =  _initial_step >> *(_step | _transition | _action);
//  _sequential_function_chart
//      =  _sfc_network >> *_sfc_network;
////}


  /****************************************************************************/
  /*                        B.1.7 Configuration elements.                     */
  /****************************************************************************/
//  // B.1.7 Configuration elements
//  _instance_specific_init
//      =  _resource_name > char_('.') > _program_name > char_(".")
//      >> *(_fb_name > char_("."))
//      >  (
//            (
//                 _variable_name >> -_location
//              >  char_(":") > _located_var_spec_init
//            )
//            |
//            (
//                _fb_name > char_(":")
//             >  _function_block_type_name > ":="
//             >  _structure_initialization
//            )
//         )
//     ;
//  _instance_specific_initializations
//      =  "VAR_CONFIG" > +(_instance_specific_init > char_(';')) > "END_VAR";
//  _data_sink
//      =  _global_var_reference | _direct_variable;
//  _prog_data_source
//      =  _constant
//      |  _enumerated_value
//      |  _global_var_reference
//      |  _direct_variable;
//  _prog_cnxn
//      =  _symbolic_variable > ":=" > _prog_data_source
//      |  _symbolic_variable > "=>" > _data_sink;
//  _fb_task
//      =  _fb_name > "WITH" > _task_name;
//  _prog_conf_element
//      =  _fb_task | _prog_cnxn;
//  _prog_conf_elements
//      =  _prog_conf_element > -(char_(',') > _prog_conf_element);
//  bsqi::symbols<char> fttf;
//  fttf.add("RETAIN");
//  fttf.add("NON_RETAIN");
//  _program_configuration
//      =  "PROGRAM"
//      >> -fttf  // FIXME(denisacostaq\@gmail.com): see grammar in the pdf.
//      >  _program_name >> -("WITH" > _task_name) > char_(':')
//      >  _program_type_name
//      >> -(char_('(') > _prog_conf_elements > char_(')'));
//  _data_source
//      =  _constant
//      |  _global_var_reference
//      |  _program_output_reference
//      |  _direct_variable;
////  _task_initialization
////      =  char_('(')
////      >> -("SINGLE" > ":=" > _data_source > char_(','))
////      >> -("INTERVAL" > ":=" > _data_source > char_(','))
////      >  "PRIORITY" > ":=" > _integer
////      >  char_(')');
//  _task_name
//      =  token._identifier;
//  _task_configuration
//      =  "TASK" > _task_name > _task_initialization;
//  bsqi::symbols<char> trrtr;
//  trrtr.add("READ_WRITE");
//  trrtr.add("READ_WRITE");
//  _direction
//      =  trrtr;
//  _program_name
//      =  token._identifier;
//  _program_output_reference
//      =  _program_name > char_('.') > _symbolic_variable;

//  _access_name
//      =  token._identifier;
//  _global_var_reference
//      =  -(_resource_name > char_('.'))
//      >  _global_var_name
//      >> -(char_('.') > _structure_element_name);
//  _access_path
//      =  -(_resource_name > char_('.')) > _direct_variable
//      |  -(_resource_name > char_('.')) >> -(_program_name > char_('.'))
//      >> *(_fb_name > char_("."))
//      >  _symbolic_variable;
//  _access_declaration
//      =  _access_name > char_(":") > _access_path > char_(":")
//      >  _non_generic_type_name >> -_direction;
//  _access_declarations
//      =  "VAR_ACCESS" > +(_access_declaration > char_(";")) > "END_VAR";
//  _resource_name
//      =  token._identifier;
//  _single_resource_declaration
//      =  *(_task_configuration > char_(";"))
//      >  +(_program_configuration > char_(";"));
//  _resource_declaration
//      =  "RESOURCE" > _resource_name > "ON" > _resource_type_name
//      >> -_global_var_declarations
//      >  _single_resource_declaration
//      >  "END_RESOURCE";
//  _configuration_declaration
//      =  "CONFIGURATION" > _configuration_name
//      >> -_global_var_declarations
//      >  (_single_resource_declaration | +_resource_declaration)
//      >> -_access_declaration >> -_instance_specific_initializations
//      >  "END_CONFIGURATION";
//  _configuration_name
//      =  token._identifier;
//  _resource_type_name
//      =  token._identifier;



  /****************************************************************************/
  /*                 B.1.1 Letters, digits and identifiers.                   */
  /****************************************************************************/
  //    _letter
  //        =  token._letter;
  //    _digit
  //        =  token._digit;
  //    _octal_digit
  //        =  token._octal_digit;
  //    _hex_digit
  //        = _digit
  //        |  char_('A')
  //        |  char_('B')
  //        |  char_('C')
  //        |  char_('D')
  //        |  char_('E')
  //        |  char_('F');
  //    _identifier
  //        =  token._identifier;
  //}




  /****************************************************************************/
  /*                            B.0 Programming model.                        */
  /****************************************************************************/
  //  _library_element_name
  //      =  _data_type_name.alias()
  //      |  _function_name.alias()
  //      |  _function_block_type_name.alias()
  //      |  _program_type_name.alias()
  //      |  _resource_type_name.alias()
  //      |  _configuration_name.alias();
    _library_element_declaration = token._signed_integer_type_dint;
  //      =  _data_type_declaration
  //      |  _function_declaration
  //      |  _function_block_declaration
  //      |  _program_declaration
  //      |  _configuration_declaration;

}


}  // namespace iec61131_3
}  // namespace compiler
}  // namespcae ciaa

#endif  // CIAA_COMPILER_IEC_GRAMMAR_DEFINITION_H
