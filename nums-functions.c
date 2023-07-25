#include "main.h"

/**
 * print_int - function that prints integers
 * @args: an argument list
 * Return: returns length of integrs
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);
	int div = 1, i = 0, x = 0;
	unsigned int num;

	if (n < 0)
	{
		_putchar('-');
		num = -n;
		i += 1;
	}
	else
		num = n;
	for (; num / div >= 10; x++)
		div *= 10;
	for (; div != 0; i++)
	{
		_putchar((num / div)  + '0');
		num %= div;
		div /= 10;
	}
	return (i);
}

/**
 * print_b - function that prints binary
 * @args: an argument list
 * Return: returns length of integrs
*/
int print_b(va_list args)
{
	int i, arr[32], len = 0;
	unsigned int n;

	n = va_arg(args, unsigned int);

	for (i = 0; n > 0; i++)
	{
		arr[i] = n % 2;
		n = n / 2;
		len++;
	}

	for (i = i - 1; i >= 0; i--)
	{
		_putchar(arr[i] + '0');
	}

	if (len == 0)
	{
		len++;
		_putchar('0');
	}

	return (len);
}
/**
 * print_p - a function that prints address
 * @args: an argument list
 * Return: returns length of the address
 */
int print_p(va_list args)
{
	unsigned long int n;
	char buffer[50];
	char *s, *array = "0123456789abcdef";
	int len;

	n = va_arg(args, unsigned long int);

	if (n == 0)
		return (write(1, "(nil)", 5));

	s = &buffer[49];
	*s = '\0';

	while (n != 0)
	{
		*--s = array[n % 16];
		n /= 16;
	}
	*--s = 'x';
	*--s = '0';

	for (len = 0; *s; len++)
		_putchar(*s++);

	return (len);
}
