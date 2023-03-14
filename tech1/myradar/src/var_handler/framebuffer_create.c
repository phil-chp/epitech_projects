/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** framebuffer_create
*/

#include <stdlib.h>
#include "../includes/struct.h"

framebuffer_t *framebuffer_create(void)
{
    framebuffer_t *fb;

    fb = malloc(sizeof(*fb));
    if (!fb) return (NULL);
    fb->width = WIDTH;
    fb->height = HEIGHT;
    fb->pixels = malloc(sizeof(sfUint8) * (WIDTH * HEIGHT * 4));
    if (!fb->pixels) {
        free(fb);
        return (NULL);
    }
    return (fb);
}
