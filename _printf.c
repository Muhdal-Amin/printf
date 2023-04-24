#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - custom implementation of printf function
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	if (!format)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'c':
				count += printf("%c", va_arg(args, int));
				break;
			case 's':
				count += printf("%s", va_arg(args, char *));
				break;
			case '%':
				count += printf("%%");
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
