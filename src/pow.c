/*
 * E89 Pedagogical & Technical Lab
 * project:     stu_dprintf
 * created on:  2022-12-06 - 10:16 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: stu_pow
 */

int stu_pow(int nb, int power)
{
    int nb_f;

    nb_f = nb;
    if (power == 0) {
        return 1;
    }
    while (power > 1) {
        nb_f = nb * nb_f;
        power = power - 1;
    }
    return (nb_f);
}
