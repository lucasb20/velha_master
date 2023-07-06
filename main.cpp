#include "lib/TicTacToe.hpp"
#include "lib/minimax.hpp"

int main(){
    TicTacToe partida;

    char match[] = {1,2,0,1,1,0,2,0,2};
    partida.define_match(match);
    partida.display_match();

    char eng = do_machine_move(partida.match,true);

    printf("Palavras da engine:\n");

    switch(eng){
        case -3:
        std::cout << "Sem movimentos possíveis.\n";
        break;
        default:
        printf("O melhor movimento é %hhd\n",eng);
    }

    return 0;
}