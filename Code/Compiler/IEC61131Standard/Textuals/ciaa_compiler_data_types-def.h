#ifndef CIAA_COMPILER_IEC_DATA_TYPESDEF_H
#define CIAA_COMPILER_IEC_DATA_TYPESDEF_H

#include "Code/Compiler/IEC61131Standard/Textuals/ciaa_compiler_data_types.h"

namespace ciaa {
namespace compiler {
namespace iec61131_3 {
template <typename Iterator>
template<typename TokenDef>
ciaaDataTypes<Iterator>::ciaaDataTypes(const TokenDef& token)
  : ciaaDataTypes::base_type(_data_type_name) {
  #ifndef BOOST_SPIRIT_QI_DEBUG
    bsqi::char_type char_;
  #else
    using boost::spirit::qi::char_;
  #endif

  // B.1.3.1 Elementary data types
  bsqi::symbols<char> elementary_type_name_others;
  _bit_string_type_name.add("BOOL");
  _bit_string_type_name.add("BYTE");
  _bit_string_type_name.add("WORD");
  _bit_string_type_name.add("DWORD");
  _bit_string_type_name.add("LWORD");
  _date_type_name.add("DATE");
  _date_type_name.add("TIME_OF_DAY");
  _date_type_name.add("TOD");
  _date_type_name.add("DATE_AND_TIME");
  _date_type_name.add("DT");
  _real_type_name.add("REAL");
  _real_type_name.add("LREAL");
  _unsigned_integer_type_name.add("USINT");
  _unsigned_integer_type_name.add("UINT");
  _unsigned_integer_type_name.add("UDINT");
  _unsigned_integer_type_name.add("ULINT");
  _signed_integer_type_name.add("SINT");
  _signed_integer_type_name.add("INT");
  _signed_integer_type_name.add("DINT");
  _signed_integer_type_name.add("LINT");
  elementary_type_name_others.add("STRING");
  elementary_type_name_others.add("WSTRING");
  elementary_type_name_others.add("TIME");
  _integer_type_name
      =   _signed_integer_type_name
      |   _unsigned_integer_type_name;
  _numeric_type_name
      =  _integer_type_name
      |  _real_type_name;
  _elementary_type_name
      =  _numeric_type_name
      |  _date_type_name
      |  _bit_string_type_name
      |  elementary_type_name_others;

  // B.1.3.2 Generic data types
  bsqi::symbols<char> generic_type_name;
  generic_type_name.add("ANY");
  generic_type_name.add("ANY_DERIVED");
  generic_type_name.add("ANY_ELEMENTARY");
  generic_type_name.add("ANY_MAGNITUDE");
  generic_type_name.add("ANY_NUM");
  generic_type_name.add("ANY_REAL");
  generic_type_name.add("ANY_INT");
  generic_type_name.add("ANY_BIT");
  generic_type_name.add("ANY_STRING");
  generic_type_name.add("ANY_DATE");
  _generic_type_name
      = generic_type_name;

  // B.1.3.3 Derived data types
  ciaaConstants<Iterator> constants;
  _derived_type_name
      =  _single_element_type_name
      |  _array_type_name
      |  _structure_type_name
      |  _string_type_name;
  _single_element_type_name
      =  _simple_type_name
      |  _subrange_type_name
      |  _enumerated_type_name;
  _simple_type_name
      =  token._identifier;
  _subrange_type_name
      =  token._identifier;
  _enumerated_type_name
      =  token._identifier;
  _array_type_name
      =  token._identifier;
  _structure_type_name
      =  token._identifier;
  _data_type_declaration
      =  "TYPE"
      >  _type_declaration
      >  char_(";")
      >> *(
             _type_declaration
             >  char_(";")
          )
      >  "END_TYPE";
  _type_declaration
      =  _single_element_type_declaration
      |  _array_type_declaration
      |  _structure_type_declaration
      |  _string_type_declaration;
  _single_element_type_declaration
      =  _simple_type_declaration
      |  _subrange_type_declaration
      |  _enumerated_type_declaration;
  _simple_type_declaration
      =  _simple_type_name
      >  char_(":")
      >  _simple_spec_init;
  _simple_spec_init
      =  _simple_specification
      >> -(
                 ":="
             >>  constants._constant
          );
  _simple_specification
      =  _elementary_type_name
      |  _simple_type_name;
  _subrange_type_declaration
      =  _subrange_type_name
      >  char_(":")
      >  _subrange_spec_init;
  _subrange_spec_init
      =  _subrange_specification
      >> -(
                ":="
             >  constants._signed_integer
           );
  _subrange_specification // FIXME(denisacostaq\@gmail.com): ver la precedencia del |.
      =  _integer_type_name
      >  char_('(')
      >  _subrange
      >  char_(')')
      |  _subrange_type_name;
  _subrange
      =  constants._signed_integer
      >  ".."
      >  constants._signed_integer;
  _enumerated_type_declaration
      =  _enumerated_type_name
      >  char_(':')
      >  _enumerated_spec_init;
  _enumerated_spec_init
      =  _enumerated_specification
      >> -(
                ":="
            >>  _enumerated_value
          );
  _enumerated_specification
      =  (
              char_("(")
           >  _enumerated_value
           >> *(
                  char_(",")
                > _enumerated_value
               )
           >  char_(")")
         )
      |  _enumerated_type_name ;
  _enumerated_value
      =  -(
               _enumerated_type_name
            >  char_("#")
          )
      >  token._identifier;

  _array_type_declaration
      =  _array_type_name
      >  char_(":")
      >  _array_spec_init;
  _array_spec_init
      =  _array_specification
      >> -(
               ":="
             >  _array_initialization
          );
  _array_specification
      =  _array_type_name
      |  "ARRAY"
      >  char_("[")
      >  _subrange
      >> *(
                char_(",")
            >>  _subrange
          )
      >  char_("]")
      >  "OF"
      >  _non_generic_type_name;
  _array_initialization
      =  char_("[")
      >  _array_initial_elements
      >> *(
               char_(",")
            >  _array_initial_elements
          )
      >  char_("]");
  _array_initial_elements
      =  _array_initial_element
      |  constants._integer
      >  "("
      >> -_array_initial_element
      >  ")";
  _structure_type_declaration
      =  _string_type_name
      >  char_(":")
      >  _structure_specification;
  _structure_specification
      =  _structure_declaration
      |  _initialized_structure;
  _initialized_structure
      =   _string_type_name
      >>  -(
                ":="
             >  _structure_initialization
           );
  _structure_declaration
      =  "STRUCT"
      > +(
               _structure_element_declaration
            >  char_(";")
          )
      >  "END_STRUCT";
  _structure_element_declaration
      =  _structure_element_name
      >  char_(":")
      >> (
              _simple_spec_init
           |  _subrange_spec_init
           |  _enumerated_spec_init
           |  _array_spec_init
           |  _initialized_structure
         );
  _structure_initialization
      =  char_("(")
      >  _structure_element_initialization
      >> *(
               char_(",")
            >  _structure_element_initialization
          )
      >  char_(")");
  _structure_element_initialization
      =  _structure_element_name
      >  ":="
      >> (
              constants._constant
           |  _enumerated_value
           |  _array_initialization
           |  _structure_initialization
         );
  _string_type_name
      =  token._identifier;
  bsqi::symbols<char> two_string;
  two_string.add("STRING");
  two_string.add("WSTRING");
  _string_type_declaration
      =  _string_type_name
      >  char_(":")
      >  two_string
      >> -(
               char_("[")
            >  constants._integer
            >  char_("]")
          )
      >> -(
               ":="
            >  constants._character_string
          );
}
}  // namespace iec61131_3
}  // namespace compiler
}  // namespcae ciaa

#endif  // CIAA_COMPILER_IEC_DATA_TYPESDEF_H
