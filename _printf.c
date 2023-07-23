#include "main.h"

/**
 * _printf - myown implemintation of printf func
 * @format: str pointer
 * Return: length of char printed
*/
int _printf(const char *format, ...)
{
	m_handle conv[] = {
		{"%c", print_char}, {"%s", print_string}, {"%%", print_present}
	};

	va_list args;
	int i, j, len = 0;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		for (j = 0; j < (sizeof(conv) / sizeof(conv[j])); j++)
		{
			if (format[i] == conv[j].module[0] && format[i + 1] == conv[j].module[1])
			{
				len += conv[j].function(args);
				i += 2;
				continue;
			}
		}
		_putchar(format[i]);
		len++;
	}

	va_end(args);
	return (len);
}
