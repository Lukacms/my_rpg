/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** reset_mc
*/

#include "rpg.h"

int reset_mc(game_t *game)
{
    if (!game)
        return FAILURE;
    sfSprite_setPosition(game->entities.mc.sprite, (sfVector2f){1080, 1900});
    return SUCCESS;
}
