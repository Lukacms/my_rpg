/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** reset_game
*/

#include "rpg.h"

int reset_game(game_t *game)
{
    if (reset_mc(game) == FAILURE || reset_items(game) == FAILURE)
        return FAILURE;
    if (reset_enemies(game) == FAILURE || reset_scripts(game) == FAILURE)
        return FAILURE;
    if (reset_inventory(game) == FAILURE || reset_map(game) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
