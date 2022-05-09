/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** move_model.c
*/

#include "rpg.h"

static sfVector2f sec_move_infected(sfFloatRect tmp, sfFloatRect tmp2,
sfVector2f pos, sfIntRect *temp_rect)
{
    if (tmp.top > tmp2.top && (tmp.top - tmp2.top >= tmp.left - tmp2.left)
    && (tmp.top - tmp2.top >= tmp2.left - tmp.left)) {
        pos.y += 24;
        (*temp_rect) = (sfIntRect){0, 624, 24, 48};
    }
    if (tmp.top < tmp2.top && (tmp2.top - tmp.top >= tmp.left - tmp2.left)
    && (tmp2.top - tmp.top >= tmp2.left - tmp.left)) {
        pos.y -= 24;
        (*temp_rect) = (sfIntRect){0, 576, 24, 48};
    }
    return pos;
}

sfVector2f move_infected(sfFloatRect tmp, sfFloatRect tmp2, sfVector2f pos,
enemies_t *enemy)
{
    sfIntRect temp_rect = sfSprite_getTextureRect(enemy->sprite);

    if (tmp.left > tmp2.left && (tmp.left - tmp2.left >= tmp.top - tmp2.top)
    && (tmp.left - tmp2.left >= tmp2.top - tmp.top)) {
        pos.x += 24;
        temp_rect = (sfIntRect){0, 672, 24, 48};
    }
    if (tmp.left < tmp2.left && (tmp2.left - tmp.left >= tmp.top - tmp2.top)
    && (tmp2.left - tmp.left >= tmp2.top - tmp.top)) {
        pos.x -= 24;
        temp_rect = (sfIntRect){0, 720, 24, 48};
    }
    pos = sec_move_infected(tmp, tmp2, pos, &temp_rect);
    sfSprite_setTextureRect(enemy->sprite, temp_rect);
    return pos;
}
