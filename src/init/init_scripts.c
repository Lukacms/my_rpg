/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** init_scripts
*/

#include "rpg.h"

void init_scripts(game_t *game)
{
    game->scripts.plank_collapse = false;
    game->scripts.ghost_sound = false;
    game->scripts.pursuit_model = false;
    game->scripts.new_room_model = false;
    game->scripts.view_items = false;
    return;
}
