/*
** EPITECH PROJECT, 2020
** My Sort Int Array
** File description:
** Given an Integer Array, Sorts it in Ascending Order
*/

void my_is_sorting(int i, int j, int *array)
{
    int mem;

    if (array[i] > array[j]) {
        mem = array[i];
        array[i] = array[j];
        array[j] = mem;
    }
}

void my_sort_int_array(int *array, int size)
{
    for (int i = 0; i <= size - 1; i++)
        for (int j = i + 1; j <= size - 1; j++)
            my_is_sorting(i, j, array);
}
