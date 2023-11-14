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
	int sum = 0, i;
	va_list args;
	_Form type[] = {{'c', print_char}, {'s', print_str}, {'%', print_cent},
	{'d', print_int}, {'i', print_int},};

	va_start(args, format);
	if (format == NULL || (*format == '%' && *(format + 1) == '\0'))
		return (-1);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			while (*(format + 1) == ' ')
				format++;
			if (*(format + 1) == '\0')
				return (-1);
			for (i = 0; i < 5; i++)
			{
				if (*(format + 1) == type[i].valid_type)
				{
					sum += (type[i].f)(args);
					format += 2;
					break;
				}
			}
			if (i == 5)
			{
				sum += print_cent();
				format++;
			}
		}
		else
		{
			_putchar(*format++);
			sum++;
		}
	}
	_putchar(-1);
	va_end(args);
	return (sum);
}
