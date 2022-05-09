/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** add_particules
*/

#include <SFML/Graphics.h>
#include "rpg.h"

static void actions(game_t *game)
{
    sfTime time = {0};
    sfVector2i pos = {0};
    sfVector2f floating_pos = {0};

    sfRenderWindow_clear(game->window.window, sfBlack);
    display_menu(game);
    pos = sfMouse_getPosition(NULL);
    floating_pos.x = (float)pos.x;
    floating_pos.y = (float)pos.y;
    time = sfClock_getElapsedTime(game->start_menu.clock);
    if (sfTime_asSeconds(time) > 0.1) {
        game->start_menu.add(&game->start_menu, floating_pos);
        sfClock_restart(game->start_menu.clock);
    }
    sfRenderWindow_display(game->window.window);
}

int add_particules(game_t *game)
{
    sfTime time = {0};

    if (!game)
        return FAILURE;
    time = sfClock_getElapsedTime(game->window.game_clock);
    if (sfTime_asSeconds(time) > 0.1) {
        actions(game);
        sfClock_restart(game->window.game_clock);
    }
    return SUCCESS;
}
