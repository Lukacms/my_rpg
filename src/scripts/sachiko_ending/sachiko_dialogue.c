/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** sachiko_ending_loop
*/

#include "rpg.h"

static const sfIntRect portaits[] = {
    {1024 * 1, 1440 * 0, 1024, 1440},
};

static const char monologue[] = "There she is, Sachiko...!";
static const char monologue2[] = "What am I supposed to do already ?";

void third_dialogue(game_t *game);

static void first_dialogue(game_t *game)
{
    sfText_setString(game->dialogue.text, monologue);
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
    if (sfKeyboard_isKeyPressed(game->key.interact) == sfTrue && *flag != 3)
        (*flag) += 1;
    if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue)
        *flag = 3;
    if ((*flag) == 0)
        first_dialogue(game);
    if ((*flag) == 1)
        second_dialogue(game);
    if (*flag == 2)
        third_dialogue(game);
    if ((*flag) == 3) {
        say_sentence(game);
        *flag = 4;
    }
    return;
}

static void set_mc_rect(game_t *game)
{
    sfIntRect mc_rect = sfSprite_getTextureRect(game->entities.mc.sprite);

    if (game->entities.mc.type == MC)
        game->entities.mc.states_mc = FRONT;
    if (game->entities.mc.type == BLOND)
        game->entities.mc.states_mc = FRONT_BLOND;
    if (game->entities.mc.type == GIRL)
        game->entities.mc.states_mc = FRONT_GIRL;
    if (game->entities.mc.type == SKATER)
        game->entities.mc.states_mc = FRONT_SKATER;
    mc_rect.top = game->entities.mc.states_mc;
    mc_rect.left = 0;
    sfSprite_setTextureRect(game->entities.mc.sprite, mc_rect);
    return;
}

void sachiko_dialogue(game_t *game)
{
    sfTime time = {0};
    int flag = 0;

    sfMusic_play(game->ost.sachiko);
    sfRenderWindow_setView(game->window.window, game->views.ui);
    sfSprite_setTextureRect(game->dialogue.portrait, portaits[0]);
    set_mc_rect(game);
    while (flag != 4 && sfRenderWindow_isOpen(game->window.window) == sfTrue) {
        time = sfClock_getElapsedTime(game->window.game_clock);
        if (sfTime_asSeconds(time) > 0.2) {
            events(game, &flag);
            display_interaction(game);
            sfClock_restart(game->window.game_clock);
        }
    }
    return;
}
