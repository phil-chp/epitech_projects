/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** windows
*/

#ifndef WINDOWS_H_
#define WINDOWS_H_

#include <stdbool.h>
#include "my_rpg.h"

int (*windows[3])(sfRenderWindow **win, bool *game_mode) = {
    game_loop,
    other_loop,
    settings_loop
};

#endif /* WINDOWS_H_ */
