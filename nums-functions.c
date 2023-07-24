#include "main.h"
/**
 * int_to_char - function that convert integer
 * to string
 * @num: an integer numer
 * Return: returns pointer to string
 */

char *int_to_char(int num)
{
	int i = 0;
	int is_negative = 0, digit, j;
	char tempd;
	char *str = (char *) malloc(sizeof(char));

	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}
	do {
		digit = num % 10;
		str[i++] = digit + '0';
		num /= 10;
	} while (num > 0);

	if (is_negative)
	{
		str[i++] = '-';
	}

	for (j = 0; j < i / 2; j++)
	{
		tempd = str[j];
		str[j] = str[i - j - 1];
		str[i - j - 1] = tempd;
	}

	str[i] = '\0';

	return (str);
}

/**
 * print_int - function that prints integers
 * @args: an argument list
 * Return: returns length of integrs
 */

int print_int(va_list args)
{
	int num, i;
	char *s;

	num = va_arg(args, int);

	s = int_to_char(num);

	for (i = 0; s[i] != '\0'; i++)
		_putchar(s[i]);

	return (i);
}
