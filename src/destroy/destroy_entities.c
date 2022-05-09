/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** destroy_entities
*/

#include <stdbool.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg.h"

static void free_dust(character_node_t *mc)
{
    particule_node_t *anchor = NULL;
    particule_node_t *tmp = NULL;

    if (!mc || !(anchor = mc->particules.head))
        return;
    tmp = anchor;
    for (unsigned int i = 0; i < mc->particules.size; i++) {
        anchor = anchor->next;
        sfClock_destroy(tmp->clock);
        sfRectangleShape_destroy(tmp->pixel);
        free(tmp);
        tmp = anchor;
    }
    sfClock_destroy(mc->particules.clock);
    mc->particules.head = NULL;
    mc->particules.size = 0;
}

static int destroy_mc(character_node_t *mc)
{
    if (!mc)
        return FAILURE;
    sfSprite_destroy(mc->sprite);
    sfTexture_destroy(mc->tex_character);
    sfClock_destroy(mc->animate);
    free_dust(mc);
    return SUCCESS;
}

static void free_enemy_list(entities_t *entities)
{
    enemies_t *tmp = entities->enemies.head;
    enemies_t *anchor = entities->enemies.head;

    if (!entities->enemies.head)
        return;
    for (unsigned int i = 0; i < entities->enemies.size; i += 1) {
        anchor = anchor->next;
        destroy_enemies(tmp);
        free(tmp);
        tmp = anchor;
    }
    entities->enemies.head = NULL;
    entities->enemies.size = 0;
}

static void destroy_npc(npc_t *npc, bool tex)
{
    if (!npc)
        return;
    if (tex)
        sfTexture_destroy(npc->tex_npc);
    if (npc->sprite_npc)
    sfSprite_destroy(npc->sprite_npc);
    if (npc->clock)
    sfClock_destroy(npc->clock);
    if (npc->vision_npc)
        sfCircleShape_destroy(npc->vision_npc);
    free(npc);
}

void destroy_entities(entities_t *entities)
{
    if (!entities)
        return;
    free_enemy_list(entities);
    destroy_mc(&entities->mc);
    destroy_npc(entities->sachiko, false);
    for (int i = 0; entities->npc[i] && i < 5; i++)
        destroy_npc(entities->npc[i], true);
    sfClock_destroy(entities->invicible);
    sfTexture_destroy(entities->t_ennemies);
    sfClock_destroy(entities->move);
}
