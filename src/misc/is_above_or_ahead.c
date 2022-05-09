/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** is_above_or_ahead
*/

#include "rpg.h"

bool is_above_or_ahead(character_node_t mc, enemies_t *enemy)
{
    float y_mc = sfSprite_getGlobalBounds(mc.sprite).top -
                (sfSprite_getTextureRect(mc.sprite).height / 2);
    float y_enemy = sfSprite_getGlobalBounds(enemy->sprite).top -
                    (sfSprite_getTextureRect(enemy->sprite).height / 2);

    if (y_mc < y_enemy)
        return true;
    return false;
}

bool is_above_or_ahead_npc(character_node_t mc, npc_t *npc)
{
    float y_mc = sfSprite_getGlobalBounds(mc.sprite).top -
                (sfSprite_getTextureRect(mc.sprite).height / 2);
    float y_enemy = sfSprite_getGlobalBounds(npc->sprite_npc).top -
                    (sfSprite_getTextureRect(npc->sprite_npc).height / 2);

    if (y_mc < y_enemy)
        return true;
    return false;
}
