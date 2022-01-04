# Tests

# needs 'apt install libgtest-dev'
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# tests answer functions
add_executable(clibrary_answer_tests answer.cpp)
target_link_libraries (clibrary_answer_tests clibrary_template ${GTEST_BOTH_LIBRARIES})
add_test(NAME answer_tests COMMAND clibrary_answer_tests)

# tests version functions
add_executable(clibrary_version_tests version.cpp)
target_link_libraries (clibrary_version_tests clibrary_template ${GTEST_BOTH_LIBRARIES})
add_test(NAME version_tests COMMAND clibrary_version_tests)
