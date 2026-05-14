cmake_minimum_required(VERSION 3.22)
project(ModbusCRC)

add_subdirectory(dependencies/nana)
set(CMAKE_CXX_STANDARD 20)

add_executable(ModbusCRC src/main.cpp)

target_link_libraries(ModbusCRC PRIVATE nana)