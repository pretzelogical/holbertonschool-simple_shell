#include "main.h"

/**
 * _strdup - strdup C function
 * @str: String to duplicate
 *
 * Return: A new copy of the given string
 */
char *_strdup(const char *str)
{
	int i, n = 0;
	char *strcopy;

	if (str == NULL)
		return (NULL);
	do {
		n++;
	} while (str[n - 1]);
	strcopy = malloc(sizeof(char) * n);
	if (strcopy == NULL)
	{
		perror("FATAL: MALLOC FAILED");
		exit (EXIT_FAILURE);
	}
	for (i = 0; i < n; i++)
	{
		strcopy[i] = str[i];
	}
	return (strcopy);
}

/**
 * strp_array_dup- duplicates an array of string pointers
 * @strarr: array of strings
 *
 * Return: a new array of strings
*/
char **strp_array_dup(char **strarr)
{
	int i;
	char **dup;

	dup = malloc(sizeof(char *) * ENV_CP_LIMIT);

	for (i = 0; i < ENV_CP_LIMIT; i++)
	{
		dup[i] = _strdup(strarr[i]);
		if (dup[i] != NULL)
			printf("%s\n", dup[i]);

		/*if (dup[i - 1] == NULL)
		{
			perror("FATAL: MALLOC FAILED");
			exit(EXIT_FAILURE);
		}*/
		if (dup[i] == NULL)
			return (dup);
	}
	return (dup);

}

/**
 * strp_array_free - frees an array of string pointers
 * @strarr: string array to free
 *
 * Return: void return
*/
void strp_array_free(char **strarr)
{
	int i;

	for (i = 0; strarr[i]; i++)
		free(strarr[i]);
	free(strarr);
}


/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts- Prints a string to stdout
 * @str: pointer to char array
 *
 * Return: Always return nothing (void)
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
}
