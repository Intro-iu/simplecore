cmake_minimum_required(VERSION 3.10)

project(simple-session)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core WaylandCompositor Gui)

add_executable(prts-session
    src/main.cpp
    src/compositor.cpp
    src/compositor.h
    src/application.cpp
    src/application.h
)

target_link_libraries(prts-session Qt6::Core Qt6::Gui Qt6::WaylandCompositor)


install(TARGETS simple-session RUNTIME DESTINATION bin)
install(FILES resources/simple-wayland.desktop DESTINATION /usr/share/wayland-sessions/)
