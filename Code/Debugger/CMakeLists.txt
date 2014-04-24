include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../)

set(debuger_Code
	ciaaDebugger.cpp)

add_library(debuger
    ${debuger_Code})


