#include "my_fscanf.h"
#include <stdarg.h>
#include <ctype.h>
#include <stdio.h>

void my_fscanf(FILE *fp, const char *format, ...){
	va_list list;
	va_start(list, format);
	while(*format){
		if(*format == '%') {
			format++;
			int c, *_val;
			switch(*format){
			case 'd':{
				while(isspace(c = getc(fp))) {}
				_val = va_arg(list, int*);
				*_val = 0;
				while(isdigit(c)) {
					*_val = (*_val) * 10 + c - '0';
					c = getc(fp);
				}
				
				while(isspace(c = getc(fp))) {}
				ungetc(c,fp);
				break;
			}

			case 'c' :{
				while (isspace(c = getc(fp))){}
				char *_val = va_arg(list, char*);
				*_val =c;
				break;
			}
			}
		}
	
		else
			format++;
	}
	va_end(list);
}	
