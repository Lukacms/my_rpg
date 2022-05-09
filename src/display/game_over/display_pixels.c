/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** display_pixels
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg.h"
#include "my.h"

int display_pixels(game_over_t *over, game_t *game)
{
    particule_node_t *tmp = NULL;
    sfTime time = {0};

    if (!over)
        return FAILURE;
    tmp = over->particules.head;
    for (unsigned int i = 0; i < over->particules.size; i++) {
        sfRenderWindow_drawRectangleShape(game->window.window,
        tmp->pixel, NULL);
        move_pixel(tmp);
        tmp = tmp->next;
    }
    time = sfClock_getElapsedTime(over->particules.clock);
    if (sfTime_asSeconds(time) > 0.01) {
        over->particules.add(over, (sfVector2f){rand() % 1920, 0});
        sfClock_restart(over->particules.clock);
    }
    return SUCCESS;
}
