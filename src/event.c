/*
** EPITECH PROJECT, 2023
** my
** File description:
** event.c
*/

#include "../include/include.h"


static bool duck_pressed(duck_t *duck, sfVector2f mouse_pos)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(duck->sprite);

    if (sfFloatRect_contains(&rect, mouse_pos.x, mouse_pos.y)) {
        duck->prev_state = duck->state;
        duck->state = pressed;
        return (true);
    }
    return (false);
}

static void update_ducks_state(all_t *all)
{
    bool hit = false;

    for (int i = 0; i < 20; ++i) {
        if (all->ducks[i].status == alive)
            hit = duck_pressed(&all->ducks[i], all->mouse_pos);
        if (hit)
            return;
    }
}

bool button_pressed(sfSprite *sprite, sfVector2f mouse_pos)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(sprite);

    if (sfFloatRect_contains(&rect, mouse_pos.x, mouse_pos.y)) {
        return (true);
    }
    return (false);
}

void event_game_scene(all_t *all)
{
    all->last_shoot_time += all->elapsed_seconds;
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (all->last_shoot_time > 0.5) {
            update_ducks_state(all);
            all->last_shoot_time = 0;
        }
    }
}

void event_menu_scene(all_t *all)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (button_pressed(all->button_menu, all->mouse_pos)) {
            create_wave(all);
            all->scene = game;
            all->score = 0;
            sfText_setString(all->score_text, "Your Score: 0");
            sfText_setString(all->shot_text, "Miss Before Restart: 10");
            all->speed = 10;
        }
    }
}

void game_event(all_t *all, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(all->window);
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyEscape) {
            sfRenderWindow_close(all->window);
        }
    }
    if (all->scene == game) {
        event_game_scene(all);
    } else {
        event_menu_scene(all);
    }
}
