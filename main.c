#include "main.h"

/**
 * exec_prog- execute given program
 * @path: path given to program
 * @envp: environment variables to use
 *
 * Return: void return
*/
void exec_prog(char *path, char *envp[])
{
	int status;
	pid_t child_pid;
	char *args[] = {"-l", NULL};

	child_pid = fork();
	if (child_pid == -1)
	{
		fprintf(stderr, "FATAL: FORK ERROR\n");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0) /* if child PID is 0 you are the child process*/
	{
		if (execve(path, args, envp) == -1)
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
void parse_line(char *line, char *envp[])
{
	char *path;
	char *command;

	command = strtok(line, " \n\t\r");
	if (!command)
	{
		printf("Error: No command\n");
		return;
	}

	path = search_path(command, envp);

	printf("path: %s\n", path);
	printf("command: %s\n", command);

	if (!path)
	{
		_puts("Error: Command not found\n");
		return;
	}
	exec_prog(path, envp);
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
	char *prompt[] = {"$ ", "($) "};
	int tty; /* 1 if tty 0 if not*/
	size_t len = 0;
	char **envcp;

	if (argc > 1) /* if there are arguments*/
	{
		line = _strdup(argv[1]);
	}

	if (isatty(STDIN_FILENO))
		tty = 1;
	else
		tty = 0;

	printf("%s", prompt[tty]);
	while (getline(&line, &len, stdin) != -1)
	{
		envcp = strp_array_dup(envp);
		parse_line(line, envp);
		_puts(prompt[tty]);
		strp_array_free(envcp);
	}

	free(line);
	exit(EXIT_SUCCESS);
}
