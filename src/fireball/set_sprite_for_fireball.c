/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** set_sprite_for_fireball
*/

#include "rpg.h"

static const sfIntRect rects[] = {
    {72, 144, 24, 48},
    {72, 96, 24, 48},
    {72, 48, 24, 48},
};

void set_sprite_for_fireball(game_t *game)
{
    sfTime time = sfClock_getElapsedTime(game->fireball.countdown);

    if (sfKeyboard_isKeyPressed(sfKeyX) == sfTrue && sfTime_asSeconds(time) > 5
        && game->entities.mc.states_mc == RIGHT)
        sfSprite_setTextureRect(game->entities.mc.sprite, rects[0]);
    if (sfKeyboard_isKeyPressed(sfKeyX) == sfTrue && sfTime_asSeconds(time) > 5
        && game->entities.mc.states_mc == LEFT)
        sfSprite_setTextureRect(game->entities.mc.sprite, rects[1]);
    if (sfKeyboard_isKeyPressed(sfKeyX) == sfTrue && sfTime_asSeconds(time) > 5
        && game->entities.mc.states_mc == FRONT)
        sfSprite_setTextureRect(game->entities.mc.sprite, rects[2]);
    return;
}
