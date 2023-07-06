#include "lib/minimax.hpp"
#include "lib/TicTacToe.hpp"

void _max(char *pos, position *ref){
    acts copias;
    copias.qtd = 0;
    if(check_winner(pos)!=0){
        ref->val = check_winner(pos);
        copy_match(pos,&(ref->array)); 
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
            copy_and_move(pos,&(copias.acoes[k].array),i,1);
            k++;
        }
    }
    
    for(int i = 0; i < copias.qtd ; i++){
        _min(copias.acoes[i].array,&(copias.acoes[i]));
    }

    ref->val=copias.acoes[search_max(&copias)].val;
    copy_match(copias.acoes[search_max(&copias)].array,&(ref->array));
}

void _min(char *pos,position *ref){
    acts copias;
    copias.qtd = 0;
    if(check_winner(pos)!=0){
        ref->val = check_winner(pos);
        copy_match(pos,&(ref->array)); 
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
            copy_and_move(pos,&(copias.acoes[k].array),i,2);
            k++;
        }
    }

    for(int i = 0; i < copias.qtd ; i++){
        _max(copias.acoes[i].array,&(copias.acoes[i]));
    }

    ref->val=copias.acoes[search_min(&copias)].val;
    copy_match(copias.acoes[search_min(&copias)].array,&(ref->array));
}

void copy_match(char*pos,char**ref){
    if(*ref==nullptr){
        *ref = (char*) calloc(9,sizeof(char));
    }
    
    for(int i=0;i<9;i++){
        (*ref)[i] = pos[i];
    }
}

void copy_and_move(char *pos,char**ref,char move,char turn){
    if(*ref==nullptr)*ref = (char*) calloc(9,sizeof(char));
    for(int i=0;i<9;i++){
        (*ref)[i] = pos[i];
    }
    (*ref)[move] = turn;
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
    position *aux = (position*) calloc(1,sizeof(position));

    if(option){
        _max(pos,aux);
    }
    else{
        _min(pos,aux);
    }

    for(int i=0; i<9; i++){
        if(aux->array[i] != pos[i]){
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
            casa = 'X';
            break;
            case 2:
            casa = 'O';
            break;
            default:
            casa = pos[i];
            break;
        }
        printf("%c",casa);
        if(i%3==2)std::cout << '\n';
    }

    for(int i = 0; i < 9; i++){
        printf("%d ",pos[i]);
    }
    printf("\n");   
}