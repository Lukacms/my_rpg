/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** button_settings_audio
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg/game.h"
#include "rpg/macros.h"
#include "rpg/init.h"
#include <fcntl.h>
#include <stdio.h>

int game_obj_button_graphics(game_t *game)
{
    if (init_button(game, 0, (sfVector2f){1570, 235}, "1920x1080") != SUCCESS)
        return FAILURE;
    if (init_button(game, 1, (sfVector2f){1750, 235}, "800x600") != SUCCESS)
        return FAILURE;
    if (init_button(game, 2, (sfVector2f){1550, 520}, "60") != SUCCESS)
        return FAILURE;
    if (init_button(game, 3, (sfVector2f){1660, 520}, "120") != SUCCESS)
        return FAILURE;
    if (init_button(game, 4, (sfVector2f){1780, 520}, "180") != SUCCESS)
        return FAILURE;
    if (init_button(game, 5, (sfVector2f){1500, 365}, "Fullscreen") != SUCCESS)
        return FAILURE;
    if (init_button(game, 6, (sfVector2f){1700, 365},
    "No Fullscreen") != SUCCESS)
        return FAILURE;
    sfRectangleShape_setFillColor(game->settings_menu.graphics.
    button1[6]->rectangle, sfGreen);
    game->settings_menu.graphics.button1[7] = NULL;
    return SUCCESS;
}

int game_obj_button_audio(game_t *game)
{
    if (init_button_music(game, 0, (sfVector2f){1580, 235}, "ON") != SUCCESS)
        return FAILURE;
    if (init_button_music(game, 1, (sfVector2f){1700, 235}, "OFF") != SUCCESS)
        return FAILURE;
    if (init_button_music(game, 2, (sfVector2f){1580, 365}, "ON") != SUCCESS)
        return FAILURE;
    if (init_button_music(game, 3, (sfVector2f){1700, 365}, "OFF") != SUCCESS)
        return FAILURE;
    if (init_volume(game, 4, (sfVector2f){1610, 520}, "DOWN") != SUCCESS)
        return FAILURE;
    if (init_volume_up(game, 5, (sfVector2f){1610, 520}, "UP") != SUCCESS)
        return FAILURE;
    if (init_volume(game, 6, (sfVector2f){1610, 620}, "DOWN") != SUCCESS)
        return FAILURE;
    if (init_volume_up(game, 7, (sfVector2f){1610, 620}, "UP") != SUCCESS)
        return FAILURE;
    game->settings_menu.audio.button1[8] = NULL;
    return SUCCESS;
}

int game_obj_button_controls(game_t *game)
{
    if (init_key(game, 0, (sfVector2f){1550, 245}, "Left") != SUCCESS)
        return FAILURE;
    if (init_key(game, 1, (sfVector2f){1550, 315}, "Right") != SUCCESS)
        return FAILURE;
    if (init_key(game, 2, (sfVector2f){1550, 385}, "Up") != SUCCESS)
        return FAILURE;
    if (init_key(game, 3, (sfVector2f){1550, 455}, "Down") != SUCCESS)
        return FAILURE;
    if (init_key(game, 4, (sfVector2f){1550, 525}, "Interact") != SUCCESS)
        return FAILURE;
    if (init_key(game, 5, (sfVector2f){1550, 595}, "Pause") != SUCCESS)
        return FAILURE;
    if (init_key(game, 6, (sfVector2f){1550, 665}, "Quit") != SUCCESS)
        return FAILURE;
    if (init_key(game, 7, (sfVector2f){1550, 725}, "INVENTORY") != SUCCESS)
        return FAILURE;
    if (init_key(game, 8, (sfVector2f){1550, 795}, "SKILL TREE") != SUCCESS)
        return FAILURE;
    game->settings_menu.controls.button1[9] = NULL;
    return SUCCESS;
}
