#include "main.h"

/**
 * print_int - function that prints integers
 * @args: an argument list
 * Return: returns length of integrs
 */
int print_int(va_list args)
{
	int res = va_arg(args, int);
	int sign = 1, len = 0, countd = 1, digit;
	unsigned int n;

	if (res < 0)
	{
		_putchar('-');
		sign = -1;
	}

	n = sign * res;

	while (n / countd >= 10)
		countd *= 10;

	while (countd > 0)
	{
		digit = n / countd;
		_putchar('0' + digit);
		n %= countd;
		countd /= 10;
		len++;
	}

	return (len + (sign == -1));
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
