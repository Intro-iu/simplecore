cmake_minimum_required(VERSION 3.14)

# 项目信息
project(simple-session)

# 查找Qt6库
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# 添加可执行文件
add_executable(simple-session main.cpp)

# 链接Qt6库
target_link_libraries(simple-session Qt6::Core Qt6::Gui Qt6::Widgets)

install(TARGETS simple-session DESTINATION bin)
install(FILES simple-session.desktop DESTINATION /usr/share/wayland-sessions/)