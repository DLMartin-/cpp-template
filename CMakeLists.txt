cmake_minimum_required(VERSION 3.10)
project(my_proj)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_CXX_STANDARD 20)

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3)
find_package(fmt REQUIRED)

add_subdirectory(tests)

add_executable(my_proj src/main.cpp src/appmain.h src/appmain.cpp)
target_link_libraries(my_proj PRIVATE SDL3::SDL3 fmt::fmt-header-only)

