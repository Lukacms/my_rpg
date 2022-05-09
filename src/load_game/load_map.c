/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** load_pos_of_mc
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "rpg.h"

int load_map(game_t *game)
{
    int fd = -1;
    char *map = malloc(sizeof(char) * (MAP_SIZE + 1));
    int size = 0;

    fd = open(SAVED_MAP, O_RDONLY);
    if (fd == -1 || !map)
        return FAILURE;
    if ((size = read(fd, map, MAP_SIZE)) < 0)
        return FAILURE;
    map[size] = '\0';
    game->maps->map = initialize_two_d_array(map);
    free(map);
    close(fd);
    return SUCCESS;
}
