/*
** EPITECH PROJECT, 2023
** my
** File description:
** main.c
*/

#include "../include/include.h"

static sfRenderWindow *create_window(unsigned int x,
    unsigned int y, unsigned int bpp, char *title)
{
    sfVideoMode video_mode = {x, y, bpp};

    return (sfRenderWindow_create(video_mode, title,
        sfClose | sfResize, NULL));
}

all_t init(void)
{
    all_t all = {
        .window = create_window(1920, 1080, 32, "my_hunter"),
        .last_shoot_time = 0, .score = 0, .speed = 10, .left = 20,
        .score_text = create_text("Your Score: 0", (sfVector2f){20, 20}),
        .scene = menu, .miss = 0, .elapsed_seconds = 0,
        .shot_text = create_text("Miss Before Restart: 10",
            (sfVector2f){20, 60}), .clock = sfClock_create(),
            .sprite_menu = create_sprite("assets/sky.jpg", (sfVector2f){0, 0},
            (sfIntRect){0, 0, 1920, 1080}, (sfVector2f){1, 1}),
        .button_menu = create_sprite("./assets/start_red-button.png",
            (sfVector2f){627, 400},
            (sfIntRect){0, 0, 666, 281}, (sfVector2f){1, 1}),
        .tab = {(sfIntRect){101, 0, 38, 35},
        (sfIntRect){139, 0, 38, 35}, (sfIntRect){177, 0, 38, 35},
        (sfIntRect){0, 70, 38, 35}, (sfIntRect){38, 70, 38, 35},
        (sfIntRect){76, 70, 38, 35}, (sfIntRect){114, 70, 38, 35},
        (sfIntRect){0, 108, 38, 35}, (sfIntRect){38, 108, 38, 35},
        (sfIntRect){76, 108, 38, 35}, (sfIntRect){114, 108, 38, 35}}};

    return (all);
}

int main(void)
{
    all_t all = init();
    sfSoundBuffer *soundbuffer;
    sfSound *sound;

    soundbuffer = sfSoundBuffer_createFromFile("./songs/Silver-Wolf.ogg");
    sound = sfSound_create();
    sfSound_setBuffer(sound, soundbuffer);
    sfSound_play(sound);
    sfSound_setLoop(sound, sfTrue);
    all.view = sfRenderWindow_getView(all.window);
    game_loop(&all);
    sfSound_destroy(sound);
    sfSoundBuffer_destroy(soundbuffer);
    return (0);
}
