/*
** EPITECH PROJECT, 2020
** navy (Workspace)
** File description:
** map_parser
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../lib.h"
#include "../my.h"

int aread_pos(plan_t *plan, char *path, int i)
{
    char position[MAP_SIZE + 1];
    int fd = open(path, O_RDONLY);

    if (fd < 0)
        return (84);
    int rd = read(fd, position, MAP_SIZE);
    if (rd < 0)
        return (84);
    position[rd] = '\0';
    if (i == 1)
        plan->pos1 = my_strdup(position);
    else if (i == 2)
        plan->pos2 = my_strdup(position);
    return (0);
}

char **my_copy_array(char **str_src, char **str_dest)
{
    int i = 0;
    str_dest = malloc(sizeof(char *) * (MAP_H + 10));

    if (str_dest == NULL)
        return (NULL);
    for (; str_src[i]; i++) {
        str_dest[i] = malloc(sizeof(char) * (MAP_W + 10));
    }
    str_dest[i] = NULL;
    for (i = 0; str_src[i]; i++)
        str_dest[i] = my_strdup(str_src[i]);
    str_dest[i] = NULL;
    return (str_dest);
}

char *orientation(char *first, char *last)
{
    char *a = "horizontal";
    char *b = "vertical";

    if (first[0] == last[0])
        return (b);
    else
        return (a);
}

void add_element_map(char **map, char *element, char *size)
{
    int i = element[0] + 128;
    int j = element[1] - 47;
    map[j][i] = size[0];

    return;
}

int add_boat(char **map, char **temp)
{
    temp[1][0] *= 2;
    temp[2][0] *= 2;
    int a = my_getnbr(temp[0]);

    if (my_strcmp(orientation(temp[1], temp[2]), "vertical") == 0) {
        for ( ; a >= 1; a--) {
            add_element_map(map, temp[1], temp[0]);
            temp[1][1] += 1;
        }
    } else if (my_strcmp(orientation(temp[1], temp[2]), "horizontal") == 0)
        for ( ; a >= 1; a--) {
            add_element_map(map, temp[1], temp[0]);
            temp[1][0] += 2;
        }
    return (0);
}
