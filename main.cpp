#include "lib/TicTacToe.hpp"
#include "lib/minimax.hpp"

int main(){
    TicTacToe partida;

    char match[] = {1,2,1,1,2,2,1,1,2};
    partida.define_match(match);
    
    partida.display_match();

    printf("A engine diz que a solução é %hhu.\n",do_machine_move(partida.match,true));

    return 0;
}