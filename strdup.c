#include "main.h"

/**
 * _strlen- returns the length of a string
 * @s: string to check lenght of
 *
 * Return: Always return length of string
 */
int _strlen(char *s)
{
int l;

l = 0;
while (*s != '\0')
	{
		s++;
		l++;
	}

return (l);
}

/**
 * _strdup- returns a pointer to a newly allocated
 * space in memory which contains copy of str
 * @str: string to copy
 *
 * Return: Pointer to copied string, unless fail in
 * which case return null
*/
char *_strdup(char *str)
{
	int i, l;
	char *out;

	if (str == NULL)
		return (NULL);
	l = _strlen(str) + 1;
	out = malloc(l  *sizeof(char));
	if (out == NULL)
		return (NULL);
	for (i = 0; i < l; i++)
		out[i] = str[i];
	return (out);
}
