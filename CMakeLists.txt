cmake_minimum_required(VERSION 3.10)

project(SimpleSession)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Quick WaylandClient WaylandCompositor)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(simple-session main.cpp)

target_link_libraries(simple-session Qt6::Core Qt6::Gui Qt::Quick Qt6::WaylandClient Qt6::WaylandCompositor)

install(TARGETS simple-session DESTINATION bin)
install(FILES simple-session.desktop DESTINATION /usr/share/wayland-sessions)