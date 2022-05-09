/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** ending
*/

#include <math.h>
#include "rpg.h"

static const sfVector2f mc_pos = {1920 / 2, 1080 / 2};

static const sfIntRect mc_rect[] = {
    {24, 0, 24, 48},
    {24, 48, 24, 48},
    {24, 96, 24, 48},
    {24, 144, 24, 48}
};

static void fader(game_t *game, sfClock *clock)
{
    sfColor color = sfSprite_getColor(game->ending.fade);
    sfTime time = sfClock_getElapsedTime(clock);

    if (sfTime_asSeconds(time) > 0.3 && color.a > (sfUint8){0}) {
        color.a -= 5;
        sfClock_restart(clock);
    }
    sfSprite_setColor(game->ending.fade, color);
    return;
}

static void ending_cinematic(game_t *game)
{
    sfClock *clock = sfClock_create();
    sfClock *fade = sfClock_create();
    sfTime time = sfClock_getElapsedTime(clock);

    while (sfTime_asSeconds(time) < 30 &&
            sfRenderWindow_isOpen(game->window.window) == sfTrue) {
        display_ending(game);
        fader(game, fade);
        time = sfClock_getElapsedTime(clock);
        if (sfTime_asSeconds(time) > 10 && sfTime_asSeconds(time) < 15)
            sfSprite_setTextureRect(game->entities.mc.sprite, mc_rect[2]);
        if (sfTime_asSeconds(time) > 15 && sfTime_asSeconds(time) < 20)
            sfSprite_setTextureRect(game->entities.mc.sprite, mc_rect[3]);
        if (sfTime_asSeconds(time) > 20) {
            game->entities.mc.states_mc = FRONT;
            sfSprite_move(game->entities.mc.sprite, (sfVector2f){0, 5});
        }
    }
    sfClock_destroy(clock);
    sfClock_destroy(fade);
}

int ending(game_t *game)
{
    sfMusic_stop(game->ost.sachiko);
    sfRenderWindow_setView(game->window.window, game->views.normal);
    sfView_setSize(game->views.normal, (sfVector2f){1920, 1080});
    sfView_setCenter(game->views.normal, (sfVector2f){1920 / 2, 1080 / 2});
    sfSprite_setTextureRect(game->entities.mc.sprite, mc_rect[0]);
    sfRenderWindow_clear(game->window.window, sfBlack);
    game->entities.mc.states_mc = BACK;
    if (!game)
        return FAILURE;
    sfSprite_setPosition(game->entities.mc.sprite, mc_pos);
    ending_cinematic(game);
    game->status = ENDING;
    return SUCCESS;
}
