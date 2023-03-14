/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** main
*/

#include <stdlib.h>
#include "struct.h"
#include "lib.h"
#include "my.h"

static void help_menu(void)
{
    my_putstr("USAGE");
    my_putstr("    Usage: ./my_radar [file]");
    my_putstr("DESCRIPTION");
    my_putstr("    file   path to the .rdr file containing info on");
    my_putstr("           airplanes and control towers");
}

static int param_handling(char **av)
{
    if (av[1][0] == '-' && av[1][1] == 'h') {
        help_menu();
        return (1);
    }
    return (0);
}

static void event_handler(vars_t *va)
{
    if (va->event.type == sfEvtClosed)
        sfRenderWindow_close(va->window);
}

static void main_loop(framebuffer_t *fb, vars_t *va, pos_t *pos)
{
    set_orientation(pos);
    while (sfRenderWindow_isOpen(va->window)) {
        while (sfRenderWindow_pollEvent(va->window, &va->event))
            event_handler(va);
        sfRenderWindow_clear(va->window, sfBlack);
        sfRenderWindow_drawSprite(va->window, va->background, NULL);
        check_collision(pos);
        move_planes(va, pos);
        sfTexture_updateFromPixels(va->texture, fb->pixels,    \
                                    fb->width, fb->height, 0, 0);
        sfRenderWindow_drawSprite(va->window, va->sprite, NULL);
        sfRenderWindow_display(va->window);
    }
}

int main(int ac, char **av)
{
    framebuffer_t *fb;
    vars_t *va;
    pos_t *pos;

    if (ac != 2) {
        BAD_FILE;
        return (84);
    }
    if (param_handling(av) == 1) return (0);
    if ((fb = framebuffer_create()) == NULL) return (84);
    if ((va = vars_create(fb)) == NULL) return (84);
    sfSprite_setTexture(va->sprite, va->texture, sfTrue);
    sfRenderWindow_setFramerateLimit(va->window, FPS);
    if ((pos = get_positions(av[1])) == NULL) {
        BAD_FILE;
        return (84);
    }
    main_loop(fb, va, pos);
    screen_end(fb, va, pos);
    return (0);
}
