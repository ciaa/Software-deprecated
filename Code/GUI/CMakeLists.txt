find_package(Qt5Widgets REQUIRED)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

qt5_wrap_ui(UI_HEADERS
    MainWindow/ciaaMainwindow_View.ui)
qt5_wrap_cpp(CPP_HEADERS
    MainWindow/ciaaMainWindow_Controller.h)
set(gui_Code
    MainWindow/ciaaMainwindow_Controller.cpp)

add_library(gui
    ${gui_Code}
    ${UI_HEADERS}
    ${CPP_HEADERS})
qt5_use_modules(gui Widgets)
