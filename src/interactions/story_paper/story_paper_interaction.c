/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** story_paper_interaction
*/

#include "rpg.h"

static int event_2(game_t *game, int *flag)
{
    if (game == NULL || flag == NULL)
        return FAILURE;
    if ((*flag) == 2)
        story_dialogue_2(game);
    if ((*flag) == 3)
        story_dialogue_3(game);
    if ((*flag) == 4)
        story_dialogue_4(game);
    if ((*flag) == 5) {
        story_dialogue_5(game);
        sfMusic_stop(game->ost.panic);
        sfMusic_play(game->ost.main_theme);
        (*flag) += 1;
    }
    if ((*flag) == 6)
        story_dialogue_5(game);
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
        *flag = 7;
    if ((*flag) == 0)
        story_dialogue_1(game);
    if ((*flag) == 1) {
        story_dialogue_2(game);
        sfMusic_stop(game->ost.main_theme);
        sfMusic_play(game->ost.panic);
        (*flag) += 1;
    }
    event_2(game, flag);
}

int story_paper_interaction(game_t *game)
{
    sfTime time = {0};
    int flag = 0;

    if (game == NULL)
        return FAILURE;
    sfRenderWindow_setView(game->window.window, game->views.ui);
    sfSprite_setTextureRect(game->dialogue.portrait,
    (sfIntRect){1024 * 1, 0, 1024, 1440});
    while (flag < 7 && sfRenderWindow_isOpen(game->window.window) == sfTrue) {
        time = sfClock_getElapsedTime(game->window.game_clock);
        if (sfTime_asSeconds(time) > 0.2) {
            events(game, &flag);
            display_interaction(game);
            sfClock_restart(game->window.game_clock);
        }
    }
    game->inventory.key = true;
    return SUCCESS;
}
