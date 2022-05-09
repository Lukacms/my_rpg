/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** display_fireball
*/

#include "rpg.h"

int display_fireball(game_t *game)
{
    if (!game)
        return FAILURE;
    if (game->fireball.hidden == false)
        sfRenderWindow_drawSprite(game->window.window, game->fireball.fire,
                                NULL);
    return SUCCESS;
}
