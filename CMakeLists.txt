# CMakeList.txt : CMake project for HaikuReporter, include source and define
# project specific logic here.
# TODO: Add tests and install targets if needed.
project(HaikuReporter)
#
cmake_minimum_required (VERSION 3.8)
find_package(nlohmann_json CONFIG REQUIRED)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/whoshuu/cpr.git)
FetchContent_MakeAvailable(cpr)

# Add source to this project's executable.
add_executable (main "main.cpp")

target_link_libraries(main PRIVATE cpr)
target_link_libraries(main PRIVATE nlohmann_json)
