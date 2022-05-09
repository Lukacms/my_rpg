/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** inventory_events
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include "rpg.h"

static int analyse_slots(game_t *game, sfMouseButtonEvent button)
{
    if (in_rectangle(game->inventory.slot[0]->rectangle, button.x,
    button.y, game->window.scaling) == true) {
        game->inventory.slot[0]->clicked = true;
        game->status = GAME;
    }
    if (in_rectangle(game->inventory.slot[1]->rectangle, button.x,
    button.y, game->window.scaling) == true) {
        game->inventory.slot[1]->clicked = true;
        game->status = PAUSE;
    }
    check_slot1(game, button);
    check_slot2(game, button);
    check_slot3(game, button);
    check_slot4(game, button);
    check_slot5(game, button);
    check_slot6(game, button);
    check_slot7(game, button);
    check_slot8(game, button);
    return SUCCESS;
}

static int click_madness(game_t *game)
{
    if (!game)
        return FAILURE;
    if (game->inventory.slot[8]->clicked == true &&
    (game->stats.stats_obj[1].nb_value - 5) >= 0) {
        game->inventory.madness_potion = false;
        game->stats.stats_obj[1].nb_value -= 5;
    } else if (game->inventory.slot[8]->clicked == true &&
    (game->stats.stats_obj[1].nb_value - 5) > -5) {
        game->inventory.madness_potion = false;
        game->stats.stats_obj[1].nb_value = 0;
    }
    return SUCCESS;
}

static int click_heal_bottle(game_t *game)
{
    if (!game)
        return FAILURE;
    if (game->inventory.slot[6]->clicked == true &&
        (game->stats.stats_obj[0].nb_value + 50) <= 150) {
        game->inventory.heal_bottle = false;
        game->stats.stats_obj[0].nb_value += 50;
    } else if (game->inventory.slot[6]->clicked == true &&
        (game->stats.stats_obj[0].nb_value + 50) < 200) {
        game->inventory.heal_bottle = false;
        game->stats.stats_obj[0].nb_value = 150;
    }
    return SUCCESS;
}

static int click_puppet(game_t *game)
{
    if (!game)
        return FAILURE;
    return SUCCESS;
}

static int analyse_click(game_t *game, sfMouseButtonEvent button)
{
    if (game == NULL)
        return FAILURE;
    if (in_text(game->inventory.text_click, button.x, button.y,
    game->window.scaling) == true) {
        click_madness(game);
        click_heal_bottle(game);
        click_puppet(game);
    }
    if (in_text(game->inventory.text_fusion, button.x, button.y,
    game->window.scaling) && game->inventory.body_puppet == true &&
    game->inventory.head_puppet == true) {
        game->inventory.full_puppet = true;
        game->stats.stats_obj[2].nb_value += 1;
        game->inventory.body_puppet = false;
        game->inventory.head_puppet = false;
    }
    return SUCCESS;
}

static int color_choices(game_t *game, sfMouseMoveEvent button)
{
    if (!game)
        return FAILURE;
    sfText_setColor(game->inventory.text_click, sfWhite);
    sfText_setColor(game->inventory.text_fusion, sfWhite);
    if (in_text(game->inventory.text_click, button.x, button.y,
    game->window.scaling) == true)
        sfText_setColor(game->inventory.text_click, sfRed);
    if (in_text(game->inventory.text_fusion, button.x, button.y,
    game->window.scaling) == true)
        sfText_setColor(game->inventory.text_fusion, sfRed);
    return SUCCESS;
}

int analyse_inventory_events(game_t *game, sfEvent event)
{
    if (!game)
        return FAILURE;
    if (event.type == sfEvtMouseButtonPressed) {
        play_sound_selected(game, 4);
        analyse_slots(game, event.mouseButton);
        analyse_click(game, event.mouseButton);
    } else if (event.type == sfEvtMouseMoved) {
        color_choices(game, event.mouseMove);
    }
    return SUCCESS;
}
