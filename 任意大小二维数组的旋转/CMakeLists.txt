cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)
project(rotate_array2D)

# find_package(Eigen3)
# include_directories(${EIGEN3_INCLUDE_DIR})

add_executable(${PROJECT_NAME} src/main.cpp)
target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)



