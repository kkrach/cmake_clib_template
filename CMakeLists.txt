# cmake_lib_template

cmake_minimum_required (VERSION 3.17)

project (clib_template)

include (CTest)
list(APPEND CMAKE_CTEST_ARGUMENTS "--output-on-failure")

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory (examples)
add_subdirectory (sources)
add_subdirectory (tests)
