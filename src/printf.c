#include <stdarg.h>
#include <unistd.h>
#include "stu_printf.h"

int stu_dprintf(int fd, const char *pattern, ...)
{
    int size_write;
    int i;
    va_list args;

    i = 0;
    size_write = 0;
    va_start(args, pattern);
    while (pattern[i] != '\0') {
        if (pattern[i] == '%' && pattern[i + 1] == '%') {
            size_write = stu_puts(fd, "%");
        } else if (pattern[i] == '%' && pattern[i + 1] == 's') {
            size_write += stu_puts(fd, va_arg(args, const char *));
        } else if (pattern[i] == '%' && pattern[i + 1] == 'd') {
            size_write += stu_dputs(fd, va_arg(args, int));
        } else if (pattern[i] == '%' && pattern[i + 1] == 'c') {
            size_write += stu_cputs(fd, va_arg(args, int));
        } else if (pattern[i] == '%' && pattern[i + 1] == 'p') {
            size_write += stu_pputs(fd, (unsigned long)va_arg(args, void *));
        } else if (pattern[i] == '%') {
            i -= 1;
        } else {
            size_write += write(fd, &pattern[i], 1);
            i -= 1;
        }
        i += 2;
    }
    va_end(args);
    return (size_write);
}
