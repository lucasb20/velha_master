//Arquivo de depuração

#include "lib/TicTacToe.hpp"
#include "lib/minimax.hpp"
#include "lib/nnue.hpp"

#define DEBUG

int main(int argc, char**argv){
    srand(time(NULL));

    char example[] = {1,2,0,0,1,0,0,0,2};
    //char example[] = {0,1,1,2,0,2,0,0,0};
    //char example[] = {2,1,1,0,1,0,0,2,2};
    //char example[] = {0,1,0,0,2,2,1,0,0};
    //char example[] = {1,2,1,0,0,0,2,0,0};
    //char example[] = {2->6->0->1->7->4->5->8->3}
    //char example[] = {1,1,2,1,2,0,0,2,1};

    display(example);

    printf("A engine diz %hhd.\n",do_machine_move(example));

    //nnue_algorithm(example);

    return 0;
}