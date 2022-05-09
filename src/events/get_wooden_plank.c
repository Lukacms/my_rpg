/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** get_wooden_plank
*/

#include <stdbool.h>
#include "rpg.h"

void get_wooden_plank(game_t *game, int code)
{
    if (is_valid_placement_up(game, code, '\\') == SUCCESS) {
        transform_map_up(game->entities.mc.sprite, game, '4');
        game->inventory.wooden_plank = true;
    }
    if (is_valid_placement_down(game, code, '\\') == SUCCESS) {
        transform_map_down(game->entities.mc.sprite, game, '4');
        game->inventory.wooden_plank = true;
    }
    if (is_valid_placement_left(game, code, '\\') == SUCCESS) {
        transform_map_left(game->entities.mc.sprite, game, '4');
        game->inventory.wooden_plank = true;
    }
    if (is_valid_placement_right(game, code, '\\') == SUCCESS) {
        transform_map_right(game->entities.mc.sprite, game, '4');
        game->inventory.wooden_plank = true;
    }
    if (game->inventory.wooden_plank == true)
        wooden_plank_interaction(game);
    return;
}
