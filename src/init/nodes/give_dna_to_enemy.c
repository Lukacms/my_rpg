/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** give_dna_to_enemy
*/

#include <SFML/Graphics.h>
#include "rpg/game.h"
#include "rpg/macros.h"
#include "rpg/init.h"

static sfIntRect which_enemy_is(entity_type_t type)
{
    if (type == BAD_FLAMES)
        return ((sfIntRect){0, 0, 24, 48});
    if (type == NICE_FLAMES)
        return ((sfIntRect){0, 48, 24, 48});
    if (type == GHOST)
        return ((sfIntRect){0, 96, 24, 48});
    if (type == MODEL)
        return ((sfIntRect){0, 288, 24, 48});
    if (type == INFECTED)
        return ((sfIntRect){0, 576, 24, 48});
    if (type == NOT_INFECTED)
        return ((sfIntRect){0, 768, 24, 48});
    if (type == WARRIOR)
        return ((sfIntRect){0, 384, 24, 48});
    return ((sfIntRect){0, 0, 0, 0});
}

static int which_stats(enemies_t *node, entity_type_t type)
{
    if (node == NULL)
        return FAILURE;
    if (type == GHOST)
        node->life = 5;
    if (type == BAD_FLAMES)
        node->life = 2;
    if (type == MODEL)
        node->life = 1000;
    if (type == INFECTED)
        node->life = 3;
    if (type == NOT_INFECTED)
        node->life = 1;
    if (type == WARRIOR)
        node->life = 4;
    return SUCCESS;
}

static void set_radius_enemy(enemies_t *node, entity_type_t type)
{
    if (type == MODEL) {
        sfCircleShape_setRadius(node->vision, 300);
        node->state = BACK;
    } else
        sfCircleShape_setRadius(node->vision, 100);
}

int enemy_dna(enemies_t *node, entity_type_t type, sfTexture *tex,
                sfVector2f pos)
{
    node->sprite = sfSprite_create();
    if (!node->sprite)
        return FAILURE;
    sfSprite_setTexture(node->sprite, tex, sfTrue);
    sfSprite_setTextureRect(node->sprite, which_enemy_is(type));
    if (type == MODEL)
        sfSprite_setScale(node->sprite, (sfVector2f){3, 3});
    else
        sfSprite_setScale(node->sprite, (sfVector2f){2, 2});
    sfSprite_setPosition(node->sprite, pos);
    node->animate = sfClock_create();
    node->vision = sfCircleShape_create();
    node->type = type;
    set_radius_enemy(node, type);
    sfCircleShape_setFillColor(node->vision, sfWhite);
    if (which_stats(node, type) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
