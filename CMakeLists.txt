cmake_minimum_required(VERSION 3.25.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Sand VERSION 0.1)

add_definitions(-DDEBUG)

add_executable(${PROJECT_NAME}
src/main/main.cpp src/main/game.cpp 
src/world/world.cpp
src/core/window/window.cpp src/core/input/input.cpp
src/core/renderer/sdl_renderer.cpp)

find_package(SDL2 REQUIRED)

target_include_directories(${PROJECT_NAME} PUBLIC src PUBLIC .
PUBLIC ${SDL2_INCLUDE_DIRS} )

target_link_libraries(${PROJECT_NAME} PUBLIC SDL2::SDL2)
if (WIN32)
target_link_libraries(${PROJECT_NAME} PUBLIC SDL2::SDL2main)
endif()