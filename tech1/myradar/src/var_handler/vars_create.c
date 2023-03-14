/*
** EPITECH PROJECT, 2020
** my_radar (Workspace)
** File description:
** vars_create
*/

#include <stdlib.h>
#include "../includes/struct.h"

vars_t *vars_create(framebuffer_t *fb)
{
    sfTexture *no_texture;
    vars_t *va;

    va = malloc(sizeof(*va));
    if (!va) return (NULL);
    va->mode.width = fb->width;
    va->mode.height = fb->height;
    va->mode.bitsPerPixel = PIXELS;
    va->window = sfRenderWindow_create(va->mode, "My Radar", sfClose, NULL);
    va->texture = sfTexture_create(fb->width, fb->height);
    no_texture = sfTexture_createFromFile("assets/background.jpg", NULL);
    va->sprite = sfSprite_create();
    va->background = sfSprite_create();
    sfSprite_setTexture(va->background, no_texture, sfFalse);
    return (va);
}
