#include "lib/TicTacToe.hpp"

void play_human_game(TicTacToe *partida){
    char turn;
    int i, j;
    char move;
    
    while(partida->check_winner()==0){
        partida->display_match();
        turn = partida->getTurn();
        printf("Vez do %c\n",turn);
        do{
            scanf("%d,%d",&i,&j);
            move = (i-1)*3+(j-1);
        }while(!(partida->do_move(move)));
    }

    switch(partida->check_winner()){
        case -1:
        std::cout << "Draw.\n";
        break;
        default:
        printf("O vencedor foi %c.\n",(partida->check_winner()%2)?'X':'O');
    }
}