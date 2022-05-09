/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** add_node
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <math.h>
#include "rpg.h"

static void init_node(particule_node_t *node)
{
    node->clock = NULL;
    node->pixel = NULL;
    node->direction = (sfVector2f){0};
    node->pos = (sfVector2f){0};
    node->vel = (sfVector2f){0};
    node->next = node;
    node->prev = node;
}

static void put_node_in_list(particule_node_t *node, game_over_t *over)
{
    if (!over->particules.head)
        over->particules.head = node;
    else {
        node->prev = over->particules.head->prev;
        node->next = over->particules.head;
        over->particules.head->prev->next = node;
        over->particules.head->prev = node;
    }
}

static int info_in_node(particule_node_t *node, sfVector2f pos)
{
    node->pos = pos;
    node->direction = (sfVector2f){rand() % 3 - 1, rand() % 3 - 1};
    node->vel = (sfVector2f){rand() % 50 + 10, rand() % 50 + 10};
    if (!(node->clock = sfClock_create()))
        return FAILURE;
    if (!(node->pixel = sfRectangleShape_create()))
        return FAILURE;
    sfRectangleShape_setSize(node->pixel, (sfVector2f){4, 4});
    sfRectangleShape_setPosition(node->pixel, node->pos);
    sfRectangleShape_setFillColor(node->pixel,
        sfColor_fromRGB(69 + rand() % 186, 0, 0));
    return SUCCESS;
}

int add_pixelnode(game_over_t *over, sfVector2f pos)
{
    particule_node_t *node = NULL;

    if (!over || !(node = malloc(sizeof(particule_node_t))))
        return FAILURE;
    init_node(node);
    if (info_in_node(node, pos) != SUCCESS)
        return FAILURE;
    put_node_in_list(node, over);
    over->particules.size += 1;
    return SUCCESS;
}
