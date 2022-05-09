/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** plank_collipse
*/

#include "rpg.h"

static bool checking_mc_pos(sfVector2f pos)
{
    if (pos.x > 13459 && pos.x < 13659 && pos.y > 1852 && pos.y < 1901)
        return true;
    return false;
}

void sachiko_ending(game_t *game)
{
    sfFloatRect mc_rect = get_true_rect_mc(game->entities.mc.sprite);
    sfVector2f mc_pos = {mc_rect.left, mc_rect.top};

    if (checking_mc_pos(mc_pos) == true) {
        sfMusic_stop(game->ost.main_theme);
        sachiko_dialogue(game);
    }
    return;
}
