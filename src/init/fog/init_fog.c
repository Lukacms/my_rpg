/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** init_fog
*/

#include <SFML/Graphics.h>
#include "rpg.h"

int init_fog(game_maps_t *maps)
{
    if (!maps)
        return FAILURE;
    maps->head = NULL;
    maps->size = 0;
    for (int i = 0; i < 55; i++)
        if (add_fog_node(maps) != SUCCESS)
            return FAILURE;
    return SUCCESS;
}
