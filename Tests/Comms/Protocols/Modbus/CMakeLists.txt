include_directories(${Project_DIRECTORY}/Code)

enable_testing()

option(USE_QT_MODULES "Use Qt Modules?" ON)
if(USE_QT_MODULES)
    find_package(Qt5Widgets)
    find_package(Qt5SerialPort)
endif(USE_QT_MODULES)

add_executable(modbus_factory main.cc)
target_link_libraries(modbus_factory comms_protocols_modbus)
#add_test(unit-test-serial_port_tests ${EXEC_DIR}tcp_server & ${EXEC_DIR}/serial_port_tests)
