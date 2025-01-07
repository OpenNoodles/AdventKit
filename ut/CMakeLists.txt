include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        main
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE) # For Windows: Prevent overriding the parent project's compiler/linker settings
FetchContent_MakeAvailable(googletest)

file(GLOB_RECURSE TARGET_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
foreach(SOURCE_FILE ${TARGET_SOURCES})
    get_filename_component(EXECUTABLE_NAME ${SOURCE_FILE} NAME_WE)
    set(UT_EXECUTABLE_NAME ${EXECUTABLE_NAME}_ut)
    message(STATUS "AdventKit::Ut: Source found:   ${EXECUTABLE_NAME}.cpp   [${UT_EXECUTABLE_NAME}]")
    add_executable(${UT_EXECUTABLE_NAME} ${SOURCE_FILE})
    target_link_libraries(${UT_EXECUTABLE_NAME} gtest_main AdventKit)
    add_test(NAME ${UT_EXECUTABLE_NAME} COMMAND ${UT_EXECUTABLE_NAME})
endforeach()
