#poner un include de cmake
option(USE_QT_MODULES "Use Qt Modules?" ON)
if(USE_QT_MODULES)
    find_package(Qt5Network)
    find_package(Qt5SerialPort)
endif(USE_QT_MODULES)

set(comms_protocols_modbus_Code
  ciaaModbus.cpp
#  ciaa_modbus_master_ascii.cc
#  ciaa_modbus_master_interface.cc
#  ciaa_modbus_master_over_comms_interface.cc
#  ciaa_modbus_master_over_serial.cc
#  ciaa_modbus_master_rtu.cc
#  ciaa_modbus_master_serial_interface.cc
#  ciaa_modbus_master_tcp.cc
#  ciaa_modbus_master_over_tcp.cc
#  ciaa_modbus_master_over_udp.cc
)

add_library(comms_protocols_modbus
    ${comms_protocols_modbus_Code})
target_link_libraries(comms_protocols_modbus comms_drivers)

include_directories(${Project_DIRECTORY}/Code)
