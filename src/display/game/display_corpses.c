/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** display_corpses
*/

#include <stdio.h>
#include "my.h"
#include "rpg.h"

static bool is_above(corpse_node_t *corpse, game_t *game)
{
    if (!corpse || !game)
        return false;
    sfFloatRect mc_rect = get_true_rect_mc(game->entities.mc.sprite);
    sfFloatRect corpse_rect = sfSprite_getGlobalBounds(corpse->sprite);

    corpse_rect.top -= corpse_rect.height;
    corpse_rect.height -= 20;
    corpse_rect.top += corpse_rect.height / 2;
    if (mc_rect.top < corpse_rect.top)
        return true;
    return false;
}

int display_corpses_after(game_t *game)
{
    if (!game)
        return FAILURE;
    for (int index = 0; game->corpses.corpses[index] != NULL; index += 1) {
        if (game->corpses.corpses[index]->script_room_model == true)
            continue;
        if (game->corpses.corpses[index]->type == WALK_BEHIND
        && is_above(game->corpses.corpses[index], game) == true)
            sfRenderWindow_drawSprite(game->window.window,
            game->corpses.corpses[index]->sprite, NULL);
    }
    return FAILURE;
}

int display_corpses_before(game_t *game)
{
    if (!game)
        return FAILURE;
    for (int index = 0; game->corpses.corpses[index] != NULL; index += 1) {
        if (game->corpses.corpses[index]->script_room_model == true)
            continue;
        if (game->corpses.corpses[index]->type == NO_WALK)
            sfRenderWindow_drawSprite(game->window.window,
            game->corpses.corpses[index]->sprite, NULL);
        if (game->corpses.corpses[index]->type == WALK_BEHIND
        && is_above(game->corpses.corpses[index], game) == false)
            sfRenderWindow_drawSprite(game->window.window,
            game->corpses.corpses[index]->sprite, NULL);
    }
    return SUCCESS;
}
