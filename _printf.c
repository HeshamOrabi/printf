#include "main.h"

/**
 * _printf - myown implemintation of printf func
 * @format: str pointer
 * Return: length of char printed or -1 if there an error
*/
int _printf(const char *format, ...)
{
	m_handle conv[] = {
		{"%c", print_char}, {"%s", print_string}, {"%%", print_present}
	};
	va_list args;
	int i, j, len = 0;

	va_start(args, format);
	if (format == '\0' || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == conv[0].module[0])
		{
			for (j = 0; j < (sizeof(conv) / sizeof(conv[j])); j++)
			{
				if (format[i + 1] == conv[j].module[1])
				{
					len += conv[j].function(args);
					i += 1;
					break;
				}
			}
			if (j == sizeof(conv) / sizeof(conv[j]))
			{
				va_end(args);
				return (-1);
			}
		}
		else
		{
			_putchar(format[i]);
			len++;
		}
	}
	va_end(args);
	return (len);
}
