add_executable(test_compiler_il_lexer
               test_compiler_il_lexer.cc)
target_link_libraries(test_compiler_il_lexer compiler_il)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
  "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
#  set_target_properties(test_compiler_il_lexer PROPERTIES COMPILE_FLAGS "-Werror -Wall -Wextra")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  set_target_properties(test_compiler_il_lexer PROPERTIES COMPILE_FLAGS "/W4 /WX /EHsc")
endif()

add_test(test_compiler_il_lexer ${EXEC_DIR}/test_compiler_il_lexer ${CMAKE_CURRENT_SOURCE_DIR}/programs/lexer_1.il)

if(PYTHONINTERP_FOUND)
  add_style_check_target(style_check_test_compiler_il ${CMAKE_CURRENT_SOURCE_DIR})
endif(PYTHONINTERP_FOUND)
