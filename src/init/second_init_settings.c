/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** second_init_settings.c
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <fcntl.h>
#include <stdio.h>
#include "rpg/game.h"
#include "rpg/macros.h"
#include "rpg/init.h"

static int sec_game_object_settings_audio(game_t *game)
{
    game->settings_menu.audio.rectangle =
    create_rectangle((sfVector2f){40, 149}, (sfVector2f){210, 119});
    if (!game->settings_menu.audio.rectangle)
        return FAILURE;
    game->settings_menu.audio.pos_text = (sfVector2f){610, 200};
    game->settings_menu.audio.text = init_text(game->pause_menu.font_mc,
    game->settings_menu.audio.pos_text, "VOLUME");
    if (!game->settings_menu.audio.text)
        return FAILURE;
    game->settings_menu.audio.clicked = false;
    sfRectangleShape_setFillColor(game->settings_menu.audio.rectangle,
    sfColor_fromRGBA(0, 0, 0, 0));
    if (game_obj_button_audio(game) != SUCCESS)
        return FAILURE;
    return SUCCESS;
}

int game_object_settings_audio(game_t *game)
{
    game->settings_menu.audio.texture =
    sfTexture_createFromFile(TEX_SETTINGS_AUDIO, NULL);
    if (!game->settings_menu.audio.texture)
        return FAILURE;
    game->settings_menu.audio.sprite = sfSprite_create();
    if (!game->settings_menu.audio.sprite)
        return FAILURE;
    sfSprite_setTexture(game->settings_menu.audio.sprite,
    game->settings_menu.audio.texture, sfTrue);
    if (sec_game_object_settings_audio(game) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
