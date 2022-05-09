/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** idle_deplacement
*/

#include <stdlib.h>
#include "rpg.h"

static sfVector2f random_move(game_t *game, enemies_t *tmp)
{
    int x = rand() % 4;

    if (tmp->type == GHOST || tmp->type == INFECTED || tmp->type == MODEL ||
    tmp->type == NOT_INFECTED || tmp->type == WARRIOR)
        return ((sfVector2f){0, 0});
    if (x == 0 && hitbox_down(tmp->sprite, game, game->key.down) == SUCCESS)
        return ((sfVector2f){0, 16});
    if (x == 1 && hitbox_up(tmp->sprite, game, game->key.up) == SUCCESS)
        return ((sfVector2f){0, -16});
    if (x == 2 && hitbox_right(tmp->sprite, game, game->key.right) == SUCCESS)
        return ((sfVector2f){16, 0});
    if (x == 3 && hitbox_left(tmp->sprite, game, game->key.left) == SUCCESS)
        return ((sfVector2f){-16, 0});
    return ((sfVector2f){0, 0});
}

static sfVector2f which_enemy(sfFloatRect tmp, sfFloatRect tmp2,
enemies_t *enemy)
{
    sfVector2f pos = {0};

    if (enemy->type == GHOST)
        return move_ghost(tmp, tmp2, pos, enemy);
    if (enemy->type == MODEL)
        return move_model(tmp, tmp2, pos, enemy);
    if (enemy->type == INFECTED)
        return move_infected(tmp, tmp2, pos, enemy);
    if (enemy->type == NOT_INFECTED)
        return move_not_infected(tmp, tmp2, pos, enemy);
    if (enemy->type == WARRIOR)
        return move_warrior(tmp, tmp2, pos, enemy);
    return ((sfVector2f){0, 0});
}

static sfVector2f change_pos(enemies_t *enemy, game_t *game, sfFloatRect tmp,
sfFloatRect tmp2)
{
    sfVector2f pos = {0};

    if (tmp.left > tmp2.left &&
    hitbox_right(enemy->sprite, game, game->key.right) == SUCCESS)
        pos.x += 24;
    if (tmp.left < tmp2.left &&
    hitbox_left(enemy->sprite, game, game->key.left) == SUCCESS)
        pos.x += -24;
    if (tmp.top > tmp2.top &&
    hitbox_down(enemy->sprite, game, game->key.down) == SUCCESS)
        pos.y += 24;
    if (tmp.top < tmp2.top &&
    hitbox_up(enemy->sprite, game, game->key.up) == SUCCESS)
        pos.y += -24;
    return pos;
}

static sfVector2f chase(game_t *game, enemies_t *enemy, entity_type_t type)
{
    sfFloatRect tmp = get_true_rect_mc(game->entities.mc.sprite);
    sfFloatRect tmp2 = sfSprite_getGlobalBounds(enemy->sprite);

    tmp2.top -= (tmp2.height / 3) * 2;
    tmp2.height = (tmp2.height / 3);
    tmp.top += 24;
    if (type == GHOST || type == INFECTED || type == MODEL || type ==
    NOT_INFECTED || type == WARRIOR)
        return which_enemy(tmp, tmp2, enemy);
    return change_pos(enemy, game, tmp, tmp2);
}

void idle_move(game_t *game)
{
    enemies_t *tmp = game->entities.enemies.head;
    sfTime time = sfClock_getElapsedTime(game->entities.move);

    for (unsigned int i = 0; i < game->entities.enemies.size; i += 1) {
        if (sfTime_asSeconds(time) > 1.5 && is_chase(tmp, game) == false) {
            sfSprite_move(tmp->sprite, random_move(game, tmp));
            sfClock_restart(game->entities.move);
        }
        if (sfTime_asSeconds(time) > 0.25 && is_chase(tmp, game) == true) {
            sfSprite_move(tmp->sprite, chase(game, tmp, tmp->type));
            sfClock_restart(game->entities.move);
        }
        tmp = tmp->next;
    }
    return;
}
