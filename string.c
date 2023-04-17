#include "main.h"

/**
 * _strlen- returns the length of a string
 * @s: string to check length of
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
 * _strncmp- compare two strings up to n
 * @s1: first string
 * @s2: second string
 * @n: location to compare to
 *
 * Return: 0 if equal, >0 if first non matching
 * character is greater (in ascii), <0 if less
*/
int _strncmp(char *s1, char *s2, int n)
{
	int i, s1len, s2len;

	for (i = 0; i < n; i++)
		{
		if (*(s1 + i) != *(s2 + i))
			{
			return (*(s1 + i) - *(s2 + i));
			}
		}
	return (0);
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
	l = _strlen(str);
	out = malloc(l * sizeof(char));
	if (out == NULL)
		return (NULL);
	for (i = 0; i < l; i++)
		out[i] = str[i];
	return (out);
}

/**
 * _strcat- concatenates two strings
 * @dest: string to append to
 * @src: string to append
 *
 * Return: Always return a pointer to the resulting
 * string dest
*/
char *_strcat(char *dest, char *src)
{
	int i, srclen, destlen;

	srclen = _strlen(src);
	destlen = _strlen(dest);
	i = destlen;
	/* starts at nullbyte of dest*/
	while (i <= destlen + srclen)
		{
		*(dest + i) = *(src + (i - destlen));
		i++;
		}
	*(dest + i) = '\0';

	return (dest);
}
