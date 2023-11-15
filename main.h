#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * struct Form - the valide form
 * @valid_type: type
 * @f: pointer to function
*/
typedef struct Form
{
	char valid_type;
	int (*f)();
} _Form;

int _printf(const char *format, ...);
int print_char(va_list c);
int print_str(va_list s);
char *check_str(char *str, int *len);
int _strlen(char *str);
int _putchar(char c);
void _puts(char *str);
int print_cent(void);
int print_int(va_list i);

#endif
