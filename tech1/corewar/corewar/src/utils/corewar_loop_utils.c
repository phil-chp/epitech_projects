/*
** EPITECH PROJECT, 2020
** Epitech (Workspace)
** File description:
** is_alive.c
*/

#include "corewar.h"
#include "shared.h"

static void kill_champ(champs_t *iter)
{
    iter->state = false;
}

bool check_for_correct_code(code_t *code)
{
    bin_u tmp_two;
    bin_u tmp;
    int i = 0, n = 0;

    for (; code->types[i] != 0; i++);
    if (code->f == 1 || code->f == 9 || code->f == 12 || code->f == 15) i++;
    if (i != op_tab[code->f - 1].nbr_args) return (1);
    for (size_t k = 0; k < (size_t)i; k++) {
        tmp.c = op_tab[code->f - 1].type[k];
        for (tmp_two.c = code->types[k]; n < 8 && !tmp_two.b8; tmp_two.c >>= 1, n++)
            tmp.c >>= 1;
        if (tmp_two.b8 != tmp.b8)
            return (1);
    }
    return (0);
}

static __u_int read_and_check_instruction(  __u_char **arena,  \
                                            code_t *code,      \
                                            __u_int pos)
{
    pos = get_code_from_code_bytes(arena, code, pos);
    if (code->f == 0 || code->f > 16) return (pos);
    if (check_for_correct_code(code))
        code->f = 0;
    return (pos);
}

bool refresh_champions(champs_t *iter, __u_char **arena)
{
    if (iter->t_cycle > 0) {
        iter->t_cycle--;
        return (0);
    }
    iter->pos = read_and_check_instruction(arena, &iter->code, iter->pos);
    if (iter->code.f == 0 || iter->code.f > 16) {
        iter->t_cycle++;
        return (0);
    }
    iter->t_cycle = op_tab[iter->code.f - 1].nbr_cycles;
    return (0);
}

void who_is_alive(corewar_t *cw)
{
    champs_t *iter;
    int check = 0;
    for (size_t i = 0; i <= (size_t)cw->teams; i++) {
        for (iter = cw->champs->head; cw->teams > 1 && iter; iter = iter->next) {
            if (iter->state) {
                if (iter->id == i + 1) {
                    (cw->alive[i] ? ping_alive(iter) : kill_champ(iter));
                    if (!cw->alive[i]) cw->teams--;
                    cw->alive[i] = 0;
                }
            }
        }
    }
}
