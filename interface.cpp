#include "lib/interface.hpp"


int main(int argc, char ** argv){
    /* if(argc!=2){
        printf("Digite %s <choose>\n",*argv);
        printf("op:\n0 -> Player vs Player\n1 -> Player vs Engine\n2 -> Engine vs Player\n3 -> Engine vs Engine\n");
        exit(1);
    }
    int choose = atoi(*(argv+1)); */

    srand(time(NULL));

    if(SDL_Init(SDL_INIT_VIDEO)){
        std::cout << "Erro." << std::endl;
        SDL_Quit();
        exit(1);
    }

    SDL_Window *window = nullptr;

    window = SDL_CreateWindow("Velha Master", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);

    if(window == nullptr){
        std::cout << "Erro." << std::endl;
        SDL_Quit();
        exit(1);
    }

    SDL_Renderer* Render = nullptr;

    Render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    char pos[] = {0,0,0,0,0,0,0,0,0};

    drawPos(window,Render,pos);

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