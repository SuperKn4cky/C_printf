#include <unistd.h>
#include "stu_printf.h"

int stu_putchar (const char *c, int i)
{
    return (write(1, & *c, i));
}

int stu_puts(const char *str)
{
    int i;

    i = stu_strlen(str);
    if (stu_putchar(str, i) == -1)
        {
            return (-1);
        }
    return (i);
}
