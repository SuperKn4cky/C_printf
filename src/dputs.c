/*
 * E89 Pedagogical & Technical Lab
 * project:     stu_dprintf
 * created on:  2022-12-05 - 11:44 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: print decimal
 */

#include <unistd.h>
#include "stu_printf.h"
#include "struct.h"

void stu_dputs(int str, struct stu_dprintf *opt)
{
    int size;
    int digit;

    if (str < 0) {
        str = str * -1;
        opt->size_write += write(opt->fd, "-", 1);
    }
    size = nb_len(str);
    while (size > 0) {
        digit = str % stu_pow(10, size);
        digit -= str % stu_pow(10, size - 1);
        digit /= stu_pow(10, nb_len(digit) - 1);
        digit += '0';
        opt->size_write += write(opt->fd, &digit, 1);
        size -= 1;
    }
}
