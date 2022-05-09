/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** display_skill
*/

#include "rpg.h"

static int display_skill_list_speed(skill_node_t *head, int len, game_t *game)
{
    skill_node_t *tmp = head;

    if (!tmp || !game)
        return FAILURE;
    for (int i = 0; i < len; i++) {
        if (game->inventory.full_puppet == true) {
            sfCircleShape_setFillColor(tmp->circle, sfGreen);
            tmp->acquired = true;
        }
        sfRenderWindow_drawCircleShape(game->window.window, tmp->circle, NULL);
        tmp = tmp->next;
    }
    return SUCCESS;
}

static int display_skill_list_atk(skill_node_t *head, int len, game_t *game)
{
    skill_node_t *tmp = head;

    if (!tmp || !game)
        return FAILURE;
    for (int i = 0; i < len; i++) {
        if (game->inventory.head_puppet == true ||
        game->inventory.full_puppet == true) {
            sfCircleShape_setFillColor(tmp->circle, sfGreen);
            tmp->acquired = true;
        }
        sfRenderWindow_drawCircleShape(game->window.window, tmp->circle, NULL);
        tmp = tmp->next;
    }
    return SUCCESS;
}

static int display_skill_list_cool(skill_node_t *head, int len, game_t *game)
{
    skill_node_t *tmp = head;

    if (!tmp || !game)
        return FAILURE;
    for (int i = 0; i < len; i++) {
        if (game->stats.npc_kill == true) {
            sfCircleShape_setFillColor(tmp->circle, sfGreen);
            tmp->acquired = true;
        }
        sfRenderWindow_drawCircleShape(game->window.window, tmp->circle, NULL);
        tmp = tmp->next;
    }
    return SUCCESS;
}

static int display_skill_list_life(skill_node_t *head, int len, game_t *game)
{
    skill_node_t *tmp = head;

    if (!tmp || !game)
        return FAILURE;
    for (int i = 0; i < len; i++) {
        if (game->inventory.body_puppet == true ||
        game->inventory.full_puppet == true) {
            sfCircleShape_setFillColor(tmp->circle, sfGreen);
            tmp->acquired = true;
        }
        sfRenderWindow_drawCircleShape(game->window.window, tmp->circle, NULL);
        tmp = tmp->next;
    }
    return SUCCESS;
}

int display_skill(game_t *game)
{
    display_skill_list_atk(game->stats.damage, 2, game);
    display_skill_list_cool(game->stats.cooldown, 2, game);
    display_skill_list_life(game->stats.health, 2, game);
    display_skill_list_speed(game->stats.speed, 2, game);
    return SUCCESS;
}
