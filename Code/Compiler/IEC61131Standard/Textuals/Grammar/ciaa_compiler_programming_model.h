/*! \brief Do not include this file directly in external modules.
    \file ciaa_compiler_programming_model.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Sun Jul 27 18:05:52 UTC 2014

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
    \brief This file become from: Code/Compiler/IEC61131Standard/Textuals/Grammar/ciaa_compiler_programming_model.h

    [ACSE-URL]: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/ "Asociación Civil para la Investigación, Promoción y Desarrollo de los Sistemas Electrónicos Embebidos"
    [CADIEEL-URL]: http://www.cadieel.org.ar "Cámara de Industrias Electrónicas, Electromecánicas y Luminotécnicas"
    [proyecto-ciaa-URL]: http://proyecto-ciaa.com.ar "Proyecto CIAA(Computador Industrial Abierta Argentina)"
    [proyecto-ciaa-PCSoftware-URL]: http://proyecto-ciaa.com.ar/gggg "PCSoftware bla bla"
*/


#ifndef CIAA_COMPILER_IEC_PROGRAMMING_MODEL_H
#define CIAA_COMPILER_IEC_PROGRAMMING_MODEL_H

#define DEUGGGGGG
#ifdef DEUGGGGGG
#define BOOST_SPIRIT_QI_DEBUG
#endif

#include <boost/spirit/include/qi.hpp>


#include <iostream>
#include "Code/Defines/ciaa_modules_config.h"
#include "Code/Compiler/IEC61131Standard/Textuals/Lexer/ciaa_compiler_scanner.h"

namespace ciaa {
namespace compiler {
namespace iec61131_3 {
namespace bsqi = boost::spirit::qi;

/*! \brief struct ciaaProgrammingModel implemment B.0 Programming model.
 */
template <typename Iterator>
struct ciaaProgrammingModel : boost::spirit::qi::grammar<Iterator, std::string()> {
  template <typename TokenDef>
  ciaaProgrammingModel(const TokenDef& token);

  ~ciaaProgrammingModel() = default;

  ciaaProgrammingModel(const ciaaProgrammingModel&) = delete;
  ciaaProgrammingModel& operator=(const ciaaProgrammingModel&) = delete;

  ciaaProgrammingModel(const ciaaProgrammingModel&&) = delete;
  ciaaProgrammingModel& operator=(const ciaaProgrammingModel&&) = delete;

  bsqi::rule<Iterator, std::string> _library_element_name;
  bsqi::rule<Iterator, std::string()> _library_element_declaration;
  //ciaaPOU<Iterator> _function_declaration;
  //bsqi::rule<Iterator, std::string> _function_declaration;










//  /*! \brief struct ciaaCommonElements implemment B.1 Common elements.
//   */
//  struct ciaaCommonElements : boost::spirit::qi::grammar<Iterator, std::string> {
//    template<typename TokenDef>
//    ciaaCommonElements(const TokenDef& token);
//    ~ciaaCommonElements() = default;

//    ciaaCommonElements(const ciaaCommonElements&) = delete;
//    ciaaCommonElements& operator=(const ciaaCommonElements&) = delete;

//    ciaaCommonElements(const ciaaCommonElements&&) = delete;
//    ciaaCommonElements& operator=(const ciaaCommonElements&&) = delete;

    bsqi::rule<Iterator, std::string> _letter;
    bsqi::rule<Iterator, std::string> _digit;
    bsqi::rule<Iterator, std::string> _octal_digit;
    bsqi::rule<Iterator, std::string> _hex_digit;
    bsqi::rule<Iterator, std::string> _identifier;
//  };
//  ciaaCommonElements _sg_common_elements;




//  /*! \brief struct ciaaConstants implemment B.1.2 Constants.
//   */
//  struct ciaaConstants : boost::spirit::qi::grammar<Iterator, std::string> {
//    template<typename TokenDef>
//    ciaaConstants(const TokenDef& token);
//    ~ciaaConstants() = default;

//    ciaaConstants(const ciaaConstants&) = delete;
//    ciaaConstants& operator=(const ciaaConstants&) = delete;

//    ciaaConstants(const ciaaConstants&&) = delete;
//    ciaaConstants& operator=(const ciaaConstants&&) = delete;

    bsqi::rule<Iterator, std::string> _constant;

    // B.1.2.1 Numeric literals
    bsqi::rule<Iterator, std::string> _numeric_literal;
    bsqi::rule<Iterator, std::string> _integer_literal;
    bsqi::rule<Iterator, std::string> _signed_integer;
    bsqi::rule<Iterator, std::string()> _integer;
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
//  };
//  ciaaConstants _sg_constants;




//  /*! \brief struct ciaaDataTypes implemment B.1.3 Data types.
//  */
//  struct ciaaDataTypes : boost::spirit::qi::grammar<Iterator, std::string> {
//    template<typename TokenDef>
//    ciaaDataTypes(const TokenDef& token);
//    ~ciaaDataTypes() = default;

//    ciaaDataTypes(const ciaaDataTypes&) = delete;
//    ciaaDataTypes& operator=(const ciaaDataTypes&) = delete;

//    ciaaDataTypes(const ciaaDataTypes&&) = delete;
//    ciaaDataTypes& operator=(const ciaaDataTypes&&) = delete;

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
//  };
//  ciaaConstants _sg_data_types;






//  /*! \brief struct ciaaVariable implemment B.1.4 Variables.
//   */
//  struct ciaaVariables : boost::spirit::qi::grammar<Iterator, std::string> {
//    template <typename TokenDef>
//    ciaaVariables(const TokenDef& token);


//    ~ciaaVariables() = default;

//    ciaaVariables(const ciaaVariables&) = delete;
//    ciaaVariables& operator=(const ciaaVariables&) = delete;

//    ciaaVariables(const ciaaVariables&&) = delete;
//    ciaaVariables& operator=(const ciaaVariables&&) = delete;

    bsqi::rule<Iterator, std::string> _variable;
    bsqi::rule<Iterator, std::string> _symbolic_variable;
    bsqi::rule<Iterator, std::string> _variable_name;

    //B.1.4.1 Directly represented variables
    bsqi::rule<Iterator, std::string> _direct_variable;
    bsqi::rule<Iterator, std::string> _location_prefix;
    bsqi::rule<Iterator, std::string> _size_prefix;

    // B.1.4.2 Multi-element variables
    bsqi::rule<Iterator, std::string> _multi_element_variable;
    bsqi::rule<Iterator, std::string> _array_variable;
    bsqi::rule<Iterator, std::string> _subscripted_variable;
    bsqi::rule<Iterator, std::string> _subscript_list;
    bsqi::rule<Iterator, std::string> _subscript;
    bsqi::rule<Iterator, std::string> _structured_variable;
    bsqi::rule<Iterator, std::string> _record_variable;
    bsqi::rule<Iterator, std::string> _field_selector;

    // B.1.4.3 Declaration and initialization
    bsqi::rule<Iterator, std::string> _input_declarations;
    bsqi::rule<Iterator, std::string> _input_declaration;
    bsqi::rule<Iterator, std::string> _edge_declaration;
    bsqi::rule<Iterator, std::string> _var_init_decl;
    bsqi::rule<Iterator, std::string> _var1_init_decl;
    bsqi::rule<Iterator, std::string> _var1_list;
    bsqi::rule<Iterator, std::string> _array_var_init_decl;
    bsqi::rule<Iterator, std::string> _structured_var_init_decl;
    bsqi::rule<Iterator, std::string> _fb_name_decl;
    bsqi::rule<Iterator, std::string> _fb_name_list;
    bsqi::rule<Iterator, std::string> _fb_name;
    bsqi::rule<Iterator, std::string> _output_declarations;
    bsqi::rule<Iterator, std::string> _input_output_declarations;
    bsqi::rule<Iterator, std::string> _var_declaration;
    bsqi::rule<Iterator, std::string> _temp_var_decl;
    bsqi::rule<Iterator, std::string> _var1_declaration;
    bsqi::rule<Iterator, std::string> _array_var_declaration;
    bsqi::rule<Iterator, std::string> _structured_var_declaration;
    bsqi::rule<Iterator, std::string> _var_declarations;
    bsqi::rule<Iterator, std::string> _retentive_var_declarations;
    bsqi::rule<Iterator, std::string> _located_var_declarations;
    bsqi::rule<Iterator, std::string> _located_var_decl;
    bsqi::rule<Iterator, std::string> _external_var_declarations;
    bsqi::rule<Iterator, std::string> _external_declaration;
    bsqi::rule<Iterator, std::string> _global_var_name;
    bsqi::rule<Iterator, std::string> _global_var_declarations;
    bsqi::rule<Iterator, std::string> _global_var_decl;
    bsqi::rule<Iterator, std::string> _global_var_spec;
    bsqi::rule<Iterator, std::string> _located_var_spec_init;
    bsqi::rule<Iterator, std::string> _location;
    bsqi::rule<Iterator, std::string> _global_var_list;
    bsqi::rule<Iterator, std::string> _string_var_declaration;
    bsqi::rule<Iterator, std::string> _single_byte_string_var_declaration;
    bsqi::rule<Iterator, std::string> _single_byte_string_spec;
    bsqi::rule<Iterator, std::string> _double_byte_string_var_declaration;
    bsqi::rule<Iterator, std::string> _double_byte_string_spec;
    bsqi::rule<Iterator, std::string> _incompl_located_var_declarations;
    bsqi::rule<Iterator, std::string> _incompl_located_var_decl;
    bsqi::rule<Iterator, std::string> _incompl_location;
    bsqi::rule<Iterator, std::string> _var_spec;
//  };
//  ciaaVariables _sg_variables;


//  /*! \brief struct ciaaPOU implemment B.1.5 Program organization units.
//   */
//  struct ciaaPOU : bsqi::grammar<Iterator, std::string()> {
//    template <typename TokenDef>
//    ciaaPOU(const TokenDef& token);

//    ~ciaaPOU() = default;

//    ciaaPOU(const ciaaPOU&) = delete;
//    ciaaPOU& operator=(const ciaaPOU&) = delete;

//    ciaaPOU(const ciaaPOU&&) = delete;
//    ciaaPOU& operator=(const ciaaPOU&&) = delete;

    // B.1.5.1 Functions
    bsqi::rule<Iterator, std::string> _function_name;
    bsqi::rule<Iterator, std::string> _standard_function_name;
    bsqi::rule<Iterator, std::string> _derived_function_name;
    bsqi::rule<Iterator, std::string()> _function_declaration;
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
//  };
//  ciaaPOU _sg_pou;





//  /*! \brief struct ciaaSequentialFunctionChartElements implemment B.1.6 Sequential function chart elements
//   */
//  struct ciaaSequentialFunctionChartElements : boost::spirit::qi::grammar<Iterator, std::string> {
//    template <typename TokenDef>
//    ciaaSequentialFunctionChartElements(const TokenDef& token);


//    ~ciaaSequentialFunctionChartElements() = default;

//    ciaaSequentialFunctionChartElements(const ciaaSequentialFunctionChartElements&) = delete;
//    ciaaSequentialFunctionChartElements& operator=(const ciaaSequentialFunctionChartElements&) = delete;

//    ciaaSequentialFunctionChartElements(const ciaaSequentialFunctionChartElements&&) = delete;
//    ciaaSequentialFunctionChartElements& operator=(const ciaaSequentialFunctionChartElements&&) = delete;

    bsqi::rule<Iterator, std::string> _sequential_function_chart;
    bsqi::rule<Iterator, std::string> _sfc_network;
    bsqi::rule<Iterator, std::string> _initial_step;
    bsqi::rule<Iterator, std::string> _step;
    bsqi::rule<Iterator, std::string> _step_name;
    bsqi::rule<Iterator, std::string> _action_association;
    bsqi::rule<Iterator, std::string> _action_name;
    bsqi::rule<Iterator, std::string> _action_qualifier;
    bsqi::rule<Iterator, std::string> _timed_qualifier;
    bsqi::rule<Iterator, std::string> _action_time;
    bsqi::rule<Iterator, std::string> _indicator_name;
    bsqi::rule<Iterator, std::string> _transition;
    bsqi::rule<Iterator, std::string> _transition_name;
    bsqi::rule<Iterator, std::string> _steps;
    bsqi::rule<Iterator, std::string> _transition_condition;
    bsqi::rule<Iterator, std::string> _action;

//  };
//  ciaaSequentialFunctionChartElements _sg_sfce;





//  /*! \brief struct ciaaConfigurationElements implemment B.1.7 Configuration elements.
//   */
//  struct ciaaConfigurationElements : boost::spirit::qi::grammar<Iterator, std::string> {
//    template <typename TokenDef>
//    ciaaConfigurationElements(const TokenDef& token);

//    ~ciaaConfigurationElements() = default;

//    ciaaConfigurationElements(const ciaaConfigurationElements&) = delete;
//    ciaaConfigurationElements& operator=(const ciaaConfigurationElements&) = delete;

//    ciaaConfigurationElements(const ciaaConfigurationElements&&) = delete;
//    ciaaConfigurationElements& operator=(const ciaaConfigurationElements&&) = delete;

    bsqi::rule<Iterator, std::string> _configuration_name;
    bsqi::rule<Iterator, std::string> _resource_type_name;
    bsqi::rule<Iterator, std::string> _configuration_declaration;
    bsqi::rule<Iterator, std::string> _resource_declaration;
    bsqi::rule<Iterator, std::string> _single_resource_declaration;
    bsqi::rule<Iterator, std::string> _resource_name;
    bsqi::rule<Iterator, std::string> _access_declarations;
    bsqi::rule<Iterator, std::string> _access_declaration;
    bsqi::rule<Iterator, std::string> _access_path;
    bsqi::rule<Iterator, std::string> _global_var_reference;
    bsqi::rule<Iterator, std::string> _access_name;
    bsqi::rule<Iterator, std::string> _program_output_reference;
    bsqi::rule<Iterator, std::string> _program_name;
    bsqi::rule<Iterator, std::string> _direction;
    bsqi::rule<Iterator, std::string> _task_configuration;
    bsqi::rule<Iterator, std::string> _task_name;
    bsqi::rule<Iterator, std::string> _task_initialization;
    bsqi::rule<Iterator, std::string> _data_source;
    bsqi::rule<Iterator, std::string> _program_configuration;
    bsqi::rule<Iterator, std::string> _prog_conf_elements;
    bsqi::rule<Iterator, std::string> _prog_conf_element;
    bsqi::rule<Iterator, std::string> _fb_task;
    bsqi::rule<Iterator, std::string> _prog_cnxn;
    bsqi::rule<Iterator, std::string> _prog_data_source;
    bsqi::rule<Iterator, std::string> _data_sink;
    bsqi::rule<Iterator, std::string> _instance_specific_initializations;
    bsqi::rule<Iterator, std::string> _instance_specific_init;
//  };
//  ciaaConfigurationElements _sg_conf_elements;
};
}  // namespace iec61131_3
}  // namespace compiler
}  // namespcae ciaa
#endif  // CIAA_COMPILER_IEC_PROGRAMMING_MODEL_H
