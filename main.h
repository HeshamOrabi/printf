#ifndef main_h
#define main_h
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFF 1024

/**
 * struct module_handle - convertion specifiers matching
 * @module: str that holds spec
 * @function: points to the fun related to spec
*/
typedef struct module_handle
{
	char module;
	int (*function)();
} m_handle;

int _printf(const char *format, ...);
void modifiedPutChar(char buffer[], int *specifier);
int handelPrint(const char *format, int *index, va_list args);
int _putchar(char c);
int print_percent(void);
int print_char(va_list args);
int print_str(va_list args);
char *int_to_char(int num);
int print_int(va_list args);
int print_b(va_list args);
int print_p(va_list args);
int print_r(va_list args);
int print_u(void);

#endif
