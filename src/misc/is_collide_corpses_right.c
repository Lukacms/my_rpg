/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** is_collide_corpses
*/

#include "rpg.h"

static bool is_collide_no_walk(corpse_node_t *corpse, game_t *game)
{
    sfFloatRect mc_rect = get_true_rect_mc(game->entities.mc.sprite);
    sfFloatRect corpse_rect = sfSprite_getGlobalBounds(corpse->sprite);

    mc_rect.width += 11;
    corpse_rect.top -= corpse_rect.height;
    corpse_rect.height -= 20;
    if (sfFloatRect_intersects(&mc_rect, &corpse_rect, NULL) == sfTrue)
        return true;
    return false;
}

static bool is_collide_behind(corpse_node_t *corpse, game_t *game)
{
    sfFloatRect mc_rect = get_true_rect_mc(game->entities.mc.sprite);
    sfFloatRect corpse_rect = sfSprite_getGlobalBounds(corpse->sprite);

    mc_rect.width += 11;
    corpse_rect.top -= corpse_rect.height;
    corpse_rect.height -= 20;
    corpse_rect.height = corpse_rect.height / 2;
    corpse_rect.top += corpse_rect.height;
    if (sfFloatRect_intersects(&mc_rect, &corpse_rect, NULL) == sfTrue)
        return true;
    return false;
}

int is_collide_corpses_right(game_t *game)
{
    bool is_collide = false;

    for (int i = 0; game->corpses.corpses[i] != NULL; i += 1) {
        if (game->corpses.corpses[i]->script_room_model == true)
            continue;
        if (game->corpses.corpses[i]->type == NO_WALK)
            is_collide = is_collide_no_walk(game->corpses.corpses[i], game);
        else
            is_collide = is_collide_behind(game->corpses.corpses[i], game);
        if (is_collide == true)
            return SUCCESS;
    }
    return FAILURE;
}
