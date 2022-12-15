#include "stu_printf.h"

#include <stdio.h>

int main(void)
{
    stu_dprintf(1, "%-4d$\n", 56);
    dprintf(1, "%-4d$\n", 56);
    /*
     * char *str1 = "Monkey";
     * char *str2 = NULL;
     * 
     * stu_dprintf(1, "stu_dprintf :\n%%        :  %%\n");
     * stu_dprintf(1, "bourrage :  %+9dFIN\n", -569);
     * stu_dprintf(1, "char *   :  %s\n", "Monkey");
     * stu_dprintf(1, "char     :  %c\n", 'a');
     * stu_dprintf(1, "int      :| %d\n          | %d\n", 123456789, -123456789);
     * stu_dprintf(1, "adress   :| %p\n          | %p\n", str1, str2);
     * 
     * printf("\n");
     * 
     * dprintf(2, "dprintf  :\n%%        :  %%\n");
     * dprintf(2, "bourrage :  %+9dFIN\n", -569);
     * dprintf(2, "char *   :  %s\n", "Monkey");
     * dprintf(2, "char     :  %c\n", 'a');
     * dprintf(1, "int      :| %d\n          | %d\n", 123456789, -123456789);
     * dprintf(2, "adress   :| %p\n          | %p\n", str1, str2);
     */

    /*
     * int n;
     * char *str;
     * n = stu_dprintf(1, "%d\n", 12);
     * stu_dprintf(2, "bytes printed %d\n", n);
     * str = NULL;
     * stu_dprintf(1, "addr is %p\n", str);
     * str = stu_strdup("LUIGI");
     * stu_dprintf(1, "addr is %p and str %s\n", str, str);
     */

    /*
     * char *str;
     * int n;
     * 
     * str = "Projet";
     * n = 0;
     * 
     * dprintf(1, "1.0.0 : START>%%<END\n");
     * dprintf(1, "1.0.1 : START>%d<END\n", 123456789);
     * dprintf(1, "1.0.2 : START>%c<END\n", 'A');
     * dprintf(1, "1.0.3 : START>%s<END\n", str);
     * dprintf(1, "1.0.4 : START>%p<END\n", str);
     * 
     * dprintf(1, "\n");
     * 
     * stu_dprintf(1, "1.1.0 : START>%%<END\n");
     * stu_dprintf(1, "1.1.1 : START>%d<END\n", 123456789);
     * stu_dprintf(1, "1.1.2 : START>%c<END\n", 'A');
     * stu_dprintf(1, "1.1.3 : START>%s<END\n", str);
     * stu_dprintf(1, "1.1.4 : START>%p<END\n", str);
     * 
     * dprintf(1, "\n");
     * 
     * n += stu_dprintf(1, "1.2.0 : START>%%<END\n");
     * n += stu_dprintf(1, "1.2.1 : START>%d<END\n", 123456789);
     * n += stu_dprintf(1, "1.2.2 : START>%c<END\n", 'A');
     * n += stu_dprintf(1, "1.2.3 : START>%s<END\n", str);
     * n += stu_dprintf(1, "1.2.4 : START>%p<END\n", str);
     * stu_dprintf(2, "1.2.5 : START>%d<END\n", n);
     * 
     * dprintf(1, "\n");
     * 
     * //dprintf(1, "2.0.0 : START>%+16%<END\n");
     * dprintf(1, "2.0.1 : START>%+16d<END\n", 123456789);
     * //dprintf(1, "2.0.2 : START>%+16c<END\n", 'A');
     * //dprintf(1, "2.0.3 : START>%+16s<END\n", str);
     * //dprintf(1, "2.0.4 : START>%+16p<END\n", str);
     * 
     * dprintf(1, "\n");
     * 
     * //stu_dprintf(1, "2.1.0 : START>%+16%<END\n");
     * stu_dprintf(1, "2.1.1 : START>%+16d<END\n", 123456789);
     * stu_dprintf(1, "2.1.2 : START>%+16c<END\n", 'A');
     * stu_dprintf(1, "2.1.3 : START>%+16s<END\n", str);
     * stu_dprintf(1, "2.1.4 : START>%+16p<END\n", str);
     * 
     * dprintf(1, "\n");
     * 
     * //n += stu_dprintf(1, "2.2.0 : START>%+16%<END\n");
     * n += stu_dprintf(1, "2.2.1 : START>%+16d<END\n", 123456789);
     * n += stu_dprintf(1, "2.2.2 : START>%+16c<END\n", 'A');
     * n += stu_dprintf(1, "2.2.3 : START>%+16s<END\n", str);
     * n += stu_dprintf(1, "2.2.4 : START>%+16p<END\n", str);
     * stu_dprintf(2, "2.2.5 : START>%+16d<END\n", n);
     * 
     * dprintf(1, "\n");
     * 
     * //dprintf(1, "3.0.0 : START>%-16%<END\n");
     * dprintf(1, "3.0.1 : START>%-16d<END\n", 123456789);
     * dprintf(1, "3.0.2 : START>%-16c<END\n", 'A');
     * dprintf(1, "3.0.3 : START>%-16s<END\n", str);
     * dprintf(1, "3.0.4 : START>%-16p<END\n", str);
     * 
     * dprintf(1, "\n");
     * 
     * //stu_dprintf(1, "3.1.0 : START>%-16%<END\n");
     * stu_dprintf(1, "3.1.1 : START>%-16d<END\n", 123456789);
     * stu_dprintf(1, "3.1.2 : START>%-16c<END\n", 'A');
     * stu_dprintf(1, "3.1.3 : START>%-16s<END\n", str);
     * stu_dprintf(1, "3.1.4 : START>%-16p<END\n", str);
     * 
     * dprintf(1, "\n");
     * 
     * //n += stu_dprintf(1, "3.2.0 : START>%-16%<END\n");
     * n += stu_dprintf(1, "3.2.1 : START>%-16d<END\n", 123456789);
     * n += stu_dprintf(1, "3.2.2 : START>%-16c<END\n", 'A');
     * n += stu_dprintf(1, "3.2.3 : START>%-16s<END\n", str);
     * n += stu_dprintf(1, "3.2.4 : START>%-16p<END\n", str);
     * stu_dprintf(2, "3.2.5 : START>%-16d<END\n", n);
     * 
     * dprintf(1, "\n");
     * 
     * dprintf(1, "4.0.0 : START>%16d<END\n", 123456789);
     * dprintf(1, "4.0.1 : START>%+16d<END\n", 123456789);
     * dprintf(1, "4.0.2 : START>%-16d<END\n", 123456789);
     * dprintf(1, "4.0.3 : START>%+016d<END\n", 123456789);
     * dprintf(1, "4.0.4 : START>%016d<END\n", 123456789);
     * 
     * dprintf(1, "\n");
     * 
     * stu_dprintf(1, "4.1.0 : START>%16d<END\n", 123456789);
     * stu_dprintf(1, "4.1.1 : START>%+16d<END\n", 123456789);
     * stu_dprintf(1, "4.1.2 : START>%-16d<END\n", 123456789);
     * stu_dprintf(1, "4.1.3 : START>%+016d<END\n", 123456789);
     * stu_dprintf(1, "4.1.4 : START>%016d<END\n", 123456789);
     * 
     * dprintf(1, "\n");
     * 
     * dprintf(1, "4.2.0 : START>%16d<END\n", -123456789);
     * dprintf(1, "4.2.1 : START>%+16d<END\n", -123456789);
     * dprintf(1, "4.2.2 : START>%-16d<END\n", -123456789);
     * dprintf(1, "4.2.3 : START>%+016d<END\n", -123456789);
     * dprintf(1, "4.2.4 : START>%016d<END\n", -123456789);
     * 
     * dprintf(1, "\n");
     * 
     * stu_dprintf(1, "4.3.0 : START>%16d<END\n", -123456789);
     * stu_dprintf(1, "4.3.1 : START>%+16d<END\n", -123456789);
     * stu_dprintf(1, "4.3.2 : START>%-16d<END\n", -123456789);
     * stu_dprintf(1, "4.3.3 : START>%+016d<END\n", -123456789);
     * stu_dprintf(1, "4.3.4 : START>%016d<END\n", -123456789);
     */

    return 0;
}
