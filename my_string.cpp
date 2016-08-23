#include "my_string.h"

static int lenght_number(long number);

char* long_to_str(long num, char* str, size_t lenght) {
    int current_lenght = lenght_number(num);
    int i;
    if (lenght <= current_lenght)
        return 0;

    if (num < 0) {
        str[0] = '-';
        num = -num;
    }
    int compare_value = ((num < 0) ? 1 : 0);
    
    for (i = current_lenght - 1; i >= compare_value; --i) {
        str[i] = '0' + num % 10;
        num /= 10;
    }
    str[current_lenght] = '\0';
    return str;
}
char* double_to_str(double number, char* str, size_t lenght, uint8_t after_coma = 3) {
    const size_t current_lenght = lenght_number((int)number) + after_coma + 1;

    if (str == NULL ||  current_lenght >= lenght)
        return NULL;

    const int compare_value = ((number < 0) ? 1 : 0);
    if (number < 0) {
        str[0] = '-';
        number = -number;
    }
    str[current_lenght - after_coma - 1] = ',';

    for(int i = current_lenght - after_coma - 2, copy_number = (int)number; i >= compare_value; --i) {
        str[i] = '0' + copy_number % 10;;
        copy_number /= 10;
    }
    for (int i = current_lenght - after_coma; i < current_lenght; ++i) {
        number *= 10;
        str[i] = '0' + (uint64_t)(number) % 10;
    }
    str[current_lenght] = '\0';
    return str;
}

static int lenght_number(long number) {
    int lenght = number < 0 ? 1 : 0;
    number = my_abs(number);

    while (number > 9) {
        ++lenght;
        number /= 10;
    }
    return lenght + 1;
}
