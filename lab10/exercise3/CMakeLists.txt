# 指定CMake的最低版本要求（根据你的编译器适配，3.10是比较通用的版本）
cmake_minimum_required(VERSION 3.10)

# 项目名称（可自定义，比如改为ComplexProject）
project(ComplexDemo)

# 设置C++标准（推荐C++11及以上，兼容你的代码）
set(CMAKE_CXX_STANDARD 11)
# 强制启用C++标准，避免编译器自动降级
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. 定义头文件目录（告诉编译器去哪里找include里的头文件）
include_directories(${PROJECT_SOURCE_DIR}/include)

# 2. 收集所有源文件（src下的main.cpp和complex.cpp）
# 方式1：显式列出（适合文件少的情况，清晰）
set(SOURCES
    src/main.cpp
    src/complex.cpp
)

# 3. 生成可执行文件（第一个参数是可执行文件名，第二个是源文件列表）
add_executable(complex_app ${SOURCES})