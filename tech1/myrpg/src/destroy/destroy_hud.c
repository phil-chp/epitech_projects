/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** destroy_hud
*/

#include "my_rpg.h"

void destroy_hud_text(hud_t *hud)
{
    if (hud->bombs.text)     sfText_destroy(hud->bombs.text);
    if (hud->stars.text)     sfText_destroy(hud->stars.text);
    if (hud->keys.text)      sfText_destroy(hud->keys.text);
    if (hud->arms.text)      sfText_destroy(hud->arms.text);
    if (hud->special.text)   sfText_destroy(hud->special.text);
    if (hud->jump.text)      sfText_destroy(hud->jump.text);
    if (hud->defense.text)   sfText_destroy(hud->defense.text);
    if (hud->speed.text)     sfText_destroy(hud->speed.text);
    if (hud->attack.text)    sfText_destroy(hud->attack.text);
}

void destroy_hud(hud_t *hud)
{
    if (hud->health.rect)    sfRectangleShape_destroy(hud->health.rect);
    if (hud->health.bg)      sfRectangleShape_destroy(hud->health.bg);
    if (hud->mana.rect)      sfRectangleShape_destroy(hud->mana.rect);
    if (hud->mana.bg)        sfRectangleShape_destroy(hud->mana.bg);
    if (hud->health.sprite)  sfSprite_destroy(hud->health.sprite);
    if (hud->bombs.sprite)   sfSprite_destroy(hud->bombs.sprite);
    if (hud->stars.sprite)   sfSprite_destroy(hud->stars.sprite);
    if (hud->keys.sprite)    sfSprite_destroy(hud->keys.sprite);
    if (hud->arms.sprite)    sfSprite_destroy(hud->arms.sprite);
    if (hud->speed.sprite)   sfSprite_destroy(hud->speed.sprite);
    if (hud->defense.sprite) sfSprite_destroy(hud->defense.sprite);
    if (hud->jump.sprite)    sfSprite_destroy(hud->jump.sprite);
    if (hud->special.sprite) sfSprite_destroy(hud->special.sprite);
    if (hud->attack.sprite)  sfSprite_destroy(hud->attack.sprite);
    if (hud->minimap.sprite) sfSprite_destroy(hud->minimap.sprite);
    if (hud->minimap.circle) sfCircleShape_destroy(hud->minimap.circle);
    destroy_hud_text(hud);
}
