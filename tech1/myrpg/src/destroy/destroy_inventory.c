/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** destroy_inventory
*/

#include "game_data.h"

void destroy_inventory(inv_t *inv, sfSprite **screenshot)
{
    for (size_t i = 0; i < 8; i++)
        for (size_t j = 0; j < 12; j++)
            if (inv->rect[i][j]) sfRectangleShape_destroy(inv->rect[i][j]);
    for (size_t i = 0; i < 4; i++)
        if (inv->orbs[i]) sfCircleShape_destroy(inv->orbs[i]);
    if (inv->background) sfSprite_destroy(inv->background);
    if (inv->star_count) sfText_destroy(inv->star_count);
    if (*screenshot) sfSprite_destroy(*screenshot);
    if (inv->star) sfSprite_destroy(inv->star);
}
