/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** learn_keys
*/

#include <SFML/Graphics.h>
#include "rpg.h"
#include "my.h"

static char * const explanation[] = {
    "Okay...\n",
    "I hope you will be able to get yourself out of here, but you'll need all \
the assets possible.\n",
    "To pause the game, simply press [P].\n",
    "The inventory will be with the [I] key.\n",
    "...\n",
    "Dont't forget that you can change the binded keys in the pause menu.\n",
    "And to fight, which you don't need here, will be with the [X] key.\n",
    "Well...\n",
    "I don't have anything more to say.\n",
    "I hope you'll be the first to survive this damned place.\n",
    "Goodbye, young man.\n",
    NULL
};

static void display_corresponding_text(game_t *game, int i)
{
    float pos_y = game->window.wdw_size.y;
    sfVector2f text_pos = {40, pos_y - (pos_y / 10)};

    sfText_setPosition(game->htp.text, text_pos);
    text_pos.x = 0;
    sfSprite_setPosition(game->dialogue.textbox, text_pos);
    sfText_setString(game->htp.text, explanation[i]);
    sfRenderWindow_drawSprite(game->window.window,
        game->dialogue.textbox, NULL);
    sfRenderWindow_drawText(game->window.window, game->htp.text, NULL);
}

int learn_keys(game_t *game)
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
