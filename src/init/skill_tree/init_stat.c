/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** init_stat.c
*/

#include "rpg.h"

static int init_text_stats(stat_t *stats, game_t *game)
{
    if (!stats)
        return FAILURE;
    stats->stats_obj[0].nb_value = 150;
    stats->stats_obj[0].value = init_text(game->start_menu.menu_font,
    (sfVector2f){1200, 800}, "");
    stats->stats_obj[0].text_stats = init_text(game->start_menu.menu_font,
    (sfVector2f){800, 800}, "HEALTH");
    stats->stats_obj[1].nb_value = 5;
    stats->stats_obj[1].value = init_text(game->start_menu.menu_font,
    (sfVector2f){1200, 600}, "");
    stats->stats_obj[1].text_stats = init_text(game->start_menu.menu_font,
    (sfVector2f){800, 600}, "MADNESS");
    stats->stats_obj[2].nb_value = 1;
    stats->stats_obj[2].value = init_text(game->start_menu.menu_font,
    (sfVector2f){1200, 200}, "");
    stats->stats_obj[2].text_stats = init_text(game->start_menu.menu_font,
    (sfVector2f){800, 200}, "DAMAGE");
    return SUCCESS;
}

int init_stats(stat_t *stats, game_t *game)
{
    if (stats == NULL)
        return FAILURE;
    if (init_text_stats(stats, game) == FAILURE)
        return FAILURE;
    stats->stats_obj[3].nb_value = 7;
    stats->stats_obj[3].value = init_text(game->start_menu.menu_font,
    (sfVector2f){1200, 400}, "");
    stats->stats_obj[3].text_stats = init_text(game->start_menu.menu_font,
    (sfVector2f){800, 400}, "SPEED");
    stats->xp = 0;
    stats->npc_kill = false;
    stats->t_xp = init_text(game->start_menu.menu_font,
    (sfVector2f){800, 1000}, "XP");
    stats->v_xp = init_text(game->start_menu.menu_font,
    (sfVector2f){1200, 1000}, "");
    if (!stats->stats_obj[0].value || !stats->stats_obj[1].value ||
    !stats->stats_obj[2].value || !stats->stats_obj[3].value ||
    !stats->stats_obj[0].text_stats || !stats->stats_obj[1].text_stats ||
    !stats->stats_obj[2].text_stats || !stats->stats_obj[3].text_stats)
        return FAILURE;
    return SUCCESS;
}
