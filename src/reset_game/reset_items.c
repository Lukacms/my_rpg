/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** reset_items
*/

#include "rpg.h"

int reset_items(game_t *game)
{
    item_node_t **tmp = {0};
    sfVector2f size = {17, 30};

    if (!game)
        return FAILURE;
    tmp = game->items.items;
    for (int i = 0; tmp[i] != NULL; i += 1) {
        if (!tmp[i])
            return FAILURE;
        tmp[i]->taken = false;
    }
    sfRectangleShape_setSize(game->start_menu.load, size);
    return SUCCESS;
}
