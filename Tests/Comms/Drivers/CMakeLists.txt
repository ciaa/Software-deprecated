find_package(Qt5Network REQUIRED)
add_executable(tcp_test tcp_test.cc)
target_link_libraries(tcp_test comms_drivers)

add_executable(serial_port_test serial_port_tests.cc)
target_link_libraries(serial_port_test comms_drivers)


if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
  "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set_target_properties(tcp_test PROPERTIES COMPILE_FLAGS "-Werror -Wall -Wextra")
  set_target_properties(serial_port_test PROPERTIES COMPILE_FLAGS "-Werror -Wall -Wextra")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  set_target_properties(tcp_test PROPERTIES COMPILE_FLAGS "/W4 /WX /EHsc")
  set_target_properties(serial_port_test PROPERTIES COMPILE_FLAGS "/W4 /WX /EHsc")
#   set(warnings "/W4 /WX /EHsc")
endif()

add_test(tcp_test ${EXEC_DIR}/tcp_test)
set(serial_device "/dev/ttyS0")
# en win2 set(serial_device "COMM1")
add_test(serial_port_test ${EXEC_DIR}/serial_port_test ${serial_device})

if(PYTHONINTERP_FOUND)
  add_style_check_target(style_check_test_comms_drivers_tcp_test ${CMAKE_CURRENT_SOURCE_DIR})
endif(PYTHONINTERP_FOUND)

#add_executable(test1 test1.c)
#add_executable(test2 test2.c)
#add_test(NAME test
#    COMMAND ${CMAKE_COMMAND}
#            -DCMD1=$<TARGET_FILE:serial_port_test>
#            -DCMD2=$<TARGET_FILE:tcp_test>
#    -P ${CMAKE_CURRENT_SOURCE_DIR}/runtests.cmake)
