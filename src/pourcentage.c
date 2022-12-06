int pourcentage(int fd, const char *pattern, struct stu_dprintf *opt)
{
    if (pattern[opt->i] == '%' && pattern[opt->i + 1] == '%') {
        opt->size_write += stu_puts(fd, "%");
    }
    return (0);
}
