/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** move_mc.c
*/

#include <stdlib.h>
#include <stdbool.h>
#include "rpg.h"

static void set_particule_pos(character_node_t *mc, sfVector2f move)
{
    particule_node_t *node = mc->particules.head;
    sfVector2f pos = sfSprite_getPosition(mc->sprite);

    for (unsigned int i = 0; i < mc->particules.size; i++) {
        sfRectangleShape_setPosition(node->pixel, (sfVector2f){
            pos.x + move.x + rand() % 25, pos.y + move.y + rand() % 25});
        node = node->next;
    }
    mc->display_particules = true;
}

static void animate(character_node_t *mc, game_t *game, int code,
sfIntRect mc_rect)
{
    mc_rect.top = mc->states_mc;
    if (code == game->key.up || code == game->key.down ||
    code == game->key.right || code == game->key.left)
        mc_rect.left = animate_mc(mc);
    sfSprite_setTextureRect(mc->sprite, mc_rect);
}

static void move_character_sec(character_node_t *mc, game_t *game, int code,
sfIntRect mc_rect)
{
    if (sfKeyboard_isKeyPressed(game->key.left) == sfTrue) {
        check_type_left(mc);
        if (hitbox_left(mc->sprite, game, code) == SUCCESS
            && is_collide_corpses_left(game) != SUCCESS) {
            sfSprite_move(mc->sprite,
            (sfVector2f){game->stats.stats_obj[3].nb_value * -1, 0});
            set_particule_pos(mc, (sfVector2f){30, 65});
        }
    }
    if (sfKeyboard_isKeyPressed(game->key.right) == sfTrue) {
        check_type_right(mc);
        if (hitbox_right(mc->sprite, game, code) == SUCCESS
            && is_collide_corpses_right(game) != SUCCESS) {
            sfSprite_move(mc->sprite,
            (sfVector2f){game->stats.stats_obj[3].nb_value, 0});
            set_particule_pos(mc, (sfVector2f){-10, 65});
        }
    }
    animate(mc, game, code, mc_rect);
}

int move_character(character_node_t *mc, game_t *game, int code)
{
    sfIntRect mc_rect = sfSprite_getTextureRect(mc->sprite);

    if (sfKeyboard_isKeyPressed(game->key.up) == sfTrue) {
        check_type_back(mc);
        if (hitbox_up(mc->sprite, game, code) == SUCCESS
            && is_collide_corpses_up(game) != SUCCESS) {
            sfSprite_move(mc->sprite,
            (sfVector2f){0, game->stats.stats_obj[3].nb_value * -1});
            set_particule_pos(mc, (sfVector2f){10, 90});
        }
    }
    if (sfKeyboard_isKeyPressed(game->key.down) == sfTrue) {
        check_type_front(mc);
        if (hitbox_down(mc->sprite, game, code) == SUCCESS
            && is_collide_corpses_down(game) != SUCCESS)
            sfSprite_move(mc->sprite,
            (sfVector2f){0, game->stats.stats_obj[3].nb_value});
    }
    move_character_sec(mc, game, code, mc_rect);
    return SUCCESS;
}
