/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Espace de travail)
** File description:
** init_main_character
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg.h"
#include "rpg/game.h"
#include "rpg/macros.h"
#include "rpg/init.h"

static int init_mc_particules(character_node_t *mc)
{
    mc->particules.clock = NULL;
    mc->particules.head = NULL;
    mc->particules.size = 0;
    mc->particules.add = &add_pixelnode_mc;
    mc->particules.pop = NULL;
    mc->display_particules = false;
    for (int i = 0; i < 50; i++)
        add_pixelnode_mc(mc, (sfVector2f){mc->pos.x + rand() % 50,
            mc->pos.y + rand() % 50});
    return SUCCESS;
}

int init_main_character(game_t *game)
{
    sfIntRect mc_rect = {0, 0, 24, 48};

    game->entities.mc.type = MC;
    game->entities.mc.states_mc = BACK;
    game->entities.mc.tex_character = sfTexture_createFromFile(SATOSHI, NULL);
    if (!game->entities.mc.tex_character)
        return FAILURE;
    game->entities.mc.sprite = sfSprite_create();
    if (!game->entities.mc.sprite)
        return FAILURE;
    sfSprite_setTexture(game->entities.mc.sprite,
                        game->entities.mc.tex_character, sfTrue);
    sfSprite_setTextureRect(game->entities.mc.sprite, mc_rect);
    sfSprite_setScale(game->entities.mc.sprite, (sfVector2f){2, 2});
    sfSprite_setPosition(game->entities.mc.sprite,
                        (sfVector2f){5113, 5500});
    game->entities.mc.animate = sfClock_create();
    game->entities.invicible = sfClock_create();
    return init_mc_particules(&game->entities.mc);
}

static sfIntRect check_rect(entity_type_t type)
{
    if (type == NPC)
        return ((sfIntRect){0, 144, 24, 48});
    if (type == NPC2)
        return ((sfIntRect){0, 288, 24, 48});
    if (type == NPC3)
        return ((sfIntRect){0, 480, 24, 48});
    if (type == NPC4)
        return ((sfIntRect){0, 672, 24, 48});
    if (type == NPC5)
        return ((sfIntRect){0, 768, 24, 48});
    return ((sfIntRect){0, 0, 0, 0});
}

static int npc_sprite(game_t *game, entity_type_t type, int index,
sfVector2f pos_npc)
{
    game->entities.npc[index] = malloc(sizeof(npc_t));
    game->entities.npc[index]->tex_npc =
    sfTexture_createFromFile(TEX_NPC, NULL);
    game->entities.npc[index]->sprite_npc = sfSprite_create();
    if (!game->entities.npc[index]->tex_npc ||
    !game->entities.npc[index]->sprite_npc)
        return FAILURE;
    sfSprite_setTexture(game->entities.npc[index]->sprite_npc,
    game->entities.npc[index]->tex_npc, sfTrue);
    sfSprite_setTextureRect(game->entities.npc[index]->sprite_npc,
    check_rect(type));
    sfSprite_setPosition(game->entities.npc[index]->sprite_npc, pos_npc);
    sfSprite_setScale(game->entities.npc[index]->sprite_npc,
    (sfVector2f){2, 2});
    return SUCCESS;
}

int init_npc(game_t *game, entity_type_t type, int index, sfVector2f pos_npc)
{
    if (npc_sprite(game, type, index, pos_npc) != SUCCESS)
        return FAILURE;
    game->entities.npc[index]->clock = sfClock_create();
    if (!game->entities.npc[index]->clock)
        return FAILURE;
    game->entities.npc[index]->type = type;
    game->entities.npc[index]->vision_npc = sfCircleShape_create();
    sfCircleShape_setRadius(game->entities.npc[index]->vision_npc, 50);
    sfCircleShape_setFillColor(game->entities.npc[index]->vision_npc, sfRed);
    return SUCCESS;
}
