/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** is_valid_placement
*/

#include "rpg.h"

int is_valid_placement_up(game_t *game, int code, char value)
{
    if (code == game->key.interact && (game->entities.mc.states_mc == BACK ||
        game->entities.mc.states_mc == BACK_BLOND ||
        game->entities.mc.states_mc == BACK_GIRL ||
        game->entities.mc.states_mc == BACK_SKATER) &&
        get_pos_in_map_up(game->entities.mc.sprite, game) == value) {
        return SUCCESS;
    }
    return FAILURE;
}

int is_valid_placement_down(game_t *game, int code, char value)
{
    if (code == game->key.interact && (game->entities.mc.states_mc == FRONT ||
        game->entities.mc.states_mc == FRONT_BLOND ||
        game->entities.mc.states_mc == FRONT_GIRL ||
        game->entities.mc.states_mc == FRONT_SKATER) &&
        get_pos_in_map_down(game->entities.mc.sprite, game) == value) {
        return SUCCESS;
    }
    return FAILURE;
}

int is_valid_placement_left(game_t *game, int code, char value)
{
    if (code == game->key.interact && (game->entities.mc.states_mc == LEFT ||
        game->entities.mc.states_mc == LEFT_BLOND ||
        game->entities.mc.states_mc == LEFT_GIRL ||
        game->entities.mc.states_mc == LEFT_SKATER) &&
        get_pos_in_map_left(game->entities.mc.sprite, game) == value) {
        return SUCCESS;
    }
    return FAILURE;
}

int is_valid_placement_right(game_t *game, int code, char value)
{
    if (code == game->key.interact && (game->entities.mc.states_mc == RIGHT ||
        game->entities.mc.states_mc == RIGHT_BLOND ||
        game->entities.mc.states_mc == RIGHT_GIRL ||
        game->entities.mc.states_mc == RIGHT_SKATER) &&
        get_pos_in_map_right(game->entities.mc.sprite, game) == value) {
        return SUCCESS;
    }
    return FAILURE;
}
