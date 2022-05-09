/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** display_ending
*/

#include "rpg.h"

static void animate_mc_ending(game_t *game)
{
    sfIntRect rect = sfSprite_getTextureRect(game->entities.mc.sprite);
    sfTime time = sfClock_getElapsedTime(game->entities.mc.animate);

    if (game->entities.mc.states_mc == FRONT && rect.top != 48)
        rect.top = 48;
    if (game->entities.mc.states_mc == FRONT) {
        if (sfTime_asSeconds(time) > 0.2) {
            rect.left += 24;
            sfClock_restart(game->entities.mc.animate);
        }
        if (rect.left >= 72)
            rect.left = 0;
    }
    sfSprite_setTextureRect(game->entities.mc.sprite, rect);
}

int display_ending(game_t *game)
{
    sfEvent evt = {0};

    while (sfRenderWindow_pollEvent(game->window.window, &evt))
        close_window(game, evt);
    render_views(game);
    sfRenderWindow_drawSprite(game->window.window, game->ending.ending, NULL);
    display_mc(&game->entities.mc, game->window.window);
    animate_mc_ending(game);
    sfRenderWindow_drawSprite(game->window.window, game->ending.fade, NULL);
    sfRenderWindow_display(game->window.window);
    sfRenderWindow_clear(game->window.window, sfBlack);
    return SUCCESS;
}
