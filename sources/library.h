
#ifndef LIBRARY_H
#define LIBRARY_H

// answer.c
int get_answer();
void set_answer(int value);

// version.c
void print_version();
const char* get_project_name();
const char* get_git_source_version();
const char* get_git_source_date();
const char* get_git_repository();
const char* get_compile_host();
const char* get_compile_date();
const char* get_compile_user();
const char* get_compile_source();
const char* get_compile_dir();

#endif // LIBRARY_H
