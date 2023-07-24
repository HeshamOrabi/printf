#include "main.h"

/**
 * _putchar - a function that prints char
 * @c: char argument
 * Return: returns length bytes
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - a function that prints char
 * @args: an argument list
 * Return: returns 1 as length of one char
 */
int print_char(va_list args)
{
	char chr;

	chr = va_arg(args, int);
	_putchar(chr);
	return (1);
}

/**
 * print_str - function to print a str
 * @args: an argument list
 * Return: length of str
*/
int print_str(va_list args)
{
	int i;
	char *str;

	str = va_arg(args, char *);
	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	return (i);
}

/**
 * print_percent - print % to stdout
 * Return: 1
*/
int print_percent(void)
{
	_putchar('%');
	return (1);
}

/**
 * print_int = prints integer number
 *
