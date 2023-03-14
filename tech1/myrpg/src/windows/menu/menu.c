/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** menu
*/

#include "my_rpg.h"

static void handle_menu_events(sfRenderWindow **win, sfEvent *event)
{
    if (event->type == sfEvtClosed)
            sfRenderWindow_close(*win);
}

int menu_loop(sfRenderWindow **win, bool *game_mode)
{
    sfEvent event;
    int ret = -1;
    menu_t menu;

    if (init_menu(&menu, (sfVector2f){4, 0}, NULL)) return (84);
    WAIT_FOR_BUTTON_RELEASE;
    while (ret == -1 && sfRenderWindow_isOpen(*win)) {
        while (sfRenderWindow_pollEvent(*win, &event))
            handle_menu_events(win, &event);
        sfRenderWindow_clear(*win, sfBlack);
        render_elements(win, &menu);
        ret = handle_button_interaction(win, &menu);
        if (!ret)
            ret = gamemode_chooser(win, game_mode);
        sfRenderWindow_display(*win);
    }
    if (sfRenderWindow_isOpen(*win) == sfFalse)
        ret = 3;
    destroy_menu(&menu);
    return (ret);
}
