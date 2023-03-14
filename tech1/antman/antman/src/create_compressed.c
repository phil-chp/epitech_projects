/*
** EPITECH PROJECT, 2021
** antman
** File description:
** Creates our compression method.
*/

#include "../../include/assets.h"
#include "../../include/my.h"
#include <stdlib.h>

char *parse_word(int start, int end, char *src);

static void two_last(int *mem, int j, int count)
{
    if (mem[1] == j && mem[1] == mem[0])
        my_lprintf(" %dx%d", mem[0], count + 2);
    else if (mem[0] == mem[1])
        my_lprintf(" %dx%d %d", mem[0], count + 1, j);
    else
        my_lprintf(" %d %d", mem[1], j);
    my_putchar('\n');
}

static int print_checker(buff_t *buff, int i, int *mem, int count)
{
    if (mem[1] == mem[0] && FILE_EXISTS) {
        count++;
    } else {
        if (count < 1) {
            my_lprintf(" %d", mem[0]);
        } else if (count > 0) {
            my_lprintf(" %dx%d", mem[0], count + 1);
            count = 0;
        } else {
            my_lprintf(" %d", mem[0]);
        }
    }
    return (count);
}

void create_compressed(buff_t *buff, char *file_str)
{
    int count = 0;
    int mem[] = { -1, -1 };
    int j;

    my_lprintf("%t\a\a", buff->array);
    for (int i = 0; FILE_EXISTS; i++) {
        int start = i;
        for (; IS_NOT_SEPARATOR && FILE_EXISTS; i++);
        for (; (IS_SEPARATOR) ; i++);
        char *temp = parse_word(start, --i, file_str);
        for (j = 0; buff->array[j] && COMPARE; j++);
        if (mem[0] != -1)
            count = print_checker(buff, i, mem, count);
        if (i > 1 && file_str[i + 1])
            mem[0] = mem[1];
        if (i > 0 && file_str[i + 1])
            mem[1] = j;
        free(temp);
    }
    two_last(mem, j, count);
}
