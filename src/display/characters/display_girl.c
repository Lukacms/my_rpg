/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** display_girl
*/

#include "rpg.h"

int display_girl(game_t *game, sfIntRect *rect_girl)
{
    if (!game || !rect_girl)
        return FAILURE;
    if (game->characters.girl.clicked_girl == true) {
        sfSprite_setTextureRect(game->characters.skin, (*rect_girl));
        animate_characters(game, rect_girl, 384);
        sfRenderWindow_drawRectangleShape(game->window.window,
        game->characters.girl.girl, NULL);
        sfRenderWindow_drawText(game->window.window,
        game->characters.girl.text_girl, NULL);
        sfRenderWindow_drawSprite(game->window.window,
        game->characters.skin, NULL);
    }
    return SUCCESS;
}
