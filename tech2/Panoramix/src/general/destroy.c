/*
** EPITECH PROJECT, 2022
** Panoramix (Workspace)
** File description:
** destroy
*/

#include "pano.h"

void destroy_panoramix(pano_t *pano)
{
    for (int i = 0; i < pano->args.nb_villagers; ++i) {
        pthread_join(pano->villagers[i].thread, NULL);
    }
    if (pano->druid->alive) {
        pano->druid->alive = false;
        sem_post(&pano->refill_sem);
    }
    pthread_join(pano->druid->thread, NULL);
    pthread_mutex_destroy(&pano->villager_mutex);
    sem_destroy(&pano->refill_sem);
    sem_destroy(&pano->confirm_sem);
    if (pano) {
        if (pano->druid)     free(pano->druid);
        if (pano->villagers) free(pano->villagers);
    }
}
