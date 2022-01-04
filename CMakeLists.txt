cmake_minimum_required (VERSION 2.8.11)
project (clibrary_template)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include (CTest)

add_subdirectory (examples)
add_subdirectory (sources)
add_subdirectory (tests)
