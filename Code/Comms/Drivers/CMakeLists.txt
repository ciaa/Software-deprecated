set(CMAKE_INCLUDE_CURRENT_DIR ON)

include(CMake/CMakeDependencies.cmake)

set(comms_drivers_base_Code
  ${BASE_MODULES_FOR_COMMS_SRC})
set(comms_drivers_ethernet_Code
  Ethernet/ciaa_socket_tcp.cc
  Ethernet/ciaa_socket_udp.cc)
set(comms_drivers_serial_port_Code SerialPort/ciaa_serial_port.cc)
set(comms_Code
  ciaa_comm_facade.cc
  ${comms_drivers_serial_port_Code}
  ${comms_drivers_ethernet_Code}
  ${comms_drivers_base_Code})

add_library(comms_drivers ${comms_Code})

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
   "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set_target_properties(comms_drivers PROPERTIES COMPILE_FLAGS "-Werror")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    #TODO: set(warnings "/W4 /WX /EHsc")
endif()

if(USE_BOOST_ASIO)
else(USE_BOOST_ASIO)
  qt5_use_modules(comms_drivers Network SerialPort)
endif(USE_BOOST_ASIO)

if(PYTHONINTERP_FOUND)
  add_style_check_target(style_check_comms_drivers ${CMAKE_CURRENT_SOURCE_DIR})
endif(PYTHONINTERP_FOUND)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../)



