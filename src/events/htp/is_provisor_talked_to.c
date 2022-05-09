/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** is_provisor_talked_to
*/

#include <stdbool.h>
#include <SFML/Graphics.h>
#include "rpg.h"

int is_provisor_talked_to(game_t *game, sfKeyCode code)
{
    sfFloatRect mc = {0};
    sfFloatRect vision = {0};

    if (!game || game->htp.state != TRANSITION || code != game->key.interact)
        return FAILURE;
    mc = sfSprite_getGlobalBounds(game->entities.mc.sprite);
    vision = sfSprite_getGlobalBounds(game->htp.provisor.sprite);
    if (sfFloatRect_intersects(&mc, &vision, NULL) == sfTrue)
        game->htp.next = true;
    return SUCCESS;
}
