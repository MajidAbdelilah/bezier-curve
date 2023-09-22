#pragma once
#include "raylib.h"

typedef struct tex{
    Texture2D tex;
    Vector2 pos;
    Vector2 size;
}Tex;

typedef struct renderer{
        Tex **valid_tex;
        Tex *all_tex;
}Ren;

typedef struct game{
    Ren ren;
}Game;


char game_init();
void game_loop();
char ren_loop();