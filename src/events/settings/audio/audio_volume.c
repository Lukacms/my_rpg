/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** settings_mode_audio_volume
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include "rpg.h"

static int set_volume_down(game_t *game, float sound,
sfRectangleShape *re, float value)
{
    float get_vol = sfMusic_getVolume(game->ost.title_theme);
    float get_vol2 = sfMusic_getVolume(game->ost.main_theme);
    float get_vol3 = sfMusic_getVolume(game->ost.panic);
    sfVector2f size = sfRectangleShape_getSize(re);

    if (get_vol < sound || get_vol2 < sound || get_vol3 < sound) {
        return 0;
    } else {
        sfMusic_setVolume(game->ost.title_theme, get_vol - sound);
        sfMusic_setVolume(game->ost.main_theme, get_vol2 - sound);
        sfMusic_setVolume(game->ost.panic, get_vol3 - sound);
        sfRectangleShape_setSize(re, (sfVector2f){size.x - value, size.y});
    }
    return 0;
}

static int set_volume_up(game_t *game, float sound,
sfRectangleShape *re, float value)
{
    float get_vol = sfMusic_getVolume(game->ost.title_theme);
    float get_vol2 = sfMusic_getVolume(game->ost.main_theme);
    float get_vol3 = sfMusic_getVolume(game->ost.panic);
    sfVector2f size = sfRectangleShape_getSize(re);

    if (get_vol > 90 || get_vol2 > 90 || get_vol3 > 90) {
        return 0;
    } else {
        sfMusic_setVolume(game->ost.title_theme, get_vol + sound);
        sfMusic_setVolume(game->ost.main_theme, get_vol2 + sound);
        sfMusic_setVolume(game->ost.panic, get_vol3 + sound);
        sfRectangleShape_setSize(re, (sfVector2f){size.x + value, size.y});
    }
    return 0;
}

static int set_volume_effect_down(game_t *game, float sound,
sfRectangleShape *re, float value)
{
    float get_vol = sfSound_getVolume(game->sfx.sfx);
    sfVector2f size = sfRectangleShape_getSize(re);

    if (get_vol < sound)
        return 0;
    else {
        sfSound_setVolume(game->sfx.sfx, get_vol - sound);
        sfRectangleShape_setSize(re, (sfVector2f){size.x - value, size.y});
    }
    return 0;
}

static int set_volume_effect_up(game_t *game, float sound,
sfRectangleShape *re, float value)
{
    float get_vol = sfSound_getVolume(game->sfx.sfx);
    sfVector2f size = sfRectangleShape_getSize(re);

    if (get_vol > 90)
        return 0;
    else {
        sfSound_setVolume(game->sfx.sfx, get_vol + sound);
        sfRectangleShape_setSize(re, (sfVector2f){size.x + value, size.y});
    }
    return 0;
}

int check_clicked_audio_volume(game_t *game, sfMouseButtonEvent button)
{
    if (in_text(game->settings_menu.audio.button1[4]->text, button.x, button.y,
    game->window.scaling) == true)
        set_volume_effect_down(game, 10,
        game->settings_menu.audio.button1[5]->rectangle, 20);
    if (in_text(game->settings_menu.audio.button1[5]->text, button.x, button.y,
    game->window.scaling) == true)
        set_volume_effect_up(game, 10,
        game->settings_menu.audio.button1[5]->rectangle, 20);
    if (in_text(game->settings_menu.audio.button1[6]->text, button.x, button.y,
    game->window.scaling) == true)
        set_volume_down(game, 10,
        game->settings_menu.audio.button1[7]->rectangle, 20);
    if (in_text(game->settings_menu.audio.button1[7]->text, button.x, button.y,
    game->window.scaling) == true)
        set_volume_up(game, 10,
        game->settings_menu.audio.button1[7]->rectangle, 20);
    return SUCCESS;
}
