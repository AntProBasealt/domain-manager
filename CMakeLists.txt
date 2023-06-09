cmake_minimum_required(VERSION 3.5)

project(domain-manager VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Core)

set(HEADERS
    step_1.h
    mainwindow.h
    step_1.h
    step_2.h
    step_3.h
    step_4.h
    MDomainbegin.h)

set(SOURCES
    main.cpp
    mainwindow.cpp
    step_1.cpp
    step_2.cpp
    step_3.cpp
    step_4.cpp)

set(UI_FORMS
    mainwindow.ui
    step_1.ui
    step_2.ui
    step_3.ui
    step_4.ui)

set(RESOURCES
    logo.png)

set(PROJECT_SOURCES ${SOURCES} ${HEADERS} ${UI_FORMS} ${RESOURCES})

add_subdirectory(src)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(domain-manager
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET domain-manager APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(domain-manager SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(domain-manager
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(domain-manager PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

#set_target_properties(domain-manager PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
#    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
#    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
#    MACOSX_BUNDLE TRUE
#    WIN32_EXECUTABLE TRUE
#)

install(TARGETS domain-manager
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})


if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(domain-manager)
endif()
