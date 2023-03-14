/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace) [WSL: Ubuntu]
** File description:
** create_map.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my_rpg.h"
#include "my.h"

static char **create_array(int count, char **arr, char *buff)
{
    int x = 0;
    int y = 0;
    int len;

    len = my_strlen(buff);
    if (!(arr = malloc(sizeof(char *) * (count + 2)))) return (NULL);
    for (int i = 0; i <= count; i++)
        if (!(arr[i] = malloc(sizeof(char) * 220))) return (NULL);
    for (int j = 0; j <= len; j++) {
        if (buff[j] == '\n' || buff[j] == '\0') {
            arr[x++][y] = '\0';
            y = 0;
        } else {
            arr[x][y++] = buff[j];
        }
    }
    arr[x] = NULL;
    return (arr);
}

static char **aread(char **arr, char **path)
{
    int count = 0;
    char *buff;
    int fd, rd;

    if (!(buff = malloc(sizeof(char) * 13900))) return (NULL);
    if ((fd = open(*path, O_RDONLY)) == -1) {
        free(buff);
        return (NULL);
    } if ((rd = read(fd, buff, 13900)) == -1) {
        close(fd);
        free(buff);
        return (NULL);
    }
    buff[rd - 1] = '\0';
    for (int i = 0; buff[i]; i++)
        if (buff[i] == '\n') count++;
    arr = create_array(count, arr, buff);
    close(fd);
    return (arr);
}

static map_t *load_map(int i, int count, char **arr, int j)
{
    int r = j, m = 0;
    map_t *temp;

    if (!(temp = malloc(sizeof(map_t)))) return (NULL);
    temp->stair = i;
    i = (i * 14) + 1;
    temp->room = count;
    if (!(temp->map = malloc(sizeof(char *) * 15))) {
        free(temp);
        return (NULL);
    }
    for (m = 0; m < 13; m++, i++) {
        int n = 0;
        if (!(temp->map[m] = malloc(sizeof(char) * 23))) return (NULL);
        for (j = r; n < 22; n++, j++)
            temp->map[m][n] = arr[i][j];
        temp->map[m][n] = '\0';
    }
    temp->map[m] = NULL;
    return (temp);
}

static void map_manager(map_t **map, map_t **iter, map_t **temp)
{
    if (!(*map)) {
        (*map) = (*temp);
        (*map)->right = NULL;
        (*map)->head = (*temp);
        (*map)->left = NULL;
    } else {
        for ((*iter) = (*map)->head; (*iter)->right; (*iter) = (*iter)->right);
        (*temp)->right = NULL;
        (*temp)->head = (*map)->head;
        (*temp)->left = (*iter);
        (*iter)->right = (*temp);
    }
}

bool create_map(map_t **map, char **path)
{
    char **arr = NULL;
    int count = 0;
    map_t *temp, *iter;

    (*map) = NULL;
    if (!(arr = aread(arr, path))) return (1);
    for (int i = 0; i < 5; i++) {
        count = 0;
        for (int j = 0; j < 205; j += 21) {
            count++;
            if (!(temp = load_map(i, count, arr, j)))  return (1);
            map_manager(map, &iter, &temp);
        }
    }
    return (0);
}
