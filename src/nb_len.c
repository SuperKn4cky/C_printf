/*
 * E89 Pedagogical & Technical Lab
 * project:     stu_dprintf
 * created on:  2022-12-06 - 10:14 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: count size of number
 */

int nb_len(int str)
{
    int size;

    size = 0;
    if (str < 0) {
        str = str * -1;
    }
    if (str == 0) {
        return 1;
    }
    while (str > 0) {
        str = str / 10;
        size += 1;
    }
    return (size);
}
