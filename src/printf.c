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

static int pourcentage(struct stu_dprintf *opt, const char *pattern)
{
    if (pattern[opt->i] == '%' && pattern[opt->i + 1] == '%') {
        opt->size_write += stu_puts("%", opt);
    }
    return (0);
}

static int no_opt(struct stu_dprintf *opt, const char *pattern)
{
    if (pattern[opt->i] == '%') {
        opt->i += 2;
    }
    opt->size_write += write(opt->fd, &pattern[opt->i], 1);
    opt->i -= 1;
    return (0);
}

int stu_dprintf(int fd, const char *pattern, ...)
{
    struct stu_dprintf opt;
    va_list args;

    opt.fd = fd;
    opt.i = 0;
    opt.size_write = 0;
    va_start(args, pattern);
    while (pattern[opt.i] != '\0') {
        pourcentage(&opt, pattern);
        if (pattern[opt.i] == '%' && pattern[opt.i + 1] == 's') {
            stu_puts(va_arg(args, const char *), &opt);
        } else if (pattern[opt.i] == '%' && pattern[opt.i + 1] == 'd') {
            stu_dputs(va_arg(args, int), &opt);
        } else if (pattern[opt.i] == '%' && pattern[opt.i + 1] == 'c') {
            stu_cputs(va_arg(args, int), &opt);
        } else if (pattern[opt.i] == '%' && pattern[opt.i + 1] == 'p') {
            stu_pputs((unsigned long)va_arg(args, void *), &opt);
        }
        no_opt(&opt, pattern);
        opt.i += 2;
    }
    va_end(args);
    return (opt.size_write);
}
