#include <unistd.h>
#include "stu_printf.h"

int stu_dputs(int str)
{
    float digit;
    int size_write;
    int size;
    int tmp;

    size_write = 0;
    size = nb_len(str);
    while (size > 0)
    {
        tmp = str;
        digit = tmp / stu_pow(10, size - 1);
        digit = digit / 10;
        tmp = digit;
        digit -= tmp;
        digit = digit * 10;
        tmp = digit + '0';
        size_write += write(1, &tmp, 1);
        size -= 1;
    }
    return (size_write);
}
