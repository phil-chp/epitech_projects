/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** create_door.c
*/

#include <stdbool.h>
#include "my_rpg.h"

bool create_door(door_t *door, sfVector2f pos, bool right)
{
    sfVector2f size = {112, 112};
    sfTexture *dr_textu;
    sfIntRect rect = {49, 0, 49, 33};

    dr_textu = sfTexture_createFromFile("assets/elements/door.png", NULL);
    if (!dr_textu) return (1);
    door->door = create_rectangle(pos, size, dr_textu);
    if (!door->door) return (1);
    door->is_open = false;
    door->disabled = false;
    sfRectangleShape_setOrigin(door->door, (sfVector2f){ size.x / 2, size.y });
    sfRectangleShape_setTextureRect(door->door, rect);
    sfRectangleShape_setRotation(door->door, (right ? 90 : -90));
    return (0);
}
