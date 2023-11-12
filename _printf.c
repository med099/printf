#include "main.h"

/**
 * _print - printf function
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
	};

	va_start(args, format);
	sum = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			i = 0;
			while (i < 2)
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
		if (!(*format))
			break;
		_putchar(*format);
		format++;
		sum++;
	}
	va_end(args);

	return (sum);
}
