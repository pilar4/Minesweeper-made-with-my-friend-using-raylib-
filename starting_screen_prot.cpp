//Made a starting screen that includes going full screen (and off), quiting and starting the game
//Minesweeper not implemented yet
#include "raylib.h"
using namespace std;

int main(void)
{
    int screen_w = 1920, screen_h=1080;
    InitWindow(screen_w, screen_h, "Minesweeped_no_adds");
    //ToggleFullscreen();
    SetTargetFPS(144);
    Texture2D starting_screen_bomb;
    
    starting_screen_bomb = LoadTexture("start_bomb.png");
    
    while (!WindowShouldClose())
    {   
        
        BeginDrawing();
            ClearBackground(GRAY);
            DrawText("MineSweeper",20, 5, 150, DARKBLUE);
            DrawText("Press space to continue",20, 200, 80, WHITE);
            DrawText("Press escape or Q to close the game",20, 300, 80, WHITE);
            DrawText("Press space to F to go fullscreen",20, 400, 80, WHITE);
            DrawText("fuck ads",20, 1000, 50, WHITE);
            DrawTexture(starting_screen_bomb, 260, 980, WHITE);
            
            if(IsKeyPressed(KEY_SPACE)){
                break;
            }
            if(IsKeyPressed(KEY_Q)){
                CloseWindow();
            }
            if(IsKeyPressed(KEY_F)){
                ToggleFullscreen();
                }
            
        EndDrawing();
        
    }

    
    while (!WindowShouldClose())
    {
        
        
        
        
        BeginDrawing();
            ClearBackground(DARKGRAY);
            DrawText("123",20, 5, 150, WHITE);
        EndDrawing();
        
    }

    CloseWindow();

    return 0;
}
