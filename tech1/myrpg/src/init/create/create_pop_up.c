/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** create_pop_up
*/

#include "my_rpg.h"
#include "my.h"
#include <stdlib.h>
#include <stdbool.h>

static char **create_strings(char ***texts)
{
    (*texts) = malloc(sizeof(char *) * 10 + 1);
    (*texts)[0] = my_strdup("Hello Eric,\nHelp me, there is a dragon");
    (*texts)[1] = my_strdup("who wants to kill me!!\nPleeaasee, heeelp meee!!");
    (*texts)[2] = my_strdup("Thank you!!\nBut... There is a dragon.");
    (*texts)[3] = my_strdup("Take this orb.\nIt will help you.");
    (*texts)[4] = my_strdup("Hello Dragon,\nHelp me there is an Eric");
    (*texts)[5] = my_strdup("Oh!! Sorry Eric,\nIt's a dragon");
    (*texts)[6] = my_strdup("Oh no he came back and he's even stronger");
    (*texts)[7] = my_strdup("HELPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP!!!!?!");
    (*texts)[8] = my_strdup("Thanks Eric, but there's a last one lol");
    (*texts)[9] = my_strdup("He is stronger than ever go fight already!");
    return (*texts);
}

static bool add_texts(pop_up_t *pop_up, sfVector2f pos, int stair)
{
    char **text = create_strings(&text);

    for (int i = stair * 2, j = 0; i <= stair * 2 + 1; i++, j++) {
        pop_up->text[j] = create_text(text[i], pos, sfBlack, 20);
        pos.y += 50;
    }
    if (!pop_up->text || !pop_up->text[0] || !pop_up->text[1]) return (1);
    return (0);
}

bool create_pop_up(pop_up_t *pop_up, sfVector2f pos, int stair)
{
    sfTexture *texture = NULL;
    sfVector2f origin, text_pos;
    sfVector2u texture_size;

    pop_up->enabled = false;
    pos = (sfVector2f) { pos.x - 15, pos.y - 15 };
    texture = sfTexture_createFromFile("assets/hud/dialog.png", NULL);
    if (!texture) return (1);
    texture_size = sfTexture_getSize(texture);
    origin = (sfVector2f) { (int) texture_size.x, (int) texture_size.y };
    pop_up->pop_up = create_sprite(texture, &pos, &origin, sfFalse);
    if (!pop_up->pop_up) return (1);
    text_pos = (sfVector2f) { pos.x - (int) texture_size.x + 10, \
    pos.y - (int) texture_size.y / 2 - 50 };
    add_texts(pop_up, text_pos, stair);
    return (0);
}
