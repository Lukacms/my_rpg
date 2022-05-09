/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** dispawn_fireball
*/

#include "rpg.h"

void dispawn_fireball(game_t *game)
{
    sfTime time = {0};

    if (!game || !game->fireball.countdown)
        return;
    time = sfClock_getElapsedTime(game->fireball.countdown);
    if (sfTime_asSeconds(time) > 4) {
        game->fireball.hidden = true;
        sfSprite_setPosition(game->fireball.fire, (sfVector2f){-1000, -1000});
    }
    return;
}
