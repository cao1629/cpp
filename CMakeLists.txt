cmake_minimum_required(VERSION 3.10)

project(cpp)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_BUILD_TYPE Debug)

add_executable(main hello.cpp)
add_executable(a1 a1.c)

# Generate object file from binary data with custom symbol name
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/data.o
    COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/data ${CMAKE_CURRENT_BINARY_DIR}/data
    COMMAND objcopy -I binary -O elf64-x86-64 -B i386:x86-64
            --rename-section .data=.rodata,alloc,load,readonly,data,contents
            data data.o
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/data
    COMMENT "Generating object file from binary data"
)

# Create executable with embedded data
add_executable(numbers numbers.cpp ${CMAKE_CURRENT_BINARY_DIR}/data.o)
