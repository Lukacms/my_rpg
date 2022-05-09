/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** reset_inventory
*/

#include "rpg.h"

int reset_inventory(game_t *game)
{
    if (!game)
        return FAILURE;
    game->inventory.key = false;
    game->inventory.magic_attack = true;
    game->inventory.wooden_plank = false;
    game->inventory.full_puppet = false;
    game->inventory.head_puppet = true;
    game->inventory.madness_potion = false;
    game->inventory.body_puppet = false;
    game->inventory.heal_bottle = false;
    return SUCCESS;
}
