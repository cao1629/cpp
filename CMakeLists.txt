cmake_minimum_required(VERSION 3.10)

project(cpp)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_BUILD_TYPE Debug)

add_executable(a1 a1.c)
add_executable(hi hi.c)

add_executable(b1 b1.c)
# # add_executable(b2 b2.c)
# target_link_libraries(b2 b1)

# Generate object file from large_data binary
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/large_data.o
    COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/large_data ${CMAKE_CURRENT_BINARY_DIR}/large_data
    COMMAND objcopy -I binary -O elf64-x86-64 -B i386:x86-64
            --rename-section .data=.largedata,alloc,load,readonly,data,contents
            large_data large_data.o
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/large_data
    COMMENT "Generating object file from large_data"
)

# Create executable with embedded large_data
add_executable(numbers_max numbers_max.cpp ${CMAKE_CURRENT_BINARY_DIR}/large_data.o)

add_executable(concurrent_works concurrent_works.cpp)
target_link_libraries(concurrent_works pthread)

add_executable(concurrent_works_need_result concurrent_works_need_result.cpp)
target_link_libraries(concurrent_works_need_result pthread)

add_executable(simple_thread simple_thread.cpp)
target_link_libraries(simple_thread pthread)
