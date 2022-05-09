/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** is_enemy_hit
*/

#include <sys/types.h>
#include "rpg.h"

static enemies_t *check_life(enemies_t *tmp, game_t *game)
{
    if (!tmp || !game)
        return NULL;
    if (tmp->life <= 0) {
        tmp->hidden = true;
        game->stats.stats_obj[1].nb_value += 25;
        game->stats.xp += 1;
    } else {
        tmp->life -= game->stats.stats_obj[2].nb_value;
    }
    return tmp;
}

static void check_rect_attack(game_t *game, enemies_t *tmp, sfFloatRect attack)
{
    sfFloatRect enemy = sfSprite_getGlobalBounds(tmp->sprite);
    sfFloatRect npc =
    sfSprite_getGlobalBounds(game->entities.npc[3]->sprite_npc);

    if (sfFloatRect_intersects(&enemy, &attack, NULL) == sfTrue &&
    game->fireball.hidden == false) {
        tmp = check_life(tmp, game);
        game->fireball.hidden = true;
    } else if (sfFloatRect_intersects(&npc, &attack, NULL) == sfTrue &&
    game->fireball.hidden == false) {
        game->fireball.hidden = true;
        game->stats.npc_kill = true;
        sfSprite_setPosition(game->entities.npc[3]->sprite_npc,
        (sfVector2f){0, 0});
        game->stats.stats_obj[0].nb_value += 10;
    }
}

int is_enemy_hit(game_t *game)
{
    enemies_t *tmp = NULL;
    sfFloatRect attack = {0};

    if (!game->entities.enemies.head || !game)
        return FAILURE;
    tmp = game->entities.enemies.head;
    attack = sfSprite_getGlobalBounds(game->fireball.fire);
    for (u_int i = 0; i < game->entities.enemies.size; i++) {
        check_rect_attack(game, tmp, attack);
        tmp = tmp->next;
    }
    return SUCCESS;
}
