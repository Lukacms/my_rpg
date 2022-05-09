/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** view_items
*/

#include"rpg.h"

static bool is_good_place(game_t *game)
{
    int flag = 0;
    sfVector2f pos = sfSprite_getPosition(game->entities.mc.sprite);

    if (pos.x >= 4810 && pos.x <= 5490)
        flag += 1;
    if (pos.y >= 2980 && pos.y <= 3040)
        flag += 1;
    if (flag == 2)
        return true;
    return false;
}

void view_items(game_t *game)
{
    if (is_good_place(game) == false || game->scripts.view_items == true)
        return;
    item_view_loop(game);
}
