/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** throw_fireball
*/

#include "rpg.h"

static void throw_fireball(game_t *game)
{
    if (game->entities.mc.states_mc == RIGHT) {
        game->fireball.state = RIGHT;
        set_fireball(game);
    }
    if (game->entities.mc.states_mc == LEFT) {
        game->fireball.state = LEFT;
        set_fireball(game);
    }
    if (game->entities.mc.states_mc == FRONT) {
        game->fireball.state = FRONT;
        set_fireball(game);
    }
    if (game->entities.mc.states_mc == BACK) {
        game->fireball.state = BACK;
        set_fireball(game);
    }
    return;
}

static void throw_fireball_blond(game_t *game)
{
    if (game->entities.mc.states_mc == RIGHT_BLOND) {
        game->fireball.state = RIGHT;
        set_fireball(game);
    }
    if (game->entities.mc.states_mc == LEFT_BLOND) {
        game->fireball.state = LEFT;
        set_fireball(game);
    }
    if (game->entities.mc.states_mc == FRONT_BLOND) {
        game->fireball.state = FRONT;
        set_fireball(game);
    }
    if (game->entities.mc.states_mc == BACK_BLOND) {
        game->fireball.state = BACK;
        set_fireball(game);
    }
    return;
}

static void throw_fireball_girl(game_t *game)
{
    if (game->entities.mc.states_mc == RIGHT_GIRL) {
        game->fireball.state = RIGHT;
        set_fireball(game);
    }
    if (game->entities.mc.states_mc == LEFT_GIRL) {
        game->fireball.state = LEFT;
        set_fireball(game);
    }
    if (game->entities.mc.states_mc == FRONT_GIRL) {
        game->fireball.state = FRONT;
        set_fireball(game);
    }
    if (game->entities.mc.states_mc == BACK_GIRL) {
        game->fireball.state = BACK;
        set_fireball(game);
    }
    return;
}

static void throw_fireball_skater(game_t *game)
{
    if (game->entities.mc.states_mc == RIGHT_SKATER) {
        game->fireball.state = RIGHT;
        set_fireball(game);
    }
    if (game->entities.mc.states_mc == LEFT_SKATER) {
        game->fireball.state = LEFT;
        set_fireball(game);
    }
    if (game->entities.mc.states_mc == FRONT_SKATER) {
        game->fireball.state = FRONT;
        set_fireball(game);
    }
    if (game->entities.mc.states_mc == BACK_SKATER) {
        game->fireball.state = BACK;
        set_fireball(game);
    }
    return;
}

int check_character(game_t *game)
{
    if (game == NULL)
        return FAILURE;
    if (game->entities.mc.type == MC) {
        set_sprite_for_fireball(game);
        throw_fireball(game);
    }
    if (game->entities.mc.type == BLOND)
        throw_fireball_blond(game);
    if (game->entities.mc.type == GIRL)
        throw_fireball_girl(game);
    if (game->entities.mc.type == SKATER)
        throw_fireball_skater(game);
    return SUCCESS;
}
