/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** fireball_loop
*/

#include "rpg.h"

void fireball_loop(game_t *game)
{
    is_fireball_thrown(game);
    move_fireball(game);
    is_enemy_hit(game);
    dispawn_fireball(game);
}
