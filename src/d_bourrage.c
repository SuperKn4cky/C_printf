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

static void plus(struct stu_dprintf *opt, const char *pattern, int nb)
{
    int size;

    size = 0;
    if (pattern[opt->i] == '%' && pattern[opt->i + 1] == '+') {
        if (pattern[opt->i + 2] == '0') {
            size = (pattern[opt->i + 3] - 48) - nb_len(nb) - 1;
            opt->size_write = write(opt->fd, "+", 1);
            while (size > 0) {
                opt->size_write = write(opt->fd, "0", 1);
                size -= 1;
            }
        } else {
            size = (pattern[opt->i + 2] - 48) - nb_len(nb) - 1;
            while (size > 0) {
                opt->size_write = write(opt->fd, " ", 1);
                size -= 1;
            }
            if (nb > 0) {
                opt->size_write = write(opt->fd, "+", 1);
            }
        }
        stu_dputs(nb, opt);
    }
}

static void moins(struct stu_dprintf *opt, const char *pattern, int nb)
{
    int size;

    size = 0;
    if (pattern[opt->i] == '%' && pattern[opt->i + 1] == '-') {
        stu_dputs(nb, opt);
        size = (pattern[opt->i + 2] - 48) - nb_len(nb);
        if (nb < 0) {
            size -= 1;
        }
        while (size > 0) {
            opt->size_write = write(opt->fd, " ", 1);
            size -= 1;
        }
    }
}

void d_bourrage(struct stu_dprintf *opt, const char *pattern, va_list *args)
{
    int nb;

    nb = va_arg(*args, int);
    plus(opt, pattern, nb);
    moins(opt, pattern, nb);
    skip_bourrage(opt, pattern);
}
