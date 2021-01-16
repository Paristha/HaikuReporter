# CMakeList.txt : CMake project for HaikuReporter, include source and define
# project specific logic here.
project(HaikuReporter)
#
cmake_minimum_required (VERSION 3.8)
find_package(cpr CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

# Add source to this project's executable.
add_executable (main "main.cpp")

target_link_libraries(main PRIVATE cpr)
target_link_libraries(main PRIVATE nlohmann_json)

# TODO: Add tests and install targets if needed.
