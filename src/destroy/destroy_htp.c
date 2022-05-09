/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** destroy_htp
*/

#include <SFML/Graphics.h>
#include "rpg.h"
#include "my.h"

void destroy_htp(howtoplay_t *htp)
{
    if (!htp)
        return;
    free_array((void **)htp->map);
    sfText_destroy(htp->text);
    sfClock_destroy(htp->clock);
    sfSprite_destroy(htp->provisor.sprite);
    sfClock_destroy(htp->provisor.animate);
    sfTexture_destroy(htp->provisor.texture);
    sfCircleShape_destroy(htp->provisor.vision);
}
