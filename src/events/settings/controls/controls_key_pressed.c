/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** settings_events_key_pressed
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include "rpg.h"

static void check_button_skill_inv(game_t *game, sfEvent event)
{
    int status = 0;

    if (game->settings_menu.controls.button1[6]->key_set == true) {
        if ((status = change_key(event.key.code, &game->key)) != -1)
            game->key.quit = status;
        sfText_setString(game->settings_menu.controls.button1[6]->text,
        change_text(event.key.code));
    }
    game->settings_menu.controls.button1[6]->key_set = false;
    if (game->settings_menu.controls.button1[7]->key_set == true) {
        game->key.open_inv = change_key(event.key.code, &game->key);
        sfText_setString(game->settings_menu.controls.button1[7]->text,
        change_text(event.key.code));
    }
    game->settings_menu.controls.button1[7]->key_set = false;
    if (game->settings_menu.controls.button1[8]->key_set == true) {
        game->key.open_skill = change_key(event.key.code, &game->key);
        sfText_setString(game->settings_menu.controls.button1[8]->text,
        change_text(event.key.code));
    }
    game->settings_menu.controls.button1[8]->key_set = false;
}

static void check_button_quit_pause(game_t *game, sfEvent event)
{
    if (game->settings_menu.controls.button1[4]->key_set == true) {
        game->key.interact = change_key(event.key.code, &game->key);
        sfText_setString(game->settings_menu.controls.button1[4]->text,
        change_text(event.key.code));
    }
    game->settings_menu.controls.button1[4]->key_set = false;
    if (game->settings_menu.controls.button1[5]->key_set == true) {
        game->key.pause = change_key(event.key.code, &game->key);
        sfText_setString(game->settings_menu.controls.button1[5]->text,
        change_text(event.key.code));
    }
    game->settings_menu.controls.button1[5]->key_set = false;
    check_button_skill_inv(game, event);
}

static void check_button_up_down(game_t *game, sfEvent event)
{
    if (game->settings_menu.controls.button1[1]->key_set == true) {
        game->key.right = change_key(event.key.code, &game->key);
        sfText_setString(game->settings_menu.controls.button1[1]->text,
        change_text(event.key.code));
    }
    game->settings_menu.controls.button1[1]->key_set = false;
    if (game->settings_menu.controls.button1[2]->key_set == true) {
        game->key.up = change_key(event.key.code, &game->key);
        sfText_setString(game->settings_menu.controls.button1[2]->text,
        change_text(event.key.code));
    }
    game->settings_menu.controls.button1[2]->key_set = false;
    if (game->settings_menu.controls.button1[3]->key_set == true) {
        game->key.down = change_key(event.key.code, &game->key);
        sfText_setString(game->settings_menu.controls.button1[3]->text,
        change_text(event.key.code));
    }
    game->settings_menu.controls.button1[3]->key_set = false;
}

static void check_valid_key(game_t *game, sfEvent event, int status)
{
    if (status != -1) {
        game->key.left = status;
        sfText_setString(game->settings_menu.controls.button1[0]->text,
        change_text(event.key.code));
    }
}

int check_pressed(game_t *game, sfEvent event)
{
    int status = 0;

    if (event.type == sfEvtKeyPressed) {
        status = change_key(event.key.code, &game->key);
        if (game->settings_menu.controls.button1[0]->key_set == true) {
            check_valid_key(game, event, status);
            game->settings_menu.controls.button1[0]->key_set = false;
            return SUCCESS;
        }
        game->settings_menu.controls.button1[0]->key_set = false;
        if (status != -1) {
            check_button_up_down(game, event);
            check_button_quit_pause(game, event);
        }
    }
    return SUCCESS;
}
