/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** move_pixel
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg.h"

int move_pixel(particule_node_t *particule)
{
    sfVector2f offset = {0};

    if (!particule)
        return FAILURE;
    offset.x = particule->vel.x * -1;
    offset.y = particule->vel.y * particule->direction.y;
    sfRectangleShape_move(particule->pixel, offset);
    if (particule->direction.y == 0)
        particule->direction = (sfVector2f){rand() % 3 - 1, rand() % 3 - 1};
    particule->pos = sfRectangleShape_getPosition(particule->pixel);
    return SUCCESS;
}
