/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-myrpg-theo.guichard
** File description:
** update_hud
*/

#include "my_rpg.h"

static void update_hud_second(sfRenderWindow **win, hud_t *hud)
{
    sfRenderWindow_drawRectangleShape((*win), hud->health.bg, NULL);
    sfRenderWindow_drawRectangleShape((*win), hud->health.rect, NULL);
    sfRenderWindow_drawRectangleShape((*win), hud->mana.bg, NULL);
    sfRenderWindow_drawRectangleShape((*win), hud->mana.rect, NULL);
    sfRenderWindow_drawCircleShape((*win), hud->minimap.circle, NULL);
    sfRenderWindow_drawText((*win), hud->stars.text, NULL);
    sfRenderWindow_drawText((*win), hud->keys.text, NULL);
    sfRenderWindow_drawText((*win), hud->bombs.text, NULL);
    sfRenderWindow_drawText((*win), hud->arms.text, NULL);
    sfRenderWindow_drawText((*win), hud->speed.text, NULL);
    sfRenderWindow_drawText((*win), hud->attack.text, NULL);
    sfRenderWindow_drawText((*win), hud->defense.text, NULL);
    sfRenderWindow_drawText((*win), hud->jump.text, NULL);
    sfRenderWindow_drawText((*win), hud->special.text, NULL);
    sfRenderWindow_drawText((*win), hud->minimap.text, NULL);
}

void render_hud(sfRenderWindow **win, hud_t *hud)
{
    if (!hud)
        return;
    sfRenderWindow_drawSprite((*win), hud->stars.sprite, NULL);
    sfRenderWindow_drawSprite((*win), hud->bombs.sprite, NULL);
    sfRenderWindow_drawSprite((*win), hud->keys.sprite, NULL);
    sfRenderWindow_drawSprite((*win), hud->arms.sprite, NULL);
    sfRenderWindow_drawSprite((*win), hud->speed.sprite, NULL);
    sfRenderWindow_drawSprite((*win), hud->attack.sprite, NULL);
    sfRenderWindow_drawSprite((*win), hud->defense.sprite, NULL);
    sfRenderWindow_drawSprite((*win), hud->jump.sprite, NULL);
    sfRenderWindow_drawSprite((*win), hud->health.sprite, NULL);
    sfRenderWindow_drawSprite((*win), hud->mana.sprite, NULL);
    sfRenderWindow_drawSprite((*win), hud->minimap.sprite, NULL);
    sfRenderWindow_drawSprite((*win), hud->special.sprite, NULL);
    update_hud_second(win, hud);
}
