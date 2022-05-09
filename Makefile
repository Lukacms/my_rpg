##
## EPITECH PROJECT, 2022
## myrpg
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/launch.c	\
		src/check_file.c	\
		src/misc/hitbox.c	\
		src/events/event.c	\
		src/misc/is_chase.c	\
		src/events/move_mc.c	\
		src/events/move_mc_states.c	\
		src/events/pause_events.c	\
		src/events/skin/characters_select_events.c	\
		src/events/skin/characters_select_event_click.c	\
		src/events/skin/change_color_sprite.c	\
		src/events/settings/controls/controls_event.c	\
		src/events/settings/controls/controls_key_bool.c	\
		src/events/settings/controls/controls_key_pressed.c	\
		src/events/settings/events_color.c	\
		src/events/settings/audio/audio_events.c	\
		src/events/settings/audio/audio_on_off.c	\
		src/events/settings/audio/audio_on_off_music.c	\
		src/events/settings/audio/audio_volume.c	\
		src/events/settings/graphics/graphics_size_fps.c	\
		src/events/settings/graphics/graphics_events.c	\
		src/events/settings/mode_events.c	\
		src/events/settings/events.c	\
		src/events/inventory/inventory_events.c	\
		src/events/inventory/inventory_slots_events.c	\
		src/events/inventory/inventory_slots_events2.c	\
		src/help/display_help.c	\
		src/enemy/move/move_ghost.c	\
		src/enemy/move/move_model.c	\
		src/enemy/move/move_infected.c	\
		src/enemy/move/move_not_infected.c	\
		src/enemy/move/move_warrior.c	\
		src/misc/is_valid_move.c	\
		src/misc/transform_map.c	\
		src/misc/is_mc_touched.c	\
		src/save/saving_map.c	\
		src/enemy/enemy_hit.c	\
		src/misc/set_circles.c	\
		src/misc/center_view.c	\
		src/misc/write_bools.c	\
		src/save/saving_stats.c	\
		src/load_game/load_map.c	\
		src/load_game/load_game.c	\
		src/init/nodes/add_node.c	\
		src/reset_game/reset_mc.c	\
		src/load_game/load_stats.c	\
		src/misc/teleport_player.c	\
		src/misc/go_to_game_over.c	\
		src/reset_game/reset_map.c	\
		src/load_game/check_bools.c	\
		src/fireball/is_enemy_hit.c	\
		src/destroy/destroy_pause.c	\
		src/reset_game/reset_game.c	\
		src/misc/get_true_rect_mc.c	\
		src/reset_game/reset_items.c	\
		src/fireball/fireball_loop.c	\
		src/misc/is_above_or_ahead.c	\
		src/fireball/move_fireball.c	\
		src/fireball/throw_fireball.c	\
		src/events/get_wooden_plank.c	\
		src/events/put_wooden_plank.c	\
		src/misc/is_valid_placement.c	\
		src/reset_game/reset_scripts.c	\
		src/reset_game/reset_enemies.c	\
		src/destroy/destroy_settings.c	\
		src/misc/get_position_in_map.c	\
		src/fireball/dispawn_fireball.c	\
		src/fireball/throw_fireball_characters.c	\
		src/reset_game/reset_inventory.c	\
		src/sounds/play_sound_selected.c	\
		src/events/analyse_interaction.c	\
		src/interactions/doors/has_key.c	\
		src/misc/is_collide_corpses_up.c	\
		src/misc/is_collide_corpses_left.c	\
		src/misc/is_collide_corpses_down.c	\
		src/interactions/doors/open_door.c	\
		src/interactions/potion/madness.c	\
		src/interactions/potion/health.c	\
		src/interactions/puppet/body_puppet.c	\
		src/interactions/puppet/head_puppet.c	\
		src/interactions/crystal/crystal.c	\
		src/interactions/npc/npc.c	\
		src/interactions/npc/npc2.c	\
		src/interactions/npc/npc3.c	\
		src/interactions/npc/npc4.c	\
		src/init/nodes/give_dna_to_enemy.c	\
		src/misc/is_collide_corpses_right.c	\
		src/scripts/view_items/view_items.c	\
		src/scripts/view_items/moving_cam.c	\
		src/interactions/doors/has_not_key.c	\
		src/fireball/set_sprite_for_fireball.c	\
		src/interactions/keys/key_interaction.c	\
		src/interactions/items/is_item_collide.c	\
		src/scripts/view_items/items_view_loop.c	\
		src/interactions/doors/door_interaction.c	\
		src/interactions/items/item_interaction.c	\
		src/interactions/close_window/close_window.c	\
		src/scripts/plank_collapse/plank_collapse.c	\
		src/scripts/plank_collapse/plank_dialogue.c	\
		src/scripts/ghost_sound.c	\
		src/scripts/pursuit_model.c	\
		src/scripts/new_room/new_room_model.c	\
		src/scripts/new_room/launch_script_model.c	\
		src/display/settings/display_settings_mode_graphics.c	\
		src/display/settings/display_settings_mode_controls.c	\
		src/interactions/story_paper/story_paper_interaction.c	\
		src/interactions/wooden_plank/wooden_plank_interaction.c	\
		src/interactions/find_solution/find_solution.c	\
		src/events/game/npc_giving_solution.c	\
		src/destroy/destroy_menu.c	\
		src/destroy/destroy_inventory.c	\
		src/destroy/destroy_character_menu.c	\
		src/destroy/destroy_gui.c	\
		src/destroy/destroy_musics.c	\
		src/destroy/destroy_ending.c	\
		src/destroy/destroy_htp.c	\
		src/destroy/destroy_fireball.c	\
		src/destroy/destroy_items.c	\
		src/destroy/destroy_corpses.c	\
		src/destroy/destroy_dialogue.c	\
		src/destroy/destroy_entities.c	\
		src/destroy/destroy_enemies.c	\
		src/destroy/destroy_resources.c	\
		src/destroy/destroy_tilemap.c	\
		src/destroy/destroy_stats.c	\


SRC_DISPLAY	=	src/display/menu/display_menu.c	\
				src/display/pause/button_hover.c	\
				src/display/settings/display_settings_mode.c	\
				src/display/settings/display_settings_mode_audio.c	\
				src/display/characters/display_characters.c	\
				src/display/characters/display_skater.c	\
				src/display/characters/display_girl.c	\
				src/display/characters/display_satoshi.c	\
				src/display/characters/display_blond.c	\
				src/display/game/display_game.c	\
				src/interactions/story_paper/story_paper_dialogue.c	\
				src/display/game/display_mc.c	\
				src/display/game/animate_mc.c	\
				src/display/game/display_gui.c	\
				src/draw_map/draw_map.c	\
				src/draw_map/render_views.c	\
				src/display/game/display_items.c	\
				src/display/game/display_corpses.c	\
				src/display/game/animate_fireball.c	\
				src/display/game/display_fireball.c	\
				src/display/game/animate_items.c	\
				src/display/game/display_enemies.c	\
				src/scripts/sachiko_ending/sachiko_dialogue.c	\
				src/scripts/sachiko_ending/sachiko_ending.c	\
				src/scripts/sachiko_ending/say_sentence.c	\
				src/display/game/animate_enemies.c	\
				src/scripts/sachiko_ending/dialogue.c	\
				src/display/pause/display_pause.c	\
				src/scripts/sachiko_ending/bad_ending.c	\
				src/scripts/sachiko_ending/shaking_view.c	\
				src/scripts/sachiko_ending/good_ending.c	\
				src/display/inventory/display_slots.c	\
				src/display/settings/display_settings.c	\
				src/display/inventory/display_inventory.c	\
				src/display/game_over/display_game_over.c	\
				src/interactions/display_interaction.c	\
				src/draw_map/draw_fog.c	\
				src/misc/is_mc_in_map.c	\
				src/init/init_ending.c	\
				src/display/ending/display_ending_panel.c	\
				src/scripts/ending/ending.c	\
				src/scripts/ending/display_ending.c	\
				src/scripts/sachiko_ending/hole_in_ground.c	\
				src/display/menu/display_loading_screen.c	\

SRC_INIT	=	src/init/init_gui.c	\
				src/init/init_map.c	\
				src/init/init_sfx.c	\
				src/init/fog/init_fog.c	\
				src/init/init_characters.c	\
				src/init/init_pause_menu.c	\
				src/init/init_settings.c	\
				src/init/init_loading.c	\
				src/events/in_text.c	\
				src/init/init_game.c	\
				src/init/init_views.c	\
				src/init/init_items.c	\
				src/init/init_music.c	\
				src/init/init_window.c	\
				src/events/in_sprite.c	\
				src/init/init_tilemap.c	\
				src/events/game_event.c	\
				src/init/init_scripts.c	\
				src/init/init_sachiko.c	\
				src/init/init_corpses.c	\
				src/init/init_enemies.c	\
				src/events/menu_events.c	\
				src/init/init_dialogue.c	\
				src/init/fog/add_fog_node.c	\
				src/init/init_fireball.c	\
				src/init/init_inventory.c	\
				src/init/init_game_over.c	\
				src/init/init_two_d_array.c	\
				src/init/init_starting_menu.c	\
				src/init/init_main_character.c	\
				src/init/button/button_pause.c	\
				src/init/button/button_save.c	\
				src/init/second_init_settings.c	\
				src/enemy/move/idle_move.c	\
				src/init/menu_particules/init_particules.c	\
				src/init/button/button_settings_audio.c	\
				src/init/button/button_size_graphics.c	\
				src/cinematics/pixels/add_pixelnode_mc.c	\

SRC_GO	=	src/cinematics/pixels/add_node.c	\
			  src/cinematics/pixels/del_node.c	\
			  src/destroy/destroy_game_over.c	\
			  src/cinematics/pixels/init_pixel.c	\
			  src/cinematics/pixels/move_pixel.c	\
			  src/cinematics/pixels/free_pixellist.c	\
			  src/display/game_over/display_pixels.c	\

SRC_HTP	=	src/init/htp/init_htp.c	\
			src/events/htp/htp_event.c	\
			src/cinematics/htp/visual.c	\
			src/display/htp/display_htp.c	\
			src/cinematics/htp/transition.c	\
			src/cinematics/htp/learn_keys.c	\
			src/cinematics/htp/learn_moves.c	\
			src/display/htp/display_provisor.c	\
			src/display/htp/animate_provisor.c	\
			src/cinematics/htp/moving_provisor.c	\
			src/init/htp/init_principal_vision.c	\
			src/cinematics/htp/provisor_leaving.c	\
			src/cinematics/htp/change_cinematics.c	\
			src/cinematics/htp/story_explanation.c	\
			src/events/htp/is_provisor_talked_to.c	\
			src/cinematics/htp/display_cinematics.c	\

SRC_MENU	=	src/events/main_menu/del_node.c	\
				src/init/menu_particules/add_node.c	\
				src/display/menu/draw_particules.c	\
				src/display/menu/move_particule.c	\
				src/events/main_menu/add_particules.c	\

SRC_SKILLTREE	=	src/events/stats/skill_tree_events.c	\
					src/init/skill_tree/init_skill_tree.c	\
					src/init/skill_tree/add_node.c	\
					src/display/skill_tree/display_skill_tree.c	\
					src/display/skill_tree/display_skill.c	\
					src/init/skill_tree/init_stat.c

OBJ	=	$(SRC:.c=.o) $(SRC_INIT:.c=.o) $(SRC_GO:.c=.o) $(SRC_HTP:.c=.o)
OBJ += $(SRC_DISPLAY:.c=.o) $(SRC_SKILLTREE:.c=.o) $(SRC_MENU:.c=.o)

NAME	=	my_rpg

LIBMY	=	lib/libmy.a

CFLAGS	=	-W -Wall -Wextra -Wshadow -Wpedantic

CPPFLAGS	=	-I./include

CC	=	gcc

LDFLAGS	=	-L./lib

LDLIBS	=	-lmy -lm
LDLIBS	+=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

all:	$(NAME)

$(LIBMY):
	make re -C lib/my

$(NAME):	$(LIBMY) $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

debug:	fclean
debug:	CFLAGS += -g
debug:	$(NAME)

clean:
	@rm -f $(OBJ)
	@make clean -C lib/my

fclean:	clean
	@rm -f $(NAME)

re:	fclean	all	clean

.PHONY: clean fclean re all debug
