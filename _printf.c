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

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'c':
				count += printf(va_arg(args, int));
				break;
			case 's':
				count += printf("%s", va_arg(args, char *));
				break;
			case '%':
				count += printf('%');
				break;
			default:
				printf('%');
				printf(*format);
				count += 2;
				break;
			}
		}
		else
		{
			printf(*format);
			count++;
		}
		format++;
	}

	va_end(args);

	return (count);
}
