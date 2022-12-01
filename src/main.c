#include "stu_printf.h"

#include <stdio.h>

int main(void)
{
    printf("%-999d\n", 56);
    return (stu_dprintf(1, "%: %%\nstr: %s\ndigit: %d\nchar: %c\nadress: %p\n",
                        "monkey", 12345, 'a', stu_strdup("test")));
}
