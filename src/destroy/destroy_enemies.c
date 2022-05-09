/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** destroy_enemies
*/

#include "rpg.h"

int destroy_enemies(enemies_t *enemy)
{
    if (!enemy)
        return FAILURE;
    sfSprite_destroy(enemy->sprite);
    sfClock_destroy(enemy->animate);
    sfCircleShape_destroy(enemy->vision);
    return SUCCESS;
}
