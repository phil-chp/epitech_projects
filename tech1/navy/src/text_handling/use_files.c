/*
** EPITECH PROJECT, 2020
** navy (Workspace)
** File description:
** use files
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../my.h"

static int create_file(char *file)
{
    FILE *f = fopen(file, "rb+");
    if (f == NULL)
        if ((fopen(file, "wb")) == NULL)
            return (84);
    fclose(f);
    return (0);
}

char *read_file(char *file)
{
    size_t n = 16;
    char *res = malloc(sizeof(char) * n);

    int fd = open(file, O_CREAT | O_APPEND | O_RDONLY);
    if (fd < 0) {
        free(res);
        return (NULL);
    }
    ssize_t a = read(fd, res, n);
    res[a] = '\0';
    close(fd);
    return (res);
}

int write_file(char *file, char *content, int purge)
{
    size_t n = my_strlen(content);
    int fd;

    if ((create_file(file)) == 84)
        return (84);
    if (purge == 1)
        fd = open(file, O_CREAT | O_TRUNC | O_WRONLY);
    else
        fd = open(file, O_CREAT | O_APPEND | O_WRONLY);
    if (fd < 0 || (write(fd, content, n)) != my_strlen(content))
        return (84);
    close(fd);
    return (0);
}
