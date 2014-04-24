include_directories(${CMAKE_CURRENT_SOURCE_DIR}/...)

set(system_Code
	Base/ciaaBaseMapMemory.cpp
	ciaaST/ciaaSTMapMemory.cpp
	ciaaFreescale/ciaaFSMapMemory.cpp
	ciaaNXP/ciaaNXPMapMemory.cpp)

add_library(system
    ${system_Code})


