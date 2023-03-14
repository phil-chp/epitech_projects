/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** handle_menu_interactions
*/

#include "my_rpg.h"
#include "my.h"

int handle_slider_interaction(sfRenderWindow **win, menu_t *mn)
{
    sfFloatRect pos_size;
    sfVector2f m_pos;
    sfVector2i t;

    t = sfMouse_getPositionRenderWindow(*win);
    m_pos = (sfVector2f){ (float)t.x, (float)t.y };
    for (size_t i = 0; i < mn->counts.y; i++) {
        pos_size = sfRectangleShape_getGlobalBounds(mn->slider[i].rect);
        if (GET_COLLISION(m_pos, pos_size)) {
            if (sfMouse_isButtonPressed(0)) update_slider(&mn->slider[i], t.x);
        }
        sfRenderWindow_drawRectangleShape(*win, mn->slider[i].rect, NULL);
        sfRenderWindow_drawRectangleShape(*win, mn->slider[i].slide, NULL);
        sfRenderWindow_drawText(*win, mn->slider[i].text, NULL);
    }
    return (-1);
}

void handle_stat_change(entity_t *pl, inv_t *inv, int i)
{
    size_t *stat;
    int temp;

    stat = get_stats_in_order(&pl->stats);
    if (sfMouse_isButtonPressed(0) && pl->stats.stars > 0) {
        pl->stats.stars--;
        (  i == 0 ? pl->stats.health++,  0       \
        : (i == 1 ? pl->stats.mana++,    0       \
        : (i == 2 ? pl->stats.speed++,   0       \
        : (i == 3 ? pl->stats.arms++,    0       \
        : (i == 4 ? pl->stats.defense++, 0       \
        : (i == 5 ? pl->stats.jump++,    0       \
        : (i == 6 ? pl->stats.special++, 0       \
        : (i == 7 ? pl->stats.attack++,  0 : 0))))))));
        sfText_setString(inv->star_count, my_getstr(pl->stats.stars));
        // SON ACHAT
    }
}

int handle_inventory_interaction(sfRenderWindow **win, inv_t *inv, entity_t *pl)
{
    sfColor green = {0, 255, 0, 100}, red = {255, 0, 0, 100}, color;
    sfFloatRect pos_size;
    sfVector2f m_pos;
    sfVector2i temp;

    temp = sfMouse_getPositionRenderWindow(*win);
    m_pos = (sfVector2f){ (float)temp.x, (float)temp.y };
    for (size_t i = 0; i < 8; i++) {
        color = (pl->stats.stars > 0 ? green : red);
        pos_size = sfRectangleShape_getGlobalBounds(inv->rect[i][11]);
        if (GET_COLLISION(m_pos, pos_size)) {
            color.a = 220;
            handle_stat_change(pl, inv, i);
        } else {
            color.a = 100;
        }
        sfRectangleShape_setFillColor(inv->rect[i][11], color);
    }
    return (-1);
}

int handle_button_interaction(sfRenderWindow **win, menu_t *mn)
{
    sfVector2f states[] = {{1, 1}, {1.0125, 1.0125}};
    sfFloatRect pos_size;
    sfVector2f m_pos;
    sfVector2i temp;

    temp = sfMouse_getPositionRenderWindow(*win);
    m_pos = (sfVector2f){ (float)temp.x, (float)temp.y };
    for (size_t i = 0; i < mn->counts.x; i++) {
        pos_size = sfRectangleShape_getGlobalBounds(mn->button[i].rect);
        if (GET_COLLISION(m_pos, pos_size)) {
            update_button(&mn->button[i], &states[1]);
            if (sfMouse_isButtonPressed(0)) return (i);
        } else {
            update_button(&mn->button[i], &states[0]);
        }
        sfRenderWindow_drawRectangleShape(*win, mn->button[i].rect, NULL);
        sfRenderWindow_drawText(*win, mn->button[i].text, NULL);
    }
    return (-1);
}
