#include "main.h"

/**
 * get_path- extracts the PATH string from env
 * @env: environment strings
 *
 * Return: pointer to path or NULL if not found
*/
char *get_path(char *env[])
{
	int i;

	for (i = 0; env[i] != NULL; i++)
	{
		if (_strncmp(env[i], "PATH=", 5) == 0)
		{
			return (env[i] + 5);
		}
	}
	return (NULL);
}


/**
 * parse_path- tokenizes seperate paths into a null terminated
 * tokenised array stored in heap using malloc via _strdup
 * @path: path string
 *
 * Return: pointer to tokenised string array
*/
char **parse_path(char *path)
{
	char **out;
	char *pathtmp;
	int i;

	pathtmp = _strdup(path);
	out = malloc(PATH_LIMIT * sizeof(char *));
	if (out == NULL)
	{
		perror("FATAL: MALLOC FAILURE");
		exit(EXIT_FAILURE);
	}
	out[0] = _strdup(strtok(pathtmp, ":"));
	if (out[0] == NULL)
	{
		perror("FATAL: MALLOC FAILURE");
		exit(EXIT_FAILURE);
	}
	for (i = 1; i < PATH_LIMIT && out[i - 1] != NULL; i++)
	{
		out[i] = _strdup(strtok(NULL, ":"));
		/**
		 * if we get to the next one and the last one is NULL
		 * then we know for sure that malloc has failed and we haven't
		 * just reached the end of the PATH string
		*/
		if (out[i - 1] == NULL)
		{
			perror("FATAL: MALLOC FAILURE");
			exit(EXIT_FAILURE);
		}
	}
	free(pathtmp);
	return (out);
}

/**
 * free_parsed_path- frees the memory allocated for the tokenised
 * parsed path
 * @parsed_path: parsed path
 *
 * Return: void return
*/
void free_parsed_path(char **parsed_path)
{
	int i;

	for (i = 0; i < PATH_LIMIT && parsed_path[i] != NULL; i++)
	{
		free(parsed_path[i]);
	}
	free(parsed_path);
}
