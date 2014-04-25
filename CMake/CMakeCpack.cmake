include(InstallRequiredSystemLibraries)


set(CPACK_PACKAGE_VENDOR "\nCámara Argentina de Industrias Electrónicas, Electromecánicas y Luminotécnicas (CADIEEL) \n&\nAsociación Civil para la Investigación, Promoción y Desarrollo de los Sistemas Embebidos (ACSE)" VERBATIM)
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Instalador de ${CMAKE_PROJECT_NAME} del proyecto ${porject_brief}")

set(CPACK_GENERATOR "DEB")
set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY ON)
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Alvaro Denis Acosta Quesada<denisacostaq@gmail.com>")
set(CPACK_RESOURCE_FILE_WELCOME ${CMAKE_CURRENT_SOURCE_DIR}/Readme/HACKING)
SET(CPACK_RESOURCE_FILE_LICENSE ${CMAKE_CURRENT_SOURCE_DIR}/Readme/LICENSE.txt)
set(CPACK_RESOURCE_FILE_README  ${CMAKE_CURRENT_SOURCE_DIR}/README.md)

# version for tarball name:
set(CPACK_PACKAGE_VERSION_MAJOR ${${CMAKE_PROJECT_NAME}_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${${CMAKE_PROJECT_NAME}_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${${CMAKE_PROJECT_NAME}_VERSION_PATCH})
set(CPACK_PACKAGE_VERSION ${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH})

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  message("WINDOWS...")
#if WIN32 TRUE, CMAKE_HOST_UNIX, CMAKE_HOST_WIN32
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
  message("Building instaler on Linux-${CMAKE_SYSTEM_VERSION}...")
else(CMAKE_SYSTEM_NAME STREQUAL "Linux")
  message("ninguno")
endif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
message("Processor architecture ${CMAKE_SYSTEM_PROCESSOR}.")
set(CPACK_PACKAGING_INSTALL_PREFIX /usr/local)
#set(CMAKE_INSTALL_PREFIX  /usr/local on UNIX and c:/Program Files on Windows)
install(FILES ${CPACK_RESOURCE_FILE_LICENSE} DESTINATION share/doc)
install(FILES ${CPACK_RESOURCE_FILE_README}  DESTINATION share/doc/${CMAKE_PROJECT_NAME})
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/Code/${CMAKE_PROJECT_NAME} DESTINATION bin)
include(CPack)