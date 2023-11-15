#include "main.h"

/**
 * _putnbr- function that print thr number and git her length
 * @n: number to print it
 * @len: counter to her lentgth
*/
void _putnbr(int n, int *len)
{
	if (n == -2147483648)
	{
		_putchar('-');
		_putchar('2');
		(*len) += 2;
		_putnbr(147483648, len);
	}
	else if (n < 0)
	{
		_putchar('-');
		(*len)++;
		n = -n;
		_putnbr(n, len);
	}
	else if (n > 9)
	{
		_putnbr(n / 10, len);
		_putnbr(n % 10, len);
	}
	else
	{
		_putchar(n + '0');
		(*len)++;
	}
}

/**
 * print_int - Function to get number an pass it
 *  to _putnbr function
 * @i: the passed number
 * Return: length of number
 */
int print_int(va_list i)
{
	int j, len;

	len = 0;
	j = va_arg(i, int);
	_putnbr(j, &len);
	return (len);
}

/**
 * print_cent - print cent
 * Return: 1
*/
int print_cent(void)
{
	_putchar('%');
	return (1);
}

/**
 * to_binary - function that converted unsigned int
 * to binary
 * @n: number
 * @len: len of the binary
*/
void to_binary(unsigned int n, int *len)
{
	if (!n)
		return;
	(*len)++;
	to_binary(n / 2, len);
	putchar(48 + (n % 2));
}

/**
 * print_b - function that do conversion specifiers
 * @b: number
 * Return: length of binary printed
*/
int print_b(va_list b)
{
	int len;
	unsigned int n;

	len = 0;
	to_binary((va_arg(b, int)), &len);
	return (len);
}
