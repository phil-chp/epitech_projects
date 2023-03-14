/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** use_files
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"

void create_file(char *file)
{
    FILE *f = fopen(file, "rb+");
    if (f == NULL)
        f = fopen(file, "wb");
    if (f != NULL)
        fclose(f);
}

void write_file(char *file, char *content, int purge)
{
    size_t n = my_strlen(content);
    int fd;

    create_file(file);
    if (purge == 1)
        fd = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
    else
        fd = open(file, O_WRONLY | O_APPEND | O_CREAT, 0644);
    if ((write(fd, content, n)) == -1) {}
    close(fd);
    return;
}
