/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** destroy_tilemap
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg.h"
#include "my.h"

void destroy_tilemap(tilemap_t *map)
{
    if (!map)
        return;
    sfTexture_destroy(map->tilemap);
    sfSprite_destroy(map->sprite);
    free(map);
}

static void destroy_fog(game_maps_t *maps)
{
    particule_node_t *anchor = NULL;
    particule_node_t *tmp = NULL;

    if (!maps || !(anchor = maps->head))
        return;
    tmp = anchor;
    for (unsigned int i = 0; i < maps->size; i++) {
        anchor = anchor->next;
        sfClock_destroy(tmp->clock);
        sfRectangleShape_destroy(tmp->pixel);
        free(tmp);
        tmp = anchor;
    }
    maps->head = NULL;
    maps->size = 0;
}

void destroy_maps(game_maps_t *maps)
{
    if (!maps)
        return;
    if (maps->original_map)
        free(maps->original_map);
    if (maps->map)
        free_array((void **)maps->map);
    destroy_fog(maps);
    free(maps);
}
