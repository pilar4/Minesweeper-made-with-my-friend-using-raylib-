#include "raylib.h"
#include <iostream>
#include <string>
#include <cstdlib>
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

    //Badly optimized minesweeper table -------------------------------------------------------------------------
        
    srand(time(0));
    int random;
    int bomb = 0;
    const int n=10;
    char table [n+1] [n+1];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            random = rand() % 4;
            if (random == 1)
                bomb = 9;
            else 
                bomb = 0;
            table[i][j]=bomb;   
        }
    }
    int counter=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(table[i][j]!=9){
                if(table[i-1][j-1]==9)
                    counter++;
                if(table[i-1][j]==9)
                    counter++;
                if(table[i-1][j+1]==9)
                    counter++;
                if(table[i][j-1]==9)
                    counter++;
                if(table[i][j+1]==9)
                    counter++;
                if(table[i+1][j-1]==9)
                    counter++;
                if(table[i+1][j]==9)
                    counter++;
                if(table[i+1][j+1]==9)
                    counter++;
                // cout<<i<<","<<j<<" "<<counter<<endl;
                table[i][j]=counter;
                counter=0;
            }

        }
    }
    //End of badly optimized table -----------------------------------------------------------------------------
    
     
    while (!WindowShouldClose())
    {

        BeginDrawing();
            ClearBackground(DARKGRAY);
            //DrawText("3333",20, 555, 150, DARKBLUE);
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    //postion
                    int x = 100 + j * 100; 
                    int y = 50 + i * 100;  
                
                    
                    char text[n];  
                    sprintf(text, "%d", table[i][j]); // Important stuff
                
                    // Drawing this table
                    DrawText(text, x, y, 40, BLACK);
                }
            }
            if(IsKeyPressed(KEY_Q)){
                CloseWindow();
            }
            if(IsKeyPressed(KEY_F)){
                ToggleFullscreen();
                }
             
            
                
            
        EndDrawing();
        
    }

    CloseWindow();

    return 0;
}
