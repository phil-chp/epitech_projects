/*
** EPITECH PROJECT, 2020
** B-MUL-200-NCE-2-1-myrpg-theo.guichard
** File description:
** update_enemy.c
*/

#include "my_rpg.h"
#include "queue.h"

static void move_enemy( entity_t **iter,    \
                        sfUint64 s,         \
                        int speed,          \
                        sfVector2f *player_pos)
{
    sfIntRect rect;
    sfVector2u size;
    sfVector2f mov;

    rect = sfRectangleShape_getTextureRect((*iter)->body);
    size = sfTexture_getSize(sfRectangleShape_getTexture((*iter)->body));
    mov = get_advancement((*iter)->pos, (*player_pos));
    normalize(&mov);
    (*iter)->pos.x += mov.x * speed * s;
    (*iter)->pos.y += mov.y * speed * s;
    rect.top =  (mov.x < 0 ? 64                 \
    :           (mov.x > 0 ? 64 * 3             \
    :           (!mov.x && mov.y < 0 ? 0        \
    :           (!mov.x && mov.y > 0 ? 64 * 2   \
    : size.y - rect.height))));
    sfRectangleShape_setTextureRect((*iter)->body, rect);
}

static void set_pos_and_draw(sfRenderWindow **win, entity_t *iter)
{
    sfVector2f pos;

    sfRectangleShape_setPosition(iter->body, iter->pos);
    pos = (sfVector2f){iter->pos.x - 50, iter->pos.y - 50};
    sfRectangleShape_setPosition(iter->health.background, pos);
    sfRectangleShape_setPosition(iter->health.bar, pos);
    sfRenderWindow_drawRectangleShape(*win, iter->body, NULL);
    sfRenderWindow_drawRectangleShape(*win, iter->health.background, NULL);
    sfRenderWindow_drawRectangleShape(*win, iter->health.bar, NULL);
}

void damage_enemy(map_t **map, entity_t **enem, entity_t *player)
{
    sfVector2f size;
    float damage;

    damage = (float)player->stats.attack * 0.75f;
    if (!get_random(0, 16 - player->stats.special))
        damage *= 3;
    size = sfRectangleShape_getSize((*enem)->health.bar);
    size.x -= damage;
    if (size.x <= 0) {
        (*enem)->dead = true;
        (*map)->map[(*enem)->cell.i][(*enem)->cell.j] = ' ';
        // SON : MORT ENNEMIE
    } else {
        sfRectangleShape_setSize((*enem)->health.bar, size);
        // SON : PERTE DE VIE ENNEMIE
    }
}

void update_enemy(sfRenderWindow **win, game_t *game, queue_man_t **bl)
{
    entity_t *iter = NULL;
    sfFloatRect area;
    int speed;

    if (!game->enem) return;
    area = (sfFloatRect){ 32, 32, 32, 32 };
    for (iter = game->enem->head; iter; iter = iter->next) {
        if (iter->dead) continue;
        speed = 1 + iter->stats.speed / get_random(70, 125);
        move_enemy(&iter, 1, speed, &game->player.pos);
        if (get_time_elapsed(iter->animation, 10000) > 12.5) {
            handle_animation(&iter);
            sfClock_restart(iter->animation);
        }
        handle_collision(&iter->pos, GAME_FLOOR, area, 1);
        handle_player_collision(&game->player, iter->pos, iter->size);
        if (!q_isempty(*bl) && handle_bullet_collision(bl, iter->pos))
            damage_enemy(&game->map, &iter, &game->player);
        set_pos_and_draw(win, iter);
    }
}
