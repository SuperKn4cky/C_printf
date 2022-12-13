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

static void pourcentage(struct stu_dprintf *opt, const char *pattern)
{
    if (pattern[opt->i] == '%' && pattern[opt->i + 1] == '%') {
        stu_cputs('%', opt);
        opt->i += 2;
    }
}

static void skip_bourrage(struct stu_dprintf *opt, const char *pattern)
{
    if (pattern[opt->i] == '%') {
        if (pattern[opt->i + 1] == '+' || pattern[opt->i + 1] == '-') {
            while (pattern[opt->i - 1] != 'd') {
                opt->i += 1;
            }
        }
    }
}

static void no_opt(struct stu_dprintf *opt, const char *pattern)
{
    if (pattern[opt->i] == '%') {
        opt->i += 1;
    }
    opt->size_write += write(opt->fd, &pattern[opt->i], 1);
    opt->i += 1;
}

int stu_dprintf(int fd, const char *pattern, ...)
{
    struct stu_dprintf opt;
    va_list args;

    opt.fd = fd;
    opt.i = 0;
    opt.count = 0;
    opt.size_write = 0;
    va_start(args, pattern);
    while (pattern[opt.i] != '\0') {
        pourcentage(&opt, pattern);
        opt_s(&opt, pattern, args);
        opt_d(&opt, pattern, args);
        opt_c(&opt, pattern, args);
        opt_p(&opt, pattern, args);
        skip_bourrage(&opt, pattern);
        no_opt(&opt, pattern);
    }
    va_end(args);
    return (opt.size_write);
}
