#
# CMake configuration file for C Library Template (Example)
#

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wpedantic -Wall -Werror")
set (CMAKE_C_CLANG_TIDY clang-tidy)

add_executable (clib_example main.c)
target_link_libraries (clib_example LINK_PRIVATE clib_template)

# add 'install' target
install(TARGETS clib_example DESTINATION bin)
