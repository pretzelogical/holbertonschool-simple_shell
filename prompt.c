#include "main.h"

/**
 * check_tty - checks if input is a tty
 * @stream: input
 *
 * Return: 1 if tty, 0 if not
*/
int check_tty(const int stream)
{
	if (isatty(stream))
		return (1);
	else
		return (0);
}
