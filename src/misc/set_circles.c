/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** set_circles
*/

#include "rpg.h"

static sfVector2f get_sprite_pos(enemies_t *enemy)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(enemy->sprite);
    sfVector2f pos = {0};

    pos.x = rect.left + (rect.width / 2);
    pos.y = rect.top + (rect.height / 2);
    return pos;
}

void set_circles(game_t *game)
{
    enemies_t *tmp = game->entities.enemies.head;
    sfVector2f pos = {0};

    for (unsigned int i = 0; i < game->entities.enemies.size; i += 1) {
        pos = get_sprite_pos(tmp);
        if (tmp->type == MODEL)
            sfCircleShape_setPosition(tmp->vision,
                                    (sfVector2f){pos.x - 300, pos.y - 300});
        else
                sfCircleShape_setPosition(tmp->vision,
                                    (sfVector2f){pos.x - 100, pos.y - 100});
        tmp = tmp->next;
    }
    return;
}
