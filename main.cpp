#include "lib/TicTacToe.hpp"
#include "lib/minimax.hpp"
#include "lib/nnue.hpp"

int main(int argc, char**argv){
    /* if(argc!=2){
        printf("Digite %s <choose>\n",*argv);
        printf("op:\n0 -> Player vs Player\n1 -> Player vs Engine\n2 -> Engine vs Player\n3 -> Engine vs Engine\n");
        exit(1);
    }
    int choose = atoi(*(argv+1)); */

    srand(time(NULL));

    //Depuração
    char example[] = {1,2,0,0,1,0,0,0,2};
    //char example[] = {0,1,1,2,0,2,0,0,0};
    //char example[] = {2,1,1,0,1,0,0,2,2};
    //char example[] = {0,1,0,0,2,2,1,0,0};
    //char example[] = {1,2,1,0,0,0,2,0,0};
    //char example[] = {2->6->0->1->7->4->5->8->3}
    //char example[] = {1,1,2,1,2,0,0,2,1};

    /* display(example);

    printf("A engine diz %hhd.\n",do_machine_move(example)); */

    TicTacToe partida;

    nnue_algorithm(example);

    /* switch(choose){
        case 0:
        play_human_game(&partida);
        break;
        default:
        play_vs_engine(&partida,choose);
        break;
    } */

    return 0;
}