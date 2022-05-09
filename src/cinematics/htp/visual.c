/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** visual
*/

#include "rpg.h"

static int display_elements_for_view(game_t *game)
{
    sfEvent event = {0};

    if (!game)
        return FAILURE;
    sfRenderWindow_clear(game->window.window, sfBlack);
    sfRenderWindow_setView(game->window.window, game->views.normal);
    draw_map(game, game->htp.map);
    display_provisor_before(game);
    display_mc(&game->entities.mc, game->window.window);
    display_provisor_after(game);
    sfRenderWindow_display(game->window.window);
    while (sfRenderWindow_pollEvent(game->window.window, &event))
        close_window(game, event);
    return SUCCESS;
}

int set_situation(game_t *game)
{
    sfVector2f pos;
    sfVector2f move = {0, 5};
    sfVector2f present_provisor = {-5, 0};

    if (!game)
        return FAILURE;
    pos = sfSprite_getPosition(game->entities.mc.sprite);
    sfView_setCenter(game->views.normal, (sfVector2f){pos.x, pos.y - 500});
    for (double y = pos.y - 510; y < pos.y; y += 5) {
        sfView_move(game->views.normal, move);
        display_elements_for_view(game);
    }
    for (double x = pos.x; x > pos.x - 450; x -= 5) {
        sfView_move(game->views.normal, present_provisor);
        display_elements_for_view(game);
    }
    change_cinematics(&game->htp);
    return SUCCESS;
}
