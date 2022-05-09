/*
** EPITECH PROJECT, 2021
** Init tilemap
** File description:
** init_tilemap.c
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg/game.h"
#include "rpg/macros.h"
#include "rpg/init.h"

int init_tilemap(game_t *game)
{
    game->tilemap = malloc(sizeof(tilemap_t));
    if (game->tilemap == NULL)
        return FAILURE;
    if ((game->tilemap->tilemap =
    sfTexture_createFromFile("assets/scenes/tileset.png", NULL)) == NULL)
        return FAILURE;
    if ((game->tilemap->sprite = sfSprite_create()) == NULL)
        return FAILURE;
    sfSprite_setTexture(game->tilemap->sprite,
    game->tilemap->tilemap, sfTrue);
    game->tilemap->rect = (sfIntRect){0, 0, 24, 24};
    sfSprite_setTextureRect(game->tilemap->sprite,
    game->tilemap->rect);
    sfSprite_setScale(game->tilemap->sprite, (sfVector2f) {2.0, 2.0});
    return SUCCESS;
}
