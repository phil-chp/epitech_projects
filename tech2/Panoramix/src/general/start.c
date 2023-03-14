/*
** EPITECH PROJECT, 2022
** Panoramix (Workspace)
** File description:
** start
*/

#include "pano.h"

static int start_druid(pano_t *pano, char *name)
{
    int err = pthread_create(&pano->druid->thread, NULL,  \
                            &run_druid, (void *)pano);
    if (err != 0) {
        print_error(name, "Couldn't create druid thread.\n");
        print_error(name, strerror(err));
        return (ERROR_VALUE);
    }
    pano->druid->alive = true;
    return (SUCCESS_VALUE);
}

static void start_villager(pano_t *pano, int i, char *name)
{
    current_villager_t *current_villager =  \
        (current_villager_t *)malloc(sizeof(current_villager_t));
    current_villager->pano = pano;
    current_villager->vid = i;

    int err = pthread_create(&pano->villagers[i].thread, NULL, \
                            &run_villager, current_villager);
    if (err != 0)  {
        print_error(name, "Couldn't create villager thread.\n");
        print_error(name, strerror(err));
    }
}

int start_panoramix(pano_t *pano, char *name)
{
    if (start_druid(pano, name)) return (ERROR_VALUE);
    for (int i = 0; i < pano->args.nb_villagers; ++i) {
        start_villager(pano, i, name);
    }
    return (SUCCESS_VALUE);
}
