/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** hole_in_ground
*/

#include "rpg.h"

static const create_holes_t step_one[] = {
    {265, 32, '!'},
    {267, 31, '!'},
    {268, 32, '!'},
    {260, 34, '!'},
    {267, 32, '!'},
    {265, 32, '!'},
    {265, 30, '!'},
    {262, 31, '!'},
    {-1, -1, '\0'},
};

static const create_holes_t step_two[] = {
    {266, 30, '3'},
    {266, 31, '3'},
    {267, 32, '3'},
    {268, 33, '3'},
    {267, 34, '3'},
    {267, 35, '3'},
    {267, 36, '3'},
    {266, 37, '3'},
    {266, 38, '3'},
    {272, 30, '5'},
    {271, 31, '5'},
    {271, 32, '5'},
    {270, 33, '5'},
    {270, 34, '5'},
    {271, 35, '5'},
    {271, 36, '5'},
    {271, 37, '5'},
    {272, 38, '5'},
    {267, 30, '4'},
    {268, 30, '4'},
    {269, 30, '4'},
    {270, 30, '4'},
    {271, 30, '4'},
    {267, 31, '4'},
    {268, 31, '4'},
    {269, 31, '4'},
    {270, 31, '4'},
    {268, 32, '4'},
    {269, 32, '4'},
    {270, 32, '4'},
    {269, 33, '4'},
    {268, 34, '4'},
    {269, 34, '4'},
    {268, 35, '4'},
    {269, 35, '4'},
    {270, 35, '4'},
    {268, 36, '4'},
    {269, 36, '4'},
    {270, 36, '4'},
    {267, 37, '4'},
    {268, 37, '4'},
    {269, 37, '4'},
    {270, 37, '4'},
    {267, 38, '4'},
    {268, 38, '4'},
    {269, 38, '4'},
    {270, 38, '4'},
    {271, 38, '4'},
    {-1, -1, '\0'},
};

void hole_in_ground_step_one(game_t *game)
{
    if (!game || !game->maps->map)
        return;
    for (int index = 0; step_one[index].x != -1; index += 1) {
        game->maps->map[step_one[index].y][step_one[index].x] =
        step_one[index].hole;
    }
    return;
}

void hole_in_ground_step_two(game_t *game)
{
    if (!game || !game->maps->map)
        return;
    for (int index = 0; step_two[index].x != -1; index += 1) {
        game->maps->map[step_two[index].y][step_two[index].x] =
        step_two[index].hole;
    }
    return;
}
