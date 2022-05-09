/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** items_view_loop
*/

#include "rpg.h"

static const char monologue[] =
                "Thoses things, I could reach them if I had a key.";
static const char monologue2[] =
                    "There must be a key here.";

static void first_dialogue(game_t *game)
{
    sfText_setString(game->dialogue.text, monologue);
    sfSprite_setTextureRect(game->dialogue.portrait,
                            (sfIntRect){1024 * 3, 1440 * 0, 1024, 1440});
    return;
}

static void second_dialogue(game_t *game)
{
    sfText_setString(game->dialogue.text, monologue2);
    return;
}

static void events(game_t *game, int *flag)
{
    sfEvent evt = {0};

    while (sfRenderWindow_pollEvent(game->window.window, &evt))
        close_window(game, evt);
    if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue)
        *flag = 3;
    if (sfKeyboard_isKeyPressed(game->key.interact) == sfTrue)
        (*flag) += 1;
    if ((*flag) == 0)
        first_dialogue(game);
    if ((*flag) == 1) {
        second_dialogue(game);
        (*flag) += 1;
        return;
    }
    if ((*flag) == 2)
        second_dialogue(game);
    return;
}

void item_view_loop(game_t *game)
{
    sfTime time = {0};
    int flag = 0;

    sfRenderWindow_setView(game->window.window, game->views.ui);
    sfRenderWindow_clear(game->window.window, sfBlack);
    moving_cam(game);
    while (flag != 3 && sfRenderWindow_isOpen(game->window.window) == sfTrue) {
        time = sfClock_getElapsedTime(game->window.game_clock);
        if (sfTime_asSeconds(time) > 0.2) {
            events(game, &flag);
            display_interaction(game);
            sfClock_restart(game->window.game_clock);
        }
    }
    game->scripts.view_items = true;
    sfView_setCenter(game->views.normal,
                    sfSprite_getPosition(game->entities.mc.sprite));
    return;
}
