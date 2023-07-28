#include "main.h"

/**
 * root_13 - conv str to root 13 decode
 * @args: list  of arg
 *
 * Return: len
*/
int root_13(va_list args)
{
	int i = 0, len;
	char *str;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(AHYY)";

	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = ((str[i] - 'a' + 13) % 26) + 'a';
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = ((str[i] - 'A' + 13) % 26) + 'A';
		}
		i++;
	}

	len = i;

	i = 0;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
	}

	return (len);
}
