/*
** EPITECH PROJECT, 2020
** B-MUL-200-NCE-2-1-myrpg-theo.guichard
** File description:
** handle_map.c
*/

#include <stdbool.h>
#include "my_rpg.h"

static bool builder(game_t *game, cell_t *temp)
{
    switch (temp->c) {
        case 'B':
        case 'S':
        case 'E':
            enemy_manager(game, temp);
            break;
        case 'P':
            if (pnj_manager(game, temp)) return (1);
            break;
        default:
            if (obj_manager(&game->obj, temp)) return (1);
            break;
    }
    return (0);
}

bool build_map(game_t *game)
{
    cell_t temp;

    for (int i = 1, j = 1; i <= 11 && j <= 20; j++) {
        temp.c = game->map->map[i][j];
        temp.i = i;
        temp.j = j;
        if (game->map->map[i][j] != ' ' && builder(game, &temp))
            return (1);
        if (j + 1 > 20) {
            j = 0;
            i++;
        }
    }
    return (0);
}

bool build_hole(game_t *game)
{
    sfTexture *texture;
    sfVector2f size;
    sfVector2f pos;

    texture = sfTexture_createFromFile("assets/elements/hole.png",     \
    &((sfIntRect) {0, 0, 96, 64}));
    if (!texture) return (1);
    size = (sfVector2f) {192, 128};
    pos = (sfVector2f) {WIDTH / 2 - size.x / 2, HEIGHT / 2 - size.y / 2};
    game->hole.rect = create_rectangle(pos, size, texture);
    if (!game->hole.rect) return (1);
    game->hole.state = true;
    return (0);
}

static bool change_room(game_t *game, sfFloatRect hole, \
                        sfFloatRect doors, int i)
{
    handle_minimap(game);
    if (game->hole.rect && !game->state.enemies_left)
        hole = sfRectangleShape_getGlobalBounds(game->hole.rect);
    if ((GET_COLLISION(game->player.pos, doors) && game->doors[i].is_open) \
    ||  (game->hole.rect && (GET_COLLISION(game->player.pos, hole)  \
    && game->hole.state == true))) {
        game->player.pos.x = (i ? 352 : WIDTH - 352);
        game->player.pos.y = HEIGHT / 2;
        destroy_features(game);
        if (game->map->room == 1 && game->map->stair != game->player.orb.state \
        && game->player.orb.state < (game->map->stair + 1))
            add_orb(game);
        if (i == 0 && game->map->room == 1 && game->map->stair == 0) return (1);
        game->map = (i ? game->map->right : game->map->left);
        if (!game->map  || !game->map->right) return (1);
        update_stat_map(&game->map);
        if (build_map(game)) return (1);
    }
    return (0);
}

bool handle_map(game_t *game)
{
    sfFloatRect hole = {0, 0, 0, 0};
    sfFloatRect doors;

    check_no_more_enemies(game);
    if (game->map->room == 10 && !game->state.enemies_left)
        if (build_hole(game)) return (1);
    for (int i = 1; i >= 0; i--) {
        game->doors[i].disabled = ((game->map->room - 1 < 1 && !i)  \
        || (game->map->room + 1 > 10 && i) ? true : false);
        game->doors[i].is_open = (!game->state.enemies_left    \
        && !game->doors[i].disabled ? true : false);
        if (sfKeyboard_isKeyPressed(sfKeyP)) game->doors[i].is_open = true;
        doors = sfRectangleShape_getGlobalBounds(game->doors[i].door);
        if (change_room(game, hole, doors, i)) return (1);
    }
    if (game->map->room != 10 && game->hole.state == true) {
        game->hole.state = false;
        sfRectangleShape_destroy(game->hole.rect);
    }
    return (0);
}
