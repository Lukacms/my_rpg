/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** add_node
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg.h"

static int init_node(skill_node_t *node, sfVector2f pos)
{
    sfColor color = {107, 107, 107, 170};

    if (!(node->circle = sfCircleShape_create()))
        return FAILURE;
    sfCircleShape_setFillColor(node->circle, color);
    sfCircleShape_setRadius(node->circle, 33.0);
    sfCircleShape_setPosition(node->circle, pos);
    node->acquired = false;
    node->pos = pos;
    node->next = node;
    node->prev = node;
    return SUCCESS;
}

static void put_node_in_list(skill_node_t **head, skill_node_t *node)
{
    if (!(*head))
        (*head) = node;
    else {
        node->prev = (*head)->prev;
        node->next = (*head);
        (*head)->prev->next = node;
        (*head)->prev = node;
    }
}

int add_skillnode(skill_node_t **head, sfVector2f pos)
{
    skill_node_t *node = NULL;

    if (!head || !(node = malloc(sizeof(skill_node_t))))
        return FAILURE;
    if (init_node(node, pos) != SUCCESS)
        return FAILURE;
    put_node_in_list(head, node);
    return SUCCESS;
}
