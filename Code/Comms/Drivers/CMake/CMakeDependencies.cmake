if(USE_BOOST_ASIO)
  SET(Boost_USE_MULTITHREAD ON)
  SET(Boost_USE_STATIC_LIBS OFF)
  FIND_PACKAGE(Boost 1.54.0 REQUIRED COMPONENTS system)
  IF(Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
    LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
    SET(USED_LIBS ${Boost_SYSTEM_LIBRARY} pthread)
#    SET(USED_LIBS ${Boost_SYSTEM_LIBRARY} ${Boost_THREAD_LIBRARY})
  ENDIF(Boost_FOUND)
  add_definitions(-DUSE_BOOST_ASIO)
  set(ciaa_comm_drivers_R_W_size_t "size_t")
  set(ciaa_comm_drivers_R_W_size_t_header_file "stddef.h")
  set(BASE_MODULES_FOR_COMMS_SRC
    Ethernet/ciaa_boosttcp_adapter.cc
    SerialPort/ciaa_boostserialport_adapter.cc
    ciaa_ioservice_adapter.cc)
else(USE_BOOST_ASIO)
  set(ciaa_comm_drivers_R_W_size_t "qint64")
  set(ciaa_comm_drivers_R_W_size_t_header_file "QtCore/QtGlobal")
  find_package(Qt5Network REQUIRED)
  find_package(Qt5SerialPort REQUIRED)
  set(BASE_MODULES_FOR_COMMS_SRC
    Ethernet/ciaa_qtcpsocket_adapter.cc
    Ethernet/ciaa_qudpsocket_adapter.cc
    SerialPort/ciaa_qserialport_adapter.cc
    ciaa_qiodevice_adapter.cc
    )
endif(USE_BOOST_ASIO)

configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/CMake/ciaa_comm_drivers_config.h.in
  ${CMAKE_CURRENT_BINARY_DIR}/ciaa_comm_drivers_config.h)
