/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** display_blond
*/

#include "rpg.h"

int display_blond(game_t *game, sfIntRect *rect_blond)
{
    if (!game || !rect_blond)
        return FAILURE;
    if (game->characters.blond.clicked_blond == true) {
        sfSprite_setTextureRect(game->characters.skin, (*rect_blond));
        animate_characters(game, rect_blond, 192);
        sfRenderWindow_drawText(game->window.window,
        game->characters.blond.text_blond, NULL);
        sfRenderWindow_drawSprite(game->window.window,
        game->characters.skin, NULL);
    }
    return SUCCESS;
}
