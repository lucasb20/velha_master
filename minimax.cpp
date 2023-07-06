#include "lib/minimax.hpp"
#include "lib/TicTacToe.hpp"

#define DEBUG

/* 
#ifdef DEBUG
printf("teste.\n");
#endif
 */

char _max(char *pos, position *ref){
    acts copias;
    copias.qtd = 0;

    srand(time(NULL));

    if(first_move(pos)){
        return rand()%9;
    }

    if(ref->array==nullptr){
        #ifdef DEBUG
        printf("\nref->val alocado.\n");
        #endif
        ref->val=0;
    }

    #ifdef DEBUG
    printf("\nPosição recebida (max) -> %hhd.\n",check_winner(pos));
    display(pos);
    #endif

    if(check_winner(pos)!=0){
        ref->val += aval_pos(pos);
        #ifdef DEBUG
        printf("\nPosição calculada (max) -> %hhd.\n",ref->val);
        display(ref->array);
        #endif  
        copy_match(pos,&(ref->array));
        return -1;
    }
    
    #ifdef DEBUG
    printf("\nCalculando jogada seguinte (max).\n");
    #endif

    acts results;

    for(int i = 0; i < 9; i++)if(pos[i]==0)copias.qtd++;
    if(copias.qtd > 0){
        copias.acoes = (position*) calloc(copias.qtd,sizeof(position));
        results.acoes = (position*) calloc(copias.qtd,sizeof(position));
    }    
    
    int k=0;
    for(int i = 0; i < 9; i++){
        if(pos[i]==0){
            copy_and_move(pos,&(copias.acoes[k].array),i,1);
            copy_and_move(pos,&(results.acoes[k].array),i,1);
            k++;
        }
    }
    
    for(int i = 0; i < copias.qtd; i++){
        if(check_winner(copias.acoes[i].array)==1){
            ref->val+=3;
            copy_match(copias.acoes[i].array,&(ref->array));
            return check_diff(pos,copias.acoes[i].array);
        }
    }

    for(int i = 0; i < copias.qtd ; i++){
        _min(copias.acoes[i].array,&(copias.acoes[i]));
    }

    char max_val = search_max(&copias);
    char max_diff = check_diff(copias.acoes[max_val].array,results.acoes[max_val].array);
    ref->val=copias.acoes[max_val].val;
    undo_move(&(copias.acoes[max_val].array),max_diff);
    copy_match(copias.acoes[max_val].array,&(ref->array));

    return max_diff;
}

char _min(char *pos,position *ref){
    acts copias;
    copias.qtd = 0;
    
    if(ref->array==nullptr){
        printf("\nref->val alocado.\n");
        ref->val=0;
    }

    #ifdef DEBUG
    printf("\nPosição recebida (min) -> %hhd.\n",check_winner(pos));
    display(pos);
    #endif

    if(check_winner(pos)!=0){
        ref->val += aval_pos(pos);
        copy_match(pos,&(ref->array)); 
        #ifdef DEBUG
        printf("\nPosição calculada (min) -> %hhd.\n",ref->val);
        display(ref->array);
        #endif
        return -1;
    }

    #ifdef DEBUG
    printf("\nCalculando jogada seguinte (min).\n");
    #endif

    acts results;

    for(int i = 0; i < 9; i++)if(pos[i]==0)copias.qtd++;
    if(copias.qtd > 0){
        copias.acoes = (position*) calloc(copias.qtd,sizeof(position));
        results.acoes = (position*) calloc(copias.qtd,sizeof(position));
    }

    int k=0;
    for(int i = 0; i < 9; i++){
        if(pos[i]==0){
            copy_and_move(pos,&(copias.acoes[k].array),i,1);
            copy_and_move(pos,&(results.acoes[k].array),i,1);
            k++;
        }
    }

    for(int i = 0; i < copias.qtd; i++){
        if(check_winner(copias.acoes[i].array)==2){
            ref->val-=3;
            copy_match(copias.acoes[i].array,&(ref->array));
            return check_diff(pos,copias.acoes[i].array);
        }
    }

    for(int i = 0; i < copias.qtd ; i++){
        _max(copias.acoes[i].array,&(copias.acoes[i]));
    }

    char min_val = search_min(&copias);
    char min_diff = check_diff(copias.acoes[min_val].array,results.acoes[min_val].array);

    ref->val=copias.acoes[min_val].val;
    undo_move(&(copias.acoes[min_val].array),min_diff);
    copy_match(copias.acoes[min_val].array,&(ref->array));

    return min_diff;
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
    #ifdef DEBUG
    printf("Movimento a considerar [%hhd].\n",move);
    display(*ref);
    #endif
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

    char res = -3;

    if(option){
        res = _max(pos,aux);
    }
    else{
        res = _min(pos,aux);
    }

    if(res == -3)res = check_diff(aux->array,pos);

    return res;
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
            casa = '?';
            break;
        }
        printf("%c",casa);
        if(i%3==2)std::cout << '\n';
    }

/*     for(int i = 0; i < 9; i++){
        printf("%d ",pos[i]);
    }
    printf("\n"); */
}

void play_vs_engine(TicTacToe *partida, int option){
    char turn;
    int i, j;
    char move;
    
    if(option == 1){
        while(true){
            partida->display_match();
            turn = partida->getTurn();
            printf("Vez do %c\n",turn);
            do{
                scanf("%d,%d",&i,&j);
                move = (i-1)*3+(j-1);
            }while(!(partida->do_move(move)));
            if(check_winner(partida->match) != 0)break;
            move = do_machine_move(partida->match,false);
            if(move != -3)partida->do_move(move);
            if(check_winner(partida->match) != 0)break;
        }
    }
    else if(option == 2){
        while(true){
            move = do_machine_move(partida->match,true);
            if(move != -3)partida->do_move(move);
            if(check_winner(partida->match) != 0)break;
            turn = partida->getTurn();
            printf("Vez do %c\n",turn);
            partida->display_match();
            do{
                scanf("%d,%d",&i,&j);
                move = (i-1)*3+(j-1);
            }while(!(partida->do_move(move)));
            if(check_winner(partida->match) != 0)break;
        }
    }
    else{
        while(true){
            partida->display_match();
            move = do_machine_move(partida->match,true);
            if(move != -3)partida->do_move(move);
            if(check_winner(partida->match) != 0)break;
            move = do_machine_move(partida->match,false);
            if(move != -3)partida->do_move(move);
            if(check_winner(partida->match) != 0)break;
        }
    }

    switch(check_winner(partida->match)){
        case -1:
        std::cout << "Draw.\n";
        break;
        default:
        printf("O vencedor foi %c.\n",(check_winner(partida->match)%2)?'X':'O');
    }
}

char aval_pos(char*pos){
    char res;
    res = check_winner(pos);
    switch(res){
        case 1:
        res = 1;
        break;
        case 2:
        res = -1;
        break;
        default:
        res = 0;
        break;
    }
    return res;
}

char check_diff(char*pos1,char*pos2){
    int res=-3;
    for(int i = 0; i < 9; i++){
        if(pos1[i]!=pos2[i])res=i;
    }
    return res;
}

void undo_move(char **pos, char move){
    (*pos)[move] = 0;
}

bool first_move(char*pos){
    bool teste=true;
    for(int i = 0; i < 9; i++){
        if(pos[i]!=0)teste=false;
    }
    return teste;
}