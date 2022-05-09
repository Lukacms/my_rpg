/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** display_game_over
*/

#include "rpg.h"

int display_text(game_t *game)
{
    sfTime time = sfClock_getElapsedTime(game->game_over.over_clock);

    if (!game)
        return FAILURE;
    if (sfTime_asSeconds(time) < 1)
        sfRenderWindow_drawText(game->window.window, game->game_over.over_text,
        NULL);
    else if (sfTime_asSeconds(time) > 2)
        sfClock_restart(game->game_over.over_clock);
    return SUCCESS;
}

int display_game_over(game_t *game)
{
    if (!game)
        return FAILURE;
    sfRenderWindow_setView(game->window.window, game->views.ui);
    sfRenderWindow_drawSprite(game->window.window, game->game_over.over, NULL);
    display_text(game);
    display_pixels(&game->game_over, game);
    if (sfKeyboard_isKeyPressed(game->key.interact) == sfTrue) {
        sfMusic_play(game->ost.title_theme);
        game->status = MENU;
    }
    return SUCCESS;
}
