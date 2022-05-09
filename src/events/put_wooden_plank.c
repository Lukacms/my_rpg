/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** put_wooden_plank
*/

#include <stdbool.h>
#include "rpg.h"

void set_wooden_plank(game_t *game, int code)
{
    if (is_valid_placement_up(game, code, '4') == SUCCESS) {
        transform_map_up(game->entities.mc.sprite, game, '\\');
        game->inventory.wooden_plank = false;
    }
    if (is_valid_placement_down(game, code, '4') == SUCCESS) {
        transform_map_down(game->entities.mc.sprite, game, '\\');
        game->inventory.wooden_plank = false;
    }
    if (is_valid_placement_left(game, code, '4') == SUCCESS) {
        transform_map_left(game->entities.mc.sprite, game, '\\');
        game->inventory.wooden_plank = false;
    }
    if (is_valid_placement_right(game, code, '4') == SUCCESS) {
        transform_map_right(game->entities.mc.sprite, game, '\\');
        game->inventory.wooden_plank = false;
    }
    return;
}
