/*
** EPITECH PROJECT, 2023
** my
** File description:
** game_loop.c
*/

#include "../include/include.h"

static sfVector2f get_mouse_pos(sfRenderWindow *window, const sfView *view)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f world_pos = sfRenderWindow_mapPixelToCoords(window,
        mouse_pos, view);

    return (world_pos);
}

void game_loop(all_t *all)
{
    sfEvent event;

    srand(time(NULL));
    while (sfRenderWindow_isOpen(all->window)) {
        sfRenderWindow_setFramerateLimit(all->window, 120);
        all->mouse_pos = get_mouse_pos(all->window, all->view);
        while (sfRenderWindow_pollEvent(all->window, &event)) {
            game_event(all, event);
        }
        all->elapsed_seconds = sfTime_asSeconds(sfClock_restart(all->clock));
        game_update(all);
        game_render(all);
    }
}
