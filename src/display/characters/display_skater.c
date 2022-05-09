/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** check_clicked
*/

#include "rpg.h"

int display_skater(game_t *game, sfIntRect *rect_skater)
{
    if (!game || !rect_skater)
        return FAILURE;
    if (game->characters.skater.clicked_skater == true) {
        sfSprite_setTextureRect(game->characters.skin, (*rect_skater));
        animate_characters(game, rect_skater, 576);
        sfRenderWindow_drawRectangleShape(game->window.window,
        game->characters.skater.skater, NULL);
        sfRenderWindow_drawText(game->window.window,
        game->characters.skater.text_skater, NULL);
        sfRenderWindow_drawSprite(game->window.window,
        game->characters.skin, NULL);
    }
    return SUCCESS;
}
