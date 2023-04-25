#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - custom implementation of printf function
 * @format: format string
 *
 * Return: number of characters printed or -1 if an error occurs
 */

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

	if (!format)
		return (-1);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'd':
			case 'i':
				count += printf("%d", va_arg(args, int));
				break;
			default:
				return (-1);
			}
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
