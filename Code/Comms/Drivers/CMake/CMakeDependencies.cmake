#find_package (SISCP-UTILS-Utils REQUIRED)
#find_package (SISCP-COMMUNICATIONS-LibCommunicationCommons REQUIRED)

#link_directories(
#      ${UTILS_LIBRARIES_DIR}
#      ${LIBCOMMUNICATIONCOMMONS_LIBRARIES_DIR}
#)

option(USE_BOOST_ASIO "Use boost-asio for Comms/Drivers module?,
                       if not use qt5 instead" OFF)
if(USE_BOOST_ASIO)
  find_package(Boost COMPONENTS asio REQUIRED)
else(USE_BOOST_ASIO)
  find_package(Qt5Network REQUIRED)
  find_package(Qt5SerialPort REQUIRED)
  set(BASE_MODULES_FOR_COMMS_SRC
    Ethernet/ciaa_qtcpsocket_adapter.cc
    Ethernet/ciaa_qudpsocket_adapter.cc
    SerialPort/ciaa_qserialport_adapter.cc)
endif(USE_BOOST_ASIO)



