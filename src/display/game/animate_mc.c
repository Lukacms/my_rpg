/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** display_mc
*/

#include <SFML/System/Time.h>
#include "rpg.h"

int animate_mc(character_node_t *mc)
{
    sfIntRect mc_rect;
    sfTime time;
    float seconds = 0;

    if (!mc)
        return FAILURE;
    mc_rect = sfSprite_getTextureRect(mc->sprite);
    time = sfClock_getElapsedTime(mc->animate);
    seconds = time.microseconds / 100000.0;
    if (seconds > 1.5) {
        mc_rect.left += 24;
        sfClock_restart(mc->animate);
    }
    if (mc_rect.left >= 72)
        mc_rect.left = 0;
    return mc_rect.left;
}
