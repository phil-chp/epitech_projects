/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** framebuffer_destroy
*/

#include <stdlib.h>
#include "../includes/struct.h"

void framebuffer_destroy(framebuffer_t *fb)
{
    free(fb->pixels);
    free(fb);
    return;
}
