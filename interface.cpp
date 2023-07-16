#include "lib/interface.hpp"
#include <iostream>
#include <cstdlib>
#include <SDL2/SDL.h>

int main(){
    if(SDL_Init(SDL_INIT_VIDEO)){
        std::cout << "Erro." << std::endl;
        SDL_Quit();
        exit(1);
    }

    int window_height=640, window_width=480;

    SDL_Window *window = nullptr;

    window = SDL_CreateWindow("Velha Master", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_height, window_width, SDL_WINDOW_SHOWN);

    if(window == nullptr){
        std::cout << "Erro." << std::endl;
        SDL_Quit();
        exit(1);
    }

    SDL_Renderer* Render = nullptr;

    Render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Rect background;

    SDL_GetWindowSize(window,&window_width,&window_height);

    background.x = background.y = 0;
    background.h = window_height;
    background.w = window_width;

    SDL_SetRenderDrawColor(Render, 200, 255, 200, 255);
    SDL_RenderFillRect(Render,&background);
    SDL_RenderPresent(Render);

    bool isRunning = true;

    SDL_Event ev;

    while(isRunning){
        while(SDL_PollEvent(&ev) != 0){
            if(ev.type == SDL_QUIT){
                isRunning = false;
            }
        }

        SDL_RenderClear(Render);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}