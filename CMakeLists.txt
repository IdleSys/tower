cmake_minimum_required(VERSION 3.14)

project(game C)
set(CMAKE_C_STANDARD 99)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(RAYLIB_PATH "${CMAKE_SOURCE_DIR}/external/raylib")

if(NOT EXISTS "${RAYLIB_PATH}/CMakeLists.txt")
  message(
    FATAL_ERROR "Raylib not found in ${RAYLIB_PATH}. Please clone it manually!")
endif()

# Add Raylib directory
add_subdirectory(${RAYLIB_PATH} raylib_build)
# Define the executable
add_executable(${PROJECT_NAME} game.c utils/movement.c utils/enemies.c)
# Link Raylib to the executable
target_link_libraries(${PROJECT_NAME} raylib)

# Set output directory
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                                 ${CMAKE_BINARY_DIR}/bin)

message(STATUS "Build setup complete!")
