/*
 * E89 Pedagogical & Technical Lab
 * project:     printf
 * created on:  2022-11-22 - 09:38 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: printf lib
 */

#ifndef STU_PRINTF_H_
#define STU_PRINTF_H_

int stu_dprintf(const char *pattern, ...);
unsigned int stu_strlen(const char *str);
int nb_len(int str);
int stu_puts(const char *str);
int stu_dputs(int str);
int stu_pow(int nb, int power);

#endif // STU_PRINTF_H_
