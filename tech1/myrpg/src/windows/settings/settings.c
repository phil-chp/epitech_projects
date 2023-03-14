/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** settings
*/

#include "my_rpg.h"

static void handle_settings_events(sfRenderWindow **win, sfEvent *event)
{
    if (event->type == sfEvtClosed)
            sfRenderWindow_close(*win);
}

int settings_loop(sfRenderWindow **win, bool *none)
{
    int return_code = -1;
    sfEvent event;
    menu_t sett;
    if (none) {}
    if (init_settings_menu(&sett, (sfVector2f){ 1, 2 }, NULL))
        return (84);
    WAIT_FOR_BUTTON_RELEASE;
    while (return_code == -1 && sfRenderWindow_isOpen(*win)) {
        while (sfRenderWindow_pollEvent(*win, &event))
            handle_settings_events(win, &event);
        sfRenderWindow_clear(*win, sfBlack);
        render_elements(win, &sett);
        return_code = handle_button_interaction(win, &sett);
        if (return_code == -1)
            return_code = handle_slider_interaction(win, &sett);
        sfRenderWindow_display(*win);
    }
    destroy_menu(&sett);
    return (-1);
}
