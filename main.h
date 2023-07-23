#ifndef main_h
#define main_h
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>


typedef struct module_handle
{
	char *module;
	int (* function) ();
}m_handle;

int _printf(const char *format, ...);


#endif
