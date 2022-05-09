/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** can_goes_on
*/

#include "my.h"
#include "rpg.h"

static const char ch[] = {
    '0', '1', ';',
    '/', ':', '!',
    '>', '<', ' ',
    '_', '#', '\\',
    '\0',
};

static int can_goes_on(char c)
{
    for (int i = 0; ch[i] != '\0'; i += 1) {
        if (ch[i] == c)
            return SUCCESS;
    }
    return FAILURE;
}

int is_move_valid(game_t *game, sfVector2i pos, int code, char **map)
{
    if (pos.x < 0 || pos.y < 0 || !map[pos.y] || map[pos.y][pos.x] == '\0')
        return FAILURE;
    if (code == game->key.up && can_goes_on(map[pos.y][pos.x]) == SUCCESS
        && is_mc_in_map(game, pos.x, pos.y) == true)
        return SUCCESS;
    if (code == game->key.down && can_goes_on(map[pos.y][pos.x]) == SUCCESS
        && is_mc_in_map(game, pos.x, pos.y) == true)
        return SUCCESS;
    if (code == game->key.left && can_goes_on(map[pos.y][pos.x]) == SUCCESS
        && is_mc_in_map(game, pos.x, pos.y) == true)
        return SUCCESS;
    if (code == game->key.right && can_goes_on(map[pos.y][pos.x]) == SUCCESS
        && is_mc_in_map(game, pos.x, pos.y) == true)
        return SUCCESS;
    if (map[pos.y][pos.x] == 'U' || map[pos.y][pos.x] == '~' ||
        map[pos.y][pos.x] == '+' || map[pos.y][pos.x] == '?')
        teleport_player(pos.x, pos.y, game);
    return FAILURE;
}
