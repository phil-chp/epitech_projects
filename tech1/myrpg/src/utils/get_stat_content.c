/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** get_stat_content
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my_rpg.h"
#include "my.h"

bool get_stat_contents(char *file, int **stats_content)
{
    char *buff = NULL;
    int fd;
    int rd;

    if (!(buff = malloc(sizeof(char) * 45)))
        return (1);
    fd = open(file, O_RDONLY);
    if ((rd = read(fd, buff, 30)) == -1) {
        close(fd);
        free(buff);
        return (1);
    }
    buff[rd - 1] = '\0';
    close(fd);
    if (my_str_to_int_array(stats_content, buff, ' '))
        return (1);
    return (0);
}
