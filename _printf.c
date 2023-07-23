#include "main.h"

/**
*/
int _printf(const char *format, ...)
{
	m_handle conv[] = {
		{"%c", print_char}, {"%s", print_string}, {"%%", print_present}
	};

	va_list args;
	int i, j, len;

	va_start(args, format)
	for (i = 0; format[i] != NULL; i++)
	{
		for (j = 0; j < (sizeof(conv) / sizeof(conv[j])); j++)
		{
			if (format[i] == conv[j].module[0] && format[i + 1] == conv[j].module[1])
			{
				len += conv[j].function(args);
				i = i + 2;
				continue;
			}
			
		}
	}
}
