/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** animate_items
*/

#include "rpg.h"

static int animate_items_node(item_node_t *item, items_t items)
{
    sfIntRect rect;
    sfTime time;

    if (!item)
        return FAILURE;
    rect = sfSprite_getTextureRect(item->sprite);
    if (item->type != STORY_PAPER) {
        time = sfClock_getElapsedTime(items.clock);
        if (sfTime_asSeconds(time) > 0.2)
            rect.left += 48;
        if (rect.left >= 336)
            rect.left = 0;
        sfSprite_setTextureRect(item->sprite, rect);
    }
    return SUCCESS;
}

int animate_items(items_t items)
{
    sfTime time = {0};

    for (int index = 0; items.items[index] != NULL; index += 1)
        animate_items_node(items.items[index], items);
    time = sfClock_getElapsedTime(items.clock);
    if (sfTime_asSeconds(time) > 0.2)
        sfClock_restart(items.clock);
    return SUCCESS;
}
