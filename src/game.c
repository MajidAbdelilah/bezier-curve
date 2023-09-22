#include "game.h"
#include "raylib.h"
#include "bezier.h"
char game_init(){
    InitWindow(1280, 720, "car_game");
    return 1;
}
void game_loop(){
    Camera2D camera = {0};
    camera.offset = (Vector2){0,0};
    camera.rotation = 0.0f;
    camera.target = (Vector2){(float)720/2,(float)1280/2};
    camera.zoom = 1.0f;
    
    while (WindowShouldClose() == 0) {
        //BeginMode2D(camera);
        BeginDrawing();
        get_curve((Vector2[]){{0, 0}, {(float)1280/5*1, 1500},
            {(float)1280/5*2, -100}, {(float)1280/5*3, -100},
            {(float)1280/5*4, 1500}, {(float)1280/5*5, 0}}, 6);
        EndDrawing();
        //EndMode2D();
    }
}