/*
 * E89 Pedagogical & Technical Lab
 * project:     stu_dprintf
 * created on:  2022-12-06 - 10:24 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: calculate the length of a sting
 */

unsigned int stu_strlen(const char *str)
{
    int i;

    i = 0;
    while (str [i] != '\0') {
        i = i + 1;
    }
    return i;
}
