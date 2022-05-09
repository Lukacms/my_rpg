/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** skill_tree_events
*/

#include <SFML/Graphics.h>
#include "rpg.h"

static int text_damage_speed(game_t *game, sfMouseButtonEvent button)
{
    if (!game)
        return FAILURE;
    if (in_text(game->stats.stats_obj[2].text_stats,
    button.x, button.y, game->window.scaling) && game->stats.xp >= 1 &&
    game->stats.stats_obj[2].nb_value < 4) {
        game->stats.stats_obj[2].nb_value += 1;
        game->stats.xp -= 1;
    }
    if (in_text(game->stats.stats_obj[3].text_stats,
    button.x, button.y, game->window.scaling) && game->stats.xp > 1 &&
    game->stats.stats_obj[3].nb_value < 9) {
        game->stats.stats_obj[3].nb_value += 1;
        game->stats.xp -= 1;
    }
    return SUCCESS;
}

static int analyse_skill_tree(game_t *game, sfMouseButtonEvent button)
{
    if (in_text(game->stats.back, button.x, button.y, game->window.scaling))
        game->status = GAME;
    if (in_text(game->stats.stats_obj[0].text_stats,
    button.x, button.y, game->window.scaling) && game->stats.xp >= 1 &&
    game->stats.stats_obj[3].nb_value < 175) {
        game->stats.stats_obj[0].nb_value += 1;
        game->stats.xp -= 1;
    }
    if (in_text(game->stats.stats_obj[1].text_stats,
    button.x, button.y, game->window.scaling) && game->stats.xp >= 1 &&
    game->stats.stats_obj[1].nb_value > 0) {
        game->stats.stats_obj[1].nb_value -= 1;
        game->stats.xp -= 1;
    }
    if (text_damage_speed(game, button) == FAILURE)
        return FAILURE;
    return SUCCESS;
}

static int color_choices(game_t *game, sfMouseMoveEvent button)
{
    sfText_setColor(game->stats.back, sfWhite);
    if (in_text(game->stats.back, button.x, button.y, game->window.scaling))
        sfText_setColor(game->stats.back, sfRed);
    return SUCCESS;
}

int skill_tree_event(game_t *game, sfEvent event)
{
    if (!game)
        return FAILURE;
    if (event.type == sfEvtMouseButtonPressed)
        analyse_skill_tree(game, event.mouseButton);
    else if (event.type == sfEvtMouseMoved)
        color_choices(game, event.mouseMove);
    return FAILURE;
}
