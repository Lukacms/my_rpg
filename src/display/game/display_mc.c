/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** display_mc
*/

#include <stdlib.h>
#include "rpg.h"

int display_mc(character_node_t *mc, sfRenderWindow *window)
{
    particule_node_t *tmp;

    if (!mc || !window)
        return FAILURE;
    tmp = mc->particules.head;
    sfRenderWindow_drawSprite(window, mc->sprite, NULL);
    if (!mc->display_particules)
        return SUCCESS;
    for (unsigned int i = 0; i < mc->particules.size; i++) {
        sfRenderWindow_drawRectangleShape(window, tmp->pixel, NULL);
        tmp = tmp->next;
    }
    return SUCCESS;
}
