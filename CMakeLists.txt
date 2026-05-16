cmake_minimum_required(VERSION 3.22)
project(ModbusCRC)

set(BUILD_SHARED_LIBS OFF)

add_subdirectory(dependencies/nana)

set(CMAKE_CXX_STANDARD 17)

add_executable(ModbusCRC
        src/main.cpp
        src/crc_form.cpp
        src/crc_calculator.cpp
)

target_include_directories(ModbusCRC PRIVATE defs)

target_link_libraries(ModbusCRC PRIVATE nana )

if(MINGW OR WIN32)
    target_link_options(ModbusCRC PRIVATE "-static-libgcc" "-static-libstdc++" "-static")
endif()