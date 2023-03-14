/*
** EPITECH PROJECT, 2020
** navy (Workspace)
** File description:
** aread
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "../lib.h"

int aread(plan_t *plan, char *path)
{
    plan->buff = malloc(sizeof(char) * MAP_SIZE);
    if (plan->buff == NULL)
        return (84);
    int fd = open(path, O_RDONLY);
    if (fd == -1)
        return (84);
    int rd = read(fd, plan->buff, MAP_SIZE);
    plan->buff[rd] = '\0';
    return (0);
}
