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
