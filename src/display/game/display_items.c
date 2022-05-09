/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** draw_items
*/

#include "my.h"
#include "rpg.h"

int draw_items(game_t *game)
{
    if (!game)
        return FAILURE;
    for (int index = 0; game->items.items[index] != NULL; index += 1) {
        if (game->items.items[index]->taken == false)
            sfRenderWindow_drawSprite(game->window.window,
                                    game->items.items[index]->sprite, NULL);
    }
    return SUCCESS;
}
