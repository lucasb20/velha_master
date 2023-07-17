#include "lib/interface.hpp"

void drawPos(SDL_Window *window,SDL_Renderer *Render, char *pos){
    SDL_Rect background;

    int window_height = 0, window_width = 0;

    SDL_GetWindowSize(window,&window_width,&window_height);

    background.x = background.y = 0;
    background.h = window_height;
    background.w = window_width;

    SDL_SetRenderDrawColor(Render, 200, 255, 200, 255);
    SDL_RenderFillRect(Render,&background);

    SDL_SetRenderDrawColor(Render, 0, 0, 0, 255);

    int boardSize = 300;
    int barHeight = boardSize / 3;

    for (int i = 1; i < 3; i++) {
        SDL_RenderDrawLine(Render, 160, i * barHeight+60, boardSize+160, i * barHeight+60);
    }

    for (int i = 1; i < 3; i++) {
        SDL_RenderDrawLine(Render, i * barHeight+160, 60, i * barHeight+160, boardSize+60);
    }    

    int x_dist=20;
    int o_dist=20;

    std::vector<std::vector<int>> pos_it(9,std::vector<int>(2,0));

    for(int i = 0; i < 9; i++){
        switch(pos[i]){
            case 0:
            continue;
            break;

            case 1: 
            SDL_RenderDrawLine(Render, pos_it[i][0], pos_it[i][1], pos_it[i][0]+x_dist, pos_it[i][1]+x_dist);
            SDL_RenderDrawLine(Render, pos_it[i][0]+x_dist, pos_it[i][1], pos_it[i][0], pos_it[i][1]+x_dist);
            break;

            case 2:
            drawCircle(Render,pos_it[i][0]+o_dist,pos_it[i][1]+o_dist,x_dist);
            break;

            default:
            std::cout << "pos[i] -> " << pos[i] << std::endl;
            exit(1);
        }
    }
}

void drawCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius){
    int x, y;
    for (int angle = 0; angle <= 360; angle += 10)
    {
        float radians = angle * M_PI / 180.0;
        x = centerX + radius * cos(radians);
        y = centerY + radius * sin(radians);
        SDL_RenderDrawPoint(renderer, x, y);
    }
}