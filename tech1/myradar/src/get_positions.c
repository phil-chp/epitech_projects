/*
** EPITECH PROJECT, 2020
** navy (Workspace)
** File description:
** use files
*/

#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"
#include "lib.h"
#include "my.h"

static int *decomp_line(char *content, int type, char spacer)
{
    int j = 0;
    int k = 0;
    char *temp;
    int *res;

    temp = malloc(sizeof(char) * 5);
    res = malloc(sizeof(int) * type);
    if (!temp || !res) return (NULL);
    for (int i = 2; k < type; i++)
        if (content[i] && content[i] != spacer) {
            temp[j] = content[i];
            temp[++j] = '\0';
        } else {
            res[k] = my_getnbr(temp);
            temp[0] = '\0';
            j = 0;
            k++;
        }
    free(temp);
    return (res);
}

static pos_t *pos_create(int i, int j)
{
    pos_t *pos;

    pos = malloc(sizeof(*pos));
    if (!pos) return (NULL);
    pos->planes = malloc(sizeof(sfSprite *) * i);
    pos->p_dest = malloc(sizeof(sfVector2f) * i);
    pos->p_speed = malloc(sizeof(int) * i);
    pos->p_delay = malloc(sizeof(int) * i);
    pos->towers = malloc(sizeof(sfSprite *) * j);
    pos->towers_area = malloc(sizeof(sfCircleShape *) * j);
    pos->t_radius = malloc(sizeof(float) * j);
    if (!pos->planes || !pos->p_dest || !pos->p_speed || !pos->p_delay  \
            || !pos->towers || !pos->t_radius || !pos->towers_area)
        return (NULL);
    pos->p_count = 0;
    pos->t_count = 0;
    return (pos);
}

static void build_plane(pos_t *pos, char *content, int i)
{
    sfVector2f position;
    int *values;

    values = decomp_line(content, 6, ' ');
    position.x = values[0];
    position.y = values[1];
    pos->planes[i] = create_plane(position, PLANE_SIZE);
    pos->p_dest[i].x = values[2];
    pos->p_dest[i].y = values[3];
    pos->p_speed[i] = values[4];
    pos->p_delay[i] = values[5];
    pos->p_count++;
    free(values);
}

static void build_tower(pos_t *pos, char *content, int j)
{
    sfVector2f position;
    int *values;

    values = decomp_line(content, 3, ' ');
    position.x = values[0];
    position.y = values[1];
    pos->t_radius[j] = (float)values[2] * (float)WIDTH / 100.0;
    pos->towers[j] = create_tower(position, pos->t_radius[j]);
    pos->towers_area[j] = show_tower_area(position, sfGreen, pos->t_radius[j]);
    pos->t_count++;
    free(values);
}

pos_t *get_positions(char *path)
{
    FILE *file = fopen(path, "r");
    char *content;
    pos_t *pos;

    if (!file) return (NULL);
    for (struct { int i, j, n; } v = {0, 0, 0}; v.n < 2; v.n++) {
        for (size_t len = 0; (getline(&content, &len, file)) != -1; )
            (content[0] == 'A') ? ( \
            ((v.n != 0) ? (build_plane(pos, content, v.i)) : (0)), v.i++ \
            ) : (content[0] == 'T') ? ( \
            ((v.n != 0) ? (build_tower(pos, content, v.j)) : (0)), v.j++ \
            ) : (0);
        (v.n == 0) && (pos = pos_create(v.i, v.j), fclose(file), \
                    file = fopen(path, "r"), v.i = 0, v.j = 0, 0);
        if (!pos) return (NULL);
    }
    fclose(file);
    free(content);
    return (pos);
}
