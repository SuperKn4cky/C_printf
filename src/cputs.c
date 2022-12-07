/*
 * E89 Pedagogical & Technical Lab
 * project:     stu_sprintf
 * created on:  2022-12-05 - 13:58 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: printf char
 */

#include <unistd.h>
#include "struct.h"

void stu_cputs(char lettre, struct stu_dprintf *opt)
{
    opt->size_write += write(opt->fd, &lettre, 1);
}
