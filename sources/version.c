/**
 * @file version.c
 *
 * @brief Git versioning
 *
 * @author Karl Krach
 *
 * @copyright Copyright 2021 Karl Krach
 * @license{This file is licensed under the MIT license.}
 *
 */

#include "library.h"
#include "version.h"
#include <stdio.h>


/** Print all version information to stdout */
void clib_print_version()
{
	printf("%s %s (%s)\n", clib_get_project_name(), clib_get_git_source_version(), clib_get_git_source_date());
	printf("Repository: %s\n", clib_get_git_repository());
	printf("\n");
	printf("Built by %s@%s (%s)\n", clib_get_compile_user(), clib_get_compile_host(), clib_get_compile_date());
	printf("\n");
}

/** Returns the project name, e.g. "clib_template" */
const char* clib_get_project_name()
{
	return PROJECT_NAME;
}

/** Returns the source version from git, e.g. "78c11e5-dirty" */
const char* clib_get_git_source_version()
{
	return GIT_SOURCE_VERSION;
}

/** Returns the date of the last commit, e.g. "2022-01-04 22:03:19 +0100" */
const char* clib_get_git_source_date()
{
	return GIT_SOURCE_DATE;
}

/** Returns the git repository, e.g. "git@github.com:kkrach/cmake_clib_template.git" */
const char* clib_get_git_repository()
{
	return GIT_REPOSITORY;
}

/** Regurns the device, on which the sources were compiled, e.g. "XPS-17-9700" */
const char* clib_get_compile_host()
{
	return COMPILE_HOST;
}

/** Returns the date/time when the sources were compiled, e.g. "2022-01-05 15:27:15 +0100" */
const char* clib_get_compile_date()
{
	return COMPILE_DATE;
}

/** Returns the user which has compiled the sources, "charly" */
const char* clib_get_compile_user()
{
	return COMPILE_USER;
}

/** Returns the directory of the sources, e.g. "/home/charly/Projects/cmake_clib_template" */
const char* clib_get_compile_source()
{
	return COMPILE_SOURCE;
}

/** Returns the directory where the sources have been compiled, e.g. "/home/charly/Projects/cmake_clib_template/build" */
const char* clib_get_compile_dir()
{
	return COMPILE_DIR;
}
