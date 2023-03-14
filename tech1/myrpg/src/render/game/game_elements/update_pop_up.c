/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** update_pop_up
*/

#include "my_rpg.h"
#include <stdbool.h>

void update_pop_up(sfRenderWindow **win, pop_up_t *pop_up)
{
    if (pop_up->enabled == true ) {
        sfRenderWindow_drawSprite(*win, pop_up->pop_up, NULL);
        sfRenderWindow_drawText(*win, pop_up->text[0], NULL);
        sfRenderWindow_drawText(*win, pop_up->text[1], NULL);
    }
}
