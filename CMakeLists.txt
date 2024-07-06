cmake_minimum_required(VERSION 3.16)
project(simple-session)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Quick WaylandCompositor)
find_package(KF6 REQUIRED COMPONENTS Config CoreAddons WindowSystem)

add_executable(simple-session main.cpp)

target_link_libraries(simple-session Qt6::Core Qt6::Gui Qt6::Quick Qt6::WaylandCompositor KF6::Config KF6::CoreAddons KF6::WindowSystem)

# Install executable and .desktop file
install(TARGETS simple-session DESTINATION /usr/bin)
install(FILES simple-session.desktop DESTINATION /usr/share/wayland-sessions)
