set(compiler_il_Code
    ${CMAKE_CURRENT_SOURCE_DIR}/../Common/Scanner/ciaa_compiler_lexer.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/../Common/Parser/ciaa_compiler_parcer.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/../Common/ciaa_compiler_symbol_table.cc
#    ${CMAKE_CURRENT_SOURCE_DIR}/IL/ASTIL.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Scanner/ciaa_compiler_il_lexer.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/Parser/ciaa_compiler_il_parcer.cc)

add_library(compiler_iec_il
    ${compiler_il_Code})

if(PYTHONINTERP_FOUND)
  add_style_check_target(style_check_code_compiler_iec_il ${CMAKE_CURRENT_SOURCE_DIR})
endif(PYTHONINTERP_FOUND)
