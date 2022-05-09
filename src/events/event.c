/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Espace de travail)
** File description:
** event
*/

#include <SFML/Graphics.h>
#include "rpg.h"
#include "rpg/events.h"

static const game_status_t event_handler[] = {
    {.status = MENU, .event_handler = &analyse_menu_events},
    {.status = HTP, .event_handler = &analyse_htp_event},
    {.status = GAME, .event_handler = &analyse_game_events},
    {.status = PAUSE, .event_handler = &analyse_pause_events},
    {.status = INVENTARY, .event_handler = &analyse_inventory_events},
    {.status = SETTINGS, .event_handler = &analyse_settings_events},
    {.status = CHARACTERS, .event_handler = &analyse_characters_events},
    {.status = SKILL_TREE, .event_handler = &skill_tree_event},
    {0}
};

static void handle_resize(game_t *game)
{
    sfVector2u window_size = sfRenderWindow_getSize(game->window.window);

    game->window.scaling.x = (float)window_size.x / (float)1920;
    game->window.scaling.y = (float)window_size.y / (float)1080;
}

int analyse_events(game_t *game, sfEvent event)
{
    if (event.type == sfEvtResized)
        handle_resize(game);
    for (int i = 0; event_handler[i].event_handler; i += 1) {
        if (game->status == event_handler[i].status)
            return event_handler[i].event_handler(game, event);
    }
    return 0;
}
