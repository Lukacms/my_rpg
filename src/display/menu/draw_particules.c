/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** draw_particules
*/

#include <sys/types.h>
#include <SFML/Graphics.h>
#include "rpg.h"

int draw_particules(start_menu_t *menu, sfRenderWindow *window)
{
    particule_node_t *node = NULL;

    if (!menu || !(node = menu->head))
        return FAILURE;
    for (u_int i = 0; i < menu->size; i++) {
        sfRenderWindow_drawRectangleShape(window, node->pixel, NULL);
        move_particule(node, menu);
        node = node->next;
    }
    return FAILURE;
}
