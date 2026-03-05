cmake_minimum_required(VERSION 3.10)

project(ComplexProject)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加头文件路径
include_directories(include)

# 指定源文件
set(SOURCES
    src/complex.cpp
    src/main.cpp
)

# 生成可执行文件
add_executable(complex_app ${SOURCES})