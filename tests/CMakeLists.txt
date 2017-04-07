cmake_minimum_required(VERSION 2.8)

#----------------------------------------
# compile | assemble | link
#----------------------------------------
include_directories("${CMAKE_SOURCE_DIR}/src"
                    "${CMAKE_SOURCE_DIR}/src/saveArg/"
                    "${CMAKE_SOURCE_DIR}/src/invoke/")

file(GLOB_RECURSE SRC_LIST "*.cpp")
# aux_source_directory(. SRC_LIST)
#file(GLOB_RECURSE HEADERS_LIST "*.hpp")

#----------------------------------------
# set gtest library
#----------------------------------------
#link_libraries(gtest)

add_executable(Test ${SRC_LIST})
target_link_libraries(Test -Wl,--start-group saveArg invoke -Wl,--end-group gtest gmock pthread)

message("SRC_LIST is ${SRC_LIST}")
message("HEADERS_LIST is ${HEADERS_LIST}")
