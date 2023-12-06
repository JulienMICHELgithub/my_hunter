/*
** EPITECH PROJECT, 2023
** my
** File description:
** render.c
*/

#include "../include/include.h"

void game_render(all_t *all)
{
    sfRenderWindow_clear(all->window, sfBlack);
    sfRenderWindow_drawText(all->window, all->score_text, NULL);
    sfRenderWindow_drawText(all->window, all->shot_text, NULL);
    if (all->scene == game) {
        for (int i = 0; i < 20; ++i) {
            sfRenderWindow_drawSprite(all->window, all->ducks[i].sprite, NULL);
        }
    } else {
        sfRenderWindow_drawSprite(all->window, all->sprite_menu, NULL);
        sfRenderWindow_drawSprite(all->window, all->button_menu, NULL);
    }
    sfRenderWindow_display(all->window);
}
