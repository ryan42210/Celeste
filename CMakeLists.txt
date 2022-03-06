cmake_minimum_required(VERSION 3.20)

project(Celeste LANGUAGES CXX)


set(CAMEK_CXX_STANDARD 17)
set(CAMEK_CXX_STANDARD_REQUIRED ON)


find_package(glfw3 CONFIG REQUIRED)
find_package(GLEW CONFIG REQUIRED)
find_package(OpenVDB CONFIG REQUIRED)
find_package(OpenMP REQUIRED)

add_subdirectory(src)