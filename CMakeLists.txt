cmake_minimum_required(VERSION 3.5)
project(simplecore)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(QT Core Gui Widgets Quick QuickControls2 DBus X11Extras LinguistTools)
find_package(Qt5 REQUIRED ${QT})
find_package(PkgConfig REQUIRED)
find_package(ECM REQUIRED NO_MODULE)
find_package(KF5WindowSystem REQUIRED)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${ECM_MODULE_PATH})

add_subdirectory(session)