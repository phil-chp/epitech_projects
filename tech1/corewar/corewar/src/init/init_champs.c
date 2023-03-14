/*
** EPITECH PROJECT, 2021
** corewar (Workspace)
** File description:
** init_champs
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "corewar.h"
#include "shared.h"
#include "op.h"

static bool get_code_from_file(char **code_byte, int fd, int prog_size)
{
    char temp[prog_size];

    if (lseek(fd, prog_size * -1, SEEK_END) == -1)
        return (1);
    if (read(fd, temp, prog_size) == -1)
        return (1);
    for (ssize_t i = 0; i < prog_size; i++)
        my_swap_endian(temp[i]);
    (*code_byte) = my_str_to_hex(temp, prog_size);
    return (0);
}

static champs_t *load_champs(header_t *temp, int fd, size_t id)
{
    champs_t *champ;

    if (!(champ = malloc(sizeof(champs_t))))
        return (NULL);
    champ->content     = (*temp);
    champ->id          = id;
    champ->regs[0]     = id;
    champ->t_cycle     = 0;
    champ->prev        = NULL;
    champ->state       = true;
    champ->code.params = NULL;
    champ->f_head      = NULL;
    for (size_t i = 1; i < 16; champ->regs[i] = 0, i++);
    champ->code_byte = malloc(sizeof(char) * (temp->prog_size  * 2 + 1));
    if (!champ->code_byte) {
        free (champ);
        return (NULL);
    }
    if (get_code_from_file(&champ->code_byte, fd, champ->content.prog_size))
        return (NULL);
    return (champ);
}

static bool champs_manager(champs_t **champs, champs_t **elem)
{
    champs_t *iter;

    if (!(*champs)) {
        (*champs) = (*elem);
        (*champs)->next = NULL;
        (*champs)->head = (*elem);
        (*champs)->prev = NULL;
    } else {
        for (iter = (*champs)->head; iter->next; iter = iter->next);
        (*elem)->next = NULL;
        (*elem)->head = (*champs)->head;
        (*elem)->prev = iter;
        iter->next = (*elem);
    }
    return (0);
}

bool init_champs(corewar_t *cw, char **params)
{
    champs_t *elem;
    header_t temp;
    size_t cor;
    int fd;

    cw->teams = 0;
    cw->champs = NULL;
    for (size_t i = 1; params[i]; i++) {
        cw->teams += 1;
        if ((cor = my_strlen(params[i]) - 4) < 1)         continue;
        if (check_dot_cor(params[i], cor))                continue;
        if ((fd = open(params[i], O_RDONLY, 0644)) == -1) return (1);
        if (read(fd, &temp, sizeof(header_t)) < 1)        return (1);
        temp.magic = my_swap_endian(temp.magic);
        temp.prog_size = my_swap_endian(temp.prog_size);
        if (!(elem = load_champs(&temp, fd, i)))          return (1);
        if (champs_manager(&cw->champs, &elem))           return (1);
    }
    return (!cw->champs);
}
