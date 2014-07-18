set(compiler_il_Code
    ${CMAKE_CURRENT_SOURCE_DIR}/Lexer/ciaa_compiler_il_lexer.cc)

add_library(compiler_il
    ${compiler_il_Code})

if(PYTHONINTERP_FOUND)
  add_style_check_target(style_check_code_compiler_il ${CMAKE_CURRENT_SOURCE_DIR})
endif(PYTHONINTERP_FOUND)
