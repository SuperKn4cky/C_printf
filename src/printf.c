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

static void bourrage(struct stu_dprintf *opt, const char *pattern, va_list args)
{
    int nb;
    int size;

    size = 0;
    opt->tmp = opt->count;
    while (opt->tmp > 0) {
        va_arg(args, int);
        opt->tmp -= 1;
    }
    nb = va_arg(args, int);
    if (pattern[opt->i] == '%' && pattern[opt->i + 1] == '+') {
        if (pattern[opt->i + 2] == '0') {
            size = (pattern[opt->i + 3] - 48) - nb_len(nb);
            opt->size_write = write(opt->fd, "+", 1);
            while (size > 0) {
                opt->size_write = write(opt->fd, "0", 1);
                size -= 1;
            }
        } else {
            size = (pattern[opt->i + 2] - 48) - nb_len(nb);
            while (size > 0) {
                opt->size_write = write(opt->fd, " ", 1);
                size -= 1;
            }
            opt->size_write = write(opt->fd, "+", 1);
        }
        stu_dputs(nb, opt);
    } else if (pattern[opt->i] == '%' && pattern[opt->i + 1] == '-') {
        stu_dputs(nb, opt);
        size = (pattern[opt->i + 2] - 48) - nb_len(nb);
        while (size > 0) {
            opt->size_write = write(opt->fd, " ", 1);
            size -= 1;
        }
    }
    skip_bourrage(opt, pattern);
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
        //skip_bourrage(&opt, pattern);
        bourrage(&opt, pattern, args);
        no_opt(&opt, pattern);
    }
    va_end(args);
    return (opt.size_write);
}
