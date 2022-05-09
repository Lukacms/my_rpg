/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Espace de travail)
** File description:
** calculate_foot_hitbox
*/

#include "my.h"
#include "rpg.h"

int hitbox_up(sfSprite *sprite, game_t *game, int code)
{
    sfIntRect rect = {0};
    sfVector2f pos = sfSprite_getPosition(sprite);
    sfFloatRect sprite_rect = sfSprite_getGlobalBounds(sprite);
    int x = 0;
    int y = 0;

    rect.top = ((sprite_rect.height - ((sprite_rect.height / 3) * 2)) + pos.y);
    rect.left = pos.x;
    rect.width = sprite_rect.width;
    rect.height = sprite_rect.height / 3;
    x = (rect.left + 10) / 48 - (1920 / 3 / 48);
    y = rect.top / 48 - (1080 / 3 / 48);
    if (is_move_valid(game, (sfVector2i){x, y}, code,
    (game->status == GAME) ? game->maps->map : game->htp.map) == SUCCESS) {
        x = ((rect.left + rect.width) - 20) / 48 - (1920 / 3 / 48);
        return is_move_valid(game, (sfVector2i){x, y}, code,
        (game->status == GAME) ? game->maps->map : game->htp.map);
    }
    return FAILURE;
}

int hitbox_down(sfSprite *sprite, game_t *game, int code)
{
    sfIntRect rect = {0};
    sfVector2f pos = sfSprite_getPosition(sprite);
    sfFloatRect sprite_rect = sfSprite_getGlobalBounds(sprite);
    int x = 0;
    int y = 0;

    rect.top = (sprite_rect.height - 15) + pos.y;
    rect.left = pos.x;
    rect.width = sprite_rect.width;
    rect.height = sprite_rect.height / 3;
    x = (rect.left + 10) / 48 - (1920 / 3 / 48);
    y = rect.top / 48 - (1080 / 3 / 48);
    if (is_move_valid(game, (sfVector2i){x, y}, code,
    (game->status == GAME) ? game->maps->map : game->htp.map) == SUCCESS) {
        x = ((rect.left + rect.width) - 20) / 48 - (1920 / 3 / 48);
        return is_move_valid(game, (sfVector2i){x, y}, code,
        (game->status == GAME) ? game->maps->map : game->htp.map);
    }
    return FAILURE;
}

int hitbox_left(sfSprite *sprite, game_t *game, int code)
{
    sfIntRect rect = {0};
    sfVector2f pos = sfSprite_getPosition(sprite);
    sfFloatRect sprite_rect = sfSprite_getGlobalBounds(sprite);
    int x = 0;
    int y = 0;

    rect.top = ((sprite_rect.height - ((sprite_rect.height / 3) * 2))
                + pos.y + 15);
    rect.left = pos.x - 15;
    rect.width = sprite_rect.width;
    rect.height = sprite_rect.height / 3;
    x = rect.left / 48 - (1920 / 3 / 48);
    y = rect.top / 48 - (1080 / 3 / 48);
    if (is_move_valid(game, (sfVector2i){x, y}, code,
    (game->status == GAME) ? game->maps->map : game->htp.map) == SUCCESS) {
        y = (rect.top + rect.height - 10) / 48 - (1080 / 3 / 48);
        return is_move_valid(game, (sfVector2i){x, y}, code,
        (game->status == GAME) ? game->maps->map : game->htp.map);
    }
    return FAILURE;
}

int hitbox_right(sfSprite *sprite, game_t *game, int code)
{
    sfIntRect rect = {0};
    sfVector2f pos = sfSprite_getPosition(sprite);
    sfFloatRect sprite_rect = sfSprite_getGlobalBounds(sprite);
    int x = 0;
    int y = 0;

    rect.top = ((sprite_rect.height - ((sprite_rect.height / 3) * 2))
                + pos.y + 15);
    rect.left = (pos.x + sprite_rect.width) - 15;
    rect.width = sprite_rect.width;
    rect.height = sprite_rect.height / 3;
    x = rect.left / 48 - (1920 / 3 / 48);
    y = rect.top / 48 - (1080 / 3 / 48);
    if (is_move_valid(game, (sfVector2i){x, y}, code,
    (game->status == GAME) ? game->maps->map : game->htp.map) == SUCCESS) {
        y = (rect.top + rect.height - 10) / 48 - (1080 / 3 / 48);
        return is_move_valid(game, (sfVector2i){x, y}, code,
        (game->status == GAME) ? game->maps->map : game->htp.map);
    }
    return FAILURE;
}
