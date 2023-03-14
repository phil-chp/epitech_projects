/*
** EPITECH PROJECT, 2020
** test
** File description:
** test
*/

#include "corewar.h"
#include "instru.h"
#include "my.h"

static void help_menu(void)
{
    miniprint("USAGE\n\t./corewar [-dump nbr_cycle] [[-n prog_number]");
    miniprint("[-a load_address] prog_name] ...\nDESCRIPTION\n\t-");
    miniprint("dump nbr_cycle dumps the memory after the nbr_cycle execution");
    miniprint(" (if the round isn’t already over) with the following format:");
    miniprint(" 32 bytes/line in hexadecimal (A0BCDEFE1DD3...)\n");
    miniprint("-n prog_number sets the next program’s number. By default,");
    miniprint(" the first free number in the parameter order\n");
    miniprint("-a load_address sets the next program’s loading address.");
    miniprint(" When no address is specified, optimize the addresses so");
    miniprint(" that the processes are as far away from each other as");
    miniprint(" possible. The addresses are MEM_SIZE modulo.\n");
    exit(0);
}

bool corewar(corewar_t *cw)
{
    short cycle = CYCLE_TO_DIE;
    short cycle_n = cycle;

    for (champs_t *iter = cw->champs->head; cw->teams > 1 && iter   \
    && cycle > 0; iter = (iter->next ? iter->next : cw->champs->head)) {
        if (!iter->state) continue;
        refresh_champions(iter, &cw->arena);
        if (iter->code.f > 0 && iter->t_cycle == 0)
            (*ins[iter->code.f])(cw, iter);
        if (cycle_n <= 0) {
            who_is_alive(cw);
            cycle -= CYCLE_DELTA;
            cycle_n = cycle;
        }
        (cycle_n <= 0 ? cycle_n = cycle, 0  \
        : (iter == cw->champs->head && cycle_n--, 0));
        // printf("%d %d\n", cycle, cycle_n);
        if (!iter->next) cycle_n--;
    }
    if (handle_ending(cw->teams, &cw->champs)) return (1);
    return (0);
}

int main(int ac, char **av)
{
    bool return_code = 0;
    corewar_t cw;

    if (ac < 2) return (84);
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') help_menu();
    return_code = init_champs(&cw, av);
    if (return_code == 0) {
        init_alive_list(&cw);
        return_code = fill_arena(&cw.champs, &cw.arena);
    }
    if (return_code == 0)
        return_code = corewar(&cw);
    destroy_features(&cw);
    return (return_code == 0 ? 0 : 84);
}
