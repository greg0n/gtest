#----------------------------------------
# set project name
#----------------------------------------
cmake_minimum_required(VERSION 2.8)
get_filename_component(PROJECT_NAME_STR ${CMAKE_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${PROJECT_NAME_STR})
project(${ProjectId})

#----------------------------------------
# set compiler
#----------------------------------------
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    add_definitions(-std=c++1z)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    add_definitions(-D_SCL_SECURE_NO_WARNINGS)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -g -std=c++1z -O3") #-D_GLIBCXX_USE_CXX11_ABI=0 -Wabi-tag
endif()

#----------------------------------------
# set debug flags
#----------------------------------------
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wa,-adhln -fverbose-asm -O0 -march=native")

#----------------------------------------
# set boost library
#----------------------------------------
find_package(Boost 1.50)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

#----------------------------------------
# add subdirectory
#----------------------------------------
add_subdirectory(src)
add_subdirectory(tests)

#----------------------------------------
# enable test
#----------------------------------------
enable_testing()
add_test(NAME MyTest COMMAND Test)

#----------------------------------------
# message
#----------------------------------------
message("CMAKE_CXX_FLAGS_DEBUG is ${CMAKE_CXX_FLAGS_DEBUG}")
message("CMAKE_CXX_FLAGS is ${CMAKE_CXX_FLAGS}")
message("CMAKE_CXX_COMPILER_ID is ${CMAKE_CXX_COMPILER_ID}")
