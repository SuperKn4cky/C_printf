/*
 * E89 Pedagogical & Technical Lab
 * project:     stu_dprintf
 * created on:  2022-12-13 - 09:53 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: opt for %d
 */

#include <stdarg.h>
#include "stu_printf.h"
#include "struct.h"

void opt_d(struct stu_dprintf *opt, const char *pattern, va_list args)
{
    opt->tmp = opt->d;
    while (opt->tmp > 0) {
        va_arg(args, int);
        opt->tmp -= 1;
    }
    if (pattern[opt->i] == '%' && pattern[opt->i + 1] == 'd') {
        stu_dputs(va_arg(args, int), opt);
        opt->d += 1;
        opt->i += 2;
    }
}

