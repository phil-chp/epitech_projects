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
#include "sokoban.h"

char *read_file(char *file)
{
    struct stat fs;

    if (lstat(file, &fs) == -1) return (NULL);
    char *res = malloc(sizeof(char) * fs.st_size);
    if (!res) ERROR("my_sokoban: Out of memory\n\r");
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
    res[a - 1] = '\0';
    close(fd);
    return (res);
}
