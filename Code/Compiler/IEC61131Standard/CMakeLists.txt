#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Graphics)
#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Textuals)

set(compiler_iec61131_3_Code
    ${CMAKE_CURRENT_SOURCE_DIR}/Textuals/Errors/ciaa_compiler_error.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/Textuals/Errors/ciaa_compiler_error_list.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/Textuals/AST/ciaa_compiler_ast_constants.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/Textuals/AST/ciaa_compiler_ast_data_types.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/Textuals/Grammar/ciaa_compiler_grammar_definition.h
)

set(compiler_iec61131_3_il_Code
    ${CMAKE_CURRENT_SOURCE_DIR}/Textuals/IL/ciaa_compiler_language_il.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/Textuals/IL/ciaa_compiler_parser_il.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/Textuals/Lexer/ciaa_compiler_scanner.cc
)

add_library(compiler_iec61131_3
    ${compiler_iec61131_3_Code}
    ${compiler_iec61131_3_il_Code}
)

if(PYTHONINTERP_FOUND)
  add_style_check_target(style_check_code_compiler_iec61331_3 ${CMAKE_CURRENT_SOURCE_DIR})
endif(PYTHONINTERP_FOUND)
