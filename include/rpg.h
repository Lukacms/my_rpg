/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** rpg
*/

#ifndef RPG_H_
    #define RPG_H_

    #include "rpg/game.h"
    #include "rpg/macros.h"
    #include "rpg/init.h"
    #include "rpg/display.h"
    #include "rpg/events.h"

int display_skill(game_t *game);
sfFloatRect get_true_rect_npc(sfCircleShape *mc);
int npc_interact(game_t *game);
int npc_sentence(game_t *game);
int npc2_interact(game_t *game);
int npc2_sentence(game_t *game);
int npc3_interact(game_t *game);
int npc3_sentence(game_t *game);
int npc4_interact(game_t *game);
int npc4_sentence(game_t *game);
int npc5_interact(game_t *game);
int npc5_sentence(game_t *game);
void set_fireball(game_t *game);
int check_character(game_t *game);
int madness_interaction(game_t *game);
int health_interaction(game_t *game);
int body_interaction(game_t *game);
int magic_interaction(game_t *game);
int head_interaction(game_t *game);
int change_sprite_color_red(game_t *game, sfMouseWheelScrollEvent button);
int change_sprite_color_green(game_t *game, sfMouseWheelScrollEvent button);
int change_sprite_color_blue(game_t *game, sfMouseWheelScrollEvent button);
void new_room_model(game_t *game);
int launch(void);
int display_help(int argc);
int display_gui(game_t *game);
int draw_map(game_t *game, char **map_to_draw);
void render_views(game_t *game);
int hitbox_left(sfSprite *sprite, game_t *game, int code);
int hitbox_right(sfSprite *sprite, game_t *game, int code);
int hitbox_up(sfSprite *sprite, game_t *game, int code);
int hitbox_down(sfSprite *sprite, game_t *game, int code);
int check_all_file(void);
void teleport_player(int x, int y, game_t *game);
int is_move_valid(game_t *game, sfVector2i pos, int code, char **map);
int get_pos_in_map_up(sfSprite *sprite, game_t *game);
int get_pos_in_map_left(sfSprite *sprite, game_t *game);
int get_pos_in_map_right(sfSprite *sprite, game_t *game);
int get_pos_in_map_down(sfSprite *sprite, game_t *game);
void transform_map_up(sfSprite *sprite, game_t *game, char c);
void transform_map_down(sfSprite *sprite, game_t *game, char c);
void transform_map_left(sfSprite *sprite, game_t *game, char c);
void transform_map_right(sfSprite *sprite, game_t *game, char c);
int is_valid_placement_up(game_t *game, int code, char value);
int is_valid_placement_down(game_t *game, int code, char value);
int is_valid_placement_left(game_t *game, int code, char value);
int is_valid_placement_right(game_t *game, int code, char value);
void get_wooden_plank(game_t *game, int code);
void set_wooden_plank(game_t *game, int code);
void play_sound_selected(game_t *game, int id);
int wooden_plank_interaction(game_t *game);
int display_interaction(game_t *game);
void close_window(game_t *game, sfEvent evt);
int draw_items(game_t *game);
int animate_items(items_t items);
item_node_t *get_item_collide(game_t *game);
int is_collide(game_t *game);
void analyse_interaction(game_t *game, sfEvent evt);
void item_interaction(game_t *game);
int key_interaction(game_t *game);
void has_key_interaction(game_t *game);
void has_not_key_interaction(game_t *game);
void door_interaction(game_t *game);
void open_door(game_t *game);
int story_paper_interaction(game_t *game);
sfFloatRect get_true_rect_mc(sfSprite *mc);
int display_corpses_after(game_t *game);
int display_corpses_before(game_t *game);
int move_character(character_node_t *mc, game_t *game, int code);
void center_view(game_t *game);
int loop_button_game(sfVector2i pos_mouse, game_t *game);
int loop_button_title(sfVector2i pos_mouse, game_t *game);
int loop_button_options(sfVector2i pos_mouse, game_t *game);
int loop_button_inventory(sfVector2i pos_mouse, game_t *game);
bool in_rectangle(sfRectangleShape *re, int x, int y, sfVector2f scaling);
int destroy_settings(settings_menu_t *settings);
int change_status_inv(game_t *game, int value);
int check_slot1(game_t *game, sfMouseButtonEvent button);
int check_slot2(game_t *game, sfMouseButtonEvent button);
int check_slot3(game_t *game, sfMouseButtonEvent button);
int check_slot4(game_t *game, sfMouseButtonEvent button);
int check_slot5(game_t *game, sfMouseButtonEvent button);
int check_slot6(game_t *game, sfMouseButtonEvent button);
int check_slot7(game_t *game, sfMouseButtonEvent button);
int check_slot8(game_t *game, sfMouseButtonEvent button);
int set_text_for_item(char const *str, sfText *text,
sfColor color);
int loop_button(sfVector2i pos_mouse, game_t *game, sfText *text, sfVector2f p);
void check_clicked_graphics_size(game_t *game, sfMouseButtonEvent button);
void check_clicked_graphics_fps(game_t *game, sfMouseButtonEvent button);
int add_node(entities_t *entities, entity_type_t type, sfVector2f pos);
int enemy_dna(enemies_t *node, entity_type_t type, sfTexture *tex,
                sfVector2f pos);
int display_enemies_before(game_t *game);
int display_enemies_after(game_t *game);
int animate_enemies(game_t *game);
bool is_above_or_ahead(character_node_t mc, enemies_t *enemy);
void idle_move(game_t *game);
void set_circles(game_t *game);
bool is_chase(enemies_t *enemy, game_t *game);
bool is_mc_touched(game_t *game);
void enemy_hit(game_t *game);
void go_to_game_over(game_t *game);
int display_game_over(game_t *game);
int is_collide_corpses_left(game_t *game);
int is_collide_corpses_up(game_t *game);
int is_collide_corpses_down(game_t *game);
int is_collide_corpses_right(game_t *game);
int check_clicked_audio_on_off(game_t *game, sfMouseButtonEvent button);
int check_clicked_audio_volume(game_t *game, sfMouseButtonEvent button);
void plank_collapse(game_t *game);
void pursuit_model(game_t *game);
void ghost_sound(game_t *game);
void plank_collapse_dialogue(game_t *game);
int story_dialogue_1(game_t *game);
int story_dialogue_2(game_t *game);
int story_dialogue_3(game_t *game);
int story_dialogue_4(game_t *game);
int story_dialogue_5(game_t *game);
int display_fireball(game_t *game);
int animate_fireball(game_t *game);
int is_fireball_thrown(game_t *game);
void move_fireball(game_t *game);
void fireball_loop(game_t *game);
int is_enemy_hit(game_t *game);
void dispawn_fireball(game_t *game);
void set_sprite_for_fireball(game_t *game);
int color_choices_settings(game_t *game, sfMouseMoveEvent button);
int analyse_key(game_t *game, sfMouseButtonEvent button);
int change_key(int code, keyb_t *key);
char *change_text(int code);
int check_pressed(game_t *game, sfEvent event);
sfVector2f move_infected(sfFloatRect tmp, sfFloatRect tmp2, sfVector2f pos,
enemies_t *enemy);
sfVector2f move_ghost(sfFloatRect tmp, sfFloatRect tmp2, sfVector2f pos,
enemies_t *enemy);
sfVector2f move_model(sfFloatRect tmp, sfFloatRect tmp2, sfVector2f pos,
enemies_t *enemy);
sfVector2f move_not_infected(sfFloatRect tmp, sfFloatRect tmp2, sfVector2f pos,
enemies_t *enemy);
sfVector2f move_warrior(sfFloatRect tmp, sfFloatRect tmp2, sfVector2f pos,
enemies_t *enemy);
int check_type_right(character_node_t *mc);
int check_type_left(character_node_t *mc);
int check_type_back(character_node_t *mc);
int check_type_front(character_node_t *mc);
void check_clicked_music(game_t *game, sfMouseButtonEvent button);
void moving_cam(game_t *game);
void view_items(game_t *game);
void item_view_loop(game_t *game);
int reset_enemies(game_t *game);
int reset_game(game_t *game);
int reset_items(game_t *game);
int reset_mc(game_t *game);
int reset_scripts(game_t *game);
int reset_inventory(game_t *game);
int reset_map(game_t *game);
int saving_map(game_t *game);
int saving_stats(game_t *game);
void write_bools(bool boolean, int fd);
int check_bools(bool *boolean, char **str);
int load_map(game_t *game);
int load_stats(game_t *game);
int load_game(game_t *game);
void launch_script_new_room(game_t *game);
bool is_above_or_ahead_npc(character_node_t mc, npc_t *enemy);
int display_npc_after(game_t *game);
int display_npc_before(game_t *game);
void sachiko_ending(game_t *game);
void sachiko_dialogue(game_t *game);
void say_sentence(game_t *game);
void bad_ending(game_t *game);
void good_ending(game_t *game);
int shaking_view(game_t *game, sfClock *clock);
void hole_in_ground_step_one(game_t *game);
void hole_in_ground_step_two(game_t *game);
int ending(game_t *game);
int display_ending(game_t *game);
bool is_mc_in_map(game_t *game, int x, int y);
int display_ending_panel(game_t *game);
void find_solution(game_t *game);

/**********************************************************/
/*                         pixel                          */
/**********************************************************/
void free_pixellist(game_over_t *over);
int move_pixel(particule_node_t *particule);
int delete_pixelnode(particule_node_t *node, game_over_t *over);

/**********************************************************/
/*                     how to play                        */
/**********************************************************/
int change_cinematics(howtoplay_t *htp);
int display_cinematics(game_t *game);
int set_situation(game_t *game);
int story_explanation(game_t *game);
int animate_provisor(howtoplay_t *htp);
int learn_moves(game_t *game);
int moving_provisor(game_t *game);
int transition(game_t *game);
int learn_keys(game_t *game);
int provisor_leaving(game_t *game);
/*                       skill tree                       */
/**********************************************************/
int add_skillnode(skill_node_t **head, sfVector2f pos);

/**********************************************************/
/*                          menu                          */
/**********************************************************/
int del_node(particule_node_t *node, start_menu_t *menu);
int add_particule_node(start_menu_t *menu, sfVector2f pos);
int move_particule(particule_node_t *node, start_menu_t *menu);

/**********************************************************/
/*                        destroy                         */
/**********************************************************/
int destroy_menu(start_menu_t *menu);
void destroy_inventory(inventory_t *inventory);
void destroy_character_menu(character_menu_t *menu);
void destroy_gui(gui_t *gui);
void destroy_ending(ending_t *ending);
void destroy_htp(howtoplay_t *htp);
void destroy_fireball(fireball_t *fire);
void destroy_items(items_t *items);
void destroy_corpses(corpses_t *corpse);
void destroy_dialogue(dialogue_t *dialogue);
void destroy_entities(entities_t *entities);
int destroy_game_over(game_over_t *over);
int destroy_enemies(enemies_t *enemy);
void destroy_tilemap(tilemap_t *map);
void destroy_maps(game_maps_t *maps);
void destroy_musics(ost_t *ost);
void destroy_stats(stat_t *stats);

#endif /* !RPG_H_ */
