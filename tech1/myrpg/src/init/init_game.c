/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** init_game
*/

#include <stdbool.h>
#include "my_rpg.h"
#include "my.h"

static bool init_clocks(game_t *game)
{
    game->entity_movement = sfClock_create();
    game->bullet_delay    = sfClock_create();
    return (!(game->entity_movement || game->bullet_delay));
}

static bool init_doors(game_t *game)
{
    sfVector2f pos;

    pos = (sfVector2f){320, HEIGHT / 2};
    if (create_door(&game->doors[0], pos, sfFalse)) return (1);
    pos = (sfVector2f) {WIDTH - 320, HEIGHT / 2};
    if (create_door(&game->doors[1], pos, sfTrue)) return (1);
    return (0);
}

static void init_misc(game_t *game)
{
    game->enem                = NULL;
    game->obj                 = NULL;
    game->pnj.body            = NULL;
    game->state.hud           = false;
    game->state.overlay       = false;
    game->state.enemies_left  = false;
    game->hole.state          = false;
    game->hole.rect           = NULL;
    game->player.orb.rect     = NULL;
    game->player.orb.state    = 0;
    game->player.orb.speed    = 2;
    game->player.orb.coord    = (sfIntRect){0, 0, 190, 190};
}

bool init_game(sfRenderWindow **win, game_t *game, bool *gm)
{
    char *stat[2]  = { "assets/stat.rpg", "assets/save_stat.rpg" };
    char *map[2]   = { "assets/map.rpg",  "assets/save_map.rpg"  };
    int *stats_content;

    if (get_stat_contents(stat[*gm], &stats_content)) return (1);
    init_misc(game);
    create_overlay(&game->overlay);
    if (init_player(&game->player, &stats_content))   return (1);
    if (init_hud(&game->hud, &game->player))          return (1);
    if (create_map(&game->map, &map[*gm]))            return (1);
    if (start_map(game))                              return (1);
    if (init_doors(game))                             return (1);
    if (!(game->bullets = q_initialize(0)))           return (1);
    if (init_clocks(game))                            return (1);
    if (init_sounds(&game->playlist))                 return (1);
    sfRenderWindow_setMouseCursorVisible(*win, false);
    return (0);
}
