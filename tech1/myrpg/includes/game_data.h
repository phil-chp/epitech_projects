/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** game_data
*/

#ifndef GAME_DATA_H_
#define GAME_DATA_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdbool.h>
#include "queue.h"

typedef struct door_s {
    sfRectangleShape *door;
    bool is_open;
    bool disabled;
} door_t;

typedef struct map_s {
    int stair;
    int room;
    char **map;
    char **file;
    sfRectangleShape *back;
    sfRectangleShape *number;
    sfText *map_name;
    struct map_s *right, *left, *head;
} map_t;

typedef struct bar_s {
    float info;
    sfSprite *sprite;
    sfRectangleShape *bg;
    sfRectangleShape *rect;
} bar_t;

typedef struct info_s {
    int info;
    sfSprite *sprite;
    sfText *text;
    sfCircleShape *circle;
} info_t;

typedef struct cell_s {
    char c;
    int i;
    int j;
} cell_t;

typedef struct hud_s {
    bar_t health;
    bar_t mana;
    info_t stars;
    info_t keys;
    info_t bombs;
    info_t arms;
    info_t speed;
    info_t attack;
    info_t defense;
    info_t jump;
    info_t special;
    info_t minimap;
} hud_t;

typedef struct bar_maker_s {
    sfColor color;
    int value;
} bar_maker_t;

typedef struct bullet_s {
    sfCircleShape *body;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f speed;
    sfVector2f pos;
    sfColor mask;
    float radius;
    float motion;
    float life;
} bullet_t;

typedef struct obj_s {
    sfRectangleShape *rect;
    bool wall;
    bool stars;
    bool draw;
    bool trap;
    cell_t cell;
    struct obj_s *next, *prev, *head, *closest;
} obj_t;

typedef struct orb_s {
    sfCircleShape *rect;
    sfIntRect coord;
    float speed;
    int state;
} orb_t;

typedef struct stats_s {
    size_t health;
    size_t mana;
    size_t stars;
    size_t keys;
    size_t bombs;
    size_t arms;
    size_t speed;
    size_t attack;
    size_t defense;
    size_t jump;
    size_t special;
} stats_t;

typedef struct health_s
{
    sfRectangleShape *background;
    sfRectangleShape *bar;
    sfVector2f size;
    sfVector2f points;
} health_t;

typedef struct pop_up_s {
    sfSprite *pop_up;
    sfText *text[2];
    bool enabled;
} pop_up_t;

typedef struct entity_s {
    sfRectangleShape *body;
    sfClock *animation;
    sfVector2f scale;
    sfVector2f size;
    sfVector2f pos;
    health_t health;
    bool shooting;
    cell_t cell;
    stats_t stats;
    orb_t orb;
    pop_up_t pop_up;
    bool dead;
    struct entity_s *next, *prev, *head;
} entity_t;

typedef struct overlay_s {
    sfRectangleShape *rect;
    struct overlay_s *next, *head;
}   overlay_t;

typedef struct state_s {
    bool hud;
    bool overlay;
    bool enemies_left;
} state_t;

typedef struct hole_s {
    sfRectangleShape *rect;
    bool state;
} hole_t;

typedef struct track_s {
    sfMusic *track;
    bool state;
} track_t;

typedef struct music_s {
    track_t *playlist;
    char **path;
} music_t;

typedef struct inventory_s {
    sfRectangleShape ***rect;
    sfCircleShape **orbs;
    sfSprite *background;
    sfText *star_count;
    sfSprite *star;
} inv_t;

typedef struct game_s {
    door_t doors[2];
    hud_t hud;
    entity_t player;
    entity_t *enem;
    entity_t pnj;
    overlay_t *overlay;
    music_t playlist;
    map_t *map;
    obj_t *obj;
    hole_t hole;
    sfClock *bullet_delay;
    queue_man_t *bullets;
    sfClock *entity_movement;
    sfRectangleShape *temp;
    state_t state;
} game_t;

#endif /* GAME_DATA_H_ */
