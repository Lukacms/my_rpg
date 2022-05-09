/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** del_node
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "rpg.h"

int delete_pixelnode(particule_node_t *node, game_over_t *over)
{
    if (!node || !over)
        return FAILURE;
    if (node == over->particules.head)
        over->particules.head = over->particules.head->next;
    if (over->particules.head == over->particules.head->next)
        over->particules.head = NULL;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    sfClock_destroy(node->clock);
    sfRectangleShape_destroy(node->pixel);
    free(node);
    over->particules.size -= 1;
    return SUCCESS;
}
