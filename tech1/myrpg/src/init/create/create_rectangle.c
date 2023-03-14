/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** create_rectangle
*/

#include <SFML/Graphics.h>

sfRectangleShape *create_rectangle( sfVector2f pos,     \
                                    sfVector2f size,    \
                                    sfTexture *texture)
{
    sfRectangleShape *rectangle;

    if (!(rectangle = sfRectangleShape_create()))
        return (NULL);
    if (pos.x > -1) sfRectangleShape_setPosition(rectangle, pos);
    if (size.x > -1) sfRectangleShape_setSize(rectangle, size);
    if (texture) sfRectangleShape_setTexture(rectangle, texture, sfFalse);
    return (rectangle);
}
