/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** shaking_view
*/

#include "rpg.h"

static const sfVector2f movement[] = {
    {5, 0},
    {-5, 0},
    {0, 5},
    {0, -5},
};

int shaking_view(game_t *game, sfClock *clock)
{
    sfTime time;
    sfInt32 seconds;

    if (!game || !clock)
        return FAILURE;
    time = sfClock_getElapsedTime(clock);
    seconds = sfTime_asMilliseconds(time);
    if (seconds < (sfInt32){300})
        sfView_move(game->views.normal, movement[0]);
    if (seconds > (sfInt32){300} && seconds < (sfInt32){600})
        sfView_move(game->views.normal, movement[2]);
    if (seconds > (sfInt32){600} && seconds < (sfInt32){900})
        sfView_move(game->views.normal, movement[1]);
    if (seconds > (sfInt32){900} && seconds < (sfInt32){1200})
        sfView_move(game->views.normal, movement[3]);
    if (seconds > (sfInt32){1200})
        sfClock_restart(clock);
    sfRenderWindow_display(game->window.window);
    return SUCCESS;
}
