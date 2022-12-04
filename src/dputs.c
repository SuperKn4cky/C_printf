#include <unistd.h>
#include "stu_printf.h"

#include <stdio.h>

int stu_dputs(int fd, long int str)
{
    int size_write;
    int size;
    int tmp;

    size_write = 0;
    size = nb_len(str);
    while (size > 0) {
        tmp = str % stu_pow(10, size);
        tmp -= str % stu_pow(10, size - 1);
        tmp /= stu_pow(10, nb_len(tmp) - 1);
        printf("\ntmp : %d | len : %d", tmp, nb_len(tmp));
        size_write += write(fd, &tmp, 1);
        size -= 1;
    }
    return (size_write);
}
