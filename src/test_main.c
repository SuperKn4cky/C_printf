#include "stu_printf.h"
#include <stdio.h>

int main(void)
{

    stu_dprintf(1, " %d\n", 123456789);

    /*
     * char *str1 = "Monkey";
     * char *str2 = NULL;
     * 
     * stu_dprintf(1, "stu_dprintf :\n%%        :  %%\n");
     * stu_dprintf(1, "char *   :  %s\n", "Monkey");
     * stu_dprintf(1, "char     :  %c\n", 'a');
     * stu_dprintf(1, "int         %d\n            %d\n", 123456789, -123456789);
     * stu_dprintf(1, "adress   :  %p\n          | %p\n", str1, str2);
     * stu_dprintf(1, "bourrage :  $%+9d$\n", -569);
     * stu_dprintf(1, "         :  $%-9d$\n", -569);
     * stu_dprintf(1, "         :  $%+9d$\n", 569);
     * stu_dprintf(1, "         :  $%-9d$\n", 569);
     * stu_dprintf(1, "         :  $%09d$\n", 569);
     */
    return 0;
}
