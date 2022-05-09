/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** display_skill_tree
*/

#include <stdbool.h>
#include <SFML/Graphics.h>
#include "rpg.h"
#include "my.h"

static int draw_stats(game_t *game)
{
    if (!game)
        return FAILURE;
    sfText_setString(game->stats.stats_obj[0].value,
    my_int_to_str(game->stats.stats_obj[0].nb_value));
    sfText_setString(game->stats.stats_obj[1].value,
    my_int_to_str(game->stats.stats_obj[1].nb_value));
    sfText_setString(game->stats.stats_obj[2].value,
    my_int_to_str(game->stats.stats_obj[2].nb_value));
    sfText_setString(game->stats.stats_obj[3].value,
    my_int_to_str(game->stats.stats_obj[3].nb_value));
    sfText_setString(game->stats.v_xp,
    my_int_to_str(game->stats.xp));
    for (int i = 0; i < 4; i++) {
        sfRenderWindow_drawText(game->window.window,
        game->stats.stats_obj[i].value, NULL);
        sfRenderWindow_drawText(game->window.window,
        game->stats.stats_obj[i].text_stats, NULL);
    }
    sfRenderWindow_drawText(game->window.window, game->stats.t_xp, NULL);
    sfRenderWindow_drawText(game->window.window, game->stats.v_xp, NULL);
    return SUCCESS;
}

int display_skill_tree(game_t *game)
{
    if (!game)
        return FAILURE;
    sfRenderWindow_setView(game->window.window, game->views.ui);
    sfRenderWindow_drawSprite(game->window.window, game->stats.spr_background,
        NULL);
    if (display_skill(game) == FAILURE)
        return FAILURE;
    if (draw_stats(game) == FAILURE)
        return FAILURE;
    sfRenderWindow_drawText(game->window.window, game->stats.back, NULL);
    return SUCCESS;
}
