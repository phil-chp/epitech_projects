/*
** EPITECH PROJECT, 2020
** B-MUL-200-NCE-2-1-myrpg-theo.guichard
** File description:
** create_hud.c
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my.h"

int create_info(info_t *info, char *path, sfVector2f *pos, char *nbr)
{
    sfVector2f text_pos;
    sfTexture *tx;

    text_pos = (sfVector2f){ pos->x + 50, pos->y };
    if (!(tx = sfTexture_createFromFile(path, NULL)))
        return (1);
    if (!(info->sprite = create_sprite(tx, pos, NULL, sfTrue)))
        return (1);
    if (!(info->text = create_text(nbr, text_pos, sfWhite, 25)))
        return (1);
    pos->y += 54;
    return (0);
}

static int create_bar(  bar_t *bar,         \
                        char *path,        \
                        sfVector2f *pos,    \
                        bar_maker_t *maker)
{
    sfVector2f size;
    sfTexture *tx;
    sfVector2f temp;

    temp = (sfVector2f){ (*pos).x + 50, (*pos).y };
    size = (sfVector2f){ maker->value, 40 };
    if (!(tx = sfTexture_createFromFile(path, NULL)))
        return (1);
    if (!(bar->sprite = create_sprite(tx, pos, NULL, sfFalse)))
        return (1);
    if (!(bar->rect = create_rectangle(temp, size, NULL)))
        return (1);
    if (!(bar->bg = create_rectangle(temp, size, NULL)))
        return (1);
    sfRectangleShape_setFillColor(bar->rect, maker->color);
    sfRectangleShape_setFillColor(bar->bg, (sfColor){12, 12, 12, 127});
    pos->y += 52;
    return (0);
}

char **create_paths(void)
{
    char **paths;

    if (!(paths = malloc(sizeof(char *) * 12))) return (NULL);
    paths[0]  = my_strdup("assets/hud/info/health.png");
    paths[1]  = my_strdup("assets/hud/info/mana.png");
    paths[2]  = my_strdup("assets/items/star.png");
    paths[3]  = my_strdup("assets/items/bomb.png");
    paths[4]  = my_strdup("assets/items/key.png");
    paths[5]  = my_strdup("assets/hud/info/speed.png");
    paths[6]  = my_strdup("assets/hud/info/arms.png");
    paths[7]  = my_strdup("assets/hud/info/defense.png");
    paths[8]  = my_strdup("assets/hud/info/jump.png");
    paths[9]  = my_strdup("assets/hud/info/special.png");
    paths[10] = my_strdup("assets/hud/info/attack.png");
    paths[11] = my_strdup("assets/hud/info/minimap.png");
    for (size_t i = 0; i < 12; i++)
        if (!paths[i]) return (NULL);
    return (paths);
}

static bool init_info(  hud_t *hud,             \
                        char **p,              \
                        sfVector2f (*pos)[2],   \
                        stats_t *stats)
{
    if ((create_info(&hud->stars, p[2], pos[0], my_getstr(stats->stars))))
        return (1);
    if ((create_info(&hud->bombs, p[3], pos[0], my_getstr(stats->bombs))))
        return (1);
    if ((create_info(&hud->keys, p[4], pos[0], my_getstr(stats->keys))))
        return (1);
    if ((create_info(&hud->speed, p[5], pos[0], my_getstr(stats->speed))))
        return (1);
    if ((create_info(&hud->arms, p[6], pos[0], my_getstr(stats->arms))))
        return (1);
    if ((create_info(&hud->defense, p[7], pos[0], my_getstr(stats->defense))))
        return (1);
    if ((create_info(&hud->jump, p[8], pos[0], my_getstr(stats->jump))))
        return (1);
    if ((create_info(&hud->attack, p[9], pos[0], my_getstr(stats->attack))))
        return (1);
    if ((create_info(&hud->special, p[10], pos[0], my_getstr(stats->special))))
        return (1);
    return (0);
}

bool init_hud(hud_t *hud, entity_t *pl)
{
    sfVector2f pos[] = { { 15, 250 }, { 250, 15 } };
    bar_maker_t maker[] = {
        { sfRed, pl->stats.health }, { sfBlue, pl->stats.mana }
    };
    char **paths = NULL;

    if (!(paths = create_paths()))                                 return (1);
    if ((create_bar(&hud->health, paths[0], &pos[1], &maker[0]))) return (1);
    if ((create_bar(&hud->mana, paths[1], &pos[1], &maker[1])))   return (1);
    if ((init_info(hud, paths, &pos, &pl->stats)))                 return (1);
    if ((create_minimap(hud, pos, paths[11])))                    return (1);
    for (size_t i = 0; i < 12; i++) free(paths[i]);
    if (paths) free(paths);
    sfSprite_setScale(hud->keys.sprite, (sfVector2f) {3.125, 3.125});
    return (0);
}
