cmake_minimum_required(VERSION 3.10)

project(session)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core)

add_executable(session
    src/main.cpp
    src/process.cpp
    src/process.h
    src/application.cpp
    src/application.h
)

target_link_libraries(session Qt6::Core)

install(TARGETS simple-session RUNTIME DESTINATION bin)
install(FILES resources/prts-wayland.desktop DESTINATION share/applications)
