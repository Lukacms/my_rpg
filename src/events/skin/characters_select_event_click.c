/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** characters_select_event_click
*/

#include "rpg.h"

static void rectangle_blond_girl(game_t *game , sfMouseButtonEvent button)
{
    if (in_rectangle(game->characters.blond.blond, button.x,
    button.y, game->window.scaling) == true) {
        game->characters.blond.clicked_blond = true;
        game->characters.girl.clicked_girl = false;
        game->characters.satoshi.clicked_satoshi = false;
        game->characters.skater.clicked_skater = false;
        game->entities.mc.type = BLOND;
        sfSprite_setTextureRect(game->entities.mc.sprite,
        (sfIntRect){0, 192, 24, 48});
    }
    if (in_rectangle(game->characters.girl.girl, button.x,
    button.y, game->window.scaling) == true) {
        game->characters.girl.clicked_girl = true;
        game->characters.blond.clicked_blond = false;
        game->characters.satoshi.clicked_satoshi = false;
        game->characters.skater.clicked_skater = false;
        game->entities.mc.type = GIRL;
        sfSprite_setTextureRect(game->entities.mc.sprite,
        (sfIntRect){0, 384, 24, 48});
    }
}

static void rectangle_satoshi_skater(game_t *game, sfMouseButtonEvent button)
{
    if (in_rectangle(game->characters.satoshi.satoshi, button.x,
    button.y, game->window.scaling) == true) {
        game->characters.blond.clicked_blond = false;
        game->characters.girl.clicked_girl = false;
        game->characters.satoshi.clicked_satoshi = true;
        game->characters.skater.clicked_skater = false;
        game->entities.mc.type = MC;
        sfSprite_setTextureRect(game->entities.mc.sprite,
        (sfIntRect){0, 0, 24, 48});
    }
    if (in_rectangle(game->characters.skater.skater, button.x,
    button.y, game->window.scaling) == true) {
        game->characters.blond.clicked_blond = false;
        game->characters.girl.clicked_girl = false;
        game->characters.satoshi.clicked_satoshi = false;
        game->characters.skater.clicked_skater = true;
        game->entities.mc.type = SKATER;
        sfSprite_setTextureRect(game->entities.mc.sprite,
        (sfIntRect){0, 576, 24, 48});
    }
}

static int rectangle_color(game_t *game , sfMouseButtonEvent button)
{
    if (in_rectangle(game->characters.color_red, button.x, button.y,
    game->window.scaling) == true) {
        game->characters.color_red_click = true;
        game->characters.color_blue_click = false;
        game->characters.color_green_click = false;
    }
    if (in_rectangle(game->characters.color_green, button.x, button.y,
    game->window.scaling) == true) {
        game->characters.color_green_click = true;
        game->characters.color_red_click = false;
        game->characters.color_blue_click = false;
    }
    if (in_rectangle(game->characters.color_blue, button.x, button.y,
    game->window.scaling) == true) {
        game->characters.color_green_click = false;
        game->characters.color_red_click = false;
        game->characters.color_blue_click = true;
    }
    return SUCCESS;
}

int analyse_input_events_charact(game_t *game, sfMouseButtonEvent button)
{
    rectangle_color(game, button);
    rectangle_blond_girl(game, button);
    rectangle_satoshi_skater(game, button);
    if (in_text(game->characters.back, button.x,
    button.y, game->window.scaling) == true) {
        game->status = PAUSE;
    }
    return SUCCESS;
}
