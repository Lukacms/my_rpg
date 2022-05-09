/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** animate_fireball
*/

#include "rpg.h"

int animate_fireball(game_t *game)
{
    sfTime time;
    sfIntRect rect;

    if (!game)
        return FAILURE;
    time = sfClock_getElapsedTime(game->fireball.animate);
    rect = sfSprite_getTextureRect(game->fireball.fire);
    if (sfTime_asSeconds(time) > 0.05) {
        rect.left = rect.left + 100;
        sfClock_restart(game->fireball.animate);
    }
    if (rect.left >= 700)
        rect.left = 0;
    sfSprite_setTextureRect(game->fireball.fire, rect);
    return SUCCESS;
}
