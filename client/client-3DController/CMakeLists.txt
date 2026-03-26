cmake_minimum_required(VERSION 3.16)

project(RobotArmPrueba VERSION 0.1 LANGUAGES CXX)

# C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Quick3D)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appRobotArmPrueba
    main.cpp
)


qt_add_qml_module(appRobotArmPrueba
    URI RobotArmPrueba
    VERSION 1.0
    QML_FILES
    Main.qml
    balsam/RoboticArm.qml
    RESOURCES
    assets.qrc
    SOURCES
    src/parser.cpp src/parser.h
    src/parservalidate.cpp src/parservalidate.h
    src/brazovirtual.cpp src/brazovirtual.h
    src/commanddispatcher.cpp src/commanddispatcher.h
    src/commandprocessorqt.h src/commandprocessorqt.cpp
    src/commandprocessor.h src/commandprocessor.cpp
    armadapter.h armadapter.cpp

)
target_include_directories(appRobotArmPrueba PRIVATE src)
# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appRobotArmPrueba PROPERTIES
    #    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appRobotArmPrueba
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appRobotArmPrueba
    PRIVATE Qt6::Quick Qt6::Quick3D
)
target_link_libraries(appRobotArmPrueba PRIVATE Qt6::Core)
target_link_libraries(appRobotArmPrueba PRIVATE Qt6::Core)
target_link_libraries(appRobotArmPrueba PRIVATE Qt6::Core)

include(GNUInstallDirs)
install(TARGETS appRobotArmPrueba
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
