#include "main.h"

/**
 * env_bi - prints current environment
 * @env: environment pointers
 * Return: Always 0
 */

void env_bi(char **env)
{
	int i;

	for (i = 0; env[i] != NULL; i++)
	{
		printf("%s\n", env[i]);
	}
}
