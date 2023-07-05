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

    for(int i = 0; i < copias.qtd ; i++){
        copias.acoes[i] = _min(copias.acoes[i].array);
    }

    return copias.acoes[search_max(&copias)];
}

position _min(char *pos){
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
            copy_and_move(pos,copias.acoes[k].array,i,2);
            k++;
        }
    }

    for(int i = 0; i < copias.qtd ; i++){
        copias.acoes[i] = _max(copias.acoes[i].array);
    }

    return copias.acoes[search_min(&copias)];
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

int search_max(acts *copias){
    int maior = 0;
    int pos = 0;
    for(int i=0; i<copias->qtd;i++){
        if(copias->acoes[i].val>maior){
            maior = copias->acoes[i].val;
            pos = i;
        }
    }
    return pos;
}

int search_min(acts *copias){
    int menor = 0;
    int pos = 0;
    for(int i=0; i<copias->qtd;i++){
        if(copias->acoes[i].val<menor){
            menor = copias->acoes[i].val;
            pos = i;
        }
    }
    return pos;
}