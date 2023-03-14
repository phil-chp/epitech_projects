/*
** EPITECH PROJECT, 2020
** navy (Workspace)
** File description:
** set_array
*/

#include <stdlib.h>
#include <stdio.h>
#include "../lib.h"

static char **create_array(void)
{
    int k = 0;
    char **temp;
    temp = malloc(sizeof(char *) * 4);

    if (temp == NULL)
        return (NULL);
    for (k = 0; k < 4; k++)
        temp[k] = malloc(sizeof(char) * 4);
    temp[k - 1] = NULL;
    return (temp);
}

char **set_array_pos(char **usr_map, char **arr_pos, char *pos)
{
    int a = 0;
    int b = 0;
    char **temp;
    temp = create_array();
    arr_pos = my_copy_array(usr_map, arr_pos);

    for (int i = 0; pos[i]; i++, b = 0) {
        for (a = 0; pos[i] != '\n'; b++, i++) {
            (pos[i] == ':') && (temp[a][b] = '\0', b = 0, a++, i++, 0);
            temp[a][b] = pos[i];
        }
        temp[a][b] = '\0';
        add_boat(arr_pos, temp);
    }
    return (arr_pos);
}

char **set_array(plan_t *plan, char **map)
{
    int i = 0;
    int j = 0;
    plan->limit = deterline(plan);
    map = malloc(sizeof(char *) * (plan->limit + 1));

    if (map == NULL)
        return (NULL);
    for (int a = 0; plan->buff[a]; i++, a++) {
        map[i] = malloc(sizeof(char) * 20);
        for (j = 0; plan->buff[a] != '\n'; a++, j++)
            map[i][j] = plan->buff[a];
        map[i][j] = '\0';
    }
    map[i] = NULL;
    return (map);
}
