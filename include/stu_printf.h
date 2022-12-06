/*
 * E89 Pedagogical & Technical Lab
 * project:     printf
 * created on:  2022-11-22 - 09:38 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: printf lib
 */

#ifndef STU_PRINTF_H_
#define STU_PRINTF_H_

int stu_dprintf(int fd, const char *pattern, ...);
unsigned int stu_strlen(const char *str);
int nb_len(int str);
int stu_puts(int fd, const char *str);
int stu_cputs(int fd, char lettre);
int stu_dputs(int fd, int str);
int stu_pputs(int fd, unsigned long nbr);
int stu_pow(int nb, int power);
char *stu_strdup(const char *str);
int get_digit(int nb, int index);

#endif // STU_PRINTF_H_
