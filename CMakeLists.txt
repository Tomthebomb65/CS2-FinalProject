cmake_minimum_required(VERSION 3.14)
project(Spaceship_Systems_Manager)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Directories
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(SOURCE_DIR  ${CMAKE_SOURCE_DIR}/src)
set(TESTS_DIR   ${CMAKE_SOURCE_DIR}/tests)

set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_BUILD_TYPE DEBUG)

include_directories(${INCLUDE_DIR})

# Source files
set(SOURCES
    ${SOURCE_DIR}/alerts.cpp
    ${SOURCE_DIR}/alerts_list.cpp
    ${SOURCE_DIR}/ship_systems.cpp
    ${SOURCE_DIR}/crew_members.cpp
    ${SOURCE_DIR}/bst.cpp
)

##### TESTS #####
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()

add_executable(ProjectTests
    ${TESTS_DIR}/project_tests.cpp
    ${SOURCES}
)

target_include_directories(ProjectTests PUBLIC
    ${INCLUDE_DIR}
    ${SOURCE_DIR}
)

target_link_libraries(ProjectTests
    GTest::GTest
    GTest::Main
)