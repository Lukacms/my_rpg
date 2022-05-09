/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** settings_mode_graphics_events
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include "rpg.h"

static void check_clicked_fullscreen(game_t *game, sfMouseButtonEvent button)
{
    if (in_text(game->settings_menu.graphics.button1[5]->text, button.x,
    button.y, game->window.scaling) == true && game->window.screen != true) {
        sfRenderWindow_destroy(game->window.window);
        init_window_full_screen(game);
        sfRectangleShape_setFillColor(game->settings_menu.graphics.
        button1[5]->rectangle, sfColor_fromRGBA(0, 255, 0, 255));
        sfRectangleShape_setFillColor(game->settings_menu.graphics.
        button1[6]->rectangle, sfColor_fromRGBA(255, 0, 0, 255));
    }
    if (in_text(game->settings_menu.graphics.button1[6]->text, button.x,
    button.y, game->window.scaling) == true && game->window.screen == true) {
        sfRenderWindow_destroy(game->window.window);
        init_window_not_full_screen(game);
        sfRectangleShape_setFillColor(game->settings_menu.graphics.
        button1[6]->rectangle, sfColor_fromRGBA(0, 255, 0, 255));
        sfRectangleShape_setFillColor(game->settings_menu.graphics.
        button1[5]->rectangle, sfColor_fromRGBA(255, 0, 0, 255));
    }
}

void check_clicked_graphics_size(game_t *game, sfMouseButtonEvent button)
{
    if (in_text(game->settings_menu.graphics.button1[0]->text, button.x,
    button.y, game->window.scaling) == true && game->settings_menu.
    graphics.button1[0]->key_set != true && game->window.screen == true) {
        modify_size(game, (sfVector2u){1920, 1080},
        game->settings_menu.graphics.button1[0]->rectangle,
        game->settings_menu.graphics.button1[1]->rectangle);
        game->settings_menu.graphics.button1[1]->key_set = false;
        game->settings_menu.graphics.button1[0]->key_set = true;
    }
    if (in_text(game->settings_menu.graphics.button1[1]->text, button.x,
    button.y, game->window.scaling) == true && game->settings_menu.
    graphics.button1[1]->key_set != true && game->window.screen == true) {
        modify_size(game, (sfVector2u){800, 600},
        game->settings_menu.graphics.button1[1]->rectangle,
        game->settings_menu.graphics.button1[0]->rectangle);
        game->settings_menu.graphics.button1[0]->key_set = false;
        game->settings_menu.graphics.button1[1]->key_set = true;
    }
    check_clicked_fullscreen(game, button);
}

static void check_clicked_80fps(game_t *game, sfMouseButtonEvent button)
{
    if (in_text(game->settings_menu.graphics.button1[4]->text, button.x,
    button.y, game->window.scaling) == true) {
        change_fps(game, 180, game->settings_menu.graphics.
        button1[4]->rectangle);
        sfRectangleShape_setFillColor(game->settings_menu.graphics.
        button1[2]->rectangle, sfColor_fromRGBA(255, 0, 0, 255));
        sfRectangleShape_setFillColor(game->settings_menu.graphics.
        button1[3]->rectangle, sfColor_fromRGBA(255, 0, 0, 255));
    }
}

void check_clicked_graphics_fps(game_t *game, sfMouseButtonEvent button)
{
    if (in_text(game->settings_menu.graphics.button1[2]->text, button.x,
    button.y, game->window.scaling) == true) {
        change_fps(game, 60, game->settings_menu.graphics.
        button1[2]->rectangle);
        sfRectangleShape_setFillColor(game->settings_menu.graphics.
        button1[3]->rectangle, sfColor_fromRGBA(255, 0, 0, 255));
        sfRectangleShape_setFillColor(game->settings_menu.graphics.
        button1[4]->rectangle, sfColor_fromRGBA(255, 0, 0, 255));
    }
    if (in_text(game->settings_menu.graphics.button1[3]->text, button.x,
    button.y, game->window.scaling) == true) {
        change_fps(game, 120, game->settings_menu.
        graphics.button1[3]->rectangle);
        sfRectangleShape_setFillColor(game->settings_menu.graphics.
        button1[2]->rectangle, sfColor_fromRGBA(255, 0, 0, 255));
        sfRectangleShape_setFillColor(game->settings_menu.graphics.
        button1[4]->rectangle, sfColor_fromRGBA(255, 0, 0, 255));
    }
    check_clicked_80fps(game, button);
}
