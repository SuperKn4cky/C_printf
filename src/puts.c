#include <unistd.h>
#include "stu_printf.h"

int stu_putchar (int fd, const char *c, int i)
{
    return (write(fd, & *c, i));
}

int stu_puts(int fd, const char *str)
{
    int i;

    i = stu_strlen(str);
    if (stu_putchar(fd, str, i) == -1)
        {
            return (-1);
        }
    return (i);
}
