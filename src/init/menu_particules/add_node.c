#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg.h"

static void init_node(particule_node_t *node, sfVector2f pos)
{
    node->pos = pos;
    node->next = node;
    node->prev = node;
    node->direction = (sfVector2f){0};
    node->vel = (sfVector2f){0};
}

static int info_node(particule_node_t *node)
{
    sfColor red = {69 + rand() % 186, 0, 0, 255};
    sfVector2f size = {4, 4};

    node->direction = (sfVector2f){rand() % 3 - 1, rand() % 3 - 1};
    node->vel = (sfVector2f){rand() % 5 + 5, rand() % 5 + 5};
    if (!(node->clock = sfClock_create()))
        return FAILURE;
    if (!(node->pixel = sfRectangleShape_create()))
        return FAILURE;
    sfRectangleShape_setFillColor(node->pixel, red);
    sfRectangleShape_setPosition(node->pixel, node->pos);
    sfRectangleShape_setSize(node->pixel, size);
    return SUCCESS;
}

static void put_node_in_list(particule_node_t *node, start_menu_t *menu)
{
    if (!menu->head)
        menu->head = node;
    else {
        node->prev = menu->head->prev;
        node->next = menu->head;
        menu->head->prev->next = node;
        menu->head->prev = node;
    }
}

int add_particule_node(start_menu_t *menu, sfVector2f pos)
{
    particule_node_t *node = NULL;

    if (!menu || !(node = malloc(sizeof(particule_node_t))))
        return FAILURE;
    init_node(node, pos);
    if (info_node(node) != SUCCESS)
        return FAILURE;
    put_node_in_list(node, menu);
    menu->size += 1;
    return SUCCESS;
}
