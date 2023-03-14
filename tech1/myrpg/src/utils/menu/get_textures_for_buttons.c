/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** get_textures_for_buttons
*/

#include <stdlib.h>
#include "my_rpg.h"

sfTexture **get_textures_for_buttons(char *path, size_t n)
{
    sfIntRect area[] = {{0, 0, 599, 99}, {0, 100, 599, 99}};
    sfTexture **textures;

    if (!(textures = malloc(sizeof(sfTexture *) * n)))
        return (NULL);
    for (size_t i = 0; i < n; i++)
        textures[i] = sfTexture_createFromFile(path, &area[i]);
    if (n % 2)
        textures[n] = sfTexture_createFromFile(path, &area[0]);
    return (textures);
}
