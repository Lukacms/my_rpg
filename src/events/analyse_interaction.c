/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** analyse_interaction
*/

#include "rpg.h"

void analyse_interaction(game_t *game, sfEvent evt)
{
    if (game->inventory.wooden_plank == false)
        get_wooden_plank(game, evt.key.code);
    else
        set_wooden_plank(game, evt.key.code);
    if (evt.key.code == game->key.interact) {
        if (is_collide(game) == SUCCESS)
            item_interaction(game);
        door_interaction(game);
    }
    talk_to_npc2(game, evt.key.code);
}
