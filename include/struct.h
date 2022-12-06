/*
 * E89 Pedagogical & Technical Lab
 * project:     stu_dprintf
 * created on:  2022-12-06 - 10:31 +0100
 * 1st author:  quentin.gimenez - quentin.gimenez
 * description: structure
 */

#ifndef STRUCT_H_
#define STRUCT_H_

struct stu_dprintf {
    const char *pattern;
    int size_write;
    int fd;
    int i;
};

#endif // STRUCT_H_
