/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** display_gui
*/

#include <SFML/Graphics.h>
#include "rpg.h"

int display_gui(game_t *game)
{
    if (!game)
        return FAILURE;
    sfRenderWindow_setView(game->window.window, game->views.ui);
    sfRenderWindow_drawSprite(game->window.window, game->gui.icon, NULL);
    sfRenderWindow_drawRectangleShape(game->window.window, game->gui.bar, NULL);
    sfRenderWindow_drawRectangleShape(game->window.window, game->gui.health,
    NULL);
    sfRenderWindow_setView(game->window.window, game->views.normal);
    return SUCCESS;
}
