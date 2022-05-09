/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** change_color_sprite
*/

#include "rpg.h"

static void set_color(game_t *game, sfSprite *sprite_skin, sfSprite *sprite_mc)
{
    sfSprite_setColor(sprite_skin,
    sfColor_fromRGB(game->characters.red, game->characters.green,
    game->characters.blue));
    sfSprite_setColor(sprite_mc,
    sfColor_fromRGB(game->characters.red, game->characters.green,
    game->characters.blue));
}

int change_sprite_color_red(game_t *game, sfMouseWheelScrollEvent button)
{
    sfVector2f size = sfRectangleShape_getSize(game->characters.color_red);

    if (button.delta == 1.0f && size.x < 255 && game->characters.red < 255) {
        sfRectangleShape_setSize(game->characters.color_red,
        (sfVector2f){size.x + 10, size.y});
        game->characters.red += 10;
        button.delta = 0;
    } else if (button.delta == -1.0f && size.x > 10 &&
    game->characters.red > 0) {
        sfRectangleShape_setSize(game->characters.color_red,
        (sfVector2f){size.x - 10, size.y});
        game->characters.red -= 10;
        button.delta = 0;
    }
    set_color(game, game->characters.skin, game->entities.mc.sprite);
    return SUCCESS;
}

int change_sprite_color_green(game_t *game, sfMouseWheelScrollEvent button)
{
    sfVector2f size = sfRectangleShape_getSize(game->characters.color_green);

    if (button.delta == 1.0f && size.x < 255 && game->characters.green < 255) {
        sfRectangleShape_setSize(game->characters.color_green,
        (sfVector2f){size.x + 10, size.y});
        game->characters.green += 10;
        button.delta = 0;
    } else if (button.delta == -1.0f && size.x > 10 &&
    game->characters.green > 0) {
        sfRectangleShape_setSize(game->characters.color_green,
        (sfVector2f){size.x - 10, size.y});
        game->characters.green -= 10;
        button.delta = 0;
    }
    set_color(game, game->characters.skin, game->entities.mc.sprite);
    return SUCCESS;
}

int change_sprite_color_blue(game_t *game, sfMouseWheelScrollEvent button)
{
    sfVector2f size = sfRectangleShape_getSize(game->characters.color_blue);

    if (button.delta == 1.0f && size.x < 255 && game->characters.blue < 255) {
        sfRectangleShape_setSize(game->characters.color_blue,
        (sfVector2f){size.x + 10, size.y});
        game->characters.blue += 10;
        button.delta = 0;
    } else if (button.delta == -1.0f && size.x > 10 &&
    game->characters.blue > 0) {
        sfRectangleShape_setSize(game->characters.color_blue,
        (sfVector2f){size.x - 10, size.y});
        game->characters.blue -= 10;
        button.delta = 0;
    }
    set_color(game, game->characters.skin, game->entities.mc.sprite);
    return SUCCESS;
}
