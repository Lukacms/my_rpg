/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** is_chase
*/

#include "rpg.h"

void hitbox(game_t *game, sfFloatRect *mc_rect)
{
    if (!game)
        return;
    sfRectangleShape *rectangle = sfRectangleShape_create();

    sfRectangleShape_setSize(rectangle,
    (sfVector2f) {mc_rect->width, mc_rect->height});
    sfRectangleShape_setPosition(rectangle, (sfVector2f) {mc_rect->left,
    mc_rect->top});
    sfRectangleShape_setFillColor(rectangle, sfColor_fromRGBA(255, 0, 0, 100));
    sfRenderWindow_drawRectangleShape(game->window.window, rectangle, NULL);
}

bool is_chase(enemies_t *enemy, game_t *game)
{
    sfFloatRect mc_rect = get_true_rect_mc(game->entities.mc.sprite);
    sfFloatRect enemy_rect = sfCircleShape_getGlobalBounds(enemy->vision);

    mc_rect.top += 96;
    if (sfFloatRect_intersects(&mc_rect, &enemy_rect, NULL) == sfTrue)
        return true;
    return false;
}
