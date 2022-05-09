/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** reset_scripts
*/

#include "rpg.h"

int reset_scripts(game_t *game)
{
    if (!game)
        return FAILURE;
    game->scripts.plank_collapse = false;
    game->scripts.view_items = false;
    game->scripts.ghost_sound = false;
    game->scripts.pursuit_model = false;
    game->scripts.new_room_model = false;
    return SUCCESS;
}
