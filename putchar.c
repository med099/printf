#include <unistd.h>
#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: 1
 */
int _putchar(char c)
{
	static int l;
	static char buffer[1024];

	if (c != -1)
	{
		buffer[l] = c;
		l++;
	}
	if (c == -1 || l >= 1024)
	{
		write(1, &buffer, l);
		l = 0;
	}
	return (1);
}
