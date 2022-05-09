/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** reset_map
*/

#include "rpg.h"

int reset_map(game_t *game)
{
    if (!game)
        return FAILURE;
    game->maps->map = initialize_two_d_array(game->maps->original_map);
    if (!game->maps->map)
        return FAILURE;
    return SUCCESS;
}
