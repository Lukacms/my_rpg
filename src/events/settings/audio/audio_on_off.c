/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** settings_mode_audio_on_off
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include "rpg.h"

static int set_off_effect(game_t *game, sfRectangleShape *re,
sfRectangleShape *re2)
{
    sfSound_stop(game->sfx.sfx);
    sfRectangleShape_setFillColor(re, sfColor_fromRGBA(0, 255, 0, 255));
    sfRectangleShape_setFillColor(re2, sfColor_fromRGBA(255, 0, 0, 255));
    return 0;
}

static int set_on_effect(game_t *game, sfRectangleShape *re,
sfRectangleShape *re2)
{
    sfSound_play(game->sfx.sfx);
    sfRectangleShape_setFillColor(re, sfColor_fromRGBA(0, 255, 0, 255));
    sfRectangleShape_setFillColor(re2, sfColor_fromRGBA(255, 0, 0, 255));
    return 0;
}

int check_clicked_audio_on_off(game_t *game, sfMouseButtonEvent button)
{
    if (in_text(game->settings_menu.audio.button1[0]->text, button.x, button.y,
    game->window.scaling) == true) {
        sfRectangleShape_setFillColor(game->settings_menu.audio.
        button1[0]->rectangle, sfColor_fromRGBA(255, 255, 255, 100));
        set_on_effect(game, game->settings_menu.audio.button1[0]->rectangle,
        game->settings_menu.audio.button1[1]->rectangle);
    }
    if (in_text(game->settings_menu.audio.button1[1]->text, button.x, button.y,
    game->window.scaling) == true) {
        set_off_effect(game, game->settings_menu.audio.button1[1]->rectangle,
        game->settings_menu.audio.button1[0]->rectangle);
    }
    check_clicked_music(game, button);
    return SUCCESS;
}
