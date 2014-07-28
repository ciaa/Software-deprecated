#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Graphics)
#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Textuals)

set(compiler_iec61331_3_Code
    ${CMAKE_CURRENT_SOURCE_DIR}/Common/ciaa_compiler_programming_model.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/Common/ciaa_compiler_pou.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/Common/ciaa_compiler_variable.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/Common/ciaa_compiler_sequential_function_chart_elements.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/Common/ciaa_compiler_configuration_elements.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/Common/ciaa_compiler_common_elements.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/Common/ciaa_compiler_constants.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/Common/ciaa_compiler_data_types.cc
)

add_library(compiler_iec61331_3
    ${compiler_iec61331_3_Code})

if(PYTHONINTERP_FOUND)
  add_style_check_target(style_check_code_compiler_iec61331_3 ${CMAKE_CURRENT_SOURCE_DIR})
endif(PYTHONINTERP_FOUND)
