cmake_minimum_required(VERSION 3.10)
project(VoxelEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(OpenGL REQUIRED)  # Найти OpenGL
find_package(GLEW REQUIRED)    # Найти GLEW
find_package(glfw3 REQUIRED)    # Найти GLFW
find_package(PNG REQUIRED)      # Найти libpng

include_directories(${OPENGL_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} ${GLFW_INCLUDE_DIRS} ${PNG_INCLUDE_DIRS})

add_subdirectory(src/engine)
add_subdirectory(src/graphics)

add_executable(voxel src/main.cpp)
target_link_libraries(voxel
        engine
        graphics
        ${OPENGL_LIBRARIES}
        ${GLEW_LIBRARIES}
        glfw
        ${PNG_LIBRARIES}
)
