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

extern char **env_args;

void parse_line(char *line);
void exec_prog(char **path);


#endif
