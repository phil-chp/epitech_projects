/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** main
*/

#include <stdlib.h>
#include "windows.h"
#include "my.h"

int main(void)
{
    char name[] = "My RPG";
    int return_code = -1;
    sfRenderWindow *win;
    bool gm = 0;

    srand((unsigned long)&init_window);
    if (init_window(&win, name))
        return (84);
    while (return_code == -1) {
        return_code = menu_loop(&win, &gm);
        if (return_code > -1 && return_code < 3)
            return_code = windows[return_code](&win, &gm);
    }
    if (sfRenderWindow_isOpen(win)) sfRenderWindow_close(win);
    if (win) sfRenderWindow_destroy(win);
    return ((return_code != 84 ? 0 : 84));
}
