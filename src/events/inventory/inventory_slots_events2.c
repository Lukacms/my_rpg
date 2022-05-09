/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** inventory_slots_events2
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include "rpg.h"

static const char slot1[] =
                "Plank of wood, try to use it somewhere";
static const char slot2[] =
                "Key, maybe you can open a door";
static const char slot4[] =
                "Find its head to complete the item";

int change_status_inv(game_t *game, int value)
{
    if (game == NULL)
        return FAILURE;
    game->inventory.slot[value]->clicked = true;
    sfRectangleShape_setFillColor(game->inventory.slot[value]->rectangle,
    sfColor_fromRGBA(50, 50, 200, 205));
    for (int index = 2; index < 10; index += 1) {
        if (value == index) {
            continue;
        }
        sfText_setString(game->inventory.slot[index]->text, "");
        game->inventory.slot[index]->clicked = false;
        sfRectangleShape_setFillColor(game->inventory.slot[index]->rectangle,
        sfColor_fromRGBA(0, 0, 0, 0));
    }
    return SUCCESS;
}

int set_text_for_item(char const *str, sfText *text,
sfColor color)
{
    sfText_setString(text, str);
    sfText_setColor(text, color);
    sfText_setCharacterSize(text, 50);
    return SUCCESS;
}

int check_slot1(game_t *game, sfMouseButtonEvent button)
{
    if (!game)
        return FAILURE;
    if (in_rectangle(game->inventory.slot[2]->rectangle, button.x,
    button.y, game->window.scaling) == true) {
        change_status_inv(game, 2);
        set_text_for_item(slot1,
        game->inventory.slot[2]->text, sfRed);
    }
    return SUCCESS;
}

int check_slot2(game_t *game, sfMouseButtonEvent button)
{
    if (!game)
        return FAILURE;
    if (in_rectangle(game->inventory.slot[3]->rectangle, button.x,
    button.y, game->window.scaling) == true) {
        change_status_inv(game, 3);
        set_text_for_item(slot2, game->inventory.slot[3]->text, sfRed);
    }
    return SUCCESS;
}

int check_slot3(game_t *game, sfMouseButtonEvent button)
{
    if (!game)
        return FAILURE;
    if (in_rectangle(game->inventory.slot[4]->rectangle, button.x,
    button.y, game->window.scaling) == true) {
        change_status_inv(game, 4);
        set_text_for_item(slot4, game->inventory.slot[4]->text, sfRed);
    }
    return SUCCESS;
}
