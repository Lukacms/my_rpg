/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** draw_map
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "rpg/game.h"
#include "rpg/macros.h"
#include "rpg/init.h"
#include "my.h"

const rect_struct_t rect[] = {
    {'0', {24 * 0, 24 * 0, 24, 24}, "NORMAL_FLOOR"},
    {'1', {24 * 5, 24 * 13, 24, 24}, "SHOES_FLOOR"},
    {'2', {24 * 0, 24 * 3, 24, 24}, "LITTLE_HOLE"},
    {'3', {24 * 3, 24 * 5, 24, 24}, "BIG_HOLE_1"},
    {'4', {24 * 4, 24 * 5, 24, 24}, "BIG_HOLE_2"},
    {'5', {24 * 5, 24 * 5, 24, 24}, "BIG_HOLE_3"},
    {'a', {24 * 0, 24 * 16, 24, 24}, "WALL_1"},
    {'b', {24 * 0, 24 * 17, 24, 24}, "WALL_2"},
    {'c', {24 * 0, 24 * 18, 24, 24}, "WALL_3"},
    {'d', {24 * 1, 24 * 16, 24, 24}, "WALL_1_ALT"},
    {'e', {24 * 1, 24 * 17, 24, 24}, "WALL_2_ALT"},
    {'f', {24 * 1, 24 * 18, 24, 24}, "WALL_3_ALT"},
    {'g', {24 * 14, 24 * 20, 24, 24}, "TOP_WALL"},
    {'h', {24 * 14, 24 * 20, 24, 24}, "CORNER_WALL_R_1_1"},
    {'i', {24 * 14, 24 * 21, 24, 24}, "CORNER_WALL_R_1_2"},
    {'j', {24 * 14, 24 * 22, 24, 24}, "CORNER_WALL_R_1_3"},
    {'k', {24 * 14, 24 * 23, 24, 24}, "CORNER_WALL_R_1_4"},
    {'l', {24 * 15, 24 * 20, 24, 24}, "CORNER_WALL_R_2_1"},
    {'m', {24 * 15, 24 * 21, 24, 24}, "CORNER_WALL_R_2_2"},
    {'n', {24 * 15, 24 * 22, 24, 24}, "CORNER_WALL_R_2_3"},
    {'o', {24 * 15, 24 * 23, 24, 24}, "CORNER_WALL_R_2_4"},
    {'p', {24 * 3, 24 * 25, 24, 24}, "WALL_R_1"},
    {'q', {24 * 2, 24 * 25, 24, 24}, "WALL_R_2"},
    {'r', {24 * 3, 24 * 26, 24, 24}, "WALL_R_1_ALT"},
    {'s', {24 * 2, 24 * 26, 24, 24}, "WALL_R_2_ALT"},
    {'t', {24 * 13, 24 * 20, 24, 24}, "CORNER_WALL_L_1_1"},
    {'u', {24 * 11, 24 * 21, 24, 24}, "CORNER_WALL_L_1_2"},
    {'v', {24 * 11, 24 * 22, 24, 24}, "CORNER_WALL_L_1_3"},
    {'w', {24 * 11, 24 * 23, 24, 24}, "CORNER_WALL_L_1_4"},
    {'x', {24 * 10, 24 * 20, 24, 24}, "CORNER_WALL_L_2_1"},
    {'y', {24 * 10, 24 * 21, 24, 24}, "CORNER_WALL_L_2_2"},
    {'z', {24 * 10, 24 * 22, 24, 24}, "CORNER_WALL_L_2_3"},
    {'A', {24 * 10, 24 * 23, 24, 24}, "CORNER_WALL_L_2_4"},
    {'B', {24 * 0, 24 * 26, 24, 24}, "WALL_L_1"},
    {'C', {24 * 1, 24 * 26, 24, 24}, "WALL_L_2"},
    {'D', {24 * 0, 24 * 27, 24, 24}, "WALL_L_1_ALT"},
    {'E', {24 * 1, 24 * 27, 24, 24}, "WALL_L_2_ALT"},
    {'F', {24 * 12, 24 * 29, 24, 24}, "CORNER_WALL_BOTTOM_L_1_1"},
    {'G', {24 * 13, 24 * 29, 24, 24}, "CORNER_WALL_BOTTOM_L_1_2"},
    {'H', {24 * 12, 24 * 30, 24, 24}, "CORNER_WALL_BOTTOM_L_2_1"},
    {'I', {24 * 13, 24 * 30, 24, 24}, "CORNER_WALL_BOTTOM_L_2_2"},
    {'J', {24 * 5, 24 * 30, 24, 24}, "WALL_BOTTOM"},
    {'K', {24 * 14, 24 * 29, 24, 24}, "CORNER_WALL_BOTTOM_R_1_1"},
    {'L', {24 * 15, 24 * 29, 24, 24}, "CORNER_WALL_BOTTOM_R_1_2"},
    {'M', {24 * 14, 24 * 30, 24, 24}, "CORNER_WALL_BOTTOM_R_2_1"},
    {'N', {24 * 15, 24 * 30, 24, 24}, "CORNER_WALL_BOTTOM_R_2_2"},
    {'O', {24 * 12, 24 * 34, 24, 24}, "TABLE_1_1"},
    {'P', {24 * 13, 24 * 34, 24, 24}, "TABLE_1_2"},
    {'Q', {24 * 12, 24 * 35, 24, 24}, "TABLE_2_1"},
    {'R', {24 * 13, 24 * 35, 24, 24}, "TABLE_2_2"},
    {'S', {24 * 10, 24 * 25, 24, 24}, "DOOR_RIGHT_1_1"},
    {'T', {24 * 11, 24 * 25, 24, 24}, "DOOR_RIGHT_1_2"},
    {'U', {24 * 10, 24 * 26, 24, 24}, "DOOR_RIGHT_2_1"},
    {'V', {24 * 11, 24 * 26, 24, 24}, "DOOR_RIGHT_2_2"},
    {'W', {24 * 10, 24 * 27, 24, 24}, "DOOR_RIGHT_3_1"},
    {'X', {24 * 11, 24 * 27, 24, 24}, "DOOR_RIGHT_3_2"},
    {'Y', {24 * 10, 24 * 28, 24, 24}, "DOOR_LEFT_1_1"},
    {'Z', {24 * 11, 24 * 28, 24, 24}, "DOOR_LEFT_1_2"},
    {'&', {24 * 10, 24 * 29, 24, 24}, "DOOR_LEFT_2_1"},
    {'~', {24 * 11, 24 * 29, 24, 24}, "DOOR_LEFT_2_2"},
    {'"', {24 * 10, 24 * 30, 24, 24}, "DOOR_LEFT_3_1"},
    {'(', {24 * 11, 24 * 30, 24, 24}, "DOOR_LEFT_3_2"},
    {'-', {24 * 3, 24 * 36, 24, 24}, "CABINET_1"},
    {'`', {24 * 3, 24 * 37, 24, 24}, "CABINET_2"},
    {'_', {24 * 3, 24 * 38, 24, 24}, "CABINET_3"},
    {'#', {24 * 8, 24 * 46, 24, 24}, "BLOOD"},
    {'{', {24 * 9, 24 * 40, 24, 24}, "CORNER_1"},
    {'[', {24 * 10, 24 * 40, 24, 24}, "CORNER_2"},
    {'|', {24 * 11, 24 * 40, 24, 24}, "CORNER_3"},
    {'\\', {24 * 0, 24 * 47, 24, 24}, "WOODEN_PLANK"},
    {'^', {24 * 0, 24 * 48, 24, 24}, "FRONT_DOOR_OPEN_1"},
    {'@', {24 * 0, 24 * 49, 24, 24}, "FRONT_DOOR_OPEN_2"},
    {'+', {24 * 0, 24 * 50, 24, 24}, "FRONT_DOOR_OPEN_3"},
    {'=', {24 * 1, 24 * 48, 24, 24}, "FRONT_DOOR_CLOSE_1_1"},
    {'}', {24 * 1, 24 * 49, 24, 24}, "FRONT_DOOR_CLOSE_1_2"},
    {'%', {24 * 1, 24 * 50, 24, 24}, "FRONT_DOOR_CLOSE_1_3"},
    {'$', {24 * 2, 24 * 48, 24, 24}, "FRONT_DOOR_CLOSE_2_1"},
    {'.', {24 * 2, 24 * 49, 24, 24}, "FRONT_DOOR_CLOSE_2_2"},
    {'*', {24 * 2, 24 * 50, 24, 24}, "FRONT_DOOR_CLOSE_2_3"},
    {'?', {24 * 1, 24 * 47, 24, 24}, "BACK_DOOR"},
    {';', {24 * 4, 24 * 3, 24, 24}, "TRASH_1"},
    {'/', {24 * 6, 24 * 4, 24, 24}, "TRASH_2_1"},
    {':', {24 * 7, 24 * 4, 24, 24}, "TRASH_2_2"},
    {'!', {24 * 5, 24 * 2, 24, 24}, "TRASH_3"},
    {'>', {24 * 13, 24 * 42, 24, 24}, "BLACKBOARD_5_6"},
    {'<', {24 * 14, 24 * 42, 24, 24}, "BLACKBOARD_5_7"},
    {-1, {-1, -1, -1, -1}, "NONE"},
};

static void which_rect(int type, game_t *game)
{
    for (int i = 0; rect[i].index > 0; i += 1) {
        if (type == rect[i].index) {
            sfSprite_setTextureRect(game->tilemap->sprite, rect[i].rect);
            return;
        }
    }
    return;
}

int draw_map(game_t *game, char **map)
{
    sfVector2f pos = {1920 / 3, 1080 / 3};
    int height = 0;

    for (int width = 0; map[height] != NULL; width += 1) {
        sfSprite_setPosition(game->tilemap->sprite, pos);
        which_rect(map[height][width], game);
        if (map[height][width] != '\n' && map[height][width] != ' '
            && map[height][width] != '\0')
            sfRenderWindow_drawSprite(game->window.window,
        game->tilemap->sprite, NULL);
        pos.x += 48;
        if (map[height][width] == '\0') {
            width = -1;
            height += 1;
            pos.x = MAGIC_PLACEMENT;
            pos.y += 48;
        }
    }
    return SUCCESS;
}
