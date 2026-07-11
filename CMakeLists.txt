cmake_minimum_required(VERSION 3.15)
project(LPM LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 1. Automatically grab ALL .c files in the src directory 
# (This fixes lpm_invalid, lpm_init, lpm_help)
file(GLOB SOURCES "src/*.c")

add_executable(lpm ${SOURCES})

# 2. Inform the compiler that libsodium is a static library
# (This fixes the __declspec(dllimport) sodium_init error)
target_compile_definitions(lpm PRIVATE SODIUM_STATIC)

set_target_properties(lpm PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build"
)

target_include_directories(lpm PRIVATE
    include
    libs/libsodium/include
)

target_link_directories(lpm PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/libsodium/x64/Release/v143/static
)

target_link_libraries(lpm PRIVATE libsodium)
