#include "main.h"

/**
 * _printf - myown implemintation of printf func
 * @format: str pointer
 * Return: length of char printed or -1 if there an error
*/
int _printf(const char *format, ...)
{
	int i, lenAfterCallFunc = 0, overAllLen = 0, specifier = 0;
	va_list args;
	char buffer[1024];

	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[specifier++] = format[i];
			if (specifier == 1024)
				modifiedPutChar(buffer, &specifier);

			overAllLen++;
		}
		else
		{
			modifiedPutChar(buffer, &specifier);
			i++;

			lenAfterCallFunc = handelPrint(format, &i, args);

			if (lenAfterCallFunc == -1)
				return (-1);

			overAllLen += lenAfterCallFunc;
		}
	}

	modifiedPutChar(buffer, &specifier);

	va_end(args);

	return (overAllLen);
}
