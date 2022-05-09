/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** settings_mode_audio_on_off_volume
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include "rpg.h"

static int set_off_music(game_t *game, sfRectangleShape *re,
sfRectangleShape *re2)
{
    sfMusic_stop(game->ost.title_theme);
    sfMusic_stop(game->ost.main_theme);
    sfMusic_stop(game->ost.panic);
    sfRectangleShape_setFillColor(re, sfColor_fromRGBA(0, 255, 0, 255));
    sfRectangleShape_setFillColor(re2, sfColor_fromRGBA(255, 0, 0, 255));
    return 0;
}

static int set_on_music(game_t *game, sfRectangleShape *re,
sfRectangleShape *re2)
{
    sfMusic_play(game->ost.title_theme);
    sfMusic_play(game->ost.main_theme);
    sfMusic_play(game->ost.panic);
    sfRectangleShape_setFillColor(re, sfColor_fromRGBA(0, 255, 0, 255));
    sfRectangleShape_setFillColor(re2, sfColor_fromRGBA(255, 0, 0, 255));
    return 0;
}

void check_clicked_music(game_t *game, sfMouseButtonEvent button)
{
    if (in_text(game->settings_menu.audio.button1[2]->text, button.x, button.y,
    game->window.scaling) == true) {
        set_on_music(game, game->settings_menu.audio.button1[2]->rectangle,
        game->settings_menu.audio.button1[3]->rectangle);
    }
    if (in_text(game->settings_menu.audio.button1[3]->text, button.x, button.y,
    game->window.scaling) == true) {
        set_off_music(game, game->settings_menu.audio.button1[3]->rectangle,
        game->settings_menu.audio.button1[2]->rectangle);
    }
}
