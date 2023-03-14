/*
** EPITECH PROJECT, 2022
** PDG-D4-AM
** File description:
** main
*/

#include <stdio.h>
#include <string.h>

void sort_int_array(int *array, size_t nmemb);

size_t uniq_int_array(int *array, size_t nmemb);

void disp_int_array(const int *array, size_t nmemb);

void sort_array(void *array, size_t nmemb, size_t size, \
                            int (*compar) (const void *, const void *));

size_t uniq_array(void *array, size_t nmemb, size_t size,   \
                            int (*compar) (const void *, const void *));

void disp_array(const void *array, size_t nmemb, size_t size,   \
                            void (*print) (const void *));

static int test_comp(const void *a, const void * b)
{
    return (strcmp(*(char **)a, *(char **)b));
}

static void test_disp(const void * str )
{
    printf("%s", *(char **)str);
}

int main(int argc, const char ** argv)
{
    printf("argv:");
    disp_array(argv, argc, sizeof(*argv), &test_disp);
    printf("\n");
    argc = uniq_array(argv, argc, sizeof(* argv), &test_comp);
    printf("uniq:");
    disp_array(argv, argc, sizeof(* argv), &test_disp);
    printf("\n");
    sort_array(argv, argc, sizeof(*argv), &test_comp);
    printf("sort:");
    disp_array(argv, argc, sizeof(*argv), &test_disp);
    printf("\n");
    return (0);
}
