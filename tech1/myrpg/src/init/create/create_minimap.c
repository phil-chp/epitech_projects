/*
** EPITECH PROJECT, 2020
** B-MUL-200-NCE-2-1-myrpg-theo.guichard
** File description:
** create_minimap.c
*/

#include "my_rpg.h"

bool create_minimap(hud_t *hud, sfVector2f pos[], char *path)
{
    pos[0] = (sfVector2f){ 1650, 900 };
    if ((create_info(&hud->minimap, path, &pos[0], NULL)))
        return (1);
    if (!(hud->minimap.circle = sfCircleShape_create()))
        return (1);
    sfCircleShape_setRadius(hud->minimap.circle, 7);
    sfCircleShape_setFillColor(hud->minimap.circle, sfRed);
    sfCircleShape_setPosition(hud->minimap.circle, (sfVector2f){7, 2});
    return (0);
}
