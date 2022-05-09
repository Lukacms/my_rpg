/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** display_plank_interaction
*/

#include <SFML/Graphics.h>
#include "rpg.h"

static int display_ui(game_t *game)
{
    sfRenderWindow_drawSprite(game->window.window, game->dialogue.portrait,
    NULL);
    sfRenderWindow_drawSprite(game->window.window, game->dialogue.textbox,
    NULL);
    return SUCCESS;
}

static void display_interact_ui(game_t *game)
{
    sfRenderWindow_setView(game->window.window, game->views.ui);
    display_ui(game);
    animate_items(game->items);
    sfRenderWindow_drawText(game->window.window, game->dialogue.text, NULL);
    sfRenderWindow_setView(game->window.window, game->views.normal);
    sfRenderWindow_display(game->window.window);
}

static void display_npc_interaction(game_t *game)
{
    sfRenderWindow_drawSprite(game->window.window,
    game->entities.sachiko->sprite_npc, NULL);
    sfRenderWindow_drawSprite(game->window.window,
    game->entities.npc[0]->sprite_npc, NULL);
    sfRenderWindow_drawSprite(game->window.window,
    game->entities.npc[1]->sprite_npc, NULL);
    sfRenderWindow_drawSprite(game->window.window,
    game->entities.npc[2]->sprite_npc, NULL);
    sfRenderWindow_drawSprite(game->window.window,
    game->entities.npc[3]->sprite_npc, NULL);
}

int display_interaction(game_t *game)
{
    if (!game)
        return FAILURE;
    sfRenderWindow_clear(game->window.window, sfBlack);
    draw_map(game, game->maps->map);
    display_corpses_before(game);
    display_enemies_before(game);
    draw_items(game);
    display_mc(&game->entities.mc, game->window.window);
    display_enemies_after(game);
    display_corpses_after(game);
    display_npc_interaction(game);
    display_interact_ui(game);
    return SUCCESS;
}
