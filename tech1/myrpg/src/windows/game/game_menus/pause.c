/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** pause_menu
*/

#include "my_rpg.h"

static void handle_pause_events(sfRenderWindow **win,    \
                                sfEvent *event,          \
                                int *check_return)
{
    switch (event->type) {
        case (sfEvtClosed):
            sfRenderWindow_close(*win);
            break;
        case (sfEvtKeyPressed):
            (*check_return) = (event->key.code == sfKeyEscape ? 1 : 0);
            break;
        default:
            break;
    }
}

static int init_pause_menu(menu_t *pau,        \
                            sfVector2f counts, \
                            char *music)
{
    char *strings[] = { "RESUME", "EXIT" };
    sfVector2f text_pos;

    if (init_menu(pau, counts, music))
        return (1);
    for (size_t i = 0; i < pau->counts.x; i++) {
        sfText_setString(pau->button[i].text, strings[i]);
        sfVector2f button_pos   \
        = sfRectangleShape_getPosition(pau->button[i].rect);
        text_pos = calculate_text_position(strings[i], button_pos,  \
        (sfVector2f){600, 100}, 50);
        sfText_setPosition(pau->button[i].text, text_pos);
    }
    return (0);
}

int pause_loop(sfRenderWindow **win)
{
    int check_return = 0;
    sfSprite *screenshot;
    sfEvent event;
    menu_t pau;

    if (get_screenshot(&screenshot, *win)) return (84);
    if (init_pause_menu(&pau, (sfVector2f){2, 0}, NULL)) return (84);
    sfRenderWindow_setMouseCursorVisible(*win, true);
    while (check_return == 0 && sfRenderWindow_isOpen(*win)) {
        while (sfRenderWindow_pollEvent(*win, &event))
            handle_pause_events(win, &event, &check_return);
        sfRenderWindow_clear(*win, sfBlack);
        sfRenderWindow_drawSprite(*win, screenshot, NULL);
        if (check_return == 0)
            check_return = handle_button_interaction(win, &pau) + 1;
        sfRenderWindow_display(*win);
    }
    destroy_menu(&pau);
    sfRenderWindow_setMouseCursorVisible(*win, false);
    return ((check_return == 2 ? 0 : 1));
}
