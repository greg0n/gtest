cmake_minimum_required(VERSION 2.8)

#----------------------------------------
# compile | assemble | link
#----------------------------------------
include_directories("${CMAKE_SOURCE_DIR}/src"
                    "${CMAKE_SOURCE_DIR}/src/saveArg/"
                    "${CMAKE_SOURCE_DIR}/srd/invoke/")

add_library(saveArg ./saveArg/saveArg.cpp)
add_library(invoke ./invoke/invoke.cpp)

file(GLOB_RECURSE SRC_LIST "*.cpp")
# add_library(asteroids ${SRC_LIST})
#file(GLOB_RECURSE HEADERS_LIST "*.hpp")

add_executable(${PROJECT_NAME}-main main.cpp)
target_link_libraries(${PROJECT_NAME}-main -Wl,--start-group saveArg invoke -Wl,--end-group)
# target_link_libraries(${PROJECT_NAME}-main asteroids)
