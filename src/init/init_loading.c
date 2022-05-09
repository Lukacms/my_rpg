/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** init_loading
*/

#include "rpg.h"

int init_load(start_menu_t *menu, sfVector2u wdw_size)
{
    sfVector2f pos = {wdw_size.x / 2.0 - 100, wdw_size.y / 2.0};
    sfVector2f size = {17, 30};

    if (!(menu->loading = init_text(menu->menu_font, pos,
    "Loading\n")))
        return FAILURE;
    if (!(menu->load = sfRectangleShape_create()))
        return FAILURE;
    pos.y += 100;
    sfRectangleShape_setFillColor(menu->load, sfWhite);
    sfRectangleShape_setPosition(menu->load, pos);
    sfRectangleShape_setSize(menu->load, size);
    return SUCCESS;
}
