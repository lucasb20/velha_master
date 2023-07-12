#include "lib/TicTacToe.hpp"
#include "lib/minimax.hpp"
#include "lib/nnue.hpp"

int main(int argc, char**argv){
    if(argc!=2){
        printf("Digite %s <choose>\n",*argv);
        printf("op:\n0 -> Player vs Player\n1 -> Player vs Engine\n2 -> Engine vs Player\n3 -> Engine vs Engine\n");
        exit(1);
    }
    int choose = atoi(*(argv+1));

    srand(time(NULL));

    TicTacToe partida;

    switch(choose){
        case 0:
        play_human_game(&partida);
        break;
        default:
        play_vs_engine(&partida,choose);
        break;
    }

    return 0;
}