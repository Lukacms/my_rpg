/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** init_sachiko
*/

#include <stdlib.h>
#include "rpg.h"

static const sfIntRect sachiko_sprite = {0, 1055, 24, 48};
static const sfVector2f sachiko_pos = {13549, 2005};
static const sfVector2f sachiko_scale = {2, 2};

int init_sachiko(game_t *game)
{
    if (!game || !game->entities.t_ennemies)
        return FAILURE;
    game->entities.sachiko = malloc(sizeof(npc_t));
    if (!game->entities.sachiko)
        return FAILURE;
    game->entities.sachiko->clock = NULL;
    game->entities.sachiko->vision_npc = NULL;
    game->entities.sachiko->sprite_npc = sfSprite_create();
    if (!game->entities.sachiko->sprite_npc)
        return FAILURE;
    sfSprite_setTexture(game->entities.sachiko->sprite_npc,
                        game->entities.t_ennemies, sfTrue);
    sfSprite_setTextureRect(game->entities.sachiko->sprite_npc, sachiko_sprite);
    sfSprite_setPosition(game->entities.sachiko->sprite_npc, sachiko_pos);
    sfSprite_setScale(game->entities.sachiko->sprite_npc, sachiko_scale);
    return SUCCESS;
}
