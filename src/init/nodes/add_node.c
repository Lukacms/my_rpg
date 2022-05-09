/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** add_node
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg.h"

int add_node(entities_t *entities, entity_type_t type, sfVector2f pos)
{
    enemies_t *node = malloc(sizeof(enemies_t));

    if (entities->enemies.size == 0) {
        enemy_dna(node, type, entities->t_ennemies, pos);
        node->next = node;
        node->prev = node;
        entities->enemies.head = node;
    } else {
        enemy_dna(node, type, entities->t_ennemies, pos);
        node->prev = entities->enemies.head->prev;
        node->next = entities->enemies.head;
        entities->enemies.head->prev->next = node;
        entities->enemies.head->prev = node;
    }
    entities->enemies.size += 1;
    node->hidden = false;
    return SUCCESS;
}
