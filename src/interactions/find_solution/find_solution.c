/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** find_solution
*/

#include <SFML/Graphics.h>
#include "rpg.h"

static char * const dialogue[] = {
    "Hey, so you've managed to stay alive until here...\n",
    "Good job, but you'll need more help to get out of here.\n",
    "Well...\n",
    "Sachiko, the ghost, she needs to be appeased.\n",
    "I've read that in order to do that, you must say:\n\
'Sachiko, WE beg you'\n",
    "And repeat this for every one in the room, including her.\n",
    "Now, please go and appease her, you're our only hope\n",
    NULL
};

static void display_elements(game_t *game)
{
    sfRenderWindow_clear(game->window.window, sfBlack);
    draw_map(game, game->maps->map);
    display_corpses_before(game);
    display_enemies_before(game);
    draw_items(game);
    display_mc(&game->entities.mc, game->window.window);
    sfRenderWindow_drawSprite(game->window.window,
        game->entities.npc[1]->sprite_npc, NULL);
    display_enemies_after(game);
    display_corpses_after(game);
    sfRenderWindow_drawSprite(game->window.window,
                                game->entities.sachiko->sprite_npc, NULL);
    sfRenderWindow_setView(game->window.window, game->views.ui);
    sfRenderWindow_drawSprite(game->window.window, game->dialogue.textbox,
        NULL);
    animate_items(game->items);
    sfRenderWindow_drawText(game->window.window, game->dialogue.text, NULL);
    sfRenderWindow_setView(game->window.window, game->views.normal);
    sfRenderWindow_display(game->window.window);
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
    sfText_setString(game->dialogue.text, dialogue[*flag]);
}

void find_solution(game_t *game)
{
    sfTime time = {0};
    int flag = 0;
    sfIntRect npc = {0};

    if (!game)
        return;
    npc = sfSprite_getTextureRect(game->entities.npc[1]->sprite_npc);
    npc.top += 48;
    sfSprite_setTextureRect(game->entities.npc[1]->sprite_npc, npc);
    sfRenderWindow_setView(game->window.window, game->views.ui);
    while (dialogue[flag] && sfRenderWindow_isOpen(game->window.window)) {
        time = sfClock_getElapsedTime(game->window.game_clock);
        if (sfTime_asSeconds(time) > 0.2) {
            events(game, &flag);
            display_elements(game);
            sfClock_restart(game->window.game_clock);
        }
    }
}
