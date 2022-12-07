/*
 * E89 Pedagogical & Technical Lab
 * project:     stu_dprintf
 * created on:  2022-12-06 - 10:16 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: printf adresss
 */

#include <stdlib.h>
#include <unistd.h>
#include "stu_printf.h"
#include "struct.h"

int stu_pputs(unsigned long nbr, struct stu_dprintf *opt)
{
    char str[50];
    char *base16;
    int i;

    i = 1;
    base16 = "0123456789abcdef";
    if (nbr == 0) {
        write(opt->fd, "(null)", 6);
        return 0;
    }
    while (nbr != 0) {
        str[i] = base16[nbr % 16];
        nbr /= 16;
        i += 1;
    }
    opt->size_write += write(opt->fd, "0x", 2);
    while (i > 0) {
        i -= 1;
        opt->size_write += write(opt->fd, &str[i], 1);
    }
    return 0;
}
