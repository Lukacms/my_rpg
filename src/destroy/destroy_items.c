/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** destroy_items
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg.h"

static void destroy_item(item_node_t *node)
{
    sfSprite_destroy(node->sprite);
    free(node);
}

void destroy_items(items_t *items)
{
    if (!items)
        return;
    sfTexture_destroy(items->sparkle);
    sfTexture_destroy(items->paper);
    sfClock_destroy(items->clock);
    for (int i = 0; items->items[i]; i++)
        destroy_item(items->items[i]);
    free(items->items);
}
