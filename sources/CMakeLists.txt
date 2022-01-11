#
# CMake configuration file for C Library Template (Library)
#

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wpedantic -Wall -Werror")
set (CMAKE_C_CLANG_TIDY clang-tidy)

add_library (clib_template answer.c version.c)
target_include_directories (clib_template PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# automated version generation
include(../cmake/version.cmake)
ADD_DEPENDENCIES(clib_template version)

# add 'install' target
install(TARGETS clib_template DESTINATION lib)
