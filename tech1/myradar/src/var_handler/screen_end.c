/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** radar_end
*/

#include <stdlib.h>
#include "../includes/struct.h"

void screen_end(framebuffer_t *fb, vars_t *va, pos_t *pos)
{
    framebuffer_destroy(fb);
    sfSprite_destroy(va->sprite);
    sfTexture_destroy(va->texture);
    sfRenderWindow_destroy(va->window);
    free(va);
    free(pos->p_delay);
    free(pos->p_speed);
    free(pos->p_dest);
    free(pos->planes);
    free(pos->t_radius);
    free(pos->towers_area);
    free(pos->towers);
    free(pos);
}
