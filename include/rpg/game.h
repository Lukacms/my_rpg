/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** game
*/

#ifndef GAME_H_
    #define GAME_H_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <sys/types.h>
    #include <stdbool.h>

/*
* @brief enum to handle on which page the game is
*
* @param MENU
* @param HTP
* @param GAME
* @param SKILL_TREE
* @param INVENTARY
* @param SPECIAL_SCENES
* @param FIGHTS
* @param GAME_OVER
* @param ENDING
*/

typedef enum {
    MENU,
    HTP,
    SETTINGS,
    CHARACTERS,
    GAME,
    PAUSE,
    SKILL_TREE,
    INVENTARY,
    SPECIAL_SCENES,
    FIGHTS,
    ENDING,
    GAME_OVER,
    QUIT
} scene_handler_t;

typedef enum {
    NONE,
    GRAPHICS,
    AUDIO,
    CONTROLS,
} mode_settings_t;

typedef enum {
    NO_WALK,
    WALK_BEHIND
} corpses_type_t;

typedef enum {
    MC,
    BLOND,
    GIRL,
    SKATER,
    MODEL,
    GHOST,
    INFECTED,
    NOT_INFECTED,
    NICE_FLAMES,
    BAD_FLAMES,
    WARRIOR,
    NPC,
    NPC2,
    NPC3,
    NPC4,
    NPC5,
} entity_type_t;

typedef enum {
    KEY,
    STORY_PAPER,
    MADNESS_POTION,
    HEALTH_POTION,
    HEAD_PUPPET,
    BODY_PUPPET,
    MAGIC_ATTACK
} item_type_t;

typedef enum {
    BACK = 0,
    BACK_BLOND = 192,
    BACK_GIRL = 384,
    BACK_SKATER = 576,
    FRONT = 48,
    FRONT_BLOND = 240,
    FRONT_GIRL = 432,
    FRONT_SKATER = 624,
    RIGHT = 144,
    RIGHT_BLOND = 288,
    RIGHT_GIRL = 480,
    RIGHT_SKATER = 672,
    LEFT = 96,
    LEFT_BLOND = 336,
    LEFT_GIRL = 528,
    LEFT_SKATER = 720,
} states_mc_t;

typedef enum htp_state_s {
    VISUAL,
    STORY_EXPLANATION,
    LEARN_MOVES,
    MOVING_PROVISOR,
    TRANSITION,
    BASIC_KEYS,
    PROVISOR_LEAVING,
    FINISHED
} htp_state_t;

typedef struct scritps_s {
    bool plank_collapse;
    bool ghost_sound;
    bool pursuit_model;
    bool new_room_model;
    bool view_items;
} scripts_t;

typedef struct button_s {
    sfRectangleShape *rectangle;
    sfIntRect rect;
    sfVector2f pos_rect;
    sfVector2f pos_text;
    sfText *text;
    bool key_set;
} button_t;

typedef struct pause_menu_s {
    button_t return_game;
    button_t inventory;
    button_t options;
    button_t return_to_title;
    button_t mc;
    button_t quit;
    button_t mc_sprite;
    button_t stats;
    button_t save;
    sfTexture *texture;
    sfSprite *sprite;
    sfSprite *sprite_mc;
    sfFont *font_mc;
} pause_menu_t;

typedef struct game_object_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfRectangleShape *rectangle;
    sfText *text;
    sfVector2f pos_text;
    bool clicked;
    button_t *button1[9];
} game_obj_settings_t;

typedef struct settings_menu_s {
    game_obj_settings_t audio;
    game_obj_settings_t controls;
    game_obj_settings_t graphics;
    sfRectangleShape *back;
    sfTexture *texture;
    sfSprite *sprite;
} settings_menu_t;

typedef struct corpse_struct_s {
    sfVector2f pos;
    sfIntRect rect;
    int type;
    bool script_room_model;
} corpse_struct_t;

typedef struct item_struct_s {
    sfVector2f pos;
    int type;
} item_struct_t;

typedef struct sfx_s {
    sfSoundBuffer *b_items;
    sfSoundBuffer *b_door;
    sfSoundBuffer *b_start;
    sfSoundBuffer *b_over;
    sfSoundBuffer *b_wood;
    sfSoundBuffer *b_fire;
    sfSoundBuffer *b_click;
    sfSoundBuffer *b_laught;
    sfSound *sfx;
} sfx_t;

typedef struct fireball_s {
    sfTexture *t_fire;
    sfSprite *fire;
    int state;
    bool hidden;
    sfClock *animate;
    sfClock *countdown;
} fireball_t;

typedef struct enemies_s {
    sfSprite *sprite;
    sfClock *animate;
    sfVector2f pos;
    sfCircleShape *vision;
    struct enemies_s *prev;
    struct enemies_s *next;
    states_mc_t state;
    entity_type_t type;
    bool hidden;
    sfTexture *texture;
    int life;
} enemies_t;

typedef struct rect_item_s {
    sfIntRect rect;
    int index;
} rect_item_t;

typedef struct slot_s {
    sfRectangleShape *rectangle;
    sfSprite *sprite;
    sfText *text;
    bool clicked;
} slot_t;

typedef struct inventory_s {
    bool wooden_plank;
    bool key;
    bool head_puppet;
    bool body_puppet;
    bool full_puppet;
    bool heal_bottle;
    bool madness_potion;
    bool magic_attack;
    slot_t *slot[10];
    sfTexture *texture;
    sfSprite *sprite;
    sfText *text_click;
    sfText *text_fusion;
    sfTexture *tex_item;
} inventory_t;

typedef struct npc_s {
    sfTexture *tex_npc;
    sfSprite *sprite_npc;
    sfClock *clock;
    sfCircleShape *vision_npc;
    entity_type_t type;
} npc_t;

typedef struct particule_node_s {
    sfVector2f pos;
    sfVector2f vel;
    sfVector2f direction;
    sfRectangleShape *pixel;
    sfClock *clock;
    struct particule_node_s *prev;
    struct particule_node_s *next;
} particule_node_t;

typedef struct character_node_s {
    sfTexture *tex_character;
    sfSprite *sprite;
    sfClock *animate;
    sfVector2f pos;
    states_mc_t states_mc;
    entity_type_t type;
    bool display_particules;
    struct {
        particule_node_t *head;
        sfClock *clock;
        unsigned int size;
        int (*add)(struct character_node_s *mc, sfVector2f pos);
        int (*pop)(particule_node_t *node, struct character_node_s *mc);
    } particules;
} character_node_t;

typedef struct entities_s {
    sfTexture *t_ennemies;
    sfClock *move;
    sfClock *invicible;
    character_node_t mc;
    npc_t *npc[6];
    npc_t *sachiko;
    bool instant_dead;
    struct {
        enemies_t *head;
        unsigned int size;
    } enemies;
} entities_t;

typedef struct start_menu_s {
    sfTexture *tex_logo;
    sfTexture *tex_bg;
    sfSprite *logo;
    sfSprite *bg;
    sfFont *menu_font;
    sfText *menu_continue;
    sfText *menu_ng;
    sfText *menu_quit;
    sfText *loading;
    sfRectangleShape *load;
    particule_node_t *head;
    unsigned int size;
    sfClock *clock;
    int (*add)(struct start_menu_s *menu, sfVector2f pos);
    int (*pop)(particule_node_t *node, struct start_menu_s *menu);
} start_menu_t;

typedef struct game_over_s {
    sfTexture *t_over;
    sfSprite *over;
    sfText *over_text;
    sfClock *over_clock;
    struct {
        particule_node_t *head;
        sfClock *clock;
        unsigned int size;
        int (*add)(struct game_over_s *over, sfVector2f pos);
        int (*pop)(particule_node_t *node, struct game_over_s *over);
    } particules;
} game_over_t;

typedef struct gui_s {
    sfTexture *tex_icon;
    sfSprite *icon;
    sfRectangleShape *health;
    sfRectangleShape *bar;
} gui_t;

typedef struct tilemap_s {
    sfTexture *tilemap;
    sfSprite *sprite;
    sfIntRect rect;
} tilemap_t;

typedef struct ending_s {
    sfTexture *t_ending;
    sfSprite *ending;
    sfSprite *fade;
    sfSprite *panel;
} ending_t;

typedef struct game_maps_s {
    char *original_map;
    char **map;
    particule_node_t *head;
    unsigned int size;
} game_maps_t;

typedef struct views_s {
    sfView *normal;
    sfView *ui;
} views_t;

typedef struct dialogue_s {
    sfTexture *t_portraits;
    sfSprite *portrait;
    sfTexture *t_textbox;
    sfSprite *textbox;
    sfFont *font;
    sfText *text;
} dialogue_t;

typedef struct item_node_s {
    sfSprite *sprite;
    int type;
    bool taken;
    sfVector2f pos;
} item_node_t;

typedef struct items_s {
    sfTexture *sparkle;
    sfTexture *paper;
    item_node_t **items;
    sfClock *clock;
} items_t;

typedef struct corpse_node_s {
    sfSprite *sprite;
    sfVector2f pos;
    corpses_type_t type;
    bool script_room_model;
} corpse_node_t;

typedef struct corpses_s {
    sfTexture *texture;
    corpse_node_t **corpses;
} corpses_t;

typedef struct ost_s {
    sfMusic *title_theme;
    sfMusic *main_theme;
    sfMusic *panic;
    sfMusic *sachiko;
    sfMusic *ghost;
} ost_t;

typedef struct window_s {
    sfRenderWindow *window;
    sfVector2f scaling;
    sfVector2u wdw_size;
    sfClock *game_clock;
    bool screen;
} window_t;

typedef struct howtoplay_s {
    char **map;
    enemies_t provisor;
    htp_state_t state;
    sfText *text;
    sfClock *clock;
    bool next;
} howtoplay_t;

typedef struct keyb_s {
    int up;
    int down;
    int left;
    int right;
    int interact;
    int pause;
    int quit;
    int open_inv;
    int open_skill;
} keyb_t;

typedef struct satoshi_s {
    sfRectangleShape *satoshi;
    sfText *text_satoshi;
    sfIntRect rect;
    bool clicked_satoshi;
} satoshi_t;

typedef struct blond_s {
    sfRectangleShape *blond;
    sfText *text_blond;
    sfIntRect rect;
    bool clicked_blond;
} blond_t;

typedef struct girl_s {
    sfRectangleShape *girl;
    sfText *text_girl;
    sfIntRect rect;
    bool clicked_girl;
} girl_t;

typedef struct skater_s {
    sfRectangleShape *skater;
    sfText *text_skater;
    sfIntRect rect;
    bool clicked_skater;
} skater_t;

typedef struct character_menu_s {
    skater_t skater;
    girl_t girl;
    satoshi_t satoshi;
    blond_t blond;
    sfRectangleShape *color_red;
    sfRectangleShape *color_blue;
    sfRectangleShape *color_green;
    bool color_red_click;
    bool color_green_click;
    bool color_blue_click;
    sfUint8 red;
    sfUint8 green;
    sfUint8 blue;
    sfText *back;
    sfSprite *sprite;
    sfTexture *tex_charact;
    sfSprite *skin;
    sfClock *clock;
    entity_type_t type;
} character_menu_t;

typedef struct skill_node_s {
    sfCircleShape *circle;
    sfVector2f pos;
    bool acquired;
    struct skill_node_s *prev;
    struct skill_node_s *next;
} skill_node_t;

typedef struct stats_obj_s {
    int nb_value;
    sfText *value;
    sfText *text_stats;
} stats_obj_t;

typedef struct stat_s {
    sfTexture *tex_background;
    sfSprite *spr_background;
    sfText *back;
    stats_obj_t stats_obj[4];
    int xp;
    sfText *t_xp;
    sfText *v_xp;
    bool npc_kill;
    skill_node_t *speed;
    skill_node_t *damage;
    skill_node_t *health;
    skill_node_t *cooldown;
    int len_skill;
} stat_t;

typedef struct game_s {
    window_t window;
    inventory_t inventory;
    pause_menu_t pause_menu;
    settings_menu_t settings_menu;
    character_menu_t characters;
    gui_t gui;
    ost_t ost;
    sfx_t sfx;
    ending_t ending;
    howtoplay_t htp;
    fireball_t fireball;
    scripts_t scripts;
    game_over_t game_over;
    items_t items;
    corpses_t corpses;
    dialogue_t dialogue;
    start_menu_t start_menu;
    scene_handler_t status;
    mode_settings_t mode;
    entities_t entities;
    tilemap_t *tilemap;
    game_maps_t *maps;
    views_t views;
    keyb_t key;
    stat_t stats;
} game_t;

typedef int (*command_handler_t)(game_t *game);
typedef int (*event_handler_t)(game_t *game, sfEvent event);
typedef int (*event_settings_handler_t)(game_t *game, sfEvent event);

typedef struct game_status_s {
    mode_settings_t mode;
    scene_handler_t status;
    command_handler_t scene_handler;
    event_handler_t event_handler;
    event_settings_handler_t event_settings_handler;
} game_status_t;

typedef struct htp_status_s {
    htp_state_t state;
    command_handler_t cinematic;
} htp_status_t;

typedef struct game_interaction_s {
    int type;
    int (*fptr)(game_t *);
} game_interaction_t;

typedef struct rect_struct_s {
    int index;
    sfIntRect rect;
    char *name;
} rect_struct_t;

typedef struct keystru_s {
    int index;
    sfKeyCode key;
    char *str;
} keystru_t;

typedef struct create_holes_s {
    int x;
    int y;
    char hole;
} create_holes_t;

#endif /* !GAME_H_ */
