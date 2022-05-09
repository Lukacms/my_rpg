/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** pursuit_model.c
*/

#include "rpg.h"

static bool checking_mc_pos(sfVector2f pos)
{
    if (pos.x >= 13299 && pos.y >= 1007 && pos.y <= 1154)
        return true;
    return false;
}

static void break_floor(game_t *game, sfVector2f mc_pos)
{
    if (mc_pos.x <= 12200 && mc_pos.y >= 1007 && mc_pos.y <= 1154) {
        game->maps->map[16][239] = '3';
        game->maps->map[18][239] = '4';
    }
    if (mc_pos.x <= 12350 && mc_pos.y >= 1007 && mc_pos.y <= 1154) {
        game->maps->map[18][243] = '4';
        game->maps->map[16][242] = '3';
        game->maps->map[16][243] = '5';
    }
    if (mc_pos.x <= 12800 && mc_pos.y >= 1007 && mc_pos.y <= 1154) {
        game->maps->map[18][245] = '4';
        game->maps->map[16][245] = '3';
        game->maps->map[18][247] = '5';
        game->maps->map[18][246] = '4';
        game->maps->map[16][247] = '5';
    }
}

void pursuit_model(game_t *game)
{
    sfFloatRect mc_rect = get_true_rect_mc(game->entities.mc.sprite);
    sfVector2f mc_pos = {mc_rect.left, mc_rect.top};

    if (checking_mc_pos(mc_pos) == true &&
    game->scripts.pursuit_model == false) {
        game->scripts.pursuit_model = true;
    }
    if (game->scripts.pursuit_model == true)
        break_floor(game, mc_pos);
}
