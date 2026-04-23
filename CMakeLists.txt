cmake_minimum_required(VERSION 3.14)
project(Spaceship_Systems_Manager)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)

set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_BUILD_TYPE DEBUG)

include_directories(${INCLUDE_DIR})

add_executable(ClassProject ${SOURCE_DIR}/main.cpp)

target_include_directories(ClassProject PUBLIC ${INCLUDE_DIR})

##### NEW FOR TESTS #####
set(TESTS_DIR ${CMAKE_SOURCE_DIR}/tests)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()

add_executable(ProjectTests ${TESTS_DIR}/project_tests.cpp)

target_include_directories(ProjectTests PUBLIC ${SOURCE_DIR})

target_link_libraries(ProjectTests GTest::GTest GTest::Main)