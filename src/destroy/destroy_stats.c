/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** destroy_stats
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg.h"

static void free_stat_list(skill_node_t *head, int len)
{
    skill_node_t *anchor = head;
    skill_node_t *tmp = head;

    if (!head)
        return;
    for (int i = 0; i < len; i++) {
        anchor = anchor->next;
        sfCircleShape_destroy(tmp->circle);
        tmp = anchor;
    }
}

void destroy_stats(stat_t *stats)
{
    if (!stats)
        return;
    sfTexture_destroy(stats->tex_background);
    sfSprite_destroy(stats->spr_background);
    sfText_destroy(stats->back);
    sfText_destroy(stats->t_xp);
    sfText_destroy(stats->v_xp);
    free_stat_list(stats->speed, stats->len_skill);
    free_stat_list(stats->damage, stats->len_skill);
    free_stat_list(stats->health, stats->len_skill);
    free_stat_list(stats->cooldown, stats->len_skill);
}
