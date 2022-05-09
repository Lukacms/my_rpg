/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** moving_cam
*/

#include "rpg.h"

static void display_elements_for_view(game_t *game)
{
    sfRenderWindow_clear(game->window.window, sfBlack);
    sfRenderWindow_setView(game->window.window, game->views.normal);
    draw_map(game, game->maps->map);
    display_corpses_before(game);
    display_enemies_before(game);
    draw_items(game);
    display_mc(&game->entities.mc, game->window.window);
    display_enemies_after(game);
    display_corpses_after(game);
    animate_items(game->items);
    sfRenderWindow_display(game->window.window);
}

void moving_cam(game_t *game)
{
    sfVector2f pos = sfSprite_getPosition(game->entities.mc.sprite);
    sfVector2f move = {0, 10};

    for (double y = pos.y; y < 3400; y += 5) {
        move.x = 0;
        if (pos.x > 5160 && pos.x > 5130)
            move.x = -2;
        if (pos.x < 5100 && pos.x < 5130)
            move.x = 2;
        sfView_move(game->views.normal, move);
        display_elements_for_view(game);
    }
}
