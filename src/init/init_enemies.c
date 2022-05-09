/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** init_ennemies
*/

#include "rpg.h"

int init_ennemies(game_t *game)
{
    if (!game)
        return FAILURE;
    game->entities.enemies.size = 0;
    game->entities.t_ennemies = sfTexture_createFromFile(ENNEMIES, NULL);
    game->entities.move = sfClock_create();
    game->entities.instant_dead = false;
    if (!game->entities.t_ennemies || !game->entities.move)
        return FAILURE;
    add_node(&game->entities, BAD_FLAMES, (sfVector2f){48 * 134, 48 * 109});
    add_node(&game->entities, BAD_FLAMES, (sfVector2f){48 * 137, 48 * 112});
    add_node(&game->entities, BAD_FLAMES, (sfVector2f){48 * 140, 48 * 109});
    add_node(&game->entities, BAD_FLAMES, (sfVector2f){48 * 155, 48 * 111});
    add_node(&game->entities, GHOST, (sfVector2f){10386, 2880});
    add_node(&game->entities, MODEL, (sfVector2f){13609, 1070});
    add_node(&game->entities, INFECTED, (sfVector2f){5211, 2791});
    add_node(&game->entities, NOT_INFECTED, (sfVector2f){10356, 3400});
    add_node(&game->entities, WARRIOR, (sfVector2f){2655, 716});
    return SUCCESS;
}
