# Library

add_library (clibrary_template answer.c version.c)
target_include_directories (clibrary_template PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
