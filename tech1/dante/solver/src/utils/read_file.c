/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** read_file
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "solver.h"

char *read_file(char *file)
{
    struct stat fs;

    if (lstat(file, &fs) == -1) return (NULL);
    char *res = malloc(sizeof(char) * (fs.st_size + 1));
    if (!res) return (NULL);
    int fd = open(file, O_CREAT | O_APPEND | O_RDONLY, 0600);
    if (fd == -1) {
        if (res) free(res);
        return (NULL);
    }
    ssize_t a = read(fd, res, fs.st_size);
    if (a == -1) {
        if (res) free(res);
        return (NULL);
    }
    res[a] = '\0';
    close(fd);
    return (res);
}
