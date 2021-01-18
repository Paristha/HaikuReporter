# CMakeList.txt : CMake project for HaikuReporter, include source and define
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
# option(BUILD_CPR_TESTS "BUILD_CPR_TESTS" OFF)
# option(CMAKE_USE_WINSSL "CMAKE_USE_WINSSL" ON)
# option(USE_WINSSL "USE_WINSSL" ON)
# option(CMAKE_USE_OPENSSL "CMAKE_USE_OPENSSL" OFF)
# option(USE_OPENSSL "USE_OPENSSL" OFF)
# project specific logic here.
# TODO: Add tests and install targets if needed.
project(HaikuReporter)
#
cmake_minimum_required (VERSION 3.11)

include(FetchContent)

FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/whoshuu/cpr)
FetchContent_MakeAvailable(cpr)

FetchContent_Declare(json GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent)

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
  FetchContent_Populate(json)
  add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

# Add source to this project's executable.
add_executable (main "main.cpp")

target_link_libraries(main PRIVATE cpr::cpr)
target_link_libraries(main PRIVATE nlohmann_json::nlohmann_json)
