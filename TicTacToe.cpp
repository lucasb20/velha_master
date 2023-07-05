#include "lib/TicTacToe.hpp"

void play_human_game(TicTacToe *partida){
    char turn;
    int i, j;
    char move;
    
    while(check_winner(partida->match)==0){
        partida->display_match();
        turn = partida->getTurn();
        printf("Vez do %c\n",turn);
        do{
            scanf("%d,%d",&i,&j);
            move = (i-1)*3+(j-1);
        }while(!(partida->do_move(move)));
    }

    switch(check_winner(partida->match)){
        case -1:
        std::cout << "Draw.\n";
        break;
        default:
        printf("O vencedor foi %c.\n",(check_winner(partida->match)%2)?'X':'O');
    }
}

char check_winner(char*partida){
    char winner = 0;
    char qtd_winner = 0;
    for(int i = 0; i < 7; i+=3){
        if((partida[i] == partida[i+1]) && (partida[i+1] == partida[i+2]) && (partida[i] != 0)){
            winner = partida[i];
            qtd_winner++;
        }
    }
    for(int i = 0; i < 3; i++){
        if((partida[i] == partida[i+3]) && (partida[i+3] == partida[i+6]) && (partida[i] != 0)){
            winner = partida[i];
            qtd_winner++;
        }
    }
    if((partida[0] == partida[4]) && (partida[4] == partida[8]) && (partida[0] != 0)){
            winner = partida[0];
            qtd_winner++;
        }
    if((partida[2] == partida[4]) && (partida[4] == partida[6]) && (partida[2] != 0)){
            winner = partida[2];
            qtd_winner++;
        }

    if(qtd_winner > 1)return -2;

    if(winner != 0)return winner;

    bool draw = true;
    for(int i = 0; i < 9; i++)if(partida[i]==0)draw=false;

    if(draw)return -1;

    return 0;
}