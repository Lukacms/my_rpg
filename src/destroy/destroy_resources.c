/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** free_enemy_list
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg.h"

static void destroy_views(views_t *views)
{
    if (!views)
        return;
    sfView_destroy(views->normal);
    sfView_destroy(views->ui);
}

static int destroy_sfx(sfx_t *sfx)
{
    if (!sfx)
        return FAILURE;
    sfSound_destroy(sfx->sfx);
    sfSoundBuffer_destroy(sfx->b_items);
    sfSoundBuffer_destroy(sfx->b_door);
    sfSoundBuffer_destroy(sfx->b_start);
    sfSoundBuffer_destroy(sfx->b_over);
    sfSoundBuffer_destroy(sfx->b_wood);
    sfSoundBuffer_destroy(sfx->b_fire);
    sfSoundBuffer_destroy(sfx->b_click);
    sfSoundBuffer_destroy(sfx->b_laught);
    return SUCCESS;
}

static void destroy_game(game_t *game)
{
    destroy_character_menu(&game->characters);
    destroy_entities(&game->entities);
    destroy_fireball(&game->fireball);
    destroy_dialogue(&game->dialogue);
    destroy_tilemap(game->tilemap);
    destroy_maps(game->maps);
    destroy_views(&game->views);
    destroy_stats(&game->stats);
    destroy_gui(&game->gui);
    destroy_musics(&game->ost);
    destroy_ending(&game->ending);
    destroy_htp(&game->htp);
}

int destroy_resources(game_t *game)
{
    if (!game)
        return FAILURE;
    destroy_menu(&game->start_menu);
    destroy_pause(&game->pause_menu);
    destroy_settings(&game->settings_menu);
    destroy_sfx(&game->sfx);
    sfClock_destroy(game->window.game_clock);
    sfRenderWindow_destroy(game->window.window);
    destroy_game_over(&game->game_over);
    destroy_inventory(&game->inventory);
    destroy_corpses(&game->corpses);
    destroy_items(&game->items);
    destroy_game(game);
    return SUCCESS;
}
