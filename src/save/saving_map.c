/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** saving_map
*/

#include <fcntl.h>
#include <unistd.h>
#include "rpg.h"
#include "my.h"

int saving_map(game_t *game)
{
    int fd = -1;

    if (!game)
        return FAILURE;
    fd = open(SAVED_MAP, O_RDWR | O_CREAT | O_TRUNC, 0666);
    if (fd <= -1)
        return FAILURE;
    for (int i = 0; game->maps->map[i] != NULL; i += 1) {
        write(fd, game->maps->map[i], my_strlen(game->maps->map[i]));
        write(fd, "\n", 1);
    }
    close(fd);
    return SUCCESS;
}
