/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** inventory_slots_events
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include "rpg.h"

static const char slot3[] =
                "Oh... what is that ? Find the last part";
static const char slot5[] =
                "Use for healing yourself";
static const char slot6[] =
                "Now you can use magic spell";
static const char slot7[] =
                "Using pills for reduce your madness, above 100 you will die";
static const char slot8[] =
                "Now you can use the puppet";

int check_slot4(game_t *game, sfMouseButtonEvent button)
{
    if (game == NULL)
        return FAILURE;
    if (in_rectangle(game->inventory.slot[5]->rectangle, button.x,
    button.y, game->window.scaling) == true) {
        change_status_inv(game, 5);
        set_text_for_item(slot3, game->inventory.slot[5]->text, sfRed);
    }
    return SUCCESS;
}

int check_slot5(game_t *game, sfMouseButtonEvent button)
{
    if (game == NULL)
        return FAILURE;
    if (in_rectangle(game->inventory.slot[6]->rectangle, button.x,
    button.y, game->window.scaling) == true) {
        change_status_inv(game, 6);
        set_text_for_item(slot5, game->inventory.slot[6]->text, sfRed);
    }
    return SUCCESS;
}

int check_slot6(game_t *game, sfMouseButtonEvent button)
{
    if (game == NULL)
        return FAILURE;
    if (in_rectangle(game->inventory.slot[7]->rectangle, button.x,
    button.y, game->window.scaling) == true) {
        change_status_inv(game, 7);
        set_text_for_item(slot6, game->inventory.slot[7]->text, sfRed);
    }
    return SUCCESS;
}

int check_slot7(game_t *game, sfMouseButtonEvent button)
{
    if (game == NULL)
        return FAILURE;
    if (in_rectangle(game->inventory.slot[8]->rectangle, button.x,
    button.y, game->window.scaling) == true) {
        change_status_inv(game, 8);
        set_text_for_item(slot7, game->inventory.slot[8]->text, sfRed);
    }
    return SUCCESS;
}

int check_slot8(game_t *game, sfMouseButtonEvent button)
{
    if (game == NULL)
        return FAILURE;
    if (in_rectangle(game->inventory.slot[9]->rectangle, button.x,
    button.y, game->window.scaling) == true) {
        change_status_inv(game, 9);
        set_text_for_item(slot8, game->inventory.slot[9]->text, sfRed);
    }
    return SUCCESS;
}
