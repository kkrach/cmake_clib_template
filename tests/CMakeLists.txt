#
# CMake configuration file for C Library Template (Unit tests)
#

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# requires 'apt install libgtest-dev libgmock-dev'
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wpedantic -Wall -Werror")
# do not use clang-tidy since gtest causes too many errors
unset (CMAKE_CXX_CLANG_TIDY)

# tests answer functions
add_executable(clib_answer_tests answer.cpp)
target_link_libraries (clib_answer_tests PRIVATE clib_template)
target_link_libraries (clib_answer_tests PRIVATE ${GTEST_BOTH_LIBRARIES})
target_link_libraries (clib_answer_tests PRIVATE Threads::Threads)
add_test(NAME answer_tests COMMAND clib_answer_tests)

# tests version functions
add_executable(clib_version_tests version.cpp)
target_link_libraries (clib_version_tests PRIVATE clib_template)
target_link_libraries (clib_version_tests PRIVATE ${GTEST_BOTH_LIBRARIES})
target_link_libraries (clib_version_tests PRIVATE Threads::Threads)
add_test(NAME version_tests COMMAND clib_version_tests)
