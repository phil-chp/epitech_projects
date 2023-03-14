/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** fill_arena
*/

#include "corewar.h"
#include "op.h"

static void write_champ_code_on_arena(champs_t *champ, __u_char **arena)
{
    char hex_byte[2];
    size_t hex_size;
    int offset = 0;
    char dec_byte;

    hex_size = (size_t)champ->content.prog_size * 2;
    for (size_t i = 0, j = 0; i < hex_size; i++, j++) {
        if (champ->pos + j - offset > 4095)
            offset += 4096;
        hex_byte[0] = champ->code_byte[i++];
        hex_byte[1] = champ->code_byte[i];
        dec_byte = hex_to_deci(hex_byte);
        (*arena)[champ->pos + j - offset] = dec_byte;
    }
}

bool fill_arena(champs_t **champs, __u_char **arena)
{
    char champ_count;
    champs_t *iter;
    short spacing;

    if (!((*arena) = malloc(sizeof(char) * ARENA_SIZE)))
        return (1);
    for (size_t i = 0; i < ARENA_SIZE; i++)
        (*arena)[i] = 0;
    for (iter = (*champs)->head; iter->next; iter = iter->next);
    champ_count = iter->id;
    spacing = (champ_count == 1 ? 0 : ARENA_SIZE / champ_count);
    iter = (*champs)->head;
    for (size_t i = 0; i < (size_t)champ_count; i++) {
        iter->pos = i * spacing;
        write_champ_code_on_arena(iter, arena);
        iter = iter->next;
    }
    return (0);
}
