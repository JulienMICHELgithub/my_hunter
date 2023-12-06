/*
** EPITECH PROJECT, 2023
** include
** File description:
** include
*/

#pragma once

#include "../lib/my/libmy.h"

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Network.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/System/Export.h>

#include <stdbool.h>

#define SUCCESS 0
#define FAILURE 1
#define ERROR 84

typedef enum scene_e {
    menu,
    game
}scene_m;

typedef enum state_e {
    none,
    hover,
    pressed,
    released
}state_m;

typedef enum status_e {
    up,
    alive,
    dead,
    down,
    haaaa
}status_m;

sfSprite *create_sprite(char *path, sfVector2f position,
    sfIntRect subrect, sfVector2f scale);

typedef struct duck_s {
    sfSprite *sprite;
    state_m state;
    state_m prev_state;
    status_m status;
    float last_action_time;
    u_int8_t index;
    int speed;
}duck_t;

duck_t create_duck(int base_speed);

typedef struct all_s {
    sfRenderWindow *window;
    const sfView *view;
    sfClock* clock;
    float elapsed_seconds;
    float last_shoot_time;
    int score;
    int speed;
    sfVector2f mouse_pos;
    duck_t ducks[20];
    int left;
    int miss;
    sfText *score_text;
    sfText *shot_text;
    sfIntRect tab[11];
    scene_m scene;
    sfSprite *sprite_menu;
    sfSprite *button_menu;
}all_t;

void game_loop(all_t *all);
void game_event(all_t *all, sfEvent event);
void game_render(all_t *all);
void game_update(all_t *all);

void create_wave(all_t *all);
sfText *create_text(char *str, sfVector2f position);
