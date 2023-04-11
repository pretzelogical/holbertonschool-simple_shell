#ifndef MAIN_H
#define MAIN_H
#define BUFFER_SIZE 32
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
void parse_line(char *line);
void exec_prog(char **path);

#endif
