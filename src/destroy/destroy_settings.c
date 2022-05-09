/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** destroy_settings
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg/game.h"
#include "rpg/macros.h"
#include "rpg/init.h"

static void destroy_button(button_t *button)
{
    if (!button)
        return;
    sfRectangleShape_destroy(button->rectangle);
    sfText_destroy(button->text);
    free(button);
}

static int destroy_game_obj(game_obj_settings_t *obj)
{
    if (!obj)
        return FAILURE;
    sfRectangleShape_destroy(obj->rectangle);
    sfText_destroy(obj->text);
    sfSprite_destroy(obj->sprite);
    sfTexture_destroy(obj->texture);
    for (int i = 0; obj->button1[i]; i++)
        destroy_button(obj->button1[i]);
    return SUCCESS;
}

int destroy_settings(settings_menu_t *settings)
{
    if (!settings)
        return FAILURE;
    destroy_game_obj(&settings->audio);
    destroy_game_obj(&settings->controls);
    destroy_game_obj(&settings->graphics);
    sfTexture_destroy(settings->texture);
    sfSprite_destroy(settings->sprite);
    sfRectangleShape_destroy(settings->back);
    return SUCCESS;
}
