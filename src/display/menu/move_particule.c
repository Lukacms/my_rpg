/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** move_particule
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg.h"

int move_particule(particule_node_t *node, start_menu_t *menu)
{
    sfVector2f move = {node->direction.x * node->vel.x,
                        node->direction.y * node->vel.y};
    sfTime time = {0};

    if (!node || !menu)
        return FAILURE;
    if (node->direction.x == 0 && node->direction.y == 0)
        node->direction = (sfVector2f){rand() % 3 - 1, rand() % 3 - 1};
    sfRectangleShape_move(node->pixel, move);
    time = sfClock_getElapsedTime(node->clock);
    if (sfTime_asSeconds(time) > 3.0)
        menu->pop(node, menu);
    return SUCCESS;
}
