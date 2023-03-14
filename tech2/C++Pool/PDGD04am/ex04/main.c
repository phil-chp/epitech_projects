/*
** EPITECH PROJECT, 2022
** PDG-D4-AM (Workspace)
** File description:
** main
*/

#include "print.h"

void do_action(action_t action, const char *str);

int main(void)
{
    const char *str = "So long, and thanks for all the fish.";

    do_action(PRINT_NORMAL, str);
    do_action(PRINT_REVERSE, str);
    do_action(PRINT_UPPER, str);
    do_action(PRINT_42, str);
    return (0);
}
