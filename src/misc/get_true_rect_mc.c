/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** get_true_rect_mc
*/

#include "rpg.h"

sfFloatRect get_true_rect_mc(sfSprite *mc)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(mc);

    rect.height = (rect.height / 3);
    rect.top -= rect.height * 2;
    return rect;
}

sfFloatRect get_true_rect_npc(sfCircleShape *mc)
{
    sfFloatRect rect = sfCircleShape_getGlobalBounds(mc);

    rect.height = (rect.height / 3);
    rect.top -= rect.height * 2;
    return rect;
}
