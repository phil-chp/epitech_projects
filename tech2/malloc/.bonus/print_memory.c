/*
** EPITECH PROJECT, 2022
** MyMalloc (Workspace)
** File description:
** print_memory
*/

void print_vanilla_memory(char *heap)
{
    char *new_heap = sbrk(0);
    size_t blocks = ((void *)new_heap - (void *)heap) / PAGE_SIZE;

    for (size_t i = 0; i < blocks; ++i) {
        if (i % 24 == 0) my_putchar('\n');
        my_putnbr(*(heap + i));
        my_putchar(' ');
    }
    my_putchar('\n');
}

void print_memory(char *heap)
{
    char *new_heap = sbrk(0);
    size_t blocks = ((void *)new_heap - (void *)heap) / PAGE_SIZE;

    for (size_t i = 0; i < blocks; ++i) {
        if (i % 24 == 0) printf("\n%5ld: ", i / 24);
        printf("%4d", *(heap + i));
    }
    printf("\n");
}
