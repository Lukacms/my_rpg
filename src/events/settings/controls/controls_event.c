/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** settings_controls_event
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include "rpg.h"

static const keystru_t key_board[] = {
    {0, 0, "A"},
    {1, 1, "B"},
    {2, 2, "C"},
    {3, 3, "D"},
    {4, 4, "E"},
    {5, 5, "F"},
    {6, 6, "G"},
    {7, 7, "H"},
    {8, 8, "I"},
    {9, 9, "J"},
    {10, 10, "K"},
    {11, 11, "L"},
    {12, 12, "M"},
    {13, 13, "N"},
    {14, 14, "O"},
    {15, 15, "P"},
    {16, 16, "Q"},
    {17, 17, "R"},
    {18, 18, "S"},
    {19, 19, "T"},
    {20, 20, "U"},
    {21, 21, "V"},
    {22, 22, "W"},
    {23, 23, "X"},
    {24, 24, "Y"},
    {25, 25, "Z"},
    {26, 26, "0"},
    {27, 27, "1"},
    {28, 28, "2"},
    {29, 29, "3"},
    {30, 30, "4"},
    {31, 31, "5"},
    {32, 32, "6"},
    {33, 33, "7"},
    {34, 34, "8"},
    {35, 35, "9"},
    {36, 36, "Escape"},
    {37, 37, "RIGHT"},
    {38, 71, "LEFT"},
    {39, 72, "RIGHT"},
    {40, 73, "UP"},
    {40, 74, "DOWN"},
    {-10, -10, NULL},
};

static int check_code_key(int code, keyb_t *key, int i)
{
    if (code == key->interact || code == key->quit || code == key->pause ||
    code == key->right || code == key->up || code == key->down ||
    code == key->left || code == key->open_inv || code == key->open_skill)
        return 0;
    if (key_board[i].key == code)
        return 1;
    return 0;
}

int change_key(int code, keyb_t *key)
{
    for (int i = 0; key_board[i].index > -10; i += 1) {
        if (check_code_key(code, key, i) == 1)
            return key_board[i].key;
    }
    return -1;
}

char *change_text(int code)
{
    for (int i = 0; key_board[i].index > -10; i++) {
        if (key_board[i].key == code)
            return key_board[i].str;
    }
    return NULL;
}

int analyse_controls_events(game_t *game, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed) {
        play_sound_selected(game, 4);
        analyse_key(game, event.mouseButton);
    }
    check_pressed(game, event);
    return SUCCESS;
}
