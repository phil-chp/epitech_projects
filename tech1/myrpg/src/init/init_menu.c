/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** menu
*/

#include "my_rpg.h"

static int handle_buttons(button_t **buttons, size_t count)
{
    char *texts[] = {"PLAY", "HOW TO PLAY", "SETTINGS", "EXIT"};
    sfFloatRect pos_sizes;

    if (count == 0)
        return (0);
    pos_sizes = (sfFloatRect){ 660, 360, 600, 100 };
    if (create_button_list(buttons, count, texts, pos_sizes))
        return (1);
    return (0);
}

static int handle_sliders(slider_t **sliders, int count)
{
    char *texts[] = {"SFX", "MUSIC"};
    sfFloatRect pos_sizes;

    if (count == 0)
        return (0);
    pos_sizes = (sfFloatRect){ 660, 360, 600, 100 };
    if (create_slider_list(sliders, count, texts, pos_sizes))
        return (1);
    return (0);
}

bool init_menu( menu_t *menu,        \
                sfVector2f counts,  \
                char *music)
{
    char background[] = "assets/hud/background.png";
    sfTexture *bg_texture;
    sfVector2f empty;

    empty = (sfVector2f){0, 0};
    if (!(bg_texture = sfTexture_createFromFile(background, NULL)))
        return (1);
    if (!(menu->bg = create_sprite(bg_texture, &empty, &empty, sfTrue)))
        return (1);
    if (counts.x || counts.y) menu->counts = counts;
    if (handle_buttons(&menu->button, menu->counts.x)) return (1);
    if (handle_sliders(&menu->slider, menu->counts.y)) return (1);
    menu->music = (music ? sfMusic_createFromFile(music) : NULL);
    if (music && !menu->music) return (1);
    return (0);
}
