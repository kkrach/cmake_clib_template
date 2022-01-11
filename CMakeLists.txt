#
# CMake configuration file for C Library Template
#

cmake_minimum_required (VERSION 3.17)

project (clib_template)

include (CTest)
list(APPEND CMAKE_CTEST_ARGUMENTS "--output-on-failure")

# use -std=c11 and -std=c++14
set (CMAKE_C_STANDARD 11)
set (CMAKE_CXX_STANDARD 14)
# disables https://gcc.gnu.org/onlinedocs/gcc/C-Extensions.html
set (CMAKE_C_EXTENSIONS OFF)
set (CMAKE_CXX_EXTENSIONS OFF)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory (examples)
add_subdirectory (sources)
add_subdirectory (tests)
