/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** animate_enemies
*/

#include "rpg.h"

static int manage_rect(enemies_t *enemy)
{
    sfIntRect rect;

    if (!enemy)
        return FAILURE;
    rect = sfSprite_getTextureRect(enemy->sprite);
    rect.left += 24;
    if (rect.left > 48)
        rect.left = 0;
    sfSprite_setTextureRect(enemy->sprite, rect);
    return SUCCESS;
}

int animate_enemies(game_t *game)
{
    enemies_t *tmp;
    sfTime time = {0};

    if (!game)
        return FAILURE;
    tmp = game->entities.enemies.head;
    for (unsigned int i = 0; i < game->entities.enemies.size; i += 1) {
        time = sfClock_getElapsedTime(tmp->animate);
        if (sfTime_asSeconds(time) > 0.2) {
            manage_rect(tmp);
            sfClock_restart(tmp->animate);
        }
        tmp = tmp->next;
    }
    return SUCCESS;
}
