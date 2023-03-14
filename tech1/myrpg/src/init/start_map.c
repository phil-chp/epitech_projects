/*
** EPITECH PROJECT, 2020
** B-MUL-200-NCE-2-1-myrpg-theo.guichard
** File description:
** init_map.c
*/

#include "my_rpg.h"

static int get_area(int stair, sfIntRect *area, int opt)
{
    if (opt == 0) {
        (*area) = (sfIntRect){ 0, 200 * (stair - 1), 200, 200 };
        if (stair > 10)
            return (1);
    } else {
        (*area) = (sfIntRect){ 0, 154 * stair, 237, 154 };
        if (stair > 5)
            return (1);
    }
    return (0);
}

int fill_map(   game_t *game,           \
                sfVector2f size,        \
                sfVector2f back_size,   \
                sfVector2f center)
{
    char map_path[] = "assets/hud/map/map.jpg";
    char num_path[] = "assets/hud/map/numbers.png";
    sfIntRect map_area, num_area;
    sfVector2f origins = { 0, 0 };
    sfTexture *texture, *texture2;

    if (get_area(game->map->room, &num_area, 0)) return (1);
    if (get_area(game->map->stair, &map_area, 1)) return (1);
    if (!(texture = sfTexture_createFromFile(map_path, &map_area)))
        return (1);
    if (!(texture2 = sfTexture_createFromFile(num_path, &num_area)))
        return (1);
    if (!(game->map->number = create_rectangle(center, size, texture2)))
        return (1);
    if (!(game->map->back = create_rectangle(origins, back_size, texture)))
        return (1);
    return (0);
}

int update_stat_map(map_t **map)
{
    char map_path[] = "assets/hud/map/map.jpg";
    char num_path[] = "assets/hud/map/numbers.png";
    sfVector2f origins = {0, 0}, size = {200, 200};
    sfVector2f back_size = {237, 154}, center;
    sfTexture *texture, *texture2;
    sfIntRect map_area, num_area;
    (*map)->map[0][1] = 's';
    center = get_center(SCREEN, (sfVector2f){ 200, 200 });
    if (get_area((*map)->room, &num_area, 0)) return (1);
    if (get_area((*map)->stair, &map_area, 1)) return (1);
    if (!(texture = sfTexture_createFromFile(map_path, &map_area)))
        return (1);
    if (!(texture2 = sfTexture_createFromFile(num_path, &num_area)))
        return (1);
    if (!((*map)->number = create_rectangle(center, size, texture2)))
        return (1);
    if (!((*map)->back = create_rectangle(origins, back_size, texture)))
        return (1);
    return (0);
}

int start_map(game_t *game)
{
    sfVector2f back_size, center, size;
    map_t *temp;

    size = (sfVector2f){200, 200};
    back_size = (sfVector2f){237, 154};
    center = get_center(SCREEN, size);
    for (temp = game->map->head; temp; temp = temp->right)
        if (temp->map[0][1] == 's') break;
    if (temp->right == NULL)
        return (1);
    game->map = temp;
    if (fill_map(game, size, back_size, center)) return (1);
    if (build_map(game))
        return (1);
    add_orb(game);
    return (0);
}
