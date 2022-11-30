#include <stdarg.h>
#include <unistd.h>
#include "stu_printf.h"

int stu_dprintf(const char *pattern, ...)
{
    const char *arg;
    int argd;
    int size_write;
    int i;
    va_list args;

    i = 0;
    size_write = 0;
    va_start(args, pattern);
    while (pattern[i] != '\0') {
        if (pattern[i] == '%' && pattern[i + 1] == '%') {
            size_write = stu_puts("%");
            i += 2;
        } else if (pattern[i] == '%' && pattern[i + 1] == 's') {
            arg = va_arg(args, const char *);
            size_write += stu_puts(arg);
            i += 2;
        } else if (pattern[i] == '%' && pattern[i + 1] == 'd') {
            argd = va_arg(args, int);
            size_write += stu_dputs(argd);
            i += 2;
        } else {
            size_write += write(1, &pattern[i], 1);
            i += 1;
        }
    }
    va_end(args);
    return (size_write);
}
