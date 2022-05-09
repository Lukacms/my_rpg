/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** enemy_hit
*/

#include "rpg.h"

void enemy_hit(game_t *game)
{
    sfVector2f size = sfRectangleShape_getSize(game->gui.health);

    if (is_mc_touched(game) == true) {
        if (game->entities.instant_dead == true) {
            game->stats.stats_obj[0].nb_value = 0;
            size.x = 0;
        }
        size.x -= 50;
        game->stats.stats_obj[0].nb_value -= 50;
        sfRectangleShape_setSize(game->gui.health, size);
    }
    if (size.x <= 0 || game->stats.stats_obj[0].nb_value <= 0)
        game->status = GAME_OVER;
    return;
}
