cmake_minimum_required(VERSION 3.16)
project(simplecore)

set(CMAKE_CXX_STANDARD 17)

find_package(KF6 REQUIRED COMPONENTS Wayland)
find_package(Qt6 REQUIRED COMPONENTS Core Gui)

add_executable(simplecore src/main.cpp)

target_link_libraries(simplecore
    Qt6::Core
    Qt6::Gui
    KF6::Wayland
)
