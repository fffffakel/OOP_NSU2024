cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(googletest
 URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(time src/time.cpp)

add_executable(time_test test/time_test.cpp)

target_link_libraries(time_test PRIVATE time GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(time_test)