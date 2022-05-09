/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** display_game
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg.h"

static int game_events(game_t *game)
{
    if (!game)
        return FAILURE;
    idle_move(game);
    enemy_hit(game);
    set_circles(game);
    go_to_game_over(game);
    plank_collapse(game);
    fireball_loop(game);
    ghost_sound(game);
    pursuit_model(game);
    new_room_model(game);
    view_items(game);
    sachiko_ending(game);
    npc_interact(game);
    npc2_interact(game);
    npc3_interact(game);
    npc4_interact(game);
    return SUCCESS;
}

static void animate_and_events(game_t *game)
{
    animate_items(game->items);
    animate_enemies(game);
    game_events(game);
}

int display_game(game_t *game)
{
    if (!game)
        return FAILURE;
    render_views(game);
    draw_map(game, game->maps->map);
    display_npc_before(game);
    display_corpses_before(game);
    draw_items(game);
    display_enemies_before(game);
    display_mc(&game->entities.mc, game->window.window);
    display_corpses_after(game);
    display_enemies_after(game);
    display_fireball(game);
    animate_fireball(game);
    display_npc_after(game);
    draw_fog(game->maps, game);
    display_gui(game);
    animate_and_events(game);
    return SUCCESS;
}
