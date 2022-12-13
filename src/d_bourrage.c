/*
 * E89 Pedagogical & Technical Lab
 * project:     stu_dprintf
 * created on:  2022-12-13 - 15:06 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: print bourrage for %d
 */

#include <stdarg.h>
#include <unistd.h>
#include "stu_printf.h"
#include "struct.h"

void d_bourrage(struct stu_dprintf *opt, const char *pattern, va_list args)
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
