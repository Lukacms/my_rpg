/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** del_node
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg.h"

int del_node(particule_node_t *node, start_menu_t *menu)
{
    if (!node || !menu)
        return FAILURE;
    if (node == menu->head)
        menu->head = menu->head->next;
    if (menu->head->next == menu->head)
        menu->head = NULL;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    sfClock_destroy(node->clock);
    sfRectangleShape_destroy(node->pixel);
    free(node);
    menu->size -= 1;
    return SUCCESS;
}
