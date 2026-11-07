cmake_minimum_required(VERSION 3.16)
project(physics_engine CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3)

add_executable(Physics
  src/main.cpp
  src/physics/rigidBody/rigidBody.h 
  src/physics/rigidBody/rigidBody.cpp 
  src/renderer/render.h 
  src/renderer/render.cpp
  src/clock/clock.h 
  src/clock/clock.cpp
)

target_include_directories(Physics PRIVATE src)

target_link_libraries(Physics PRIVATE SDL3::SDL3)
