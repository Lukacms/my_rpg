/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** analyse_characters_events
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include "rpg.h"

static void rectangle_move_satoshi_skater(game_t *game, sfMouseMoveEvent button)
{
    if (in_rectangle(game->characters.satoshi.satoshi, button.x,
    button.y, game->window.scaling) == true) {
        sfRectangleShape_setFillColor(game->characters.satoshi.satoshi,
        sfColor_fromRGBA(0, 0, 255, 100));
    }
    if (in_rectangle(game->characters.skater.skater, button.x,
    button.y, game->window.scaling) == true) {
        sfRectangleShape_setFillColor(game->characters.skater.skater,
        sfColor_fromRGBA(0, 0, 255, 100));
    }
    if (in_text(game->characters.back, button.x,
    button.y, game->window.scaling) == true) {
        sfText_setColor(game->characters.back, sfRed);
    }
}

static int rectangle_move(game_t *game,sfMouseMoveEvent button)
{
    if (in_rectangle(game->characters.blond.blond, button.x,
    button.y, game->window.scaling) == true) {
        sfRectangleShape_setFillColor(game->characters.blond.blond,
        sfColor_fromRGBA(0, 0, 255, 100));
    }
    if (in_rectangle(game->characters.girl.girl, button.x,
    button.y, game->window.scaling) == true) {
        sfRectangleShape_setFillColor(game->characters.girl.girl,
        sfColor_fromRGBA(0, 0, 255, 100));
    }
    rectangle_move_satoshi_skater(game, button);
    return SUCCESS;
}

static int color_choices(game_t *game, sfMouseMoveEvent button)
{
    sfRectangleShape_setFillColor(game->characters.skater.skater,
    sfColor_fromRGBA(0, 0, 0, 0));
    sfRectangleShape_setFillColor(game->characters.girl.girl,
    sfColor_fromRGBA(0, 0, 0, 0));
    sfRectangleShape_setFillColor(game->characters.blond.blond,
    sfColor_fromRGBA(0, 0, 0, 0));
    sfRectangleShape_setFillColor(game->characters.satoshi.satoshi,
    sfColor_fromRGBA(0, 0, 0, 0));
    sfText_setColor(game->characters.back, sfWhite);
    rectangle_move(game, button);
    return SUCCESS;
}

int analyse_characters_events(game_t *game, sfEvent event)
{
    if (!game)
        return FAILURE;
    if (event.type == sfEvtMouseButtonPressed) {
        play_sound_selected(game, 4);
        analyse_input_events_charact(game, event.mouseButton);
    } else if (event.type == sfEvtMouseMoved)
        color_choices(game, event.mouseMove);
    if (event.type == sfEvtMouseWheelScrolled) {
        if (game->characters.color_green_click == true)
            change_sprite_color_green(game, event.mouseWheelScroll);
        if (game->characters.color_red_click == true)
            change_sprite_color_red(game, event.mouseWheelScroll);
        if (game->characters.color_blue_click == true)
            change_sprite_color_blue(game, event.mouseWheelScroll);
    }
    return SUCCESS;
}
