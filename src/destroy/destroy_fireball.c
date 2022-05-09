/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** destroy_fireball
*/

#include <SFML/Graphics.h>
#include "rpg.h"

void destroy_fireball(fireball_t *fire)
{
    if (!fire)
        return;
    sfTexture_destroy(fire->t_fire);
    sfSprite_destroy(fire->fire);
    sfClock_destroy(fire->animate);
    sfClock_destroy(fire->countdown);
}
