/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** health.c
*/

#include "my.h"
#include "rpg.h"

static const char monologue[] =
                    "I should take this potion !";
static const char monologue2[] =
                    "Acquired [Heal Bottle], Can be drunk";

static int first_dialogue(game_t *game)
{
    if (game == NULL)
        return FAILURE;
    sfText_setString(game->dialogue.text, monologue);
    return SUCCESS;
}

static int second_dialogue(game_t *game)
{
    if (game == NULL)
        return FAILURE;
    sfText_setString(game->dialogue.text, monologue2);
    return SUCCESS;
}

static void events(game_t *game, int *flag)
{
    sfEvent evt = {0};

    while (sfRenderWindow_pollEvent(game->window.window, &evt))
        close_window(game, evt);
    if (sfKeyboard_isKeyPressed(game->key.interact) == sfTrue)
        (*flag) += 1;
    if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue)
        *flag = 3;
    if ((*flag) == 0)
        first_dialogue(game);
    if ((*flag) == 1) {
        play_sound_selected(game, 0);
        second_dialogue(game);
        (*flag) += 1;
        return;
    }
    if ((*flag) == 2)
        second_dialogue(game);
}

int health_interaction(game_t *game)
{
    sfTime time = {0};
    int flag = 0;

    if (!game)
        return FAILURE;
    sfRenderWindow_setView(game->window.window, game->views.ui);
    sfSprite_setTextureRect(game->dialogue.portrait,
    (sfIntRect){1024 * 3, 0, 1024, 1440});
    while (flag != 3 && sfRenderWindow_isOpen(game->window.window) == sfTrue) {
        time = sfClock_getElapsedTime(game->window.game_clock);
        if (sfTime_asSeconds(time) > 0.2) {
            events(game, &flag);
            display_interaction(game);
            sfClock_restart(game->window.game_clock);
        }
    }
    game->inventory.heal_bottle = true;
    return SUCCESS;
}
