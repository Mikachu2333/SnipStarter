cmake_minimum_required(VERSION 3.27)

project(Test)

set(VERSION_NUMBER  V101)
add_executable(SnipStarter main.cpp)
set(CMAKE_EXE_LINKER_FLAGS "-static")