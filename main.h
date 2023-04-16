#ifndef MAIN_H
#define MAIN_H
#define BUFFER_SIZE 128
#define ARG_LIMIT 2

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int _strlen(char *s);
char *_strdup(char *str);
int _strncmp(char *s1, char *s2, int n);
void parse_line(char *line);
void exec_prog(char **path);
char *get_path(char *env[]);
char **parse_path(char *path);
void free_parsed_path(char **parsed_path);
char *search_path(char **parsed_path, char *command);
#endif
