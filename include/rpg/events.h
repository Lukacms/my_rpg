/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** events
*/

#ifndef EVENTS_H_
    #define EVENTS_H_

    #include <stdbool.h>
    #include <SFML/Graphics.h>
    #include "rpg/game.h"

int analyse_events(game_t *game, sfEvent event);
int analyse_menu_events(game_t *game, sfEvent event);
int analyse_game_events(game_t *game, sfEvent event);
int analyse_characters_events(game_t *game, sfEvent event);
int analyse_pause_events(game_t *game, sfEvent event);
int analyse_inventory_events(game_t *game, sfEvent event);
int analyse_settings_events(game_t *game, sfEvent event);
int analyse_events_mode(game_t *game, sfEvent event);
int analyse_audio_events(game_t *game, sfEvent event);
int analyse_controls_events(game_t *game, sfEvent event);
int analyse_graphics_events(game_t *game, sfEvent event);
int analyse_system_events(game_t *game, sfEvent event);
int analyse_input_events_charact(game_t *game, sfMouseButtonEvent button);
bool in_sprite(sfSprite *text, int x, int y, sfVector2f scaling);
bool in_text(sfText *text, int x, int y, sfVector2f scaling);
int init_window_not_full_screen(game_t *game);
int init_window_full_screen(game_t *game);
int analyse_htp_event(game_t *game, sfEvent Event);
int is_provisor_talked_to(game_t *game, sfKeyCode code);
int modify_size(game_t *game, sfVector2u new_size, sfRectangleShape *re,
sfRectangleShape *re2);
int change_fps(game_t *game, int value, sfRectangleShape *re);
int add_particules(game_t *game);
int skill_tree_event(game_t *game, sfEvent event);
int talk_to_npc2(game_t *game, sfKeyCode code);

#endif /* !EVENTS_H_ */
