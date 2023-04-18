#include "main.h"

/**
 * exec_prog- execute given program
 * @path: path given to program
 * @args: arguments to pass to program
 * @envp: environment variables to use
 *
 * Return: void return
*/
void exec_prog(char *path, char **args, char *envp[])
{
	int status;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("FATAL: FORK ERROR");
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
 * check_builtins- check if command is a built in and if so run it
 * @args: arguments to check
 * @envp: environment variables to use
 *
 * Return: 2 if need to exit, 1 if builtin was run, 0 otherwise
*/
int check_builtins(char **args, char *envp[])
{
	if (_strncmp(args[0], "exit", 4) == 0)
	{
		return (2);
	}
	if (_strncmp(args[0], "env", 3) == 0)
	{
		env_bi(envp);
		return (1);
	}
	return (0);
}

/**
 * get_args- get arguments from line
 * @line: line read in from user
 *
 * Return: array of arguments
*/
char **get_args(char *line)
{
	char **args;
	int i;

	args = malloc(sizeof(char *) * ARG_LIMIT);
	if (!args)
	{
		perror("FATAL: MALLOC ERROR");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < ARG_LIMIT; i++)
	{
		if (i == 0)
			args[i] = strtok(line, " \n\t\r");
		else
			args[i] = strtok(NULL, " \n\t\r");
	}
	if (!args)
	{
		_puts("Error: No command\n");
		return (NULL);
	}
	return (args);
}

/**
 * parse_line- (Currently) takes the first argument as a path to an
 * executable forks itself and runs that executable in the child process
 * and returns
 * (Later) will be able to take multiple arguments and pass them to the
 * program
 * @line: line read in from user
 * @envp: environment variables to use
 *
 * Return: 1 if program is to exit, 0 otherwise
*/
int parse_line(char *line, char *envp[])
{
	char *path;
	char *linetmp;
	char **args;

	linetmp = _strdup(line);
	args = get_args(linetmp);
	if (!args)
	{
		free(linetmp);
		return (0);
	}
	if (check_builtins(args, envp) == 2)
	{
		free(args);
		free(linetmp);
		return (1);
	}
	else if (check_builtins(args, envp) == 1)
	{
		free(args);
		free(linetmp);
		return (0);
	}
	path = search_path(args[0], envp);
	if (!path)
	{
		_puts("Error: Command not found\n");
		return (0);
	}
	exec_prog(path, args, envp);

	free(args);
	free(linetmp);
	free(path);
	return (0);
}


/**
 * main- determine if terminal is a tty or not, gets PATH
 * and pass args to parse_line
 * @argc: number of arguments
 * @argv: arguments
 * @envp: environment variables
 *
 * Return: Exit in place of return
*/
int main(int argc, char *argv[], char *envp[])
{
	char *line = NULL;
	char *prompt = "($) ";
	int tty; /* 1 if tty 0 if not*/
	size_t len = 0;
	char **envcp;

	if (argc > 1) /* if there are arguments*/
	{
		line = _strdup(argv[1]);
	}

	tty = check_tty(STDIN_FILENO);
	if (tty == 1)
		_puts(prompt);
	while (getline(&line, &len, stdin) != -1)
	{
		if (line[0] == '\n' || line[0] == '\0' || line[0] == ' ')
		{
			if (tty == 1)
			{
				_puts(prompt);
				_puts("Error: No command\n");
			}
			continue;
		}
		envcp = strp_array_dup(envp);
		if (parse_line(line, envcp) == 1)
		{
			strp_array_free(envcp);
			break;
		}
		if (tty == 1)
			_puts(prompt);
		strp_array_free(envcp);
	}

	free(line);
	exit(EXIT_SUCCESS);
}
