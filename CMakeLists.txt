cmake_minimum_required(VERSION 3.16)
project(simple-session)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick)
find_package(KF6WindowSystem REQUIRED)

add_executable(simple-session
    main.cpp
    main.qml
)

target_link_libraries(simple-session
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    KF6::WindowSystem
)

install(TARGETS simple-session DESTINATION bin)
install(FILES simple-session.desktop DESTINATION /usr/share/wayland-sessions)