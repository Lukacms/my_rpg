/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** destroy_corpses
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg.h"

void destroy_corpses(corpses_t *corpse)
{
    sfTexture_destroy(corpse->texture);
    for (int i = 0; corpse->corpses[i]; i++) {
        sfSprite_destroy(corpse->corpses[i]->sprite);
        free(corpse->corpses[i]);
    }
    free(corpse->corpses);
}
