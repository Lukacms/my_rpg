/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** check_file
*/

#include "rpg.h"
#include <fcntl.h>
#include <stdio.h>

int check_exist_file(char *arg)
{
    FILE *file;

    if ((file = fopen(arg, "r"))) {
        fclose(file);
        return 0;
    }
    return 84;
}

static int check_song_file(void)
{
    if (check_exist_file(GHOST_SOUND) == 84 ||
    check_exist_file(CLICK_SOUND) == 84 ||
    check_exist_file(FIREBALL_SOUND) == 84 ||
    check_exist_file(FIREBALL) == 84 || check_exist_file(DOOR) == 84 ||
    check_exist_file(FALLING_WOOD) == 84 ||
    check_exist_file(GAME_OVER_SOUND) == 84 || check_exist_file(PAPER) == 84 ||
    check_exist_file(PANIC) == 84 || check_exist_file(START_SONG) == 84 ||
    check_exist_file(SPARKLE) == 84 || check_exist_file(MAIN_THEME) == 84 ||
    check_exist_file(ITEMS_SFX) == 84 || check_exist_file(TITLE_THEME) == 84)
        return FAILURE;
    return SUCCESS;
}

static int check_texture_file(void)
{
    if (check_exist_file(TEX_SETTINGS) == 84 ||
    check_exist_file(TEX_SETTINGS_GRAPHICS) == 84 ||
    check_exist_file(TEX_SETTINGS_CONTROLS) == 84 ||
    check_exist_file("assets/maps/world_map.txt") == 84 ||
    check_exist_file("assets/maps/htp_map.txt") == 84 ||
    check_exist_file(TEX_SETTINGS_AUDIO) == 84 ||
    check_exist_file(TEX_INVENTARY) == 84 ||
    check_exist_file(TEX_PAUSE) == 84 || check_exist_file(TEX_MENU) == 84 ||
    check_exist_file(TEX_ITEM) == 84 || check_exist_file(TEX_CHARACT) == 84 ||
    check_exist_file(TEX_NPC) == 84)
        return FAILURE;
    return SUCCESS;
}

static int check_legends(void)
{
    if (check_exist_file("game_save/.legend") == 84 ||
    check_exist_file("game_save/saved_map.txt") == 84 ||
    check_exist_file("game_save/saved_stats.txt") == 84 ||
    check_exist_file("assets/info_file.txt") == 84)
        return FAILURE;
    return SUCCESS;
}

int check_all_file(void)
{
    if (check_exist_file(FONT_MC) == 84 || check_exist_file(FONT) == 84 ||
    check_exist_file(LOGO) == 84 || check_exist_file(INFO_FILE) == 84 ||
    check_exist_file(SATOSHI) == 84)
        return FAILURE;
    if (check_exist_file(GAME_OVER_BG) == 84 || check_exist_file(ENNEMIES) == 84
    || check_exist_file(CORPSES) == 84 || check_exist_file(FONT_TEXT) == 84 ||
    check_exist_file(TEXTBOX) == 84 || check_exist_file(PORTRAITS) == 84 ||
    check_exist_file(ICON) == 84 || check_exist_file(WORLD_MAP) == 84 ||
    check_exist_file(SKILLS) == 84)
        return FAILURE;
    if (check_song_file() != SUCCESS || check_texture_file() != SUCCESS ||
    check_legends() != SUCCESS)
        return FAILURE;
    return SUCCESS;
}
