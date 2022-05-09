/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** is_mc_in_map
*/

#include <stdbool.h>
#include "my.h"
#include "rpg.h"

static int get_length_of_map(char **map)
{
    int index = 0;
    int count = -1;

    if (!map)
        return -1;
    while (map[index]) {
        index += 1;
        count += 1;
    }
    return count;
}

bool is_mc_in_map(game_t *game, int x, int y)
{
    int len_map = get_length_of_map(game->maps->map);
    int len_line = 0;

    if (y > len_map || len_line < 0)
        return false;
    len_line = my_strlen(game->maps->map[y]);
    if (x > len_line)
        return false;
    return true;
}
