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

int stu_pputs(int fd, unsigned long nbr)
{
    char *str;
    char *base16;
    int size_write;
    int i;

    i = 5;
    str = malloc(sizeof(char) * 6);
    base16 = "0123456789abcdef";
    size_write = 0;
    while (nbr != 0) {
        str[i] = base16[nbr % 16];
        nbr /= 16;
        i -= 1;
        }
    if (stu_strlen(str) == 0) {
        write(fd, "(null)", 6);
        return 0;
    }
    size_write += stu_puts(fd, "0x");
    size_write += write(fd, str, 6);
    return (size_write);
}
