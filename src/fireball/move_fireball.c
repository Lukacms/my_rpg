/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** move_fireball
*/

#include "rpg.h"

void move_fireball(game_t *game)
{
    sfVector2f vector = {0, 0};

    if (game->fireball.state == LEFT)
        vector.x = -25;
    if (game->fireball.state == RIGHT)
        vector.x = 25;
    if (game->fireball.state == BACK)
        vector.y = -25;
    if (game->fireball.state == FRONT)
        vector.y = 25;
    sfSprite_move(game->fireball.fire, vector);
    return;
}
