cmake_minimum_required(VERSION 2.8)

project(ciaaSoftware CXX)
set(${CMAKE_PROJECT_NAME}_VERSION_MAJOR 0)
set(${CMAKE_PROJECT_NAME}_VERSION_MINOR 0)
set(${CMAKE_PROJECT_NAME}_VERSION_PATCH 0)
set(str_VERSION ${${CMAKE_PROJECT_NAME}_VERSION_MAJOR}.${${CMAKE_PROJECT_NAME}_VERSION_MINOR}.${${CMAKE_PROJECT_NAME}_VERSION_PATCH})

if(POLICY CMP0020)
  cmake_policy(SET CMP0020 NEW)
endif(POLICY CMP0020)

set(CMAKE_CXX_FLAGS_RELEASE ${CMAKE_CXX_FLAGS_RELEASE} "-o3")

option(USE_BOOST_ASIO "Use boost-asio for Comms/Drivers module?,
                       if not use qt5 instead" ON)

option(DEBUG_MODE "Debug or release?" ON)
if(DEBUG_MODE)
  set(CMAKE_BUILD_TYPE DEBUG)
else(DEBUG_MODE)
  set(CMAKE_BUILD_TYPE RELEASE)
endif(DEBUG_MODE)

option(LIBRARY_TYPE_SHARED "Static or shared?" OF)
if(LIBRARY_TYPE_SHARED)
  set(BUILD_SHARED_LIBS TRUE)
else(LIBRARY_TYPE_SHARED)
  set(BUILD_SHARED_LIBS FALSE)
endif(LIBRARY_TYPE_SHARED)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    add_definitions(-std=c++11)
    set(warnings "-Wall -Wextra")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(warnings "/W4 /WX /EHsc")
endif()
set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} ${warnings}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${warnings}")


include(CMake/CMakeStyleCheck.cmake)

# FIXME: con set(CMAKE_INCLUDE_CURRENT_DIR ON) seria suficiente?
set(CMAKE_INCLUDE_CURRENT_DIR ON)
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Code)
#include_directories(${CMAKE_CURRENT_BINARY_DIR}/Code)
#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Code)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Code)

option(BUILD_TESTS "Build test for modules?" ON)
if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(Tests)
endif(BUILD_TESTS)

include(CMake/CMakeCpack.cmake)

include(CMake/CMakeConfig.cmake)
configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/CMake/config.h.in
  ${CMAKE_CURRENT_BINARY_DIR}/Code/config.h)
configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/CMake/ciaaSoftware.desktop.in
  ${CMAKE_CURRENT_BINARY_DIR}/Code/ciaaSoftware.desktop)

add_subdirectory(Doc)
