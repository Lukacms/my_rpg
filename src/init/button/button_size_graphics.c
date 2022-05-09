/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** button_size_graphics
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg/game.h"
#include "rpg/macros.h"
#include "rpg/init.h"
#include <fcntl.h>
#include <stdio.h>

int init_button_music(game_t *game, int index, sfVector2f pos_r, char *str)
{
    sfVector2f pos_text;
    game->settings_menu.audio.button1[index] = malloc(sizeof(button_t));
    game->settings_menu.audio.button1[index]->rectangle =
    create_rectangle((pos_r), (sfVector2f){30, 30});
    pos_text = sfRectangleShape_getPosition(game->settings_menu.
    audio.button1[index]->rectangle);
    game->settings_menu.audio.button1[index]->pos_text =
    (sfVector2f){pos_text.x, pos_text.y + 30};
    game->settings_menu.audio.button1[index]->text =
    init_text(game->pause_menu.font_mc, game->settings_menu.audio.
    button1[index]->pos_text, str);
    sfText_setCharacterSize(game->settings_menu.audio.
    button1[index]->text, 30);
    if (!game->settings_menu.audio.button1[index]->text ||
    !game->settings_menu.audio.button1[index]->rectangle)
        return FAILURE;
    sfRectangleShape_setFillColor(game->settings_menu.
    audio.button1[index]->rectangle, sfColor_fromRGBA(255, 0, 0, 255));
    game->settings_menu.audio.button1[index]->key_set = false;
    return SUCCESS;
}

int init_button(game_t *game, int index, sfVector2f pos_r, char *str)
{
    sfVector2f pos_text;
    game->settings_menu.graphics.button1[index] = malloc(sizeof(button_t));
    game->settings_menu.graphics.button1[index]->rectangle =
    create_rectangle((pos_r), (sfVector2f){30, 30});
    pos_text = sfRectangleShape_getPosition(game->settings_menu.
    graphics.button1[index]->rectangle);
    game->settings_menu.graphics.button1[index]->pos_text =
    (sfVector2f){pos_text.x, pos_text.y + 30};
    game->settings_menu.graphics.button1[index]->text =
    init_text(game->pause_menu.font_mc, game->settings_menu.graphics.
    button1[index]->pos_text, str);
    sfText_setCharacterSize(game->settings_menu.graphics.
    button1[index]->text, 30);
    if (!game->settings_menu.graphics.button1[index]->text ||
    !game->settings_menu.graphics.button1[index]->rectangle)
        return FAILURE;
    sfRectangleShape_setFillColor(game->settings_menu.
    graphics.button1[index]->rectangle, sfColor_fromRGBA(255, 0, 0, 255));
    game->settings_menu.graphics.button1[index]->key_set = false;
    return SUCCESS;
}

int init_volume(game_t *game, int index, sfVector2f pos_r, char *str)
{
    sfVector2f pos_text;
    game->settings_menu.audio.button1[index] = malloc(sizeof(button_t));
    game->settings_menu.audio.button1[index]->rectangle =
    create_rectangle((pos_r), (sfVector2f){10, 30});
    pos_text = sfRectangleShape_getPosition(game->settings_menu.
    audio.button1[index]->rectangle);
    game->settings_menu.audio.button1[index]->pos_text =
    (sfVector2f){pos_text.x - 70, pos_text.y + 30};
    game->settings_menu.audio.button1[index]->text =
    init_text(game->pause_menu.font_mc,
    game->settings_menu.audio.button1[index]->pos_text, str);
    sfText_setCharacterSize(game->settings_menu.audio.
    button1[index]->text, 30);
    if (!game->settings_menu.audio.button1[index]->text ||
    !game->settings_menu.audio.button1[index]->rectangle)
        return FAILURE;
    sfRectangleShape_setFillColor(game->settings_menu.
    audio.button1[index]->rectangle, sfColor_fromRGBA(255, 0, 0, 255));
    game->settings_menu.audio.button1[index]->key_set = false;
    return SUCCESS;
}

int init_volume_up(game_t *game, int index, sfVector2f pos_r, char *str)
{
    sfVector2f pos_text;
    game->settings_menu.audio.button1[index] = malloc(sizeof(button_t));
    game->settings_menu.audio.button1[index]->rectangle =
    create_rectangle((pos_r), (sfVector2f){10, 30});
    pos_text = sfRectangleShape_getPosition(game->settings_menu.
    audio.button1[index]->rectangle);
    game->settings_menu.audio.button1[index]->pos_text =
    (sfVector2f){pos_text.x + 200, pos_text.y + 30};
    game->settings_menu.audio.button1[index]->text =
    init_text(game->pause_menu.font_mc, game->settings_menu.audio.
    button1[index]->pos_text, str);
    sfText_setCharacterSize(game->settings_menu.audio.
    button1[index]->text, 30);
    if (!game->settings_menu.audio.button1[index]->text ||
    !game->settings_menu.audio.button1[index]->rectangle)
        return FAILURE;
    sfRectangleShape_setFillColor(game->settings_menu.
    audio.button1[index]->rectangle, sfColor_fromRGBA(0, 255, 0, 255));
    game->settings_menu.audio.button1[index]->key_set = false;
    return SUCCESS;
}

int init_key(game_t *game, int index, sfVector2f pos_r, char *str)
{
    sfVector2f pos_text;
    game->settings_menu.controls.button1[index] = malloc(sizeof(button_t));
    game->settings_menu.controls.button1[index]->rectangle =
    create_rectangle((pos_r), (sfVector2f){50, 30});
    pos_text = sfRectangleShape_getPosition(game->settings_menu.
    controls.button1[index]->rectangle);
    game->settings_menu.controls.button1[index]->pos_text =
    (sfVector2f){pos_text.x - 10, pos_text.y - 5};
    game->settings_menu.controls.button1[index]->text =
    init_text(game->pause_menu.font_mc, game->settings_menu.controls.
    button1[index]->pos_text, str);
    sfText_setCharacterSize(game->settings_menu.controls.
    button1[index]->text, 30);
    if (!game->settings_menu.controls.button1[index]->text ||
    !game->settings_menu.controls.button1[index]->rectangle)
        return FAILURE;
    sfRectangleShape_setFillColor(game->settings_menu.
    controls.button1[index]->rectangle, sfColor_fromRGBA(255, 0, 0, 255));
    game->settings_menu.controls.button1[index]->key_set = false;
    return SUCCESS;
}
