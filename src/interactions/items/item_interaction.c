/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** item_interaction
*/

#include "rpg.h"

static const game_interaction_t interactions[] = {
    {KEY, &key_interaction},
    {STORY_PAPER, &story_paper_interaction},
    {MADNESS_POTION, &madness_interaction},
    {HEALTH_POTION, &health_interaction},
    {HEAD_PUPPET, &head_interaction},
    {BODY_PUPPET, &body_interaction},
    {MAGIC_ATTACK, &magic_interaction},
    {0}
};

void item_interaction(game_t *game)
{
    item_node_t *item = get_item_collide(game);

    for (int i = 0; interactions[i].fptr != NULL; i += 1) {
        if (interactions[i].type == item->type && item->taken == false)
            interactions[i].fptr(game);
    }
    if (item->type != STORY_PAPER)
        item->taken = true;
    return;
}
