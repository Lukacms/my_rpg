/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** learn_moves
*/

#include <SFML/Graphics.h>
#include "rpg.h"

static char * const explanation[] = {
    "First, how to navigate in this horrendous world.\n",
    "Of course, all the keys listed will be able to be changed later\n\
but learn the basics first.\n",
    "To move, use the arrow keys:\n\
left to go to your left, up to go upward...",
    "Try it for yourself !",
    "Good, good, now I will explain what actions you will be able to do \
when you will be in the game.\n",
    "Oh, and if you don't want this tutorial, simply press [Enter] to skip it.\
\n",
    NULL
};

static int display_corresponding_text(game_t *game, int i)
{
    float pos_y = 0.0f;
    sfVector2f text_pos;

    if (!game)
        return FAILURE;
    pos_y = game->window.wdw_size.y;
    text_pos = (sfVector2f){40, pos_y - (pos_y / 10)};
    sfText_setPosition(game->htp.text, text_pos);
    text_pos.x = 0;
    sfSprite_setPosition(game->dialogue.textbox, text_pos);
    sfText_setString(game->htp.text, explanation[i]);
    sfRenderWindow_drawSprite(game->window.window,
        game->dialogue.textbox, NULL);
    sfRenderWindow_drawText(game->window.window, game->htp.text, NULL);
    return SUCCESS;
}

int learn_moves(game_t *game)
{
    static int i = 0;
    sfTime time = {0};

    if (!game)
        return FAILURE;
    time = sfClock_getElapsedTime(game->htp.clock);
    if (game->htp.next == true) {
        i += 1;
        game->htp.next = false;
        sfClock_restart(game->htp.clock);
    }
    display_corresponding_text(game, i);
    if (sfTime_asSeconds(time) > 5.0) {
        sfClock_restart(game->htp.clock);
        i += 1;
    }
    if (!explanation[i])
        change_cinematics(&game->htp);
    return SUCCESS;
}
