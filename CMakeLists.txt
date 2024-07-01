cmake_minimum_required(VERSION 3.10)

project(simple-session)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core)

add_executable(simple-session
    src/main.cpp
    src/process.cpp
    src/process.h
    src/application.cpp
    src/application.h
)

target_link_libraries(simple-session Qt6::Core)

install(TARGETS simple-session RUNTIME DESTINATION bin)
install(FILES resources/simple-session.desktop DESTINATION share/applications)
