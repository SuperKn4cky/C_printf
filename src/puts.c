/*
 * E89 Pedagogical & Technical Lab
 * project:     stu_dprintf
 * created on:  2022-12-06 - 10:23 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: print str
 */

#include <unistd.h>
#include "stu_printf.h"
#include "struct.h"

void stu_puts(const char *str, struct stu_dprintf *opt)
{
    opt->size_write += write(opt->fd, str, stu_strlen(str));
}
