/*
** EPITECH PROJECT, 2022
** Panoramix (Workspace)
** File description:
** villager
*/

#include "pano.h"

static bool drink(int vid, pano_t *pano, villager_t *villager)
{
    printf("Villager %d: I need a drink... I see %d servings left.\n",  \
                                                vid, pano->nb_servings_left);
    if (pano->args.nb_refills == 0 && pano->nb_servings_left == 0) {
        return (false);
    }
    if (pano->nb_servings_left == 0) {
        printf("Villager %d: Hey Pano wake up! We need more potion.\n", vid);
        sem_post(&pano->refill_sem);
        sem_wait(&pano->confirm_sem);
    }
    --(pano->nb_servings_left);
    villager->has_drunk = true;
    return (true);
}

static void fight(int vid, villager_t *villager)
{
    --(villager->nb_fights);
    printf("Villager %d: Take that roman scum! Only %d left.\n",  \
                                            vid, villager->nb_fights);
    villager->has_drunk = false;
}

void *run_villager(void *data)
{
    villager_t *villager;
    bool drink_left = true;
    pano_t *pano;
    int vid;

    vid = ((current_villager_t *)data)->vid;
    pano = ((current_villager_t *)data)->pano;
    villager = &pano->villagers[vid];
    printf("Villager %d: Going into battle!\n", vid);
    while (villager->nb_fights > 0 && drink_left) {
        pthread_mutex_lock(&pano->villager_mutex);
        drink_left = drink(vid, pano, villager);
        pthread_mutex_unlock(&pano->villager_mutex);
        if (villager->has_drunk) fight(vid, villager);
    }
    printf("Villager %d: I'm going to sleep now.\n", vid);
    free(data);
    return (NULL);
}
