#include <stdarg.h>
#include <unistd.h>
#include "stu_printf.h"

#include <stdio.h>

int stu_dprintf(int fd, const char *pattern, ...)
{
    const char *arg;
    char argc;
    unsigned long argp;
    int argd;
    int size_write;
    int i;
    va_list args;

    i = 0;
    size_write = 0;
    va_start(args, pattern);
    while (pattern[i] != '\0') {
        if (pattern[i] == '%' && pattern[i + 1] == '%') {
            size_write = stu_puts(fd, "%");
            i += 2;
        } else if (pattern[i] == '%' && pattern[i + 1] == 's') {
            arg = va_arg(args, const char *);
            size_write += stu_puts(fd, arg);
            i += 2;
        } else if (pattern[i] == '%' && pattern[i + 1] == 'd') {
            argd = va_arg(args, int);
            size_write += stu_dputs(fd, argd);
            i += 2;
        } else if (pattern[i] == '%' && pattern[i + 1] == 'c') {
            argc = va_arg(args, int);
            size_write += write(fd, &argc, 1);
            i += 2;
        } else if (pattern[i] == '%' && pattern[i + 1] == 'p') {
            argp = (unsigned long)va_arg(args, void *);
            size_write += write(fd, &argp, sizeof(argp));
            printf("\nprintf adress: %p\n", (void *)argp);
            i += 2;
        } else {
            size_write += write(fd, &pattern[i], 1);
            i += 1;
        }
    }
    va_end(args);
    return (size_write);
}
