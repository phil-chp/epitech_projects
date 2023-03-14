/*
** EPITECH PROJECT, 2020
** antman
** File description:
** Reads a given file and returns it's content in a char *
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../../include/my.h"

char *read_file(char *file)
{
    struct stat data;
    int fd;
    int rd;
    char *buff;

    if (stat(file, &data) == -1) return (NULL);
    buff = malloc(sizeof(char) * (data.st_size + 2));
    if (!buff) return (NULL);
    fd = open(file, O_RDONLY);
    if (fd == -1) {
        free(buff);
        return (NULL);
    }
    rd = read(fd, buff, data.st_size);
    if (rd == -1 || my_strlen(buff) < 1) {
        free(buff);
        return (NULL);
    }
    buff[rd] = '\0';
    return (buff);
}
