/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** story_explanation
*/

#include <SFML/Graphics.h>
#include "rpg.h"
#include "my.h"

static char * const explanation[] = {
    "Hello good sir, welcome to your new nightmare.\n",
    "I can't say I hoped someone would find their way here again, but let me \
at least teach you how to survive\n",
    "You'll learn how to navigate in this cursed school, and hopefully free \
yourself\n",
    "...\n",
    "Let's get you started then.\n",
    "If you choose to try to survive, you'll have to fight with numerous \
enemies.\n",
    "The model will be the worst, you can't kill him (or can you?)\n",
    "And one attack of them will wipe you instantly\n",
    NULL
};

static int display_corresponding_text(game_t *game, int i)
{
    float pos_y = 0.0;
    sfVector2f text_pos = {0};

    if (!game || !i)
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

int story_explanation(game_t *game)
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
