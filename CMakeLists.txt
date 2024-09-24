cmake_minimum_required(VERSION 3.29)
project(LandGameDemo)

set(CMAKE_CXX_STANDARD 20)

# Specify the directories where the include files are located
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/include/CardTypes)

# Collect all source files in the /src directory
file(GLOB SOURCES
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/CardTypes/*.cpp")

# Add the executable target, using the collected source files
add_executable(LandGameDemo main.cpp ${SOURCES})