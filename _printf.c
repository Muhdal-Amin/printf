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

	if (!format || (format[0] == '%' && !format[1]))
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
				count += putchar(va_arg(args, int));
				break;
			case 's':
				count += printf("%s", va_arg(args, char *));
				break;
			case '%':
				count += putchar('%');
				break;
			case 'd':
			case 'i':
				count += printf("%d", va_arg(args, int));
				break;
			default:
				putchar('%');
				putchar(*format);
				count += 2;
				break;
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
