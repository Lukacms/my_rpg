/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** display_characters
*/

#include "rpg.h"

int animate_characters(game_t *game, sfIntRect *rect, int top)
{
    sfTime time = {0};

    if (!game || !rect)
        return FAILURE;
    time = sfClock_getElapsedTime(game->characters.clock);
    if (sfTime_asSeconds(time) > 0.8) {
        (*rect).top += 48;
        sfClock_restart(game->characters.clock);
    }
    if ((*rect).top >= top + (4 * 48))
        (*rect).top = top;
    sfSprite_setTextureRect(game->characters.skin, (*rect));
    return SUCCESS;
}

static int display_shape(game_t *game)
{
    if (!game)
        return FAILURE;
    sfRenderWindow_drawSprite(game->window.window, game->characters.sprite,
    NULL);
    sfRenderWindow_drawRectangleShape(game->window.window,
    game->characters.blond.blond, NULL);
    sfRenderWindow_drawRectangleShape(game->window.window,
    game->characters.girl.girl, NULL);
    sfRenderWindow_drawRectangleShape(game->window.window,
    game->characters.skater.skater, NULL);
    sfRenderWindow_drawRectangleShape(game->window.window,
    game->characters.satoshi.satoshi, NULL);
    sfRenderWindow_drawRectangleShape(game->window.window,
    game->characters.color_red, NULL);
    sfRenderWindow_drawRectangleShape(game->window.window,
    game->characters.color_blue, NULL);
    sfRenderWindow_drawRectangleShape(game->window.window,
    game->characters.color_green, NULL);
    return SUCCESS;
}

int display_characters(game_t *game)
{
    if (!game)
        return FAILURE;
    display_shape(game);
    sfRenderWindow_drawText(game->window.window, game->characters.back,NULL);
    display_skater(game, &game->characters.skater.rect);
    display_satoshi(game, &game->characters.satoshi.rect);
    display_girl(game, &game->characters.girl.rect);
    display_blond(game, &game->characters.blond.rect);
    return SUCCESS;
}
