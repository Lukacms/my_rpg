/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** get_position_in_map
*/

#include "my.h"
#include "rpg.h"

int get_pos_in_map_up(sfSprite *sprite, game_t *game)
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
    return game->maps->map[y][x];
}

int get_pos_in_map_down(sfSprite *sprite, game_t *game)
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
    return game->maps->map[y][x];
}

int get_pos_in_map_left(sfSprite *sprite, game_t *game)
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
    return game->maps->map[y][x];
}

int get_pos_in_map_right(sfSprite *sprite, game_t *game)
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
    return game->maps->map[y][x];
}
