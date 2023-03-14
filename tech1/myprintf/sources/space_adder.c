/*
** EPITECH PROJECT, 2020
** Space adder
** File description:
** Space adder
*/

#include "bsprintf.h"

void space_adder(unsigned int p)
{
    for (p; p >= 50; p -= 50)
        my_putstr("                                                  ");
    for (p; p >= 10; p -= 10)
        my_putstr("          ");
    for (p; p >= 1; p--)
        my_putstr(" ");
    return;
}