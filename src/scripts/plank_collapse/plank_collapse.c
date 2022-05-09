/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** plank_collipse
*/

#include "rpg.h"

static bool checking_mc_pos(sfVector2f pos)
{
    if (pos.x > 5162 && pos.x < 5242 && pos.y > 5076 && pos.y < 5126)
        return true;
    return false;
}

void plank_collapse(game_t *game)
{
    sfFloatRect mc_rect = get_true_rect_mc(game->entities.mc.sprite);
    sfVector2f mc_pos = {mc_rect.left, mc_rect.top};

    if (checking_mc_pos(mc_pos) == true &&
        game->scripts.plank_collapse == false) {
        game->maps->map[102][95] = '4';
        game->scripts.plank_collapse = true;
        plank_collapse_dialogue(game);
    }
    return;
}
