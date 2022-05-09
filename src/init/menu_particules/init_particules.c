/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** init_particules
*/

#include <SFML/Graphics.h>
#include "rpg.h"

int init_particules(start_menu_t *menu)
{
    if (!menu)
        return FAILURE;
    menu->pop = &del_node;
    menu->add = &add_particule_node;
    menu->head = NULL;
    menu->size = 0;
    if (!(menu->clock = sfClock_create()))
        return FAILURE;
    return SUCCESS;
}
