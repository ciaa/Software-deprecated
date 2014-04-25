include_directories(${Project_DIRECTORY}/Code)

enable_testing()

option(USE_QT_MODULES "Use Qt Modules?" ON)
if(USE_QT_MODULES)
    find_package(Qt5Widgets)
    find_package(Qt5SerialPort)
endif(USE_QT_MODULES)

add_executable(tcp_test tcp_test.cc)
qt5_use_modules(tcp_test Network)
target_link_libraries(tcp_test comms_drivers)
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
  "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set_target_properties(tcp_test PROPERTIES COMPILE_FLAGS "-Werror -Wall -Wextra")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  set_target_properties(tcp_test PROPERTIES COMPILE_FLAGS "/W4 /WX /EHsc")
#   set(warnings "/W4 /WX /EHsc")
endif()

#add_executable(serial_port_tests serial_port_tests.cc)
#target_link_libraries(serial_port_tests comms_drivers)
#add_test(unit-test-serial_port_tests ${EXEC_DIR}tcp_server & ${EXEC_DIR}/serial_port_tests)
add_test(tcp_test ${EXEC_DIR}/tcp_test)
if(PYTHONINTERP_FOUND)
  add_style_check_target(style_check_test_comms_drivers_tcp_test ${CMAKE_CURRENT_SOURCE_DIR})
endif(PYTHONINTERP_FOUND)


#add_executable(test1 test1.c)
#add_executable(test2 test2.c)
#add_test(NAME test
#    COMMAND ${CMAKE_COMMAND}
#            -DCMD1=$<TARGET_FILE:serial_port_tests>
#            -DCMD2=$<TARGET_FILE:tcp_test>
#    -P ${CMAKE_CURRENT_SOURCE_DIR}/runtests.cmake)
