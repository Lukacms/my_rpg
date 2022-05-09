/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** settings_mode_audio_events
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include "rpg.h"

static int analyse_audio(game_t *game, sfMouseButtonEvent button)
{
    check_clicked_audio_on_off(game, button);
    check_clicked_audio_volume(game, button);
    return SUCCESS;
}

static int color_choices(game_t *game, sfMouseMoveEvent button)
{
    for (int i = 0; i < 8; i++) {
        sfText_setColor(game->settings_menu.audio.button1[i]->text, sfWhite);
        if (in_text(game->settings_menu.audio.button1[i]->text, button.x,
        button.y, game->window.scaling))
            sfText_setColor(game->settings_menu.audio.button1[i]->text,
            sfRed);
    }
    return SUCCESS;
}

int analyse_audio_events(game_t *game, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed) {
        play_sound_selected(game, 4);
        analyse_audio(game, event.mouseButton);
    } else if (event.type == sfEvtMouseMoved)
        color_choices(game, event.mouseMove);
    return SUCCESS;
}

void set_bool_system(game_t *game)
{
    game->settings_menu.graphics.clicked = false;
    game->settings_menu.audio.clicked = false;
    game->settings_menu.controls.clicked = false;
}
