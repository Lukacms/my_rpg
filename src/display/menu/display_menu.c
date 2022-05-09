/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** display_menu
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg.h"

int display_menu(game_t *game)
{
    if (!game)
        return FAILURE;
    sfRenderWindow_setView(game->window.window, game->views.ui);
    sfRenderWindow_drawSprite(game->window.window, game->start_menu.bg, NULL);
    sfRenderWindow_drawSprite(game->window.window, game->start_menu.logo, NULL);
    sfRenderWindow_drawText(game->window.window, game->start_menu.menu_continue,
    NULL);
    sfRenderWindow_drawText(game->window.window, game->start_menu.menu_ng,
    NULL);
    sfRenderWindow_drawText(game->window.window, game->start_menu.menu_quit,
    NULL);
    draw_particules(&game->start_menu, game->window.window);
    return SUCCESS;
}
