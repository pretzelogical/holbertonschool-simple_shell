#include "main.h"
#define PATH_LIMIT 24
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
			return(env[i] + 5);
		}
	}
	return (NULL);
}


/**
 * parse_path- tokenizes seperate paths into a tokenised array
 * @path: path string
 *
 * Return: pointer to tokenised string array
*/
char *parse_path(char *path)
{
	char *out[];


}