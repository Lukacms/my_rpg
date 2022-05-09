/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** init_pixel
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg.h"

int init_pixellist(game_t *game)
{
    if (!game)
        return FAILURE;
    game->game_over.particules.clock = NULL;
    game->game_over.particules.head = NULL;
    game->game_over.particules.size = 0;
    game->game_over.particules.add = &add_pixelnode;
    game->game_over.particules.pop = &delete_pixelnode;
    if (!(game->game_over.particules.clock = sfClock_create()))
        return FAILURE;
    return SUCCESS;
}
