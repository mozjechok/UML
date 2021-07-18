cmake_minimum_required(VERSION 3.5)

#SET(CMAKE_PREFIX_PATH "C:\\Qt\\6.1.2\\msvc2019_64")

project(UML VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        umlbasefigure.h
        umlbasefigure.cpp
        umlpolygon.h
        umlpolygon.cpp
        umlrectangle.h
        umlrectangle.cpp
        umlcircle.h
        umlcircle.cpp
        umlconnectiveline.h
        umlconnectiveline.cpp
        umlbasebutton.h
        umlbasebutton.cpp
        umlcreatebasefigurebutton.h
        umlcreatebasefigurebutton.cpp
        umlcreaterectanglebutton.h
        umlcreaterectanglebutton.cpp
        umlcreatecirclebutton.h
        umlcreatecirclebutton.cpp
        umlcreatetrianglebutton.h
        umlcreatetrianglebutton.cpp
        umlcreateconnectivelinebutton.h
        umlcreateconnectivelinebutton.cpp
        umlmovehandbutton.h
        umlmovehandbutton.cpp
        umlgraphicsscene.h
        umlgraphicsscene.cpp
)

qt_add_resources(PROJECT_SOURCES UML_resurses.qrc)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(UML
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(UML SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(UML
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(UML PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(UML PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(UML)
endif()
