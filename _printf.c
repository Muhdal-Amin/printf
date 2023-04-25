#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string with directives for formatting output
 * Return: number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (!format)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			if (*format == '%')
				count += putchar('%');
			else if (*format == 'c')
				count += putchar(va_arg(args, int));
			else if (*format == 's')
				count += printf("%s", va_arg(args, char *));
			else if (*format == 'd' || *format == 'i')
				count += printf("%d", va_arg(args, int));
			else
				count += printf("%%%c", *format);
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
