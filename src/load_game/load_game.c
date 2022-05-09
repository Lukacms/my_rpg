/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** load_game
*/

#include <fcntl.h>
#include <stdlib.h>
#include "rpg.h"

int load_game(game_t *game)
{
    if (!game)
        return FAILURE;
    if (load_map(game) == FAILURE) {
        reset_game(game);
        return FAILURE;
    }
    if (load_stats(game) == FAILURE) {
        reset_game(game);
        return FAILURE;
    }
    return SUCCESS;
}
