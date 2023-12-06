/*
** EPITECH PROJECT, 2023
** my
** File description:
** update.c
*/

#include "../include/include.h"

static void update_alive_duck(all_t *all, int k)
{
    float period = 0.25f;
    sfVector2f pos = sfSprite_getPosition(all->ducks[k].sprite);

    if (all->ducks[k].last_action_time > period) {
        all->ducks[k].index = (all->ducks[k].index + 1) % 3;
        sfSprite_setTextureRect(all->ducks[k].sprite,
                                all->tab[all->ducks[k].index]);
        all->ducks[k].last_action_time = 0;
    }
    if (pos.x > 2072) {
        all->ducks[k].status = haaaa;
        --all->left;
        if (all->miss < 10)
            ++all->miss;
        sfText_setString(all->shot_text,
            my_concat("Miss Before Restart: ", my_itoa(10 - all->miss)));
    }
    sfSprite_setPosition(all->ducks[k].sprite,
        (sfVector2f){pos.x + all->ducks[k].speed / 10, pos.y});
}

static void update_dead_duck(all_t *all, int k)
{
    float period = 0.5f;

    if (all->ducks[k].last_action_time > period) {
        all->ducks[k].status = down;
    }
}

void update_down_duck(all_t *all, int k)
{
    float period = 0.25f;
    sfVector2f pos = sfSprite_getPosition(all->ducks[k].sprite);

    if (all->ducks[k].last_action_time > period) {
        all->ducks[k].index = ((all->ducks[k].index + 1) % 4);
        sfSprite_setTextureRect(all->ducks[k].sprite,
            all->tab[7 + all->ducks[k].index]);
        all->ducks[k].last_action_time = 0;
    }
    if (pos.y > 1280) {
        all->ducks[k].status = haaaa;
        --all->left;
    }
    sfSprite_setPosition(all->ducks[k].sprite,
        (sfVector2f){pos.x, pos.y += 4});
}

void update_duck_status(all_t *all, int k)
{
    if (all->ducks[k].state == pressed) {
        if (all->ducks[k].status == alive) {
            ++all->score;
            sfText_setString(all->score_text, my_concat("Your Score: ",
                my_itoa(all->score)));
        }
        all->ducks[k].last_action_time = 0;
        all->ducks[k].status = dead;
        sfSprite_setTextureRect(all->ducks[k].sprite,
                                all->tab[3 + rand() % 4]);
        all->ducks[k].state = none;
    }
}

void update_up_duck(all_t *all, int k)
{
    float period = 5.0f;

    if (all->ducks[k].last_action_time > period) {
        all->ducks[k].status = alive;
        all->ducks[k].last_action_time = 0;
    }
}

void update_ducks(all_t *all)
{
    for (int i = 0; i < 20; ++i) {
        all->ducks[i].last_action_time += all->elapsed_seconds;
        update_duck_status(all, i);
        switch (all->ducks[i].status) {
            case alive:
                update_alive_duck(all, i);
                break;
            case dead:
                update_dead_duck(all, i);
                break;
            case down:
                update_down_duck(all, i);
                break;
            case up:
                update_up_duck(all, i);
                break;
            default:
                continue;
        }
    }
}

void game_update(all_t *all)
{
    if (all->scene != game)
        return;
    update_ducks(all);
    if (all->left <= 0) {
        if (all->miss == 10) {
            all->scene = menu;
            all->miss = 0;
        }
        all->speed += 2;
        create_wave(all);
    }
}
