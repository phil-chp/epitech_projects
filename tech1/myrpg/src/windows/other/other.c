/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** other
*/

#include "my_rpg.h"

static void handle_other_events( sfRenderWindow **win, sfEvent *event)
{
    if (event->type == sfEvtClosed)
            sfRenderWindow_close(*win);
}

static void set_other_elements_positions(sfSprite **how_to_play, menu_t *oth)
{
    sfVector2f temp;
    sfVector2f pos;

    pos = (sfVector2f){WIDTH / 2 - 500, HEIGHT / 2 - 240};
    sfSprite_setPosition((*how_to_play), pos);
    temp = sfRectangleShape_getPosition(oth->button[0].rect);
    temp.y += 550;
    sfRectangleShape_setPosition(oth->button[0].rect, temp);
    temp = sfText_getPosition(oth->button[0].text);
    temp.y += 550;
    sfText_setPosition(oth->button[0].text, temp);
}

bool init_other_menu(   menu_t *oth,        \
                        sfVector2f counts,  \
                        char *music,        \
                        sfSprite **how_to_play)
{
    char path[] = "assets/hud/map/howtoplay.png";
    sfTexture *texture;

    if (init_menu(oth, counts, music))
        return (1);
    if (!((*how_to_play) = sfSprite_create()))
        return (1);
    texture = sfTexture_createFromFile(path, NULL);
    sfText_setString(oth->button[0].text, "RETURN");
    sfSprite_setTexture(*how_to_play, texture, sfFalse);
    set_other_elements_positions(how_to_play, oth);
    return (0);
}

void render_other_elements( sfRenderWindow **win,   \
                            menu_t *menu,           \
                            sfSprite **how_to_play)
{
    sfRenderWindow_drawSprite(*win, menu->bg, NULL);
    sfRenderWindow_drawSprite(*win, *how_to_play, NULL);
}

int other_loop(sfRenderWindow **win, bool *none)
{
    sfSprite *how_to_play = NULL;
    int return_code = -1;
    sfEvent event;
    menu_t oth;

    if (none) {}
    init_other_menu(&oth, (sfVector2f){ 1, 0 }, NULL, &how_to_play);
    WAIT_FOR_BUTTON_RELEASE;
    while (return_code == -1 && sfRenderWindow_isOpen(*win)) {
        while (sfRenderWindow_pollEvent(*win, &event))
            handle_other_events(win, &event);
        sfRenderWindow_clear(*win, sfBlack);
        render_other_elements(win, &oth, &how_to_play);
        return_code = handle_button_interaction(win, &oth);
        sfRenderWindow_display(*win);
    }
    destroy_menu(&oth);
    return (-1);
}
