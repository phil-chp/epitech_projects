/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** menu
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "my_rpg.h"

static void handle_menu_events(sfRenderWindow **win, sfEvent *event)
{
    if (event->type == sfEvtClosed)
            sfRenderWindow_close(*win);
}

static void edit_button_data(menu_t *menu)
{
    sfVector2f button_pos;
    sfVector2f text_pos;
    sfVector2f size;
    char *strings[3] = {"RESUME", "NEW GAME", "RETURN"};

    size = (sfVector2f){600, 100};
    button_pos = sfRectangleShape_getPosition(menu->button[0].rect);
    for (size_t i = 0; i < 3; i++) {
        sfText_setString(menu->button[i].text, strings[i]);
        text_pos = calculate_text_position(strings[i], button_pos, size, 50);
        sfText_setPosition(menu->button[i].text, text_pos);
        button_pos.y += 130;
    }
}

int init_gamemode_menu(menu_t *menu,         \
                        sfVector2f counts,   \
                        char *music)
{
    if (init_menu(menu, counts, music))
        return (1);
    edit_button_data(menu);
    return (0);
}

void check_if_saved(int *check)
{
    char *res;
    int fd;

    if ((fd = open("assets/save_map.rpg", O_RDONLY)) == -1) {
        (*check) = 0;
        return;
    }
    if ((fd = open("assets/save_stats.rpg", O_RDONLY)) == -1) {
        (*check) = 0;
        return;
    }
    (*check) = 1;
    close(fd);
}

int gamemode_chooser(sfRenderWindow **win, bool *game_mode)
{
    sfEvent event;
    int ret = -1;
    menu_t gm;

    if (init_gamemode_menu(&gm, (sfVector2f){3, 0}, NULL)) return (84);
    WAIT_FOR_BUTTON_RELEASE;
    while (ret == -1 && sfRenderWindow_isOpen(*win)) {
        while (sfRenderWindow_pollEvent(*win, &event))
            handle_menu_events(win, &event);
        sfRenderWindow_clear(*win, sfBlack);
        render_elements(win, &gm);
        ret = handle_button_interaction(win, &gm);
        if (!ret) check_if_saved(&ret);
        sfRenderWindow_display(*win);
    }
    if (!ret || ret) (*game_mode) = !ret;
    if (sfRenderWindow_isOpen(*win) == sfFalse) ret = 3;
    destroy_menu(&gm);
    WAIT_FOR_BUTTON_RELEASE;
    return ((ret ? 0 : (ret == 2 ? -1 : (ret == 3 ? 4 : ret))));
}
