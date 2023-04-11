#include "main.h"

char **env_args;

/**
 * exec_prog- execute given program
 * @path: path given to program
 *
 * Return: void return
*/
void exec_prog(char **path)
{
	int status;
	pid_t child_pid;

	printf("%s\n", getenv("PATH"));

	child_pid = fork();
	if (child_pid == -1)
	{
		fprintf(stderr, "FATAL: FORK ERROR\n");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0) /* if child PID is 0 you are the child process*/
	{
		if (execve((const char *)path[0], path, env_args) == -1)
		{
			perror("Execve error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}

/**
 * parse_line- (Currently) takes the first argument as a path to an
 * executable forks itself and runs that executable in the child process
 * and returns
 * (Later) will be able to take multiple arguments and pass them to the
 * program
 * @line: line read in from user
 *
 * Return: Void return
*/
void parse_line(char *line)
{
	char **path;
	char *command;
	int i;


	path = malloc(sizeof(char *) * ARG_LIMIT);
	if (!path)
	{
		fprintf(stderr, "FATAL: MALLOC FAILURE\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < ARG_LIMIT; i++)
	{
		path[i] = malloc(sizeof(char) * BUFFER_SIZE);
		if (path[i] == NULL)
		{
			fprintf(stderr, "FATAL: MALLOC FAILURE\n");
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

	exec_prog(path);

	for (i = 0; i < ARG_LIMIT; i++)
		free(path[i]);

	free(path);

}

/**
 * main- determine if terminal is a tty or not, gets PATH
 * and pass args to parse_line
 *
 * Return: Exit in place of return
*/
int main(int argc, char *argv[], char *envp[])
{
	char *line = NULL;
	const char *prompt[] = {"$ ", "($) "};
	int tty; /* 1 if tty 0 if not*/
	size_t len = 0;

	env_args = envp;

	if (argc > 1) /* if there are arguments*/
	{
		line = strdup(argv[1]);
	}

	if (isatty(STDIN_FILENO))
		tty = 1;
	else
		tty = 0;


	printf("%s", prompt[tty]);
	while (getline(&line, &len, stdin) != -1)
	{
		parse_line(line);
		printf("%s", prompt[tty]);
	}

	exit(EXIT_SUCCESS);
}