/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** say_sentence
*/

#include "rpg.h"

static const char *monologue1 = "Do you want to say the sentences ?\n" \
                                "(Press S to say or Press X to stop)";
static const char *monologue2 = "...";

void duration_of_say(game_t *game)
{
    sfClock *clock = sfClock_create();
    sfTime time = sfClock_getElapsedTime(clock);
    sfEvent evt = {0};

    while (sfTime_asSeconds(time) < 3.0 &&
            sfRenderWindow_isOpen(game->window.window) == sfTrue) {
        while (sfRenderWindow_pollEvent(game->window.window, &evt))
            close_window(game, evt);
        display_interaction(game);
        sfText_setString(game->dialogue.text, monologue2);
        time = sfClock_getElapsedTime(clock);
    }
    sfClock_destroy(clock);
    return;
}

void say_sentence(game_t *game)
{
    int say = 0;
    sfEvent evt = {0};

    while (sfKeyboard_isKeyPressed(sfKeyX) == sfFalse &&
            sfRenderWindow_isOpen(game->window.window) == sfTrue) {
        while (sfRenderWindow_pollEvent(game->window.window, &evt))
            close_window(game, evt);
        display_interaction(game);
        if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue) {
            duration_of_say(game);
            say += 1;
        }
        sfText_setString(game->dialogue.text, monologue1);
    }
    if (say == 2)
        good_ending(game);
    else
        bad_ending(game);
    return;
}
