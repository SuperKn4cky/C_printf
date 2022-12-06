/*
 * E89 Pedagogical & Technical Lab
 * project:     stu_dprintf
 * created on:  2022-12-06 - 10:20 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: dprintf
 */

#include <stdarg.h>
#include <unistd.h>
#include "stu_printf.h"
#include "struct.h"

static int pourcentage(int fd, const char *pattern, struct stu_dprintf *opt)
{
    if (pattern[opt->i] == '%' && pattern[opt->i + 1] == '%') {
        opt->size_write += stu_puts(fd, "%");
    }
    return (0);
}

static int no_opt(int fd, const char *pattern, struct stu_dprintf *opt)
{
    if (pattern[opt->i] == '%') {
        opt->i += 2;
    }
    opt->size_write += write(fd, &pattern[opt->i], 1);
    opt->i -= 1;
    return (0);
}

int stu_dprintf(int fd, const char *pattern, ...)
{
    struct stu_dprintf opt;
    va_list args;

    opt.i = 0;
    opt.size_write = 0;
    va_start(args, pattern);
    while (pattern[opt.i] != '\0') {
        pourcentage(fd, pattern, &opt);
        if (pattern[opt.i] == '%' && pattern[opt.i + 1] == 's') {
            opt.size_write += stu_puts(fd, va_arg(args, const char *));
        } else if (pattern[opt.i] == '%' && pattern[opt.i + 1] == 'd') {
            opt.size_write += stu_dputs(fd, va_arg(args, int));
        } else if (pattern[opt.i] == '%' && pattern[opt.i + 1] == 'c') {
            opt.size_write += stu_cputs(fd, va_arg(args, int));
        } else if (pattern[opt.i] == '%' && pattern[opt.i + 1] == 'p') {
            opt.size_write += stu_pputs(fd, (unsigned long)va_arg(args, void *));
        }
        no_opt(fd, pattern, &opt);
        opt.i += 2;
    }
    va_end(args);
    return (opt.size_write);
}
