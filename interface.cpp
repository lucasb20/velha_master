#include "lib/interface.hpp"
#include "lib/TicTacToe.hpp"
#include "lib/minimax.hpp"

int main(int argc, char ** argv){
    if(argc!=2){
        printf("Digite %s <choose>\n",*argv);
        printf("op:\n0 -> Player vs Player\n1 -> Player vs Engine\n2 -> Engine vs Player\n3 -> Engine vs Engine\n");
        exit(1);
    }
    int choose = atoi(*(argv+1));

    srand(time(NULL));
    SDL_SetHint(SDL_HINT_VIDEO_MINIMIZE_ON_FOCUS_LOSS, "0");

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

    TicTacToe partida;

    char (*player1)(std::vector<char>);
    char (*player2)(std::vector<char>);

    switch(choose){
        case 0:
        player1 = &getPlayer;
        player2 = &getPlayer;
        break;

        case 1:
        player1 = &getPlayer;
        player2 = &do_machine_move;
        break;

        case 2:
        player1 = &do_machine_move;
        player2 = &getPlayer;
        break;

        default:
        player1 = &do_machine_move;
        player2 = &do_machine_move;
        break;
    }

    char move;
    drawPos(window,Render,partida.match);
    SDL_RenderPresent(Render);

    SDL_Event ev;

    bool running = true;

    while(running){
        printf("Vez do %c:\n",partida.getTurn());

        move = (!(partida.getTurn_num()%2))?player1(partida.match):player2(partida.match);
        if(move != -3)partida.do_move(move);

        drawPos(window,Render,partida.match);
        SDL_RenderPresent(Render);

        SDL_Delay(500);
        if(check_winner(partida.match) != 0)break;
    }

    switch(check_winner(partida.match)){
        case -1:
        std::cout << "Draw.\n";
        break;
        default:
        printf("O vencedor foi %c.\n",(check_winner(partida.match)%2)?'X':'O');
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}