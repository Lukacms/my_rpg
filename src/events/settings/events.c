/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** settings_events
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include "rpg.h"

static void clicked_audio_controls(game_t *game, sfMouseButtonEvent button)
{
    if (in_rectangle(game->settings_menu.audio.rectangle, button.x,
    button.y, game->window.scaling) == true) {
        game->mode = AUDIO;
        game->settings_menu.audio.clicked = true;
        game->settings_menu.graphics.clicked = false;
        game->settings_menu.controls.clicked = false;
        sfRectangleShape_setFillColor(game->settings_menu.audio.rectangle,
        sfColor_fromRGBA(0, 0, 255, 100));
    }
    if (in_rectangle(game->settings_menu.controls.rectangle, button.x,
    button.y, game->window.scaling) == true) {
        game->mode = CONTROLS;
        game->settings_menu.controls.clicked = true;
        game->settings_menu.graphics.clicked = false;
        game->settings_menu.audio.clicked = false;
        sfRectangleShape_setFillColor(game->settings_menu.controls.rectangle,
        sfColor_fromRGBA(0, 0, 255, 100));
    }
}

static void check_back(game_t *game, sfMouseButtonEvent button)
{
    if (in_rectangle(game->settings_menu.back, button.x, button.y,
    game->window.scaling) == true) {
        game->mode = NONE;
        game->status = PAUSE;
        game->settings_menu.graphics.clicked = false;
        game->settings_menu.controls.clicked = false;
        game->settings_menu.audio.clicked = false;
        sfRectangleShape_setFillColor(game->settings_menu.back,
        sfColor_fromRGBA(0, 0, 255, 100));
    }
}

static int analyse_settings(game_t *game, sfMouseButtonEvent button)
{
    clicked_audio_controls(game, button);
    if (in_rectangle(game->settings_menu.graphics.rectangle, button.x,
    button.y, game->window.scaling) == true) {
        game->mode = GRAPHICS;
        game->settings_menu.graphics.clicked = true;
        game->settings_menu.controls.clicked = false;
        game->settings_menu.audio.clicked = false;
        sfRectangleShape_setFillColor(game->settings_menu.graphics.rectangle,
        sfColor_fromRGBA(0, 0, 255, 100));
    }
    check_back(game, button);
    return SUCCESS;
}

int analyse_settings_events(game_t *game, sfEvent event)
{
    if (!game)
        return FAILURE;
    if (event.type == sfEvtMouseButtonPressed) {
        play_sound_selected(game, 4);
        analyse_settings(game, event.mouseButton);
    } else if (event.type == sfEvtMouseMoved)
        color_choices_settings(game, event.mouseMove);
    if (game->settings_menu.audio.clicked == true ||
    game->settings_menu.graphics.clicked == true ||
    game->settings_menu.controls.clicked == true) {
        analyse_events_mode(game, event);
    }
    return SUCCESS;
}
