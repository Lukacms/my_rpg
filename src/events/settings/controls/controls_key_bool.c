/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** settings_controls_key_bool
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include "rpg.h"

static void check_in_text_inv_skill(game_t *game, sfMouseButtonEvent button)
{
    if (in_text(game->settings_menu.controls.button1[7]->text, button.x,
    button.y, game->window.scaling) == true &&
    game->settings_menu.controls.button1[7]->key_set == false)
        game->settings_menu.controls.button1[7]->key_set = true;
    if (in_text(game->settings_menu.controls.button1[8]->text, button.x,
    button.y, game->window.scaling) == true &&
    game->settings_menu.controls.button1[8]->key_set == false)
        game->settings_menu.controls.button1[8]->key_set = true;
}

static void check_in_text(game_t *game, sfMouseButtonEvent button)
{
    if (in_text(game->settings_menu.controls.button1[3]->text, button.x,
    button.y, game->window.scaling) == true &&
    game->settings_menu.controls.button1[3]->key_set == false)
        game->settings_menu.controls.button1[3]->key_set = true;
    if (in_text(game->settings_menu.controls.button1[4]->text, button.x,
    button.y, game->window.scaling) == true &&
    game->settings_menu.controls.button1[4]->key_set == false)
        game->settings_menu.controls.button1[4]->key_set = true;
    if (in_text(game->settings_menu.controls.button1[5]->text, button.x,
    button.y, game->window.scaling) == true &&
    game->settings_menu.controls.button1[5]->key_set == false)
        game->settings_menu.controls.button1[5]->key_set = true;
    if (in_text(game->settings_menu.controls.button1[6]->text, button.x,
    button.y, game->window.scaling) == true &&
    game->settings_menu.controls.button1[6]->key_set == false)
        game->settings_menu.controls.button1[6]->key_set = true;
    check_in_text_inv_skill(game, button);
}

int analyse_key(game_t *game, sfMouseButtonEvent button)
{
    if (in_text(game->settings_menu.controls.button1[0]->text, button.x,
    button.y, game->window.scaling) == true &&
    game->settings_menu.controls.button1[0]->key_set == false)
        game->settings_menu.controls.button1[0]->key_set = true;
    if (in_text(game->settings_menu.controls.button1[1]->text, button.x,
    button.y, game->window.scaling) == true &&
    game->settings_menu.controls.button1[1]->key_set == false)
        game->settings_menu.controls.button1[1]->key_set = true;
    if (in_text(game->settings_menu.controls.button1[2]->text, button.x,
    button.y, game->window.scaling) == true &&
    game->settings_menu.controls.button1[2]->key_set == false)
        game->settings_menu.controls.button1[2]->key_set = true;
    check_in_text(game, button);
    return SUCCESS;
}
