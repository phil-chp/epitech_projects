/*
** EPITECH PROJECT, 2022
** ftrace (Workspace)
** File description:
** main
*/

#include "ftrace.h"
#include "delf.h"
#include "stack.h"

int iscall(long peek1, long peek2)
{
    union {
        long longs[2];
        unsigned char bytes[16];
    } data;

    int opcode, reg;
    size_t offset;

    /* turn peeked longs into bytes */
    data.longs[0] = peek1;
    data.longs[1] = peek2;

    /* ignore relevant prefixes */
    for (offset = 0; offset < sizeof data.bytes &&
        ((data.bytes[offset] & 0xe7) == 0x26 /* cs, ds, ss, es override */
        || (data.bytes[offset] & 0xfc) == 0x64 /* fs, gs, addr32, data16 override */
        || (data.bytes[offset] & 0xf0) == 0x40); /* REX prefix */
        offset++);

    /* instruction is composed of all prefixes */
    if (offset > 15)
        return (0);

    opcode = data.bytes[offset];


    /* E8: CALL NEAR rel32? */
    if (opcode == 0xe8)
        return (1);

    /* sufficient space for modr/m byte? */
    if (offset > 14)
        return (0);

    reg = data.bytes[offset + 1] & 0070; /* modr/m byte, reg field */

    if (opcode == 0xff) {
        /* FF /2: CALL NEAR r/m64? */
        if (reg == 0020)
            return (1);

        /* FF /3: CALL FAR r/m32 or r/m64? */
        if (reg == 0030)
            return (1);
    }

    /* not a CALL instruction */
    return (0);
}

static void main_loop(Elf *elf, pid_t pid, _uss *regs)
{
    int status = 0;
    long addr = 0;
    char *sym = NULL;

    wait(&status);
    while (1) {
        ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL);
        wait(&status);
        if (WIFEXITED(status)) break;
        ptrace(PTRACE_GETREGS, pid, NULL, regs);
        addr = ptrace(PTRACE_PEEKTEXT, pid, regs->rip, NULL);
        if (iscall(addr, ptrace(PTRACE_PEEKTEXT, pid, regs->rip + 8, NULL))) {

            ptrace(PTRACE_GETREGS, pid, NULL, &regs);
            addr = ptrace(PTRACE_PEEKTEXT, pid, regs->rip, NULL);

            sym = elf_lookup(elf, addr);
            if (sym) {
                printf("%s\n", sym->name);
            }
            else {
                printf("%p\n", (void *)addr);
            }
        }
    }

        // if ((addr & 0xFF) == 0xE8) {
        //     // e8 050F
        //     long offset = 0;
        //     offset = ptrace(PTRACE_PEEKTEXT, pid, regs.rip + 1, NULL);
        //     int off = offset & 0xFFFFFFFF;

        //     size_t symbol_addr = (regs.rip + 5 + off);

        //     char *symbol = delf_get_symbol(elf, symbol_addr);
        //     if (symbol) printf("symbol:\t\t%s\n", symbol);
        //     //func_0x4ddf4468@data/example_program at 0x4ddf4468
        // }
    }
}

static void ftrace(Elf *elf, char **av)
{
    pid_t pid = 0;
    _uss regs;
    // long peek[2];

    pid = fork();
    if (pid == 0) {
        ptrace(PTRACE_TRACEME, 0, NULL, NULL);
        execvp(av[1], av + 1);
    } else if (pid > 0) {
        main_loop(elf, pid, &regs);
        ptrace(PTRACE_DETACH, pid, NULL, NULL);
    } else {
        perror("fork");
        exit(1);
    }
}

int main(int ac, char **av, char **env)
{
    (void)env;
    // long address = 0;
    Elf *elf;

    if (ac < 2) {
        fprintf(stderr, "USAGE: %s <ELF binary> <symbols address>\n", av[0]);
        return (84);
    }
    if ((elf = delf_start(av[1])) == NULL) return (84);
    // address = strtol(av[2], NULL, 0);
    // char *str = delf_get_symbol(elf, address);
    ftrace(elf, av);
    delf_end(elf);
    return (0);
}
