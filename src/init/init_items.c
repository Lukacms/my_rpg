/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** init_items
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg.h"
#include "my.h"

static const item_struct_t items[] = {
    {{-0.5, 73.3}, KEY},
    {{39, 3.5}, STORY_PAPER},
    {{155, 100}, KEY},
    {{81, 68}, KEY},
    {{84, 55}, KEY},
    {{43, 9}, MADNESS_POTION},
    {{85, 80}, HEALTH_POTION},
    {{192, 50}, HEAD_PUPPET},
    {{193, 12}, BODY_PUPPET},
    {{0, 40}, MAGIC_ATTACK},
    {{-1, -1}, -1}
};

static item_node_t *create_item_node(sfVector2f pos, int type,
sfTexture *texture)
{
    item_node_t *node = malloc(sizeof(item_node_t));

    if (!node)
        return NULL;
    node->pos.x = 1920 / 2 + (pos.x * 48);
    node->pos.y = 1080 / 2 + (pos.y * 48);
    node->type = type;
    node->taken = false;
    node->sprite = sfSprite_create();
    if (!node->sprite)
        return NULL;
    sfSprite_setTexture(node->sprite, texture, sfTrue);
    sfSprite_setTextureRect(node->sprite, (sfIntRect){0, 0, 48, 48});
    sfSprite_setPosition(node->sprite, node->pos);
    return node;
}

static int create_items(game_t *game, int len)
{
    for (int i = 0; items[i].type != -1; i += 1) {
        if (items[i].type == STORY_PAPER)
            game->items.items[i] = create_item_node(items[i].pos, items[i].type,
            game->items.paper);
        else
            game->items.items[i] = create_item_node(items[i].pos, items[i].type,
            game->items.sparkle);
    }
    game->items.items[len] = NULL;
    for (int i = 0; i < len; i += 1) {
        if (game->items.items[i] == NULL)
            return FAILURE;
    }
    return SUCCESS;
}

int init_items(game_t *game)
{
    int i = 0;

    for (; items[i].type != -1; i += 1);
    game->items.items = malloc((sizeof(item_node_t *) * (i + 1)));
    game->items.sparkle = sfTexture_createFromFile(SPARKLE, NULL);
    game->items.paper = sfTexture_createFromFile(PAPER, NULL);
    if (!game->items.sparkle || !game->items.paper)
        return FAILURE;
    if (!game->items.items)
        return FAILURE;
    game->items.clock = sfClock_create();
    return create_items(game, i);
}
