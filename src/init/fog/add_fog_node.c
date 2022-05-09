/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** add_fog_node
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg.h"

static int info_in_node(particule_node_t *node)
{
    sfColor color = {175 + rand() % 15, 175 + rand() % 15, 175 + rand() % 15,
                    51 + rand() % 80};
    sfVector2f size = {200 + rand() % 100, 100 + rand() % 100};

    if (!(node->clock = sfClock_create()))
        return FAILURE;
    node->direction = (sfVector2f){0};
    node->vel = (sfVector2f){rand() % 3 + 1, rand() % 3 + 1};
    node->pos.x = FOG_PLACEMENT.x + rand() % 3000;
    node->pos.y = FOG_PLACEMENT.y + rand() % 100;
    if (!(node->pixel = sfRectangleShape_create()))
        return FAILURE;
    sfRectangleShape_setFillColor(node->pixel, color);
    sfRectangleShape_setSize(node->pixel, size);
    sfRectangleShape_setPosition(node->pixel, node->pos);
    return SUCCESS;
}

static void put_node_in_list(particule_node_t *node, game_maps_t *maps)
{
    if (!maps->head)
        maps->head = node;
    else {
        node->prev = maps->head->prev;
        node->next = maps->head;
        maps->head->prev->next = node;
        maps->head->prev = node;
    }
}

int add_fog_node(game_maps_t *maps)
{
    particule_node_t *node = NULL;

    if (!maps || !(node = malloc(sizeof(particule_node_t))))
        return FAILURE;
    node->prev = node;
    node->next = node;
    if (info_in_node(node) != SUCCESS)
        return FAILURE;
    put_node_in_list(node, maps);
    maps->size += 1;
    return SUCCESS;
}
