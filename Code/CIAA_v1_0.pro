#-------------------------------------------------
#
# Project created by QtCreator 2014-01-09T14:28:58
#
#-------------------------------------------------

QT       += core gui network serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CIAA_v1_0

TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
    GUI/MainWindow/ciaaMainwindow_Controller.cpp \
    Coder/Ladder/Elements/ciaaLElement_Controller.cpp \
    Coder/Ladder/Elements/ciaaLElement_Model.cpp \
    Coder/Ladder/Elements/ciaaLElement_View.cpp \
    Coder/Ladder/Elements/ciaaLContact_Controller.cpp \
    Coder/Ladder/Elements/ciaaLContact_Model.cpp \
    Coder/Ladder/Elements/ciaaLContact_View.cpp \
    Coder/Ladder/Elements/ciaaLCoil_View.cpp \
    Coder/Ladder/Elements/ciaaLCoil_Controller.cpp \
    Coder/Ladder/Elements/ciaaLCoil_Model.cpp \
    Coder/Ladder/Elements/ciaaLOutput_Controller.cpp \
    Coder/Ladder/Elements/ciaaLOutput_View.cpp \
    Coder/Ladder/Elements/ciaaLOutput_Model.cpp \
    Coder/Ladder/Elements/ciaaLInput_Model.cpp \
    Coder/Ladder/Elements/ciaaLInput_Controller.cpp \
    Coder/Ladder/Elements/ciaaLInput_View.cpp \
    Coder/Ladder/Visualiser/ciaaVLadder_View.cpp \
    Coder/Ladder/Visualiser/ciaaVLadder_Model.cpp \
    Coder/Ladder/Visualiser/ciaaVLadder_Controller.cpp \
    Coder/IEC61131Standard/DataTypes/ciaaIECBoolType.cpp \
    Coder/IEC61131Standard/DataTypes/ciaaIECByteType.cpp \
    Coder/IEC61131Standard/DataTypes/ciaaIECWordType.cpp \
    Coder/IEC61131Standard/DataTypes/ciaaIECDWordType.cpp \
    Coder/IEC61131Standard/DataTypes/ciaaIECDBaseType.cpp \
    Coder/IEC61131Standard/DataTypes/ciaaIECDIntType.cpp \
    Coder/IEC61131Standard/Variables/ciaaIECVariable.cpp \
    Coder/IEC61131Standard/Variables/ciaaIECAttributes.cpp \
    Coder/IEC61131Standard/Variables/ciaaIECArrays.cpp \
    Coder/IEC61131Standard/Variables/ciaaIECStructures.cpp \
    Coder/IEC61131Standard/Blocks/Programs/ciaaIECBaseProgram.cpp \
    Coder/IEC61131Standard/Blocks/FunctionsBlocks/ciaaIECBaseFB.cpp \
    Coder/IEC61131Standard/Blocks/Functions/ciaaIECBaseF.cpp \
    Coder/IEC61131Standard/Operators/ciaaIECAdd.cpp \
    Coder/IEC61131Standard/Operators/ciaaIECBBinaryOperator.cpp \
    Coder/IEC61131Standard/Operators/ciaaIECBUnaryOperator.cpp \
    Coder/IEC61131Standard/Operators/ciaaIECAnd.cpp \
    Coder/IEC61131Standard/Operators/ciaaIECOr.cpp \
    Coder/IEC61131Standard/ConfigElements/Configurations/ciaaIECConfig.cpp \
    Coder/IEC61131Standard/ConfigElements/Resources/ciaaIECResource.cpp \
    Coder/IEC61131Standard/ConfigElements/Tasks/ciaaIECTask.cpp \
    Coder/Ladder/Operators/ciaaLAnd.cpp \
    Coder/IL/Visualiser/ciaaVIL_Controller.cpp \
    Coder/IL/Elements/ciaaILRegister.cpp \
    Coder/IL/Operators/ciaaILAnd.cpp \
    System/Base/ciaaBaseMapMemory.cpp \
    System/ciaaFreescale/ciaaFSMapMemory.cpp \
    System/ciaaNXP/ciaaNXPMapMemory.cpp \
    System/ciaaST/ciaaSTMapMemory.cpp \
    Comms/Protocols/Modbus/ciaaModbus.cpp \
    Coder/IEC61131Standard/Projects/ciaaIECProject.cpp \
    Compiler/ciaaIECCompiler.cpp \
    Debugger/ciaaDebugger.cpp \
    Programmer/ciaaProgrammer.cpp \
    Coder/Ladder/Elements/ciaaLFB.cpp \
    Coder/Ladder/Elements/ciaaLF.cpp \
    Coder/Ladder/Elements/ciaaLProgram.cpp \
    Coder/IEC61131Standard/Blocks/ciaaIECBaseBlock.cpp \
    Coder/IEC61131Standard/ciaaIECBaseElement.cpp \
    Coder/IL/Visualiser/ciaaVIL_Model.cpp \
    Coder/IL/Visualiser/ciaaVIL_View.cpp \
    Coder/ciaaProject.cpp \
    Comms/Drivers/Ethernet/ciaa_socket_tcp.cc \
    Comms/Drivers/Ethernet/ciaa_qudpsocket_adapter.cc \
    Comms/Drivers/Ethernet/ciaa_socket_udp.cc \
    Comms/Drivers/Ethernet/ciaa_qtcpsocket_adapter.cc \
    Comms/Drivers/SerialPort/ciaa_serial_port.cc \
    Comms/Drivers/SerialPort/ciaa_qserialport_adapter.cc \
    Comms/Drivers/ciaa_comm_facade.cc

HEADERS  += GUI/MainWindow/ciaaMainWindow_Controller.h \
    Coder/Ladder/Elements/ciaaLElement_Controller.h \
    Coder/Ladder/Elements/ciaaLElement_Model.h \
    Coder/Ladder/Elements/ciaaLElement_View.h \
    Coder/Ladder/Elements/ciaaLContact_Controller.h \
    Coder/Ladder/Elements/ciaaLContact_Model.h \
    Coder/Ladder/Elements/ciaaLContact_View.h \
    Coder/Ladder/Elements/ciaaLCoil_View.h \
    Coder/Ladder/Elements/ciaaLCoil_Controller.h \
    Coder/Ladder/Elements/ciaaLCoil_Model.h \
    Coder/Ladder/Elements/ciaaLOutput_Controller.h \
    Coder/Ladder/Elements/ciaaLOutput_View.h \
    Coder/Ladder/Elements/ciaaLOutput_Model.h \
    Coder/Ladder/Elements/ciaaLInput_Model.h \
    Coder/Ladder/Elements/ciaaLInput_Controller.h \
    Coder/Ladder/Elements/ciaaLInput_View.h \
    Coder/Ladder/Visualiser/ciaaVLadder_View.h \
    Coder/Ladder/Visualiser/ciaaVLadder_Model.h \
    Coder/Ladder/Visualiser/ciaaVLadder_Controller.h \
    Coder/IEC61131Standard/DataTypes/ciaaIECBoolType.h \
    Coder/IEC61131Standard/DataTypes/ciaaIECByteType.h \
    Coder/IEC61131Standard/DataTypes/ciaaIECWordType.h \
    Coder/IEC61131Standard/DataTypes/ciaaIECDWordType.h \
    Coder/IEC61131Standard/DataTypes/ciaaIECDBaseType.h \
    Coder/IEC61131Standard/DataTypes/ciaaIECDIntType.h \
    Coder/IEC61131Standard/Variables/ciaaIECVariable.h \
    Coder/IEC61131Standard/Variables/ciaaIECAttributes.h \
    Coder/IEC61131Standard/Variables/ciaaIECArrays.h \
    Coder/IEC61131Standard/Variables/ciaaIECStructures.h \
    Coder/IEC61131Standard/Blocks/Programs/ciaaIECBaseProgram.h \
    Coder/IEC61131Standard/Blocks/FunctionsBlocks/ciaaIECBaseFB.h \
    Coder/IEC61131Standard/Blocks/Functions/ciaaIECBaseF.h \
    Coder/IEC61131Standard/Operators/ciaaIECAdd.h \
    Coder/IEC61131Standard/Operators/ciaaIECBBinaryOperator.h \
    Coder/IEC61131Standard/Operators/ciaaIECBUnaryOperator.h \
    Coder/IEC61131Standard/Operators/ciaaIECAnd.h \
    Coder/IEC61131Standard/Operators/ciaaIECOr.h \
    Coder/IEC61131Standard/ConfigElements/Configurations/ciaaIECConfig.h \
    Coder/IEC61131Standard/ConfigElements/Resources/ciaaIECResource.h \
    Coder/IEC61131Standard/ConfigElements/Tasks/ciaaIECTask.h \
    Coder/Ladder/Operators/ciaaLAnd.h \
    Coder/IL/Visualiser/ciaaVIL_Controller.h \
    Coder/IL/Elements/ciaaILRegister.h \
    Coder/IL/Operators/ciaaILAnd.h \
    System/Base/ciaaBaseMapMemory.h \
    System/ciaaFreescale/ciaaFSMapMemory.h \
    System/ciaaNXP/ciaaNXPMapMemory.h \
    System/ciaaST/ciaaSTMapMemory.h \
    Comms/Protocols/Modbus/ciaaModbus.h \
    Coder/IEC61131Standard/Projects/ciaaIECProject.h \
    Compiler/ciaaIECCompiler.h \
    Debugger/ciaaDebugger.h \
    Programmer/ciaaProgrammer.h \
    Coder/Ladder/Elements/ciaaLFB.h \
    Coder/Ladder/Elements/ciaaLF.h \
    Coder/Ladder/Elements/ciaaLProgram.h \
    Coder/IEC61131Standard/Blocks/ciaaIECBaseBlock.h \
    Coder/IEC61131Standard/ciaaIECBaseElement.h \
    Defines/ciaaGlobalMacros.h \
    Coder/IL/Visualiser/ciaaVIL_Model.h \
    Coder/IL/Visualiser/ciaaVIL_View.h \
    Coder/ciaaProject.h \
    Comms/Drivers/ciaa_comm_facade.h \
    Comms/Drivers/ciaa_comm_interface.h \
    Comms/Drivers/ciaa_comm_driver_error_code.h \
    Comms/Drivers/ciaa_comm_adapter_interface.h \
    Comms/Drivers/SerialPort/ciaa_serial_port.h \
    Comms/Drivers/SerialPort/ciaa_qserialport_adapter.h \
    Comms/Drivers/Ethernet/ciaa_socket_udp.h \
    Comms/Drivers/Ethernet/ciaa_socket_tcp.h \
    Comms/Drivers/Ethernet/ciaa_qudpsocket_adapter.h \
    Comms/Drivers/Ethernet/ciaa_qtcpsocket_adapter.h

FORMS    += GUI/MainWindow/ciaaMainwindow_View.ui

OTHER_FILES += \
    TODO \
    Doc/MainPage.h

RESOURCES += \
    Resources/StartIcons.qrc \
    Resources/LadderIcons.qrc \
    Resources/AppIcon.qrc
