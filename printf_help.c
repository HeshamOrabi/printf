#include "main.h"

/**
 * modifiedPutChar - a function that prints buffer
 * @buffer: Array of chars
 * @specifier: Index at which to add next char, represents the length.
 */
void modifiedPutChar(char buffer[], int *specifier)
{
	if (*specifier > 0)
		write(1, &buffer[0], *specifier);

	*specifier = 0;
}


/**
 * handelPrint - Prints conv argument
 * @format: input str.
 * @index: i of the printf.
 * @args: List of arguments to be printed.
 * Return: lenght of prented chars or -1 if erroe;
*/
int handelPrint(const char *format, int *index, va_list args)
{
	m_handle conv[] = {
		{'c', print_char}, {'s', print_str}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_b},
		{'p', print_p}, {'r', print_r}, {'\0', NULL}
	};
	int i, UnkownSpecifierLen = 0;

	for (i = 0; conv[i].module != '\0'; i++)
	{
		if (format[*index] == conv[i].module)
			return (conv[i].function(args));
	}

	if (conv[i].module == '\0')
	{
		if (format[*index] == '\0')
			return (-1);

		UnkownSpecifierLen += _putchar('%');

		if (format[*index - 1] == ' ')
			UnkownSpecifierLen += _putchar(' ');

		UnkownSpecifierLen += write(1, &format[*index], 1);
		return (UnkownSpecifierLen);
	}
	return (-1);
}
