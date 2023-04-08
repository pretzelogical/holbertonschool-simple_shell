#include "main.h"
#define BUFFER_SIZE 32
#define ARG_LIMIT 2


/**
 * exec_prog- (Currently) takes the first argument as a path to an
 * executable forks itself and runs that executable in the child process
 * and returns
 * (Later) will be able to take multiple arguments and pass them to the
 * program
 * @line: line read in from user
 *
 * Return: Void return
*/
void exec_prog(char *line)
{
	int status;
	pid_t child_pid;
	char **path;
	char *command;
	int i;
	char *env_args[] = {"PATH=/", NULL};

	path = malloc(sizeof(char *) * ARG_LIMIT);
	if (!path)
	{
		printf("FATAL: MALLOC FAILURE\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < ARG_LIMIT; i++)
	{
		path[i] = malloc(sizeof(char) * BUFFER_SIZE);
		if (path[i] == NULL)
		{
			printf("FATAL: MALLOC FAILURE\n");
			exit(EXIT_FAILURE);
		}
	}
	command = strtok(line, " \n\t\r");
	if (!command)
	{
		printf("Error: No command\n");
		return;
	}
	path[0] = strdup(command);
	path[1] = NULL;

	child_pid = fork();
	if (child_pid == -1)
	{
		printf("FATAL: FORK ERROR\n");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0) /* if child PID is 0 you are the child process*/
	{
		if (execve((const char *)path[0], path, env_args) == -1)
		{
			perror("Execv error:");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}

	for (i = 0; i < ARG_LIMIT; i++)
		free(path[i]);

	free(path);

}

/**
 * main- determine if terminal is a tty or not and pass args to
 * exec_prog
 *
 * Return: Exit in place of return
*/
int main(void)
{
	char *line = NULL;
	const char *prompt[] = {"$ ", "($) "};
	int tty; /* 1 if tty 0 if not*/
	size_t len = 0;

	if (isatty(STDIN_FILENO))
		tty = 1;
	else
		tty = 0;


	printf("%s", prompt[tty]);
	while (getline(&line, &len, stdin) != -1)
	{
		exec_prog(line);
		printf("%s", prompt[tty]);
	}

	exit(EXIT_SUCCESS);
}
