/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** open_door
*/

#include "rpg.h"

void open_door(game_t *game)
{
    sfIntRect rect = {0};
    sfVector2f pos = sfSprite_getPosition(game->entities.mc.sprite);
    sfFloatRect sprite_rect =
                    sfSprite_getGlobalBounds(game->entities.mc.sprite);
    int x = 0;
    int y = 0;

    rect.top = ((sprite_rect.height - ((sprite_rect.height / 3) * 2)) + pos.y);
    rect.left = pos.x;
    rect.width = sprite_rect.width;
    rect.height = sprite_rect.height / 3;
    x = (rect.left + 10) / 48 - (1920 / 3 / 48);
    y = rect.top / 48 - (1080 / 3 / 48);
    game->maps->map[y][x] = '+';
    game->maps->map[y - 1][x] = '@';
    return;
}
