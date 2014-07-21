set(compiler_Code
    ${CMAKE_CURRENT_SOURCE_DIR}/ciaaIECCompiler.cpp)

add_library(compiler
    ${compiler_Code})


add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/IEC61131Standard)
