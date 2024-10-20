cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(googletest
 URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(bitarray src/bitarray.cpp)

add_executable(bitarray_test test/bitarray_test.cpp)

target_link_libraries(bitarray_test PRIVATE bitarray GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(bitarray_test)
