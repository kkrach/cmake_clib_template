/**
 * @file library.h
 *
 * @brief Library header
 *
 * @author Karl Krach
 *
 * @copyright Copyright 2021 Karl Krach
 * @license{This file is licensed under the MIT license.}
 *
 */

#ifndef LIBRARY_H
#define LIBRARY_H

// answer.c
int clib_get_answer();
void clib_set_answer(int value);

// version.c
void clib_print_version();
const char* clib_get_project_name();
const char* clib_get_git_source_version();
const char* clib_get_git_source_date();
const char* clib_get_git_repository();
const char* clib_get_compile_host();
const char* clib_get_compile_date();
const char* clib_get_compile_user();
const char* clib_get_compile_source();
const char* clib_get_compile_dir();

#endif // LIBRARY_H
