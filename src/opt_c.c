/*
 * E89 Pedagogical & Technical Lab
 * project:     stu_dprintf
 * created on:  2022-12-13 - 10:19 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: opt for %c
 */

#include <stdarg.h>
#include "stu_printf.h"
#include "struct.h"

void opt_c(struct stu_dprintf *opt, const char *pattern, va_list args)
{
    opt->tmp = opt->count;
    while (opt->tmp > 0) {
        va_arg(args, int);
        opt->tmp -= 1;
    }
    if (pattern[opt->i] == '%' && pattern[opt->i + 1] == 'c') {
        stu_cputs(va_arg(args, int), opt);
        opt->count += 1;
        opt->i += 2;
    }
}
