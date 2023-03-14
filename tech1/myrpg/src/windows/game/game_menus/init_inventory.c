/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** init_inventory
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my.h"

char **get_inventory_paths(void)
{
    char **paths;

    if (!(paths = malloc(sizeof(char *) * 8))) return (NULL);
    paths[0]  = my_strdup("assets/hud/info/health.png");
    paths[1]  = my_strdup("assets/hud/info/mana.png");
    paths[2]  = my_strdup("assets/hud/info/speed.png");
    paths[3]  = my_strdup("assets/hud/info/arms.png");
    paths[4]  = my_strdup("assets/hud/info/defense.png");
    paths[5]  = my_strdup("assets/hud/info/jump.png");
    paths[6]  = my_strdup("assets/hud/info/special.png");
    paths[7] = my_strdup("assets/hud/info/attack.png");
    for (size_t i = 0; i < 8; i++)
        if (!paths[i]) return (NULL);
    return (paths);
}

bool handle_inventory_sliders(inv_t *inv, sfVector2f pos, stats_t *stats)
{
    sfVector2f orb_pos[] = {{1061, 470}, {1090, 373}, {1192, 373}, {1219, 470}};
    char **path = get_inventory_paths();
    sfColor c[] = {sfWhite, {0, 252, 254, 255}, {6, 254, 21, 255}, sfRed};
    sfFloatRect pos_size;

    pos_size = (sfFloatRect){ pos.x + 62, pos.y + 63, 338, 34 };
    if (create_inventory_list(&inv->rect, 12, path, pos_size))
        return (1);
    if (!(inv->orbs = malloc(sizeof(sfCircleShape *) * 4)))
        return (1);
    for (size_t i = 0; i < 4; i++) {
        inv->orbs[i] = create_circle(orb_pos[i], 20, NULL);
        sfCircleShape_setFillColor(inv->orbs[i], c[i]);
        sfCircleShape_setOutlineColor(inv->orbs[i], c[i]);
        sfCircleShape_setOutlineThickness(inv->orbs[i], 1.0f);
    }
    return (0);
}

bool handle_star_counter(inv_t *inv, size_t star_n)
{
    sfTexture *texture;
    char *stars;

    stars = my_getstr(star_n);
    texture = sfTexture_createFromFile("assets/items/star.png", NULL);
    inv->star = sfSprite_create();
    sfSprite_setTexture(inv->star, texture, sfFalse);
    inv->star_count = create_text(stars, (sfVector2f){1185, 677}, sfBlack, 70);
    sfSprite_setPosition(inv->star, (sfVector2f){1085, 680});
    sfSprite_setScale(inv->star, (sfVector2f){3.0f, 3.0f});
    return (0);
}
