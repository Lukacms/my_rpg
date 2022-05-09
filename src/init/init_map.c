/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** init_map
*/

#include <SFML/Graphics.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include "rpg/game.h"
#include "rpg/macros.h"
#include "rpg/init.h"

static char *load_file(char const *filepath, int size)
{
    int status = -1;
    char *buffer = NULL;
    int fd = -1;

    if (!filepath)
        return NULL;
    if ((fd = open(filepath, O_RDONLY)) < 0)
        return NULL;
    buffer = malloc(sizeof(char) * (size + 1));
    if (!buffer)
        return NULL;
    if ((status = read(fd, buffer, size)) < 0)
        return NULL;
    buffer[status] = '\0';
    close(fd);
    return buffer;
}

int init_map(game_t *game)
{
    char *tmp = NULL;

    game->maps = malloc(sizeof(game_maps_t));
    if (!game->maps)
        return FAILURE;
    if ((tmp = load_file(WORLD_MAP, 2000000000)) == NULL)
        return FAILURE;
    game->maps->original_map = tmp;
    if ((game->maps->map = initialize_two_d_array(tmp)) == NULL)
        return FAILURE;
    if (init_fog(game->maps) != SUCCESS)
        return FAILURE;
    return SUCCESS;
}
