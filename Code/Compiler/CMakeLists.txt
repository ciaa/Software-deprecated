include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../)

set(compiler_Code
	ciaaIECCompiler.cpp)

add_library(compiler
    ${compiler_Code})


