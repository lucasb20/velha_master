#include "lib/minimax.hpp"
#include "lib/TicTacToe.hpp"

#define DEBUG

void _max(char *pos, position *ref){
    acts copias;
    copias.qtd = 0;
    #ifdef DEBUG
    std::cout << "Check position\n";           
    #endif
    if(check_winner(pos)!=0){
        ref->val = check_winner(pos);
        copy_match(pos,ref->array); 
        return;
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
        _min(copias.acoes[i].array,&(copias.acoes[i]));
    }

    ref->val=copias.acoes[search_max(&copias)].val;
    copy_match(copias.acoes[search_max(&copias)].array,ref->array);

    return;
}

void _min(char *pos,position *ref){
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

char do_machine_move(char *pos,bool option){
    position aux;

    if(option){
        aux = _max(pos);
    }
    else{
        aux = _min(pos);
    }

    #ifdef DEBUG
    std::cout << "aux.array\n";
    display(aux.array);
    std::cout << "pos\n";
    display(pos);
    #endif

    for(int i=0; i<9; i++){
        if(aux.array[i] != pos[i]){
            return i;
        }
    }
    return -3;
}

void display(char*pos){
            char casa=-1;
            for(int i = 0; i < 9; i++){
                switch(pos[i]){
                    case 0:
                    casa = '-';
                    break;
                    case 1:
                    casa = 'O';
                    break;
                    case 2:
                    casa = 'X';
                    break;
                    default:
                    casa = pos[i];
                    break;
                }
                printf("%c",casa);
                if(i%3==2)std::cout << '\n';
            }
}