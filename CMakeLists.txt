cmake_minimum_required(VERSION 3.2.0)

project(CursorTrack)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -Wextra")

set(BUILD_SHARED_LIBS OFF)
set(CMAKE_EXE_LINKER_FLAGS "-static")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(Boost_USE_MULTITHREADED ON)

find_package(Boost 1.54.0 COMPONENTS system thread filesystem program_options REQUIRED)
find_package(Threads REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

include_directories("${CursorTrack_SOURCE_DIR}/src")
include_directories(SYSTEM "${CursorTrack_SOURCE_DIR}/include")

file(GLOB_RECURSE SRC_LIST src/*.cpp)
file(GLOB_RECURSE HDR_LIST src/*.h)

message(STATUS "Source directory: ${CursorTrack_SOURCE_DIR}")
message(STATUS "Binary directory: ${CursorTrack_BINARY_DIR}")

add_executable(ctrack ${SRC_LIST} ${HDR_LIST})

target_link_libraries(ctrack ${Boost_LIBRARIES})
target_link_libraries(ctrack ws2_32)
target_link_libraries(ctrack wsock32)
