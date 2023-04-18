#include "main.h"

/**
 * get_path- extracts the PATH string from env
 * @envp: environment strings
 *
 * Return: pointer to path or NULL if not found
*/
char *get_path(char *envp[])
{
	int i;

	for (i = 0; envp[i] != NULL; i++)
	{
		if (_strncmp(envp[i], "PATH=", 5) == 0)
		{
			return (envp[i]);
		}
	}
	return (NULL);
}

/**
 * exec_add_dir- formats the exec string so that it can be used to search
 * for the executable
 * @exec: the string to format
 *
 * Return: character pointer to string
*/
char *exec_add_dir(char *exec)
{
	char *out;

	if (exec[0] != '/')
	{
		out = str_concat("/", exec);
		return (out);
	}
	else
	{
		out = _strdup(exec);
		return (out);
	}
}

/**
 * search_path- takes a parsed path array and returns the first file
 * in the path that matches the executable.
 * @exec: the executable to search for
 * @envp: environment strings
 *
 * Return: the full path of the file, if no file is found, return NULL.
*/
char *search_path(char *exec, char *envp[])
{
	int i;
	char *execTmp;
	char *pathTmpStart;
	char *pathTmp;
	char *parsed[PATH_LIMIT];
	char *out;

	execTmp = exec_add_dir(exec);
	pathTmpStart = _strdup(get_path(envp));
	pathTmp = pathTmpStart + 5;

	parsed[0] = strtok(pathTmp, ":");
	i = 1;
	while ((parsed[i] = strtok(NULL, ":")) != NULL)
		i++;

	for (i = 0; parsed[i + 1] != NULL; i++)
	{
		if (exec_search(parsed[i], execTmp) == 1)
		{
			out = str_concat(parsed[i], execTmp);
			free(execTmp);
			free(pathTmpStart);
			return (out);
		}
	}
	free(execTmp);
	free(pathTmpStart);

	return (NULL);
}

/**
 * exec_search- searches for the executable in the path given
 * @path: the path to search
 * @exec: the executable to search for
 *
 * Return: 1 if the executable is found, 0 otherwise.
*/
int exec_search(char *path, char *exec)
{
	char *fullPath;

	fullPath = str_concat(path, exec);

	if (access(fullPath, F_OK) != 0)
	{
		free(fullPath);
		return (0);
	}

	if (access(fullPath, X_OK) == 0)
	{
		free(fullPath);
		return (1);
	}

	free(fullPath);
	return (0);
}


