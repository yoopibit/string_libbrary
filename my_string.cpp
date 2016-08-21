#include "my_string.h"

#define my_abs(num) ((num) < 0 ? -(num) : (num))

static int lenght_number(long number);

char* long_to_str(long num, char* str, size_t lenght) {
    int current_lenght = lenght_number(num);
    int i;
    if (lenght <= current_lenght)
        return 0;

    if (num < 0)
        str[0] = '-';

    int compare_value = ((num < 0) ? 1 : 0);
    num = my_abs(num);

    for (i = current_lenght - 1; i >= compare_value; --i) {
        str[i] = '0' + num % 10;
        num /= 10;
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
