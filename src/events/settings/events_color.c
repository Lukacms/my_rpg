/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** settings_events_color
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include "rpg.h"

static void make_color(game_t *game)
{
    sfRectangleShape_setFillColor(game->settings_menu.audio.rectangle,
    sfColor_fromRGBA(0, 0, 0, 0));
    sfRectangleShape_setFillColor(game->settings_menu.controls.rectangle,
    sfColor_fromRGBA(0, 0, 0, 0));
    sfRectangleShape_setFillColor(game->settings_menu.graphics.rectangle,
    sfColor_fromRGBA(0, 0, 0, 0));
    sfRectangleShape_setFillColor(game->settings_menu.back,
    sfColor_fromRGBA(0, 0, 0, 0));
}

static void check_moove_rectangle(game_t *game, sfMouseMoveEvent button)
{
    if (in_rectangle(game->settings_menu.back, button.x, button.y,
    game->window.scaling) == true)
        sfRectangleShape_setFillColor(game->settings_menu.back,
        sfColor_fromRGBA(0, 0, 200, 155));
}

int color_choices_settings(game_t *game, sfMouseMoveEvent button)
{
    make_color(game);
    if (in_rectangle(game->settings_menu.audio.rectangle,
    button.x, button.y, game->window.scaling) == true)
        sfRectangleShape_setFillColor(game->settings_menu.audio.rectangle,
        sfColor_fromRGBA(0, 0, 200, 155));
    if (in_rectangle(game->settings_menu.controls.rectangle,
    button.x, button.y, game->window.scaling) == true)
        sfRectangleShape_setFillColor(game->settings_menu.controls.rectangle,
        sfColor_fromRGBA(0, 0, 200, 155));
    if (in_rectangle(game->settings_menu.graphics.rectangle,
    button.x, button.y, game->window.scaling) == true)
        sfRectangleShape_setFillColor(game->settings_menu.graphics.rectangle,
        sfColor_fromRGBA(0, 0, 200, 155));
    check_moove_rectangle(game, button);
    return SUCCESS;
}
