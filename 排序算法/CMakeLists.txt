cmake_minimum_required(VERSION 3.5)

project(sort_algorithm)

find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME} 
  src/main.cpp 
)
add_executable(test 
  src/test.cpp 
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
  Threads::Threads
)
target_include_directories(${PROJECT_NAME}
  PRIVATE
  ${PROJECT_SOURCE_DIR}/include
)
