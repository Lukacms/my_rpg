/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** init
*/

#ifndef INIT_H_
    #define INIT_H_

    #include "rpg/game.h"

int init_load(start_menu_t *menu, sfVector2u wdw_size);
int init_game(game_t *game);
int init_window(game_t *game);
int init_starting_menu(game_t *game);
int init_main_character(game_t *game);
int init_enemies(game_t *game);
int init_map(game_t *game);
int init_tilemap(game_t *game);
int init_views(game_t *game);
char **initialize_two_d_array(char *map);
int init_gui(game_t *game);
int init_inventory(game_t *game);
int init_sfx(game_t *game);
int init_dialogue(game_t *game);
int init_items(game_t *game);
int init_music(game_t *game);
int init_corpses(game_t *game);
int init_button_return_game(game_t *game);
int init_button_return_to_title(game_t *game);
int init_button_options(game_t *game);
int init_button_inventory(game_t *game);
int init_button_mc(game_t *game);
int init_pause_menu(game_t *game);
int init_settings_menu(game_t *game);
int destroy_pause(pause_menu_t *pause_menu);
sfRectangleShape *create_rectangle(sfVector2f pos, sfVector2f size);
sfText *init_text(sfFont *str, sfVector2f pos_text, char *text_str);
int init_key(game_t *game, int index, sfVector2f pos_r, char *str);
int init_volume_up(game_t *game, int index, sfVector2f pos_r, char *str);
int init_volume(game_t *game, int index, sfVector2f pos_r, char *str);
int init_button(game_t *game, int index, sfVector2f pos_r, char *str);
int init_button_music(game_t *game, int index, sfVector2f pos_r, char *str);
int game_obj_button_audio(game_t *game);
int game_obj_button_graphics(game_t *game);
int game_obj_button_controls(game_t *game);
int init_ennemies(game_t *game);
int init_game_over(game_t *game);
void init_scripts(game_t *game);
int game_object_settings_audio(game_t *game);
void set_bool_system(game_t *game);
int init_pixellist(game_t *game);
int add_pixelnode(game_over_t *over, sfVector2f pos);
int add_pixelnode_mc(character_node_t *mc, sfVector2f pos);
int init_slots1_sprite(game_t *game);
int init_slots2_sprite(game_t *game);
int init_slots3_sprite(game_t *game);
int init_fireball(game_t *game);
int init_htp(game_t *game);
int set_provisor_vision(howtoplay_t *htp);
int init_npc(game_t* game, entity_type_t type, int index, sfVector2f pos_npc);
int init_character(game_t *game);
int add_fog_node(game_maps_t *maps);
int init_fog(game_maps_t *maps);
int init_particules(start_menu_t *menu);
int init_skill_tree(game_t *game);
int init_sachiko(game_t *game);
int init_ending(game_t *game);
int init_stats(stat_t *stats, game_t *game);

#endif /* !INIT_H_ */
