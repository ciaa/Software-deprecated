CIAA_v1_0
=========
 _Software de la Computadora Industrial Abierta Argentina (v_0.0.0).


BUILD:
------
- Para compilar en linux ejecutas la siguiente secuencia de comandos:
	- git clone https://github.com/ciaa/Software.git
	- cd Software
	- mkdir build
	- cd build
	- sudo apt-get install cmake
	- ccmake .. -DCMAKE_PREFIX_PATH=your_path -DUSE_BOOST_ASIO=OFF
	- make
  Donde &quot;PATH_TO_QT_CMAKE_MODULES&quot; es el directorio donde est&eacute;n
  instalados los m&oacute;dulos de cmake para qt, en mi caso por ejemplo
  ser&iacute;a cmake .. -DCMAKE_PREFIX_PATH=/opt/Qt5.2.0/5.2.0/gcc/lib/cmake.

- Para compilar en windows:
  Abres el proyecto, c&oacute;modamente pudiera ser abriendo el qtcreator
  y le &quot;tiras&quot; para arriba el CMakeLists.txt del directorio ra&iacute;z,
  seleccionas el direcotrio de compilaci&oacute;n y das click haces click
  en el bot&oacute;n Run CMake.
