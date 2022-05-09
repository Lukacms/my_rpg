/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** reset_enemies
*/

#include "rpg.h"

int reset_enemies(game_t *game)
{
    enemies_t *tmp = {0};

    if (!game)
        return FAILURE;
    tmp = game->entities.enemies.head;
    for (unsigned int i = 0; i < game->entities.enemies.size; i += 1) {
        if (!tmp)
            return FAILURE;
        tmp->hidden = false;
        tmp = tmp->next;
    }
    return SUCCESS;
}
