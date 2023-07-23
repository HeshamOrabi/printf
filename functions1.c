#include "main.h"
/**
 * _putchar - a function that prints char
 * @c: an argument
 * Return: returns length bytes
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
