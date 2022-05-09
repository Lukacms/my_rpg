/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** init_skill_tree
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg.h"

static int init_backtext(stat_t *stats, game_t *game)
{
    if (!(stats->back = init_text(game->start_menu.menu_font,
    (sfVector2f){50, 900}, "BACK")))
        return FAILURE;
    sfText_setColor(stats->back, sfWhite);
    return SUCCESS;
}

static int init_skill_elements(stat_t *stats)
{
    if (!(stats->tex_background = sfTexture_createFromFile(SKILLS, NULL)))
        return FAILURE;
    if (!(stats->spr_background = sfSprite_create()))
        return FAILURE;
    sfSprite_setTexture(stats->spr_background, stats->tex_background, sfTrue);
    stats->len_skill = 2;
    stats->cooldown = NULL;
    stats->damage = NULL;
    stats->health = NULL;
    stats->speed = NULL;
    return SUCCESS;
}

static int add_all_node(game_t *game)
{
    if (add_skillnode(&game->stats.speed, (sfVector2f){124, 431}))
        return FAILURE;
    if (add_skillnode(&game->stats.speed, (sfVector2f){124, 588}))
        return FAILURE;
    if (add_skillnode(&game->stats.damage, (sfVector2f){229, 431}))
        return FAILURE;
    if (add_skillnode(&game->stats.damage, (sfVector2f){229, 588}))
        return FAILURE;
    if (add_skillnode(&game->stats.health, (sfVector2f){333, 431}))
        return FAILURE;
    if (add_skillnode(&game->stats.health, (sfVector2f){333, 588}))
        return FAILURE;
    if (add_skillnode(&game->stats.cooldown, (sfVector2f){439, 431}))
        return FAILURE;
    if (add_skillnode(&game->stats.cooldown, (sfVector2f){439, 588}))
        return FAILURE;
    return SUCCESS;
}

int init_skill_tree(game_t *game)
{
    if (!game)
        return FAILURE;
    if (init_skill_elements(&game->stats) != SUCCESS)
        return FAILURE;
    if (add_all_node(game) != SUCCESS)
        return FAILURE;
    if (init_backtext(&game->stats, game) == FAILURE)
        return FAILURE;
    if (init_stats(&game->stats, game) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
