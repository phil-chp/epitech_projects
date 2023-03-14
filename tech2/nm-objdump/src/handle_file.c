/*
** EPITECH PROJECT, 2022
** nm-objdump (Workspace)
** File description:
** handle_file
*/

#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "utils.h"

#include <stdio.h> // TODO: remove

void *get_map_file(char *file)
{
    void *file_contents = NULL;
    struct stat data;
    int fd;

    if ((fd = open(file, O_RDONLY)) == -1) {
        return (NULL);
    }
    if (fstat(fd, &data) == -1) {
        return (NULL);
    }
    file_contents = mmap(NULL, data.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (file_contents == (void *)-1) {
        return (NULL);
    }
    close(fd);
    return (file_contents);
}

void unmap_file(void *file_contents)
{
    if (file_contents) {
        munmap(file_contents, strlen(file_contents));
    }
}
