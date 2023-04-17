#include "main.h"

/**
 * search_path- takes a parsed path array and returns the first file
 * in the path that matches the executable.
 * @parsed_path: the parsed path to search
 *
 * Return: the full path of the file, if no file is found, return NULL.
*/
char *search_path(char **parsed_path, char *exec)
{
	int i;

	for (i = 0; i < PATH_LIMIT && parsed_path[i] != NULL; i++)
	{
		if (exec_search(parsed_path[i], exec) == 1)
			return (parsed_path[i]);
	}
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
	char *tmp;

	tmp = _strdup(_strcat(path, exec));

	if (access(tmp, F_OK) == 0)
	{
		printf("File %s exists\n", path);
	}
	else
	{
		free(tmp);
		return (0);
	}

	if (access(tmp, X_OK) == 0)
	{
		free(tmp);
		printf("File %s executable\n", path);
		return (1);
	}

	free(tmp);
	return (0);
}
