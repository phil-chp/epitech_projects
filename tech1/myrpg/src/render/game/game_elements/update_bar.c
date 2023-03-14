/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** update_bar.c
*/

#include "my_rpg.h"

void update_bar(game_t *game, size_t e)
{
    sfVector2f s;

    s = sfRectangleShape_getSize(game->hud.mana.bg);
    sfVector2f size = sfRectangleShape_getSize(game->hud.mana.rect);
    if (!(sfKeyboard_isKeyPressed(sfKeyLShift)  \
    || sfKeyboard_isKeyPressed(sfKeyRShift))   \
    && game->player.stats.speed == 40 && size.x < s.x)
        size.x = (size.x + 1 * e < s.x ? size.x + 1 * e : s.x);
    else if (game->player.stats.speed == 1000 && size.x > 0)
        size.x = (size.x - 2 * e > 0 ? size.x - 2 * e : 0);
    sfRectangleShape_setSize(game->hud.mana.rect, size);
}
