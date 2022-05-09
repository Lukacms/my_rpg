/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** display_inventory
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg.h"

int display_inventory(game_t *game)
{
    if (!game)
        return FAILURE;
    sfRenderWindow_setView(game->window.window, game->views.ui);
    sfRenderWindow_drawSprite(game->window.window, game->inventory.sprite,
    NULL);
    display_slots(game);
    sfRenderWindow_drawText(game->window.window, game->inventory.text_click,
    NULL);
    if (game->inventory.body_puppet == true &&
    game->inventory.head_puppet == true)
        sfRenderWindow_drawText(game->window.window,
                                game->inventory.text_fusion, NULL);
    return SUCCESS;
}
