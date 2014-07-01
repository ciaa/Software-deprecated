if(USE_BOOST_ASIO)
#  FIXME(denisacostaq\@gmail.com): add_definitions(-DUSE_BOOST_ASIO)
   #add_definitions(-DUSE_BOOST_ASIO_WITH_CMAKE_BUG)
endif(USE_BOOST_ASIO)

find_package(Qt5Network REQUIRED)
add_executable(tcp_test
               tcp_test.cc
               comms_drivers_master_test.cc)
target_link_libraries(tcp_test comms_drivers)

#FIXME(denisacostaq@gmail.com): Si no tienes instalado QtSerial port, este test te lo pide
#ya que no esta reciviendo la flag add_definitions(-DUSE_BOOST_ASIO)
add_executable(async_tcp_test async_tcp_test.cc)
target_link_libraries(async_tcp_test comms_drivers)



add_executable(serial_port_test
               serial_port_tests.cc
               comms_drivers_master_test.cc)
target_link_libraries(serial_port_test comms_drivers)





if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
  "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
#  set_target_properties(tcp_test PROPERTIES COMPILE_FLAGS "-Werror -Wall -Wextra")
#  set_target_properties(async_tcp_test PROPERTIES COMPILE_FLAGS "-Werror -Wall -Wextra")
#  set_target_properties(serial_port_test PROPERTIES COMPILE_FLAGS "-Werror -Wall -Wextra")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  set_target_properties(tcp_test PROPERTIES COMPILE_FLAGS "/W4 /WX /EHsc")
  set_target_properties(async_tcp_test PROPERTIES COMPILE_FLAGS "/W4 /WX /EHsc")
  set_target_properties(serial_port_test PROPERTIES COMPILE_FLAGS "/W4 /WX /EHsc")
   set(warnings "/W4 /WX /EHsc")
endif()

add_test(tcp_test ${EXEC_DIR}/tcp_test)
add_test(async_tcp_test ${EXEC_DIR}/async_tcp_test)

set(serial_device1 "/dev/pts/2")
set(serial_device2 "/dev/pts/3")
# en win2 set(serial_device "COMM1")
add_test(serial_port_test ${EXEC_DIR}/serial_port_test ${serial_device1} ${serial_device2})

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


if(USE_BOOST_ASIO)
  qt5_use_modules(tcp_test Network)
  qt5_use_modules(async_tcp_test Network)

  find_package(Qt5Core REQUIRED)
  qt5_use_modules(serial_port_test Core)

  add_definitions(-DUSE_BOOST_ASIO_WITH_CMAKE_BUG)
endif(USE_BOOST_ASIO)
