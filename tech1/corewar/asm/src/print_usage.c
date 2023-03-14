/*
** EPITECH PROJECT, 2020
** print_usage.c
** File description:
** print usage
*/

#include "asm.h"

void print_usage(void)
{
    miniprint("%s\n", "USAGE\n./asm file_name[.s]");
    miniprint("%s", "DESCRIPTION\nfile_name file in assembly language to be");
    miniprint("%s", " converted into file_name.cor, an executable ");
    miniprint("%s\n", "in the Virtual Machine.");
}