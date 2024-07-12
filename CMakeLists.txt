cmake_minimum_required(VERSION 3.10)

# 项目信息
project(simple-session)

# 查找Qt6包
find_package(Qt6 REQUIRED COMPONENTS Core Gui WaylandClient WaylandCompositor)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加可执行文件
add_executable(simple-session 
    src/main.cpp
    src/compositor.h
    src/compositor.cpp
)

# 链接Qt6库
target_link_libraries(simple-session Qt6::Core Qt6::Gui Qt6::WaylandClient Qt6::WaylandCompositor)

install(TARGETS simple-session DESTINATION bin)
install(FILES resources/simple-session.desktop DESTINATION share/wayland-sessions)
