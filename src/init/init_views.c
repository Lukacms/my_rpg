/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** init_views
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "rpg/game.h"
#include "rpg/macros.h"
#include "rpg/init.h"

int init_views(game_t *game)
{
    game->views.normal = sfView_create();
    game->views.ui = sfView_create();
    if (!game->views.normal)
        return FAILURE;
    if (!game->views.ui)
        return FAILURE;
    sfView_setSize(game->views.normal, (sfVector2f){1920, 1080});
    sfView_setSize(game->views.ui, (sfVector2f){1920, 1080});
    sfView_setCenter(game->views.normal, (sfVector2f){1920 / 2, 1080 / 2});
    sfView_setCenter(game->views.ui, (sfVector2f){1920 / 2, 1080 / 2});
    sfRenderWindow_setView(game->window.window, game->views.normal);
    return SUCCESS;
}
