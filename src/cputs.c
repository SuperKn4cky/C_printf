/*
 * E89 Pedagogical & Technical Lab
 * project:     stu_sprintf
 * created on:  2022-12-05 - 13:58 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: printf char
 */

#include <unistd.h>

int stu_cputs(int fd, char lettre)
{
    return (write(fd, &lettre, 1));
}
