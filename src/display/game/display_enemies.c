/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** display_enemies
*/

#include "rpg.h"

int display_enemies_after(game_t *game)
{
    enemies_t *tmp = NULL;

    if (!game)
        return FAILURE;
    tmp = game->entities.enemies.head;
    for (unsigned int i = 0; i < game->entities.enemies.size; i += 1) {
        if (is_above_or_ahead(game->entities.mc, tmp) == true
            && tmp->hidden == false)
            sfRenderWindow_drawSprite(game->window.window, tmp->sprite, NULL);
        tmp = tmp->next;
    }
    return SUCCESS;
}

int display_enemies_before(game_t *game)
{
    enemies_t *tmp = NULL;

    if (!game)
        return FAILURE;
    tmp = game->entities.enemies.head;
    for (unsigned int i = 0; i < game->entities.enemies.size; i += 1) {
        if (is_above_or_ahead(game->entities.mc, tmp) == false
            && tmp->hidden == false)
            sfRenderWindow_drawSprite(game->window.window, tmp->sprite, NULL);
        tmp = tmp->next;
    }
    return SUCCESS;
}

int display_npc_before(game_t *game)
{
    if (!game)
        return FAILURE;
    for (int index = 0; index < 4; index ++) {
        if (is_above_or_ahead_npc(game->entities.mc,
            game->entities.npc[index]) == false) {
            sfRenderWindow_drawCircleShape(game->window.window,
            game->entities.npc[index]->vision_npc, NULL);
            sfRenderWindow_drawSprite(game->window.window,
            game->entities.npc[index]->sprite_npc, NULL);
        }
    }
    sfRenderWindow_drawSprite(game->window.window,
                            game->entities.sachiko->sprite_npc, NULL);
    return SUCCESS;
}

int display_npc_after(game_t *game)
{
    if (!game)
        return FAILURE;
    for (int index = 0; index < 4; index ++) {
        if (is_above_or_ahead_npc(game->entities.mc,
            game->entities.npc[index]) == true) {
            sfRenderWindow_drawCircleShape(game->window.window,
            game->entities.npc[index]->vision_npc, NULL);
            sfRenderWindow_drawSprite(game->window.window,
            game->entities.npc[index]->sprite_npc, NULL);
        }
    }
    return SUCCESS;
}
