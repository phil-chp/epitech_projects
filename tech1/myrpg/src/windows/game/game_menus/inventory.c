/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** inventory
*/

#include "my_rpg.h"
#include "my.h"

static void handle_inventory_events(sfRenderWindow **win,    \
                                    sfEvent *event,          \
                                    int *check_return)
{
    switch (event->type) {
        case (sfEvtClosed):
            sfRenderWindow_close(*win);
            break;
        case (sfEvtKeyPressed):
            (*check_return)                      \
            = (event->key.code == sfKeyEscape    \
            || event->key.code == sfKeyI ? 1 : 0);
            break;
        default:
            break;
    }
}

static int get_inventory(inv_t *inv, char *path, game_t *game)
{
    sfTexture *texture;
    sfVector2f pos;

    if (!(texture = sfTexture_createFromFile(path, NULL)))
        return (1);
    if (!(inv->background = sfSprite_create()))
        return (1);
    pos = (sfVector2f){ WIDTH / 2 - 800 / 2, HEIGHT / 2 - 600 / 2 };
    if (handle_inventory_sliders(inv, pos, &game->player.stats))
        return (1);
    handle_star_counter(inv, game->player.stats.stars);
    sfSprite_setTexture(inv->background, texture, sfFalse);
    sfSprite_setPosition(inv->background, pos);
    return (0);
}

int inventory_loop(sfRenderWindow **win, game_t *game)
{
    int check_return = 0;
    sfSprite *screenshot;
    inv_t inventory;
    sfEvent event;

    if (get_screenshot(&screenshot, *win)) return (84);
    if (get_inventory(&inventory, "assets/hud/inventory.jpg", game))
        return (84);
    sfRenderWindow_setMouseCursorVisible(*win, true);
    while (check_return == 0 && sfRenderWindow_isOpen(*win)) {
        while (sfRenderWindow_pollEvent(*win, &event))
            handle_inventory_events(win, &event, &check_return);
        sfRenderWindow_clear(*win, sfBlack);
        render_inventory_elements(win, game, &inventory, &screenshot);
        handle_inventory_interaction(win, &inventory, &game->player);
        sfRenderWindow_display(*win);
    }
    destroy_inventory(&inventory, &screenshot);
    sfRenderWindow_setMouseCursorVisible(*win, false);
    return ((check_return ? 1 : 0));
}
