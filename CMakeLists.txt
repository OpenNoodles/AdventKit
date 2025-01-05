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

add_library(${PROJECT_NAME} STATIC
    ${TARGET_SOURCES}
)
target_compile_options(${PROJECT_NAME} PRIVATE ${THIS_PROJECT_COMPILE_OPTIONS})
target_compile_features(${PROJECT_NAME} PRIVATE ${THIS_PROJECT_COMPILE_FEATURES})

# GOOGLE'S UNIT TESTS:
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        main
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE) # For Windows: Prevent overriding the parent project's compiler/linker settings
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(example example.cpp)
target_link_libraries(example gtest_main)

enable_testing()
add_test(NAME example_test COMMAND example)