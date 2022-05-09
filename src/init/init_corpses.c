/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** init_corpses
*/

#include <stdlib.h>
#include "rpg.h"

static const corpse_struct_t corpses[] = {
    {{42, 7}, {24 * 0, 48 * 0, 24, 48}, NO_WALK, false},
    {{3, 61}, {24 * 3, 48 * 1, 24, 48}, NO_WALK, false},
    {{35, 67}, {24 * 6, 48 * 1, 24, 48}, WALK_BEHIND, false},
    {{11, 70}, {24 * 6, 48 * 0, 24, 48}, WALK_BEHIND, false},
    {{32, 95}, {24 * 5, 48 * 1, 24, 48}, NO_WALK, false},
    {{82, 50}, {24 * 1, 48 * 1, 24, 48}, NO_WALK, false},
    {{84, 67}, {24 * 6, 48 * 1, 24, 48}, WALK_BEHIND, false},
    {{128, 32}, {24 * 2, 48 * 1, 24, 48}, NO_WALK, false},
    {{130, 30}, {24 * 6, 48 * 0, 24, 48}, WALK_BEHIND, false},
    {{20, 203}, {24 * 6, 48 * 0, 24, 48}, WALK_BEHIND, false},
    {{192, 16}, {24 * 6, 48 * 0, 24, 48}, WALK_BEHIND, true},
    {{202, 12}, {24 * 2, 48 * 1, 24, 48}, NO_WALK, true},
    {{-1, -1}, {-1, -1, -1, -1}, -1, false}
};

static corpse_node_t *create_corpse(sfVector2f pos, sfTexture *texture,
                                    sfIntRect rect, int type)
{
    corpse_node_t *node = malloc(sizeof(corpse_node_t));

    if (!node)
        return NULL;
    node->pos.x = 1920 / 2 + (pos.x * 48);
    node->pos.y = 1080 / 2 + (pos.y * 48);
    node->type = type;
    node->sprite = sfSprite_create();
    if (!node->sprite)
        return NULL;
    sfSprite_setTexture(node->sprite, texture, sfTrue);
    sfSprite_setTextureRect(node->sprite, rect);
    sfSprite_setPosition(node->sprite, node->pos);
    sfSprite_setScale(node->sprite, (sfVector2f){2, 2});
    return node;
}

static int create_corpses(game_t *game, int len)
{
    for (int i = 0; corpses[i].type != -1; i += 1) {
        game->corpses.corpses[i] = create_corpse(corpses[i].pos,
        game->corpses.texture, corpses[i].rect, corpses[i].type);
        game->corpses.corpses[i]->script_room_model =
        corpses[i].script_room_model;
    }
    game->corpses.corpses[len] = NULL;
    for (int i = 0; i < len; i += 1) {
        if (game->corpses.corpses[i] == NULL)
            return FAILURE;
    }
    return SUCCESS;
}

int init_corpses(game_t *game)
{
    int i = 0;

    for (; corpses[i].type != -1; i += 1);
    game->corpses.corpses = malloc((sizeof(corpse_node_t *) * (i + 1)));
    game->corpses.texture = sfTexture_createFromFile(CORPSES, NULL);
    if (!game->corpses.corpses || !game->corpses.texture)
        return FAILURE;
    return create_corpses(game, i);
}
