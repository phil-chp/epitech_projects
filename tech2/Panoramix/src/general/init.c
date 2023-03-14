/*
** EPITECH PROJECT, 2022
** Panoramix (Workspace)
** File description:
** init
*/

#include "pano.h"

static int init_mutex(pthread_mutex_t *mutex, char *name)
{
    if (pthread_mutex_init(mutex, NULL) != 0) {
        print_error(name, "Mutex initialization failed.\n");
        return (ERROR_VALUE);
    }
    return (SUCCESS_VALUE);
}

static int init_semaphore(sem_t *sem, char *name)
{
    if (sem_init(sem, THREAD_SHARED, 0)) {
        print_error(name, "Semaphore initialization failed.\n");
        return (ERROR_VALUE);
    }
    return (SUCCESS_VALUE);
}

static int init_villagers(villager_t **villagers, pano_t *pano, char *name)
{
    int size;
    int fights;

    size = pano->args.nb_villagers;
    fights = pano->args.nb_fights;
    (*villagers) = (villager_t *)malloc(sizeof(villager_t) * size);
    if (!(*villagers)) {
        print_error(name, "Couldn't allocate memory to villagers.\n");
        return (ERROR_VALUE);
    }
    for (int i = 0; i < size; ++i) {
        (*villagers)[i].has_drunk = false;
        (*villagers)[i].nb_fights = fights;
    }
    return (SUCCESS_VALUE);
}

static int init_druid(druid_t **druid, char *name)
{
    (*druid) = (druid_t *)malloc(sizeof(druid_t));
    if (!(*druid)) {
        print_error(name, "Couldn't allocate memory to druid.\n");
        return (ERROR_VALUE);
    }
    return (SUCCESS_VALUE);
}

int init_panoramix(pano_t *pano, char *name)
{
    if (init_mutex(&pano->villager_mutex, name))      return (ERROR_VALUE);
    if (init_semaphore(&pano->refill_sem, name))      return (ERROR_VALUE);
    if (init_semaphore(&pano->confirm_sem, name))     return (ERROR_VALUE);
    if (init_villagers(&pano->villagers, pano, name)) return (ERROR_VALUE);
    if (init_druid(&pano->druid, name))               return (ERROR_VALUE);
    return (SUCCESS_VALUE);
}
