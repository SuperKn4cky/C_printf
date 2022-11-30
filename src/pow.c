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
