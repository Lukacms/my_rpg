/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** check_hitbox
*/

#include "rpg.h"

item_node_t *get_item_collide(game_t *game)
{
    sfFloatRect mc_rect = sfSprite_getGlobalBounds(game->entities.mc.sprite);
    sfFloatRect item_rect = {0};
    item_node_t *item = {0};

    for (int index = 0; game->items.items[index] != NULL; index += 1) {
        item_rect = sfSprite_getGlobalBounds(game->items.items[index]->sprite);
        item = game->items.items[index];
        if (sfFloatRect_intersects(&mc_rect, &item_rect, NULL) == sfTrue)
            return item;
    }
    return NULL;
}

int is_collide(game_t *game)
{
    sfFloatRect mc_rect = sfSprite_getGlobalBounds(game->entities.mc.sprite);
    sfFloatRect item_rect = {0};

    for (int index = 0; game->items.items[index] != NULL; index += 1) {
        item_rect = sfSprite_getGlobalBounds(game->items.items[index]->sprite);
        if (sfFloatRect_intersects(&mc_rect, &item_rect, NULL) == sfTrue)
            return SUCCESS;
    }
    return FAILURE;
}
