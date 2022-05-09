/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** draw_fog
*/

#include <stdlib.h>
#include <sys/types.h>
#include <SFML/Graphics.h>
#include "rpg.h"

static void move_fog(particule_node_t *node)
{
    sfVector2f move = node->vel;

    move.x *= (rand() % 2 == 0 ? -1 : 1);
    move.y *= (rand() % 2 == 0 ? -1 : 1);
    sfRectangleShape_move(node->pixel, move);
}

int draw_fog(game_maps_t *maps, game_t *game)
{
    particule_node_t *node = NULL;

    if (!maps || !game || !(node = maps->head))
        return FAILURE;
    for (u_int i = 0; i < maps->size; i++) {
        sfRenderWindow_drawRectangleShape(game->window.window,
            node->pixel, NULL);
        move_fog(node);
        node = node->next;
    }
    return SUCCESS;
}
