/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** init_settings
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg/game.h"
#include "rpg/macros.h"
#include "rpg/init.h"
#include <fcntl.h>
#include <stdio.h>

static int init_settings_controls_text(game_t *game)
{
    game->settings_menu.controls.pos_text = (sfVector2f){610, 600};
    game->settings_menu.controls.text = init_text(game->pause_menu.font_mc,
    game->settings_menu.controls.pos_text, "CONTROLS");
    if (!game->settings_menu.controls.text)
        return FAILURE;
    game->settings_menu.controls.clicked = false;
    return SUCCESS;
}

static int game_object_settings_controls(game_t *game)
{
    game->settings_menu.controls.texture =
    sfTexture_createFromFile(TEX_SETTINGS_CONTROLS, NULL);
    if (!game->settings_menu.controls.texture)
        return FAILURE;
    game->settings_menu.controls.sprite = sfSprite_create();
    if (!game->settings_menu.controls.sprite)
        return FAILURE;
    sfSprite_setTexture(game->settings_menu.controls.sprite,
    game->settings_menu.controls.texture, sfTrue);
    game->settings_menu.controls.rectangle =
    create_rectangle((sfVector2f){40, 268}, (sfVector2f){210, 119});
    if (!game->settings_menu.controls.rectangle)
        return FAILURE;
    if (init_settings_controls_text(game) != SUCCESS)
        return FAILURE;
    sfRectangleShape_setFillColor(game->settings_menu.controls.rectangle,
    sfColor_fromRGBA(0, 0, 0, 0));
    if (game_obj_button_controls(game) != SUCCESS)
        return FAILURE;
    return SUCCESS;
}

static int init_settings_graphics_text(game_t *game)
{
    game->settings_menu.graphics.pos_text = (sfVector2f){610, 800};
    game->settings_menu.graphics.text = init_text(game->pause_menu.font_mc,
    game->settings_menu.graphics.pos_text, "VOLUME");
    if (!game->settings_menu.graphics.text)
        return FAILURE;
    game->settings_menu.graphics.clicked = false;
    game->settings_menu.back = create_rectangle((sfVector2f){0, 932},
    (sfVector2f){321, 150});
    if (!game->settings_menu.back)
        return FAILURE;
    sfRectangleShape_setFillColor(game->settings_menu.back,
    sfColor_fromRGBA(0, 0, 0, 0));
    return SUCCESS;
}

static int game_object_settings_graphics(game_t *game)
{
    game->settings_menu.graphics.texture =
    sfTexture_createFromFile(TEX_SETTINGS_GRAPHICS, NULL);
    if (!game->settings_menu.graphics.texture)
        return FAILURE;
    game->settings_menu.graphics.sprite = sfSprite_create();
    if (!game->settings_menu.graphics.sprite)
        return FAILURE;
    sfSprite_setTexture(game->settings_menu.graphics.sprite,
    game->settings_menu.graphics.texture, sfTrue);
    game->settings_menu.graphics.rectangle =
    create_rectangle((sfVector2f){40, 30}, (sfVector2f){210, 119});
    if (!game->settings_menu.graphics.rectangle)
        return FAILURE;
    if (init_settings_graphics_text(game) != SUCCESS)
        return FAILURE;
    sfRectangleShape_setFillColor(game->settings_menu.graphics.rectangle,
    sfColor_fromRGBA(0, 0, 0, 0));
    if (game_obj_button_graphics(game) != SUCCESS)
        return FAILURE;
    return SUCCESS;
}

int init_settings_menu(game_t *game)
{
    if (!game)
        return FAILURE;
    game->settings_menu.texture = sfTexture_createFromFile(TEX_SETTINGS, NULL);
    if (!game->settings_menu.texture)
        return FAILURE;
    game->settings_menu.sprite = sfSprite_create();
    if (!game->settings_menu.sprite)
        return FAILURE;
    sfSprite_setTexture(game->settings_menu.sprite,
    game->settings_menu.texture, sfTrue);
    if (game_object_settings_audio(game) != SUCCESS)
        return FAILURE;
    if (game_object_settings_graphics(game) != SUCCESS)
        return FAILURE;
    if (game_object_settings_controls(game) != SUCCESS)
        return FAILURE;
    return SUCCESS;
}
