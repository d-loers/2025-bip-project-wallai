# Minimum CMake version requirement
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(Drivetrain VERSION 1.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the output directory for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add the "include" directory to the list of directories that CMake will search for header files
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add the "libs" directory where CMake can find the external libraries
link_directories(${PROJECT_SOURCE_DIR}/libs)

# Create a list of source files (add more .cpp files as needed)
file(GLOB SOURCES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

# Add your executable target
add_executable(${PROJECT_NAME} ${SOURCES})

add_compile_options(-Wall -Wextra -g)  # Debug flags