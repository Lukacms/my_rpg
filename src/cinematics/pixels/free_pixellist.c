/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** free_pixellist
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg.h"

void free_pixellist(game_over_t *over)
{
    particule_node_t *anchor = (over ? over->particules.head : NULL);
    particule_node_t *tmp = (over ? over->particules.head : NULL);

    if (!over || !anchor)
        return;
    for (unsigned int i = 0; i < over->particules.size; i++) {
        anchor = anchor->next;
        sfClock_destroy(tmp->clock);
        sfRectangleShape_destroy(tmp->pixel);
        free(tmp);
        tmp = anchor;
    }
    sfClock_destroy(over->particules.clock);
    over->particules.head = NULL;
    over->particules.size = 0;
}
