/*
 * E89 Pedagogical & Technical Lab
 * project:     printf
 * created on:  2022-11-22 - 09:38 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: printf lib
 */

#include "struct.h"

#ifndef STU_PRINTF_H_
#define STU_PRINTF_H_

int stu_dprintf(int fd, const char *pattern, ...);
unsigned int stu_strlen(const char *str);
int nb_len(int str);
void stu_puts(const char *str, struct stu_dprintf *opt);
void stu_cputs(char lettre, struct stu_dprintf *opt);
void stu_dputs(int str, struct stu_dprintf *opt);
int stu_pputs(unsigned long nbr, struct stu_dprintf *opt);
int stu_pow(int nb, int power);
char *stu_strdup(const char *str);
int get_digit(int nb, int index);

#endif // STU_PRINTF_H_
