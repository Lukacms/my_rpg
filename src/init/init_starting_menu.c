/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Espace de travail)
** File description:
** init_starting_menu
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg/game.h"
#include "rpg/macros.h"
#include "rpg/init.h"

static int init_menu_entities(game_t *game)
{
    game->start_menu.tex_logo = sfTexture_createFromFile(LOGO, NULL);
    if (!game->start_menu.tex_logo)
        return FAILURE;
    game->start_menu.tex_bg = sfTexture_createFromFile(TEX_MENU, NULL);
    if (!game->start_menu.tex_bg)
        return FAILURE;
    game->start_menu.logo = sfSprite_create();
    if (!game->start_menu.logo)
        return FAILURE;
    game->start_menu.bg = sfSprite_create();
    if (!game->start_menu.bg)
        return FAILURE;
    sfSprite_setTexture(game->start_menu.logo,
                        game->start_menu.tex_logo, sfTrue);
    if (!game->start_menu.logo)
        return FAILURE;
    sfSprite_setTexture(game->start_menu.bg, game->start_menu.tex_bg, sfTrue);
    if (!game->start_menu.bg)
        return FAILURE;
    return SUCCESS;
}

static int set_text_menu(game_t *game)
{
    sfText_setFont(game->start_menu.menu_ng, game->start_menu.menu_font);
    sfText_setFont(game->start_menu.menu_continue, game->start_menu.menu_font);
    sfText_setFont(game->start_menu.menu_quit, game->start_menu.menu_font);
    sfText_setColor(game->start_menu.menu_continue, sfWhite);
    sfText_setColor(game->start_menu.menu_ng, sfWhite);
    sfText_setColor(game->start_menu.menu_quit, sfWhite);
    sfText_setString(game->start_menu.menu_ng, "NEW GAME");
    sfText_setString(game->start_menu.menu_continue, "CONTINUE");
    sfText_setString(game->start_menu.menu_quit, "QUIT");
    sfText_setCharacterSize(game->start_menu.menu_ng, 40);
    sfText_setCharacterSize(game->start_menu.menu_continue, 40);
    sfText_setCharacterSize(game->start_menu.menu_quit, 40);
    return SUCCESS;
}

static int init_menu_text(game_t *game)
{
    game->start_menu.menu_font = sfFont_createFromFile(FONT);
    if (!game->start_menu.menu_font)
        return FAILURE;
    game->start_menu.menu_ng = sfText_create();
    game->start_menu.menu_continue = sfText_create();
    game->start_menu.menu_quit = sfText_create();
    if (!game->start_menu.menu_ng || !game->start_menu.menu_continue ||
    !game->start_menu.menu_quit)
        return FAILURE;
    return set_text_menu(game);
}

static int init_menu_pos(game_t *game)
{
    sfVector2u size = sfRenderWindow_getSize(game->window.window);
    sfVector2f logo_pos = {50, 0};
    sfVector2f quit_pos = {size.x - 300, size.y / 2 + 200};
    sfVector2f continue_pos = {size.x - 300, size.y / 2 + 100};
    sfVector2f ng_pos = {size.x - 300, size.y / 2 + 150};

    sfSprite_setPosition(game->start_menu.logo, logo_pos);
    sfText_setPosition(game->start_menu.menu_quit, quit_pos);
    sfText_setPosition(game->start_menu.menu_continue, continue_pos);
    sfText_setPosition(game->start_menu.menu_ng, ng_pos);
    return SUCCESS;
}

int init_starting_menu(game_t *game)
{
    if (!game)
        return FAILURE;
    if (init_menu_entities(game) == FAILURE)
        return FAILURE;
    if (init_menu_text(game) == FAILURE)
        return FAILURE;
    if (init_menu_pos(game) == FAILURE)
        return FAILURE;
    if (init_particules(&game->start_menu) != SUCCESS)
        return FAILURE;
    return init_load(&game->start_menu, game->window.wdw_size);
}
