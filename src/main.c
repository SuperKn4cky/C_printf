#include "stu_printf.h"

#include <stdio.h>

int main(void)
{
    /*
     * char *str1 = "Monkey";
     * char *str2 = NULL;
     * 
     * stu_dprintf(1, "stu_dprintf :\n%%        :  %%\n");
     * stu_dprintf(1, "bourrage :  %+9d\n", 569);
     * stu_dprintf(1, "char *   :  %s\n", "Monkey");
     * stu_dprintf(1, "char     :  %c\n", 'a');
     * stu_dprintf(1, "int      :| %d\n          | %d\n", 123456789, -123456789);
     * stu_dprintf(1, "adress   :| %p\n          | %p\n", str1, str2);
     * 
     * printf("\n");
     * 
     * dprintf(2, "dprintf  :\n%%        :  %%\n");
     * dprintf(2, "bourrage :  %+9d\n", 569);
     * dprintf(2, "char *   :  %s\n", "Monkey");
     * dprintf(2, "char     :  %c\n", 'a');
     * dprintf(1, "int      :| %d\n          | %d\n", 123456789, -123456789);
     * dprintf(2, "adress   :| %p\n          | %p\n", str1, str2);
     */

    int n;
    char *str;
    n = stu_dprintf(1, "%d\n", 12);
    stu_dprintf(2, "bytes printed %d\n", n);
    stu_dprintf(1, "%+04d\n", 56);
    str = NULL;
    stu_dprintf(1, "addr is %p\n", str);
    str = stu_strdup("LUIGI");
    stu_dprintf(1, "addr is %p and str %s\n", str, str);

    return 0;
}
