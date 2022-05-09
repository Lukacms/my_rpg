/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** is_mc_touched
*/

#include "rpg.h"

static bool verify_collision(game_t *game, enemies_t *tmp)
{
    sfFloatRect mc_rect = get_true_rect_mc(game->entities.mc.sprite);
    sfFloatRect enemy_rect = {0};
    sfTime time = {0};

    enemy_rect = sfSprite_getGlobalBounds(tmp->sprite);
    enemy_rect.top -= (enemy_rect.height / 3) * 2;
    enemy_rect.height = (enemy_rect.height / 3);
    time = sfClock_getElapsedTime(game->entities.invicible);
    if (sfFloatRect_intersects(&mc_rect, &enemy_rect, NULL) == sfTrue
    && sfTime_asSeconds(time) > 3 && tmp->hidden == false) {
        sfClock_restart(game->entities.invicible);
        if (tmp->type == MODEL) {
            game->entities.instant_dead = true;
        }
        return true;
    }
    return false;
}

bool is_mc_touched(game_t *game)
{
    enemies_t *tmp = game->entities.enemies.head;

    for (unsigned int i = 0; i < game->entities.enemies.size; i += 1) {
        if (verify_collision(game, tmp) == true) {
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}
