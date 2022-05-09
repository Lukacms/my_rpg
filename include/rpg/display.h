/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** display
*/

#ifndef DISPLAY_H_
    #define DISPLAY_H_

    #include <SFML/Graphics.h>
    #include "rpg/game.h"

int display_menu(game_t *game);
int display_game(game_t *game);
int display_skill_tree(game_t *game);
int display_pause(game_t *game);
int display_inventory(game_t *game);
int display_characters(game_t *game);
int display_slots(game_t *game);
int display_npc(game_t *game);
int animate_npc(game_t *game);
int animate_characters(game_t *game, sfIntRect *rect, int top);
void set_circle_npc(game_t *game);
int display_settings(game_t *game);
int display_selected_mode(game_t *game, sfVector2i mouse);
int display_settings_mode_audio(game_t *game, sfVector2i mouse);
int display_settings_mode_controls(game_t *game, sfVector2i mouse);
int display_settings_mode_graphics(game_t *game, sfVector2i mouse);
int animate_mc(character_node_t *mc);
int display_mc(character_node_t *mc, sfRenderWindow *window);
int display_pixels(game_over_t *over, game_t *game);
int display_htp(game_t *game);
int display_provisor_after(game_t *game);
int display_provisor_before(game_t *game);
int display_skater(game_t *game, sfIntRect *rect_skater);
int display_girl(game_t *game, sfIntRect *rect_girl);
int display_blond(game_t *game, sfIntRect *rect_blond);
int display_satoshi(game_t *game, sfIntRect *rect_satoshi);
int draw_fog(game_maps_t *maps, game_t *game);
int draw_particules(start_menu_t *menu, sfRenderWindow *window);
int display_loading_screen(game_t *game);

int destroy_resources(game_t *game);
int destroy_pause(pause_menu_t *pause_menu);

#endif /* !DISPLAY_H_ */
