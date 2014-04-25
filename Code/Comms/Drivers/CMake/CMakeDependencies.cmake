#find_package (SISCP-UTILS-Utils REQUIRED)
#find_package (SISCP-COMMUNICATIONS-LibCommunicationCommons REQUIRED)

#link_directories(
#      ${UTILS_LIBRARIES_DIR}
#      ${LIBCOMMUNICATIONCOMMONS_LIBRARIES_DIR}
#)

option(USE_BOOST_ASIO "Use boost-asio for Comms/Drivers module?,
                       if not use qt5 instead" OFF)
if(USE_BOOST_ASIO)
#  set(ciaa_comm_drivers_R_W_size_t "size_t")
#  set(ciaa_comm_drivers_R_W_size_t_header_file "stddef.h")
  find_package(Boost COMPONENTS asio REQUIRED)
else(USE_BOOST_ASIO)
  set(ciaa_comm_drivers_R_W_size_t "qint64")
  set(ciaa_comm_drivers_R_W_size_t_header_file "QtCore")
  find_package(Qt5Network REQUIRED)
  find_package(Qt5SerialPort REQUIRED)
  set(BASE_MODULES_FOR_COMMS_SRC
    Ethernet/ciaa_qtcpsocket_adapter.cc
    Ethernet/ciaa_qudpsocket_adapter.cc
    SerialPort/ciaa_qserialport_adapter.cc)
endif(USE_BOOST_ASIO)

configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/CMake/ciaa_comm_drivers_config.h.in
  ${CMAKE_SOURCE_DIR}/Code/ciaa_comm_drivers_config.h)