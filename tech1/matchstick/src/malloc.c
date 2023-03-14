int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i]; i++);
    return (i);
}

int my_putchar(char c)
{
    return (write(1, &c, 1));
}

int my_putstr(char const *str)
{
    return (write(1, str, my_strlen(str)));
}

void my_putnbr(int nb)
{
    long long_nb = nb;
    int n = 0;

    if (long_nb < -2147483648) long_nb =  2147483647 - long_nb;
    if (long_nb > 2147483647)  long_nb = -2147483648 + long_nb;
    if (long_nb < 0) {
        my_putchar('-');
        long_nb = -long_nb;
    }
    if (long_nb > 9)
        my_putnbr(long_nb / 10);
    n = long_nb % 10;
    my_putchar(n + '0');
}

void print_vanilla_memory(char *heap)
{
    my_putstr("HELLO?\n");
    char *new_heap = sbrk(0);
    size_t blocks = ((void *)new_heap - (void *)heap) / 4096;

    for (size_t i = 0; i < 4096 * blocks; ++i) {
        if (i % 24 == 0) my_putchar('\n');
        my_putnbr(*(heap + i));
        my_putchar(' ');
    }
    my_putchar('\n');
}
