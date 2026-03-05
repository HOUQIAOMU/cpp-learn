# 根目录的CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(VabsProject)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)

# 添加头文件目录
include_directories(include)

# 创建共享库
add_library(vabs SHARED src/vabs.cpp)

# 创建可执行文件
add_executable(main src/main.cpp)

# 链接共享库
target_link_libraries(main vabs)

# 显示信息
message(STATUS "Shared library will be created: libvabs.so")
message(STATUS "Executable will be created: main")