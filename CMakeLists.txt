cmake_minimum_required(VERSION 3.20)
project(HW_1 C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror --coverage")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror --coverage")

add_compile_options("--coverage")

set(LIB_SOURCE_FILES project/src/utils.c)

add_library(utils STATIC ${LIB_SOURCE_FILES})
target_include_directories(utils PUBLIC project/include)

add_executable(HW_1 project/src/main.c)
target_link_libraries(HW_1 utils)

enable_testing()
find_package(GTest REQUIRED)
add_executable(gtests gtests/gtests.cpp)
target_link_libraries(gtests GTest::gtest utils gcov)
