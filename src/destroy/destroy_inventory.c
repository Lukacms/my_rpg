/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** destroy_inventory
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg.h"

static void destroy_slot(slot_t *slot)
{
    if (!slot)
        return;
    if (slot->rectangle)
        sfRectangleShape_destroy(slot->rectangle);
    if (slot->sprite)
        sfSprite_destroy(slot->sprite);
    if (slot->text)
        sfText_destroy(slot->text);
    free(slot);
}

void destroy_inventory(inventory_t *inventory)
{
    if (!inventory)
        return;
    sfSprite_destroy(inventory->sprite);
    sfTexture_destroy(inventory->texture);
    sfTexture_destroy(inventory->tex_item);
    sfText_destroy(inventory->text_click);
    sfText_destroy(inventory->text_fusion);
    for (int i = 0; i < 10; i++)
        destroy_slot(inventory->slot[i]);
}
