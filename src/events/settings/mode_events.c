/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** settings_mode_events
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include "rpg.h"

static const game_status_t event_settings_handler[] = {
    {.mode = GRAPHICS, .event_settings_handler = &analyse_graphics_events},
    {.mode = AUDIO, .event_settings_handler = &analyse_audio_events},
    {.mode = CONTROLS, .event_settings_handler = &analyse_controls_events},
    {0},
};

static void handle_resize(game_t *game)
{
    sfVector2u window_size = sfRenderWindow_getSize(game->window.window);

    game->window.scaling.x = (float)window_size.x / (float)1920;
    game->window.scaling.y = (float)window_size.y / (float)1080;
}

int analyse_events_mode(game_t *game, sfEvent event)
{
    if (event.type == sfEvtResized)
        handle_resize(game);
    for (int i = 0; event_settings_handler[i].event_settings_handler; i += 1) {
        if (game->mode == event_settings_handler[i].mode) {
            event_settings_handler[i].event_settings_handler(game, event);
        }
    }
    return SUCCESS;
}
