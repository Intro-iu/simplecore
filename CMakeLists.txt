cmake_minimum_required(VERSION 3.10)

project(SimpleSession)

find_package(Qt6 REQUIRED COMPONENTS Core Gui WaylandCompositor Qml Quick)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

qt_add_executable(simple-session
    main.cpp
    resources.qrc
)

target_link_libraries(simple-session Qt6::Core Qt6::Gui Qt6::WaylandCompositor Qt6::Qml Qt6::Quick)

install(TARGETS simple-session DESTINATION bin)
install(FILES simple-session.desktop DESTINATION /usr/share/wayland-sessions)