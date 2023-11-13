#include "main.h"

/**
 * check_str - check string if is NULL
 * @str: string to check it
 * @len: lenth of string
 * Return: string or "(nil)" if string is NULL
*/
char *check_str(char *str, int *len)
{
	if (str)
	{
		*len = _strlen(str);
		return (str);
	}
	*len = 6;
	return ("(null)");
}

/**
 * _strlen - fucntion return length of string
 * @str: string
 * Return: length of string
*/
int _strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/**
 * _puts - Function that print a string
 * @str: string to print it
 */

void _puts(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * print_char - print char
 * @c: argument from _printf
 * Return: 1
*/
int print_char(va_list c)
{
	_putchar(va_arg(c, int));
	return (1);
}

/**
 * print_str - print string
 * @s: argument from _printf
 * Return: length of string
*/
int print_str(va_list s)
{
    char *str;
    int len;
    char buffer[1024];

    str = va_arg(s, char*);
    str = check_str(str, &len);
    strncpy(buffer, str, 1024);
    _puts(buffer);
    return (len);
}
