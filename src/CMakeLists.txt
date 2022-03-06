project(Celeste-main)

file(GLOB SRC_FILES "*.cpp")
add_executable(${PROJECT_NAME} ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/libs )

target_link_libraries(${PROJECT_NAME} PRIVATE glfw GLEW::GLEW OpenVDB::openvdb OpenMP::OpenMP_CXX)