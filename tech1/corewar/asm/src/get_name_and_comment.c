/*
** EPITECH PROJECT, 2020
** get_name_and_comment.c
** File description:
** get name and comment
*/

#include "asm.h"

int get_name(asmb_t *asmm, header_t *header)
{
    short i = 0, j = 0;
    char *str = asmm->tab[0];

    for (; str[i] && str[i] != '"'; i++);
    if (my_strlen(&str[i]) > PROG_NAME_LENGTH) return-1;
    for (i++; j <= PROG_NAME_LENGTH && str[i] && str[i] != '"'; i++, j++)
        header->prog_name[j] = str[i];
    if (j > PROG_NAME_LENGTH) return ERROR_VERIF;
    for (; j <= PROG_NAME_LENGTH; j++)
        header->prog_name[j] = 0;
    return 0;
}

int get_comment(asmb_t *asmm, header_t *header)
{
    short i = 0, j = 0;
    char *str = asmm->tab[1];

    for (;str[i] && str[i] != '"'; i++);
    if (my_strlen(&str[i]) > COMMENT_LENGTH) return -1;
    for (i++; j <= COMMENT_LENGTH && str[i] && str[i] != '"'; i++, j++)
        header->comment[j] = str[i];
    if (j > COMMENT_LENGTH) return ERROR_VERIF;
    for (; j <= COMMENT_LENGTH; j++)
        header->comment[j] = 0;
    return 0;
}
