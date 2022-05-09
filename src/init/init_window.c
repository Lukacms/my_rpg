/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Espace de travail)
** File description:
** init_window
*/

#include <SFML/Graphics.h>
#include "rpg/game.h"
#include "rpg/macros.h"
#include "rpg/init.h"

int init_window(game_t *game)
{
    sfVideoMode mode = {1920, 1080, 32};
    char const *title = "Corpse Party : The Escape Game";

    game->window.window = sfRenderWindow_create(mode, title,
    sfResize | sfClose, NULL);
    if (!game->window.window)
        return FAILURE;
    sfRenderWindow_setFramerateLimit(game->window.window, 60);
    game->window.game_clock = sfClock_create();
    if (!game->window.game_clock)
        return FAILURE;
    game->status = MENU;
    game->window.scaling = (sfVector2f){1, 1};
    game->window.wdw_size = (sfVector2u){1920, 1080};
    game->window.screen = false;
    return SUCCESS;
}

int init_window_full_screen(game_t *game)
{
    sfVideoMode mode = {1920, 1080, 32};
    char const *title = "Corpse Party : The Escape Game";

    game->window.window = sfRenderWindow_create(mode, title,
    sfFullscreen, NULL);
    if (!game->window.window)
        return FAILURE;
    sfRenderWindow_setFramerateLimit(game->window.window, 60);
    game->window.game_clock = sfClock_create();
    if (!game->window.game_clock)
        return FAILURE;
    game->window.scaling = (sfVector2f){1, 1};
    game->window.wdw_size = (sfVector2u){1920, 1080};
    game->window.screen = true;
    sfRectangleShape_setFillColor(game->settings_menu.graphics.
    button1[0]->rectangle, sfGreen);
    sfRectangleShape_setFillColor(game->settings_menu.
    graphics.button1[1]->rectangle, sfRed);
    return SUCCESS;
}

int init_window_not_full_screen(game_t *game)
{
    sfVideoMode mode = {1920, 1080, 32};
    char const *title = "Corpse Party : The Escape Game";

    game->window.window = sfRenderWindow_create(mode, title,
    sfResize | sfClose, NULL);
    if (!game->window.window)
        return FAILURE;
    sfRenderWindow_setFramerateLimit(game->window.window, 60);
    game->window.game_clock = sfClock_create();
    if (!game->window.game_clock)
        return FAILURE;
    game->window.scaling = (sfVector2f){1, 1};
    game->window.wdw_size = (sfVector2u){1920, 1080};
    game->window.screen = false;
    sfRectangleShape_setFillColor(game->settings_menu.
    graphics.button1[0]->rectangle, sfGreen);
    sfRectangleShape_setFillColor(game->settings_menu.graphics.
    button1[1]->rectangle, sfRed);
    return SUCCESS;
}
