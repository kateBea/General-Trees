cmake_minimum_required(VERSION 3.18)

project(TestGenTree)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(./src)

add_executable(${PROJECT_NAME} test/main.cc)