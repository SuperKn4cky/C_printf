#include <stdlib.h>
#include <unistd.h>
#include "stu_printf.h"

int stu_pputs(int fd, unsigned long nbr)
{
    char *str;
    char *base16;
    int size_write;
    int i;

    i = 11;
    str = malloc(sizeof(char) * 12);
    base16 = "0123456789abcdef";
    size_write = 0;
    while (nbr != 0) {
        str[i] = base16[nbr % 16];
        nbr /= 16;
        i -= 1;
        }
    size_write += write(fd, str, 12);
    return (size_write);
}