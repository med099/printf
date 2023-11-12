#include "main.h"

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
 * _printf - printf function
 * @format: format
 * Return: lenth of outputs
*/
int _printf(const char *format, ...)
{
	int sum, i;
	va_list args;
	_Form type[] = {
		{'c', print_char},
		{'s', print_str},
		{'%', print_cent},
	};

	va_start(args, format);
	sum = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			i = 0;
			while (i < 3)
			{
				if (*(format + 1) == type[i].valid_type)
				{
					sum += (type[i].f)(args);
					format += 2;
					break;
				}
				i++;
			}
		}
		else
		{
			_putchar(*format);
			i = 0;
			format++;
			sum++;
		}
	}
	va_end(args);

	return (sum);
}
