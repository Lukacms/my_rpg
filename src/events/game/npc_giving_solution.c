/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** npc_giving_solution
*/

#include <SFML/Graphics.h>
#include "rpg.h"

int talk_to_npc2(game_t *game, sfKeyCode code)
{
    sfFloatRect mc = {0};
    sfFloatRect vision = {0};

    if (!game || code != game->key.interact)
        return FAILURE;
    mc = sfSprite_getGlobalBounds(game->entities.mc.sprite);
    vision = sfSprite_getGlobalBounds(game->entities.npc[1]->sprite_npc);
    if (sfFloatRect_intersects(&mc, &vision, NULL) == sfTrue)
        find_solution(game);
    return SUCCESS;
}
