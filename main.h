#ifndef main_h
#define main_h
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct module_handle - convertion specifiers matching
 * @module: str that holds spec
 * @function: points to the fun related to spec
*/
typedef struct module_handle
{
	char *module;
	int (*function)();
} m_handle;

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(void);


#endif
