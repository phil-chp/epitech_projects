/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** create_sprite
*/

#include <SFML/Graphics.h>

sfSprite *create_sprite(sfTexture *texture,     \
                        sfVector2f *pos,        \
                        sfVector2f *origin,     \
                        sfBool     animation)
{
    sfSprite *sprite;

    if (!(sprite = sfSprite_create()))
        return (NULL);
    if (texture) sfSprite_setTexture(sprite, texture, animation);
    if (pos) sfSprite_setPosition(sprite, *pos);
    if (origin) sfSprite_setOrigin(sprite, *origin);
    return (sprite);
}
