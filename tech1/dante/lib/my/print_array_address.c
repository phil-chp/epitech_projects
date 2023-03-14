/*
** EPITECH PROJECT, 2021
** dante (Workspace)
** File description:
** print_array
*/

int my_putchar(char c);

int my_strlen(char *str);

int my_putstr_len(char *str, int len);

int print_array_address(char ***array)
{
    int i = 0;

    if (!(*array))
        return (1);
    int len = my_strlen((*array)[0]);
    for (; (*array)[i + 1]; i++) {
        my_putstr_len((*array)[i], len);
        my_putchar('\n');
    }
    my_putstr_len((*array)[i], len);
    return (0);
}
