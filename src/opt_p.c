/*
 * E89 Pedagogical & Technical Lab
 * project:     stu_dprintf
 * created on:  2022-12-13 - 09:56 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: opt for %p
 */

#include <stdarg.h>
#include "stu_printf.h"
#include "struct.h"

void opt_p(struct stu_dprintf *opt, const char *pattern, va_list args)
{
    opt->tmp = opt->count;
    while (opt->tmp > 0) {
        va_arg(args, void *);
        opt->tmp -= 1;
    }
    if (pattern[opt->i] == '%' && pattern[opt->i + 1] == 'p') {
        stu_pputs((unsigned long)va_arg(args, void *), opt);
        opt->count += 1;
        opt->i += 2;
    }
}
