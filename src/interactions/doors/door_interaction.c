/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** interaction_loop
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "rpg/events.h"
#include "rpg.h"

void door_interaction(game_t *game)
{
    if (game->inventory.key == true &&
        get_pos_in_map_up(game->entities.mc.sprite, game) == '%')
        has_key_interaction(game);
    else if (game->inventory.key == false &&
        get_pos_in_map_up(game->entities.mc.sprite, game) == '%')
        has_not_key_interaction(game);
    return;
}
