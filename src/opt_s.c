/*
 * E89 Pedagogical & Technical Lab
 * project:     stu_dprintf
 * created on:  2022-12-13 - 09:49 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: opt for %s
 */

#include <stdarg.h>
#include "stu_printf.h"
#include "struct.h"

void opt_s(struct stu_dprintf *opt, const char *pattern, va_list *args)
{
    if (pattern[opt->i] == '%' && pattern[opt->i + 1] == 's') {
        stu_puts(va_arg(*args, const char *), opt);
        opt->i += 2;
    }
}
