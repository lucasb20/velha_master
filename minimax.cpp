#include "lib/minimax.hpp"
#include "lib/TicTacToe.hpp"

position _max(char *pos){
    position aux;
    acts copias;
    copias.qtd = 0;
    if(check_winner(pos)!=0){
        aux.val = check_winner(pos);
        copy_match(pos,aux.array);
        return aux;
    }

    for(int i = 0; i < 9; i++)if(pos[i]==0)copias.qtd++;
    if(copias.qtd > 0){
        copias.acoes = (position*) calloc(copias.qtd,sizeof(position));
    }    

    int k=0;
    for(int i = 0; i < 9; i++){
        if(pos[i]==0){
            copias.acoes[k].val = 0;
            copy_and_move(pos,copias.acoes[k].array,i,1);
            k++;
        }
    }

    
}

position _min(char *pos){

}

void copy_match(char*pos,char*ref){
    ref = (char*) calloc(9,sizeof(char));
    for(int i=0;i<9;i++){
        ref[i] = pos[i];
    }
}

void copy_and_move(char *pos,char*ref,char move,char turn){
    ref = (char*) calloc(9,sizeof(char));
    for(int i=0;i<9;i++){
        ref[i] = pos[i];
    }
    ref[move] = turn;
}