/*
** EPITECH PROJECT, 2022
** Panoramix (Workspace)
** File description:
** battle
*/

#include "pano.h"

static void refill_pot(pano_t *pano)
{
    --(pano->args.nb_refills);
    printf("%s%s %d more refills after this one.\n",           \
                    "Druid: Ah! Yes, yes, I'm awake! ",        \
                    "Working on it! Beware I can only make",   \
                    pano->args.nb_refills);
    pano->nb_servings_left = pano->args.pot_size;
}

void *run_druid(void *data)
{
    pano_t *pano;

    pano = data;
    puts("Druid: I'm ready... but sleepy...");
    while (pano->args.nb_refills > 0 && pano->druid->alive) {
        sem_wait(&pano->refill_sem);
        if (pano->druid->alive) refill_pot(pano);
        sem_post(&pano->confirm_sem);
    }
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
    return (NULL);
}
