/*
** EPITECH PROJECT, 2021
** dante (Workspace)
** File description:
** error_handling
*/

#include "my.h"

int error_handling(int return_code)
{
    my_putstr("USAGE\n\t/solver maze_file\n\nDESCRIPTION\n");
    my_putstr("\tmaze_file\tfile containing a valid maze");
    my_putstr("(composed of 'X' and '*')\n");
    return (return_code);
}
