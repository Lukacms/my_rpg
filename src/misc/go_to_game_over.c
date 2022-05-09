/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** go_to_game_over
*/

#include "rpg.h"

void go_to_game_over(game_t *game)
{
    if (game->status == GAME_OVER) {
        sfMusic_stop(game->ost.main_theme);
        sfSound_setBuffer(game->sfx.sfx, game->sfx.b_over);
        sfSound_play(game->sfx.sfx);
    }
    return;
}
