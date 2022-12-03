#include "stu_printf.h"

#include <stdio.h>

int main(void)
{
    char *str = NULL;

    //printf("%+09d\n", 56);
    dprintf(1, "dprintf :\n%%      :  %%\nchar * :  %s\nint    :  %d\nchar   :  %c\nadress :| %p\n        | %p\n\n",
                        "monkey", 12345, 'a', stu_strdup("Monkey"), str);

    stu_dprintf(1, "stu_dprintf :\n%%      :  %%\nchar * :  %s\nint    :  %d\nchar   :  %c\nadress :| %p\n        | %p\n",
                        "monkey", 12345, 'a', stu_strdup("Monkey"), str);
    return 0;
}
