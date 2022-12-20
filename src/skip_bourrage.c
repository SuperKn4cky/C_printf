/*
 * E89 Pedagogical & Technical Lab
 * project:     stu_dprintf
 * created on:  2022-12-13 - 15:05 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: skip bourrage in pattern
 */

#include <stdarg.h>
#include <unistd.h>
#include "stu_printf.h"
#include "struct.h"

void skip_bourrage(struct stu_dprintf *opt, const char *pattern)
{
    if (pattern[opt->i] == '%') {
        if (pattern[opt->i + 1] == '+' 
        || pattern[opt->i + 1] == '-' 
        || pattern[opt->i + 1] == '0') {
            while (pattern[opt->i - 1] != 'd' && pattern[opt->i - 1] != 's'
                   && pattern[opt->i - 1] != 'c' && pattern[opt->i - 1] != 'p') {
                opt->i += 1;
            }
        }
    }
}
