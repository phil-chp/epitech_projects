/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** menu_data
*/

#ifndef MENU_DATA_H_
#define MENU_DATA_H_

#include <stdbool.h>
#include "my_rpg.h"

typedef struct button_s {
    sfRectangleShape *rect;
    sfFloatRect pos_size;
    sfText *text;
} button_t;

typedef struct slider_s {
    sfRectangleShape *slide;
    sfRectangleShape *rect;
    sfFloatRect pos_size;
    bool random_texture;
    sfText *text;
} slider_t;

typedef struct menu_s {
    sfVector2f counts;
    button_t *button;
    slider_t *slider;
    sfMusic *music;
    sfSprite *bg;
} menu_t;

#endif /* MENU_DATA_H_ */
