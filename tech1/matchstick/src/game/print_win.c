/*
** EPITECH PROJECT, 2021
** matchstick (Workspace)
** File description:
** print_win
*/

#include "matchstick.h"
#include "my.h"

void print_win(int return_code)
{
    if (return_code == PL_W)
        my_lprintf("I lost... snif... but I'll get you next time!!\n");
    else if (return_code == AI_W)
        my_lprintf("You lost, too bad...\n");
}
