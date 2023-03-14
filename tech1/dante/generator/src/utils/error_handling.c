/*
** EPITECH PROJECT, 2021
** dante (Workspace)
** File description:
** error_handling
*/

#include "my.h"

int error_handling(int return_code)
{
    my_putstr("USAGE\n\t./generator x y [perfect]\n\nDESCRIPTION\n\tx\twidth");
    my_putstr("\n\ty\theight\n\tperfect\tif the maze should be perfect or not");
    my_putstr(" (give string \"perfect\")\n");
    return (return_code);
}
