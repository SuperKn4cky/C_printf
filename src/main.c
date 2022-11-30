#include "stu_printf.h"

#include <stdio.h>

int main(void)
{
    //printf("%c\n", 'a');
    return (stu_dprintf(1, "test: %d\n%d\n%c\n%p\n", 1234, 5, 'a', stu_strdup("Monkey")));
}
