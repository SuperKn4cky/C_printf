/*
 * E89 Pedagogical & Technical Lab
 * project:     stu_dprintf
 * created on:  2022-12-06 - 10:24 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: duplicate a string
 */

#include <stdlib.h>
#include "stu_printf.h"

char *stu_strdup(const char *str)
{
    char *dest;
    int size;
    int i;

    size = stu_strlen(str);
    dest = malloc(sizeof(char) * size);
    i = 0;
    while (str[i] != '\0') {
        dest[i] = str[i];
        i += 1;
    }
    return (dest);
}
