/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** display_slot
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg.h"

static int display_slots23(game_t *game)
{
    if (!game)
        return FAILURE;
    if (game->inventory.wooden_plank == true) {
        sfRenderWindow_drawRectangleShape(game->window.window,
        game->inventory.slot[2]->rectangle, NULL);
        sfRenderWindow_drawSprite(game->window.window,
        game->inventory.slot[2]->sprite, NULL);
        sfRenderWindow_drawText(game->window.window,
        game->inventory.slot[2]->text, NULL);
    }
    if (game->inventory.key == true) {
        sfRenderWindow_drawRectangleShape(game->window.window,
        game->inventory.slot[3]->rectangle, NULL);
        sfRenderWindow_drawSprite(game->window.window,
        game->inventory.slot[3]->sprite, NULL);
        sfRenderWindow_drawText(game->window.window,
        game->inventory.slot[3]->text, NULL);
    }
    return SUCCESS;
}

static int display_slots45(game_t *game)
{
    if (!game)
        return FAILURE;
    if (game->inventory.body_puppet == true) {
        sfRenderWindow_drawRectangleShape(game->window.window,
        game->inventory.slot[4]->rectangle, NULL);
        sfRenderWindow_drawSprite(game->window.window,
        game->inventory.slot[4]->sprite, NULL);
        sfRenderWindow_drawText(game->window.window,
        game->inventory.slot[4]->text, NULL);
    }
    if (game->inventory.head_puppet == true) {
        sfRenderWindow_drawRectangleShape(game->window.window,
        game->inventory.slot[5]->rectangle, NULL);
        sfRenderWindow_drawSprite(game->window.window,
        game->inventory.slot[5]->sprite, NULL);
        sfRenderWindow_drawText(game->window.window,
        game->inventory.slot[5]->text, NULL);
    }
    return SUCCESS;
}

static int display_slots67(game_t *game)
{
    if (!game)
        return FAILURE;
    if (game->inventory.heal_bottle == true) {
        sfRenderWindow_drawRectangleShape(game->window.window,
        game->inventory.slot[6]->rectangle, NULL);
        sfRenderWindow_drawSprite(game->window.window,
        game->inventory.slot[6]->sprite, NULL);
        sfRenderWindow_drawText(game->window.window,
        game->inventory.slot[6]->text, NULL);
    }
    if (game->inventory.magic_attack == true) {
        sfRenderWindow_drawRectangleShape(game->window.window,
        game->inventory.slot[7]->rectangle, NULL);
        sfRenderWindow_drawSprite(game->window.window,
        game->inventory.slot[7]->sprite, NULL);
        sfRenderWindow_drawText(game->window.window,
        game->inventory.slot[7]->text, NULL);
    }
    return SUCCESS;
}

static int display_slots89(game_t *game)
{
    if (!game)
        return FAILURE;
    if (game->inventory.madness_potion == true) {
        sfRenderWindow_drawRectangleShape(game->window.window,
        game->inventory.slot[8]->rectangle, NULL);
        sfRenderWindow_drawSprite(game->window.window,
        game->inventory.slot[8]->sprite, NULL);
        sfRenderWindow_drawText(game->window.window,
        game->inventory.slot[8]->text, NULL);
    }
    if (game->inventory.full_puppet == true) {
        sfRenderWindow_drawRectangleShape(game->window.window,
        game->inventory.slot[9]->rectangle, NULL);
        sfRenderWindow_drawSprite(game->window.window,
        game->inventory.slot[9]->sprite, NULL);
        sfRenderWindow_drawText(game->window.window,
        game->inventory.slot[9]->text, NULL);
    }
    return SUCCESS;
}

int display_slots(game_t *game)
{
    if (!game)
        return FAILURE;
    if (game->inventory.slot[0]->clicked == true) {
        sfRenderWindow_drawRectangleShape(game->window.window,
        game->inventory.slot[0]->rectangle, NULL);
    }
    if (game->inventory.slot[1]->clicked == true) {
        sfRenderWindow_drawRectangleShape(game->window.window,
        game->inventory.slot[1]->rectangle, NULL);
    }
    display_slots23(game);
    display_slots45(game);
    display_slots67(game);
    display_slots89(game);
    return SUCCESS;
}
