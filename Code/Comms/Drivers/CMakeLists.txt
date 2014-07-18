include(CMake/CMakeDependencies.cmake)

#include_directories(${CMAKE_SOURCE_DIR}/Code)
#FIXME: CMAKE_INCLUDE_CURRENT_DIR: Automatically add the current source- and build directories to the include path.
#include_directories(${CMAKE_BINARY_DIR}/Code)

set(comms_drivers_base_Code
  ${BASE_MODULES_FOR_COMMS_SRC})
set(comms_drivers_ethernet_Code
  Ethernet/ciaa_drivers_socket_tcp.cc
  Ethernet/ciaa_drivers_socket_udp.cc)
set(comms_drivers_serial_port_Code SerialPort/ciaa_drivers_serial_port.cc)
set(comms_Code
  ciaa_drivers_error_code.h
  ciaa_drivers_adapter_interface.h
  ciaa_drivers_interface.h
  ciaa_drivers_facade.cc
  ${comms_drivers_serial_port_Code}
  ${comms_drivers_ethernet_Code}
  ${comms_drivers_base_Code})

add_library(comms_drivers ${comms_Code})

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
  "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set_target_properties(comms_drivers PROPERTIES COMPILE_FLAGS "-Werror -Wall -Wextra")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
#  set_target_properties(comms_drivers PROPERTIES COMPILE_FLAGS "/W4 /WX /EHsc")
endif()

if(USE_BOOST_ASIO)
  target_link_libraries(comms_drivers ${USED_LIBS})
else(USE_BOOST_ASIO)
  qt5_use_modules(comms_drivers Network SerialPort)
endif(USE_BOOST_ASIO)

if(PYTHONINTERP_FOUND)
  add_style_check_target(style_check_code_comms_drivers ${CMAKE_CURRENT_SOURCE_DIR})
endif(PYTHONINTERP_FOUND)
