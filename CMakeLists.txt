cmake_minimum_required(VERSION 3.10)
project(my_proj)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3)
find_package(fmt REQUIRED)

add_subdirectory(tests)

add_executable(my_proj src/main.cpp src/appmain.cpp src/input.cpp src/gameover.cpp src/overworld.cpp src/title.cpp src/transition.cpp)
target_compile_options(my_proj PRIVATE -Wall -v -g)
target_link_libraries(my_proj PRIVATE SDL3::SDL3 fmt::fmt-header-only)

if(CMAKE_BUILD_TYPE MATCHES Debug)
  #AddressSan detects leaks in NVidia libraries, something we can't control :(
  #message("Adding AddressSan and UBSan to debug build")
  #target_compile_options(my_proj PRIVATE -fsanitize=address)
  #target_link_options(my_proj PRIVATE -fsanitize=address)
  #message("Adding UBSan to debug build")
  #target_link_options(my_proj PRIVATE -fsanitize=undefined)
  #message("Setting optimizations to -O1")
  #target_compile_options(my_proj PRIVATE -O1)
endif()

if(CMAKE_BUILD_TYPE MATCHES Release)
  message("Setting optimizations to -O3")
  target_compile_options(my_proj PRIVATE -O3)
endif()
