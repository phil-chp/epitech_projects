/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** init_sound.c
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my.h"

static bool get_music_path(char ***path)
{
    if (!((*path) = malloc(sizeof(char *) * 15)))
        return (1);
    (*path)[0]  = my_strdup("assets/sounds/young_sheesh_sound.ogg");
    (*path)[1]  = my_strdup("assets/sounds/collect_sound.ogg");
    (*path)[2]  = my_strdup("assets/sounds/damage_sound.ogg");
    (*path)[3]  = my_strdup("assets/sounds/death.ogg");
    (*path)[4]  = my_strdup("assets/sounds/death_boss.ogg");
    (*path)[5]  = my_strdup("assets/sounds/door.ogg");
    (*path)[6]  = my_strdup("assets/sounds/door_sound.ogg");
    (*path)[7]  = my_strdup("assets/sounds/hitmaker_sound.ogg");
    (*path)[8]  = my_strdup("assets/sounds/mob.ogg");
    (*path)[9] = my_strdup("assets/sounds/music.ogg");
    (*path)[10] = my_strdup("assets/sounds/npc_talking.ogg");
    (*path)[11] = my_strdup("assets/sounds/shooting_1.ogg");
    (*path)[12] = my_strdup("assets/sounds/shooting_sound_2.ogg");
    (*path)[13] = my_strdup("assets/sounds/stairs.ogg");
    (*path)[14] = NULL;
    return (0);
}

static bool initialize_playlist(music_t *music)
{
    music->playlist = malloc(sizeof(track_t) * 14);
    for (int i = 0; i < 14; i++) {
        if (!(music->playlist[i].track  \
        = sfMusic_createFromFile(music->path[i])))
            return (1);
        music->playlist[i].state = false;
    }
    return (0);
}

bool init_sounds(music_t *music)
{
    get_music_path(&music->path);
    if (initialize_playlist(music))
        return (1);
    return (0);
}
