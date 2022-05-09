/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** launch_script_model.c
*/

#include "rpg.h"

static void change_room1(game_t *game)
{
    game->maps->map[22][203] = '#';
    game->maps->map[17][210] = '#';
    game->maps->map[15][199] = '3';
    game->maps->map[15][200] = '4';
    game->maps->map[15][201] = '4';
    game->maps->map[15][202] = '4';
    game->maps->map[15][203] = '4';
    game->maps->map[15][204] = '5';
    game->maps->map[16][196] = '3';
    game->maps->map[16][197] = '4';
    game->maps->map[16][198] = '5';
}

static void change_room2(game_t *game)
{
    game->maps->map[16][201] = '4';
    game->maps->map[16][202] = '4';
    game->maps->map[16][203] = '4';
    game->maps->map[16][204] = '4';
    game->maps->map[16][205] = '4';
    game->maps->map[16][206] = '5';
    game->maps->map[17][196] = '3';
    game->maps->map[17][197] = '4';
    game->maps->map[17][198] = '4';
    game->maps->map[18][197] = '3';
    game->maps->map[18][198] = '4';
    game->maps->map[18][199] = '4';
    game->maps->map[18][200] = '4';
    game->maps->map[18][201] = '5';
    game->maps->map[18][204] = '5';
    game->maps->map[19][207] = '3';
    game->maps->map[19][208] = '4';
    game->maps->map[19][209] = '4';
    game->maps->map[19][210] = '5';
    game->maps->map[20][200] = '3';
}

static void change_room3(game_t *game)
{
    game->maps->map[20][201] = '4';
    game->maps->map[20][202] = '4';
    game->maps->map[20][203] = '4';
    game->maps->map[20][204] = '4';
    game->maps->map[20][205] = '5';
    game->maps->map[22][196] = '3';
    game->maps->map[22][197] = '4';
    game->maps->map[22][198] = '4';
    game->maps->map[22][199] = '4';
    game->maps->map[22][200] = '4';
    game->maps->map[22][207] = '3';
    game->maps->map[22][208] = '4';
    game->maps->map[22][209] = '4';
    game->maps->map[22][210] = '5';
    game->maps->map[21][197] = '\\';
}

void launch_script_new_room(game_t *game)
{
    sfTime time = {0};
    int index = 0;

    while (1) {
        time = sfClock_getElapsedTime(game->window.game_clock);
        if (sfTime_asSeconds(time) > 0.1) {
            index += 1;
            sfClock_restart(game->window.game_clock);
        }
        if (index == 1) {
            change_room1(game);
            change_room2(game);
            change_room3(game);
            sfSprite_move(game->entities.mc.sprite, (sfVector2f){0, -48});
            break;
        }
    }
}
