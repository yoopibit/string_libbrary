#ifndef MY_STRING_H
#define MY_STRING_H
#include <inttypes.h>

#if !defined(size_t) || !defined(NULL)
#define size_t unsigned long
#endif

char* long_to_str(long i, char* str, size_t lenght);
char* double_to_str(double number, char* str, size_t lenght, uint8_t after_coma = 3);

#endif // MY_STRING_H
