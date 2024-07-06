cmake_minimum_required(VERSION 3.16)

project(simple-session)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
find_package(KWayland REQUIRED)

add_executable(simple-session src/main.cpp)

target_link_libraries(simple-session 
    Qt6::Core 
    Qt6::Gui 
    Qt6::Widgets 
    Plasma::KWaylandClient
)

install(TARGETS simple-session DESTINATION /usr/bin)
install(FILES resources/simple-session.desktop DESTINATION /usr/share/wayland-sessions)
