#ifndef MAIN_H
#define MAIN_H
#define BUFFER_SIZE 128
#define ARG_LIMIT 2
#define PATH_LIMIT 24
#define ENV_CP_LIMIT 128

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int _strlen(char *s);
char *str_concat(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strncmp(char *s1, char *s2, int n);
char *_strdup(const char *str);
char **strp_array_dup(char **strarr);
int _putchar(char c);
void _puts(char *str);
void strp_array_free(char **strarr);
void parse_line(char *line, char *envp[]);
void exec_prog(char *path, char *envp[]);
char *get_path(char *envp[]);
char **parse_path(char *path);
void free_parsed_path(char **parsed_path);
char *search_path(char *exec, char *envp[]);
int exec_search(char *path, char *exec);
char *exec_add_dir(char *exec);
#endif
