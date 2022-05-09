/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "rpg.h"

static const game_status_t game_handler[] = {
    {.status = MENU, .scene_handler = &display_menu},
    {.status = HTP, .scene_handler = &display_htp},
    {.status = GAME, .scene_handler = &display_game},
    {.status = PAUSE, .scene_handler = &display_pause},
    {.status = SETTINGS, .scene_handler = &display_settings},
    {.status = CHARACTERS, .scene_handler = &display_characters},
    {.status = SKILL_TREE, .scene_handler = &display_skill_tree},
    {.status = INVENTARY, .scene_handler = &display_inventory},
    {.status = GAME_OVER, .scene_handler = &display_game_over},
    {.status = ENDING, .scene_handler = &display_ending_panel},
    {0}
};

static void get_events(game_t *game)
{
    sfEvent event = {0};

    while (sfRenderWindow_pollEvent(game->window.window, &event)) {
        if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed &&
            event.key.code == game->key.quit) || game->status == QUIT)
            sfRenderWindow_close(game->window.window);
        analyse_events(game, event);
    }
}

static void execute_actions(game_t *game)
{
    sfRenderWindow_clear(game->window.window, sfBlack);
    get_events(game);
    for (int i = 0; game_handler[i].scene_handler; i += 1) {
        if (game->status == game_handler[i].status) {
            game_handler[i].scene_handler(game);
        }
    }
    sfRenderWindow_display(game->window.window);
}

static void game_loop(game_t *game)
{
    sfTime time = {0};
    float seconds = 0.0;

    while (sfRenderWindow_isOpen(game->window.window)) {
        time = sfClock_getElapsedTime(game->window.game_clock);
        seconds = time.microseconds / 1000000.0;
        if (seconds > 0.1) {
            execute_actions(game);
            sfClock_restart(game->window.game_clock);
        }
    }
}

int launch(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return FAILURE;
    if (check_all_file() != SUCCESS)
        return FAILURE;
    if (init_game(game) != SUCCESS)
        return FAILURE;
    sfMusic_play(game->ost.title_theme);
    game_loop(game);
    sfMusic_stop(game->ost.title_theme);
    destroy_resources(game);
    free(game);
    return SUCCESS;
}
