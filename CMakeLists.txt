cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# DEFINE COMPILATION FEATURES:
set(THIS_PROJECT_COMPILE_OPTIONS
    -Wall
    -Werror 
    -Weffc++
    -Wextra
    -pedantic
    -Wconversion 
    -O3
    -Wshadow
    -Wnon-virtual-dtor
    -Wold-style-cast    
    -Woverloaded-virtual 
    -Wzero-as-null-pointer-constant
    -fPIE 
    -fstack-protector-all 
    -fno-rtti
)
set(THIS_PROJECT_COMPILE_FEATURES
    cxx_std_17
)

# DEFINE PROJECT:
project(AdventKit)
file(GLOB_RECURSE TARGET_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE MAIN_TARGET_TOOLS "${CMAKE_CURRENT_SOURCE_DIR}/../tools/*.cpp")

add_library(${PROJECT_NAME} STATIC
    ${TARGET_SOURCES}
    ${MAIN_TARGET_TOOLS}
)
target_compile_options(${PROJECT_NAME} PRIVATE ${THIS_PROJECT_COMPILE_OPTIONS})
target_compile_features(${PROJECT_NAME} PRIVATE ${THIS_PROJECT_COMPILE_FEATURES})

