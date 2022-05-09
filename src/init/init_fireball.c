/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** init_fireball
*/

#include "rpg.h"

int init_fireball(game_t *game)
{
    if (!game)
        return FAILURE;
    game->fireball.t_fire = sfTexture_createFromFile(FIREBALL, NULL);
    game->fireball.fire = sfSprite_create();
    if (!game->fireball.t_fire || !game->fireball.fire)
        return FAILURE;
    sfSprite_setTexture(game->fireball.fire, game->fireball.t_fire, sfTrue);
    game->fireball.hidden = true;
    game->fireball.animate = sfClock_create();
    game->fireball.countdown = sfClock_create();
    if (!game->fireball.animate || !game->fireball.countdown)
        return FAILURE;
    game->fireball.state = 0;
    sfSprite_setPosition(game->fireball.fire, (sfVector2f){0, 0});
    return SUCCESS;
}
