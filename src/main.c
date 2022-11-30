#include "stu_printf.h"

#include <stdio.h>

int main(void)
{
    //printf("%c\n", 'a');
    return (stu_dprintf(1, "str: %s\ndigit: %d\nchar: %c\nadress: %p\n", "Zozo", 12345, 'a', stu_strdup("ab")));
}
