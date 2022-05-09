/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** display_satoshi
*/

#include "rpg.h"

int display_satoshi(game_t *game, sfIntRect *rect_satoshi)
{
    if (!game || !rect_satoshi)
        return FAILURE;
    if (game->characters.satoshi.clicked_satoshi == true) {
        sfSprite_setTextureRect(game->characters.skin, (*rect_satoshi));
        animate_characters(game, rect_satoshi, 0);
        sfRenderWindow_drawRectangleShape(game->window.window,
        game->characters.satoshi.satoshi, NULL);
        sfRenderWindow_drawText(game->window.window,
        game->characters.satoshi.text_satoshi, NULL);
        sfRenderWindow_drawSprite(game->window.window,
        game->characters.skin, NULL);
    }
    return SUCCESS;
}
