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
    while (str > 0)
        {
            str = str / 10;
            size += 1;
        }
    return (size);
}
