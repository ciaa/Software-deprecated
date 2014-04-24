set(CMAKE_INCLUDE_CURRENT_DIR ON)

include(CMake/CMakeDependencies.cmake)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Comms)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Coder)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Compiler)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Debugger)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/GUI)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/System)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Programmer)




qt5_add_resources(UI_RESOURCES
    Resources/AppIcon.qrc
    Resources/LadderIcons.qrc
    Resources/StartIcons.qrc)

add_executable(${PROJECT_NAME} main.cpp ${UI_RESOURCES})
target_link_libraries(${PROJECT_NAME}
    gui
    coder
      comms_drivers
      comms_protocols_modbus
    compiler
    debuger
    programmer
    system)
